/*!
	@file
	@author		Albert Semenov
	@date		03/2010
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __MYGUI_INPUT_ELEMENT_H__
#define __MYGUI_INPUT_ELEMENT_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_UIElement.h"

namespace MyGUI
{

	class MYGUI_EXPORT InputElement :
		public UIElement
	{
		MYGUI_RTTI_DERIVED( InputElement )

	public:
		InputElement();
		virtual ~InputElement();

		RoutedEventHandlerDelegate eventDirect;
		RoutedEventHandlerDelegate eventTunnel;
		RoutedEventHandlerDelegate eventBubble;

	protected:
		static void registerInputElement();
		static void unregisterInputElement();

		virtual void onDirect(Widget* _sender, EventInfo* _info, EventArgs* _args);
		virtual void onTunnel(Widget* _sender, EventInfo* _info, EventArgs* _args);
		virtual void onBubble(Widget* _sender, EventInfo* _info, EventArgs* _args);
	};

} // namespace MyGUI

#endif // __MYGUI_INPUT_ELEMENT_H__