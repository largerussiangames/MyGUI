
//#include "MyGUI_Prerequest.h"
#include "StrangeButton.h"
#include "MyGUI_WidgetSkinInfo.h"
#include "MyGUI_ISubWidgetText.h"

namespace MyGUI
{

	MYGUI_RTTI_CHILD_IMPLEMENT( StrangeButton, Widget );

	StrangeButton::StrangeButton(const IntCoord& _coord, Align _align, const WidgetSkinInfoPtr _info, WidgetPtr _parent, ICroppedRectangle * _croppedParent, IWidgetCreator * _creator, const std::string & _name) :
		Widget(_coord, _align, _info, _parent, _croppedParent, _creator, _name),
		mIsMousePressed(false),
		mIsMouseFocus(false),
		mIsStateCheck(false)
	{

		// ������ ��������
		const MapString & properties = _info->getProperties();
		if (!properties.empty()) {
			MapString::const_iterator iter = properties.find("ButtonPressed");
			if (iter != properties.end()) setButtonPressed(utility::parseBool(iter->second));
		}
	}

	void StrangeButton::onMouseSetFocus(WidgetPtr _old)
	{
		Widget::onMouseSetFocus(_old);
		mIsMouseFocus = true;

		if (mText == null) return;
		Ogre::String s, str = mText->getCaption();
		for (int i = (int)str.length() - 1; i >= 0; i--)
			s += str[i];

		mText->setCaption(s);

		updateButtonState();
	}

	void StrangeButton::onMouseLostFocus(WidgetPtr _new)
	{
		Widget::onMouseLostFocus(_new);
		mIsMouseFocus = false;

		if (mText == null) return;
		Ogre::String s, str = mText->getCaption();
		for (int i = (int)str.length() - 1; i >= 0; i--)
			s += str[i];
		
		mText->setCaption(s);

		updateButtonState();
	}

	void StrangeButton::onMouseButtonPressed(int _left, int _top, MouseButton _id)
	{
		Widget::onMouseButtonPressed(_left, _top, _id);
		if (MB_Left != _id) return;
		mIsMousePressed = true;
		updateButtonState();
	}

	void StrangeButton::onMouseButtonReleased(int _left, int _top, MouseButton _id)
	{
		Widget::onMouseButtonReleased(_left, _top, _id);
		if (MB_Left != _id) return;
		mIsMousePressed = false;
		updateButtonState();
	}

} // namespace MyGUI