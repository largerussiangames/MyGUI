/*!
	@file
	@author		Albert Semenov
	@date		11/2009
	@module
*/
#include "precompiled.h"
#include "FriendPanel.h"

namespace demo
{

	FriendPanel::FriendPanel()
	{
		initialiseByAttributes(this);

		const MyGUI::IntSize& size = MyGUI::Gui::getInstance().getViewSize();
		int offset = size.width / 3;

		mMainWidget->setPosition(offset - (mMainWidget->getWidth() / 2), (size.height - mMainWidget->getHeight()) / 2);
	}

} // namespace demo