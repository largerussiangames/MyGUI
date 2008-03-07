/*!
	@file
	@author		Albert Semenov
	@date		01/2008
	@module
*/
#ifndef __MYGUI_PROGRESS_FACTORY_H__
#define __MYGUI_PROGRESS_FACTORY_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_WidgetFactoryInterface.h"
#include "MyGUI_WidgetDefines.h"

namespace MyGUI
{
	namespace factory
	{

		class _MyGUIExport ProgressFactory : public WidgetFactoryInterface
		{
		public:
			ProgressFactory();
			~ProgressFactory();

			// ���������� ���������� �������
			const Ogre::String& getType();
			WidgetPtr createWidget(const Ogre::String& _skin, const IntCoord& _coord, Align _align, CroppedRectanglePtr _parent, const Ogre::String& _name);

			// ������ ��� ��������
			void Progress_Range(WidgetPtr _widget, const Ogre::String &_key, const Ogre::String &_value);
			void Progress_Position(WidgetPtr _widget, const Ogre::String &_key, const Ogre::String &_value);
			void Progress_AutoTrack(WidgetPtr _widget, const Ogre::String &_key, const Ogre::String &_value);
		};

	} // namespace factory
} // namespace MyGUI

#endif // __MYGUI_PROGRESS_FACTORY_H__
