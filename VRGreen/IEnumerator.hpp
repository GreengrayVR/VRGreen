#pragma once

#include "Common.hpp"

namespace System::Collections
{
	struct IEnumerator
	{
		NOIMPLEMENT(IEnumerator);

		Object* current();

		bool MoveNext();
	};
}