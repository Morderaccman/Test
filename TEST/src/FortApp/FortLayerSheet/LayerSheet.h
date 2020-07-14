#pragma once
#include "i4pch.h"

namespace I4GE {


	class LayerSheet
	{
	public:
		LayerSheet();
		~LayerSheet();

		virtual void Update() {}
		virtual void Event() {}
		virtual void Detach() {}
		virtual void Attach() {}
	};
}