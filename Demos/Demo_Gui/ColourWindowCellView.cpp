/*!
	@file
	@author		Albert Semenov
	@date		01/2009
	@module
*/

#include "ColourWindowCellView.h"

namespace demo
{

	void ColourWindowCellView::getCellDimension(MyGUI::WidgetPtr _sender, MyGUI::IntCoord & _coord, bool _drop)
	{
		_coord.set(0, 0, _sender->getClientCoord().width, 20);
	}

	ColourWindowCellView::ColourWindowCellView(MyGUI::WidgetPtr _parent) :
		wraps::BaseCellView<ColourWindowCellData>("ColourWindowCellView.layout", _parent)
	{
		mMainWidget->setCoord(0, 0, _parent->getWidth(), _parent->getHeight());
		mMainWidget->setAlign(MyGUI::Align::Stretch);

		assignWidget(mText, "Text");
		assignWidget(mColour, "Colour");

		mRawColourView = mColour->getSubWidgetMain()->castType<MyGUI::RawRect>();
	}

	void ColourWindowCellView::update(const MyGUI::ItemInfo & _info, ColourWindowCellData * _data)
	{
		
		if (_info.update) {
			mText->setCaption(_data->getName());
			mRawColourView->setRectColour(_data->getColour(), _data->getColour(), _data->getColour(), _data->getColour());
		}

		if (_info.active) {
			mText->setColour(MyGUI::Colour::White);
		}
		else {
			mText->setColour(MyGUI::Colour::Black);
		}

		if (_info.select) {
			mColour->show();
		}
		else {
			mColour->hide();
		}

	}

} // namespace demo
