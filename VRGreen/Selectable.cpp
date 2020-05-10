#include "Selectable.hpp"

#include "Common.hpp"
#include <Utils\Offsets.h>

void Selectable::SetInteractable(bool value)
{
	using func_t = void(*)(Selectable* selectable, bool value);

	func_t func = GetMethod<func_t>(SETINTERACTABLE);

	func(this, value);
}
