/*!
	@file
	@author		Albert Semenov
	@date		07/2012
*/

#include "Precompiled.h"
#include "UniqueNamePropertyInitialisator.h"
#include "FactoryManager.h"
#include "DataManager.h"
#include "DataUtility.h"

namespace tools
{

	FACTORY_ITEM_ATTRIBUTE(UniqueNamePropertyInitialisator)

	UniqueNamePropertyInitialisator::UniqueNamePropertyInitialisator()
	{
	}

	UniqueNamePropertyInitialisator::~UniqueNamePropertyInitialisator()
	{
	}

	void UniqueNamePropertyInitialisator::initialise(Property* _property)
	{
		Data* parent = DataUtility::getSelectedParentDataByType(_property->getOwner()->getType()->getName());
		if (parent == nullptr)
			return;

		std::string name = DataUtility::getUniqueName(parent, "unnamed_");
		_property->setValue(name);
	}

}
