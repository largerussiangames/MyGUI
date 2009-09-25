/*!
	@file
	@author     George Evmenov
	@date       08/2009
	@module
*/
#ifndef __DEMO_KEEPER_H__
#define __DEMO_KEEPER_H__

#include "Base/BaseManager.h"

namespace demo
{

	class DemoKeeper : public base::BaseManager
	{
	public:
		virtual void createScene();
		virtual void destroyScene();

	private:
		virtual void setupResources();
	};

} // namespace demo

#endif // __DEMO_KEEPER_H__