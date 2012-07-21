/*!
	@file
	@author		Albert Semenov
	@date		07/2012
*/

#ifndef _0228cbb9_aa86_46b7_b23f_3d6ee87da9f9_
#define _0228cbb9_aa86_46b7_b23f_3d6ee87da9f9_

#include "Data.h"
#include "Property.h"

namespace tools
{
	class PropertyUtility
	{
	public:
		static bool isUniqueName(Data* _data, const std::string& _propertyName);
		static void executeAction(Property* _property, const std::string& _value, bool _merge = false);

		typedef std::pair<Property*, std::string> PairProprty;
		typedef std::vector<PairProprty> VectorPairProperty;
		static void storeUniqueNameProperty(const std::string& _propertyName, const std::string& _propertyUnique, Data* _parent, VectorPairProperty& _store);
		static void restoreUniqueNameProperty(VectorPairProperty& _store);

		static Property* getPropertyByName(const std::string& _dataType, const std::string& _propertyName);
		static bool isDataSelected(Data* _data);

	private:
		static Property* getPropertyByName(Data* _data, const std::string& _dataType, const std::string& _propertyName);
		static bool isDataSelected(Data* _parent, Data* _data);
	};
}

#endif
