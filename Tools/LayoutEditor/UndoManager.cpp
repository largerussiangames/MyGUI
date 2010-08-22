#include "precompiled.h"
#include "UndoManager.h"
#include "CommandManager.h"
#include "WidgetSelectorManager.h"

const int UNDO_COUNT = 64;

template <> UndoManager* MyGUI::Singleton<UndoManager>::msInstance = nullptr;
template <> const char* MyGUI::Singleton<UndoManager>::mClassTypeName("UndoManager");

UndoManager::UndoManager() :
	pos(0),
	operations(UNDO_COUNT),
	last_property(0),
	ew(nullptr),
	mUnsaved(false)
{
}

void UndoManager::initialise(EditorWidgets * _ew)
{
	pos = 0;
	last_property = PR_DEFAULT;
	ew = _ew;
	mUnsaved = false;

	tools::CommandManager::getInstance().registerCommand("Command_Undo", MyGUI::newDelegate(this, &UndoManager::commandUndo));
	tools::CommandManager::getInstance().registerCommand("Command_Redo", MyGUI::newDelegate(this, &UndoManager::commandRedo));
}

void UndoManager::shutdown()
{
	for (size_t i=0; i<operations.GetSize(); i++)
	{
		delete operations[i];
	}
	operations.Clear();
}

void UndoManager::undo()
{
	mUnsaved = true;

	if (pos == operations.GetSize() - 1) return;
	pos++;
	ew->clear();
	ew->loadxmlDocument(operations[pos]);
}

void UndoManager::redo()
{
	mUnsaved = true;

	if (pos == 0) return;
	pos--;
	ew->clear();
	ew->loadxmlDocument(operations[pos]);
}

void UndoManager::addValue(int _property)
{
	mUnsaved = true;

	if ((_property != PR_DEFAULT) && (_property == last_property))
	{
		delete operations.Front();
		operations.PopFirst();
		operations.Push( ew->savexmlDocument() );
		return;
	}

	last_property = _property;

	if ( pos != 0 )
	{
		last_property = PR_DEFAULT;
		while (pos)
		{
			delete operations.Front();
			operations.PopFirst();
			pos--;
		}
	}

	if ( operations.IsFull() ) delete operations.Back();
	operations.Push( ew->savexmlDocument() );
	pos = 0;
}

void UndoManager::commandUndo(const MyGUI::UString& _commandName)
{
	undo();
	tools::WidgetSelectorManager::getInstance().setSelectedWidget(nullptr);
}

void UndoManager::commandRedo(const MyGUI::UString& _commandName)
{
	redo();
	tools::WidgetSelectorManager::getInstance().setSelectedWidget(nullptr);
}
