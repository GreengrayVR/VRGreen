#pragma once

#include "Common.hpp"

namespace System::Collections
{
	struct ArrayList
	{
		NOIMPLEMENT(ArrayList);

		static ArrayList* ctor();

		int Add(Object* value);

		ObjectArray* ToArray();
	};

	template <typename... TArgs>
	inline ObjectArray* CreateObjectArray(TArgs&&... Args)
	{
		auto arraylist = ArrayList::ctor();

		using Expand__ = int[];
		(void)Expand__
		{
			0, (arraylist->Add(Args), 0)...
		};

		return arraylist->ToArray();
	}
}