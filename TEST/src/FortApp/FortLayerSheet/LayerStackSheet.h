#pragma once

#include "i4pch.h"
#include "LayerSheet.h"

namespace I4GE {

	class LayerStackSheet 
	{
	public:
	public:
		LayerStackSheet();
		~LayerStackSheet();

		void PushLayer(LayerSheet* layer);
		void PopLayer(LayerSheet* layer);
		void PushOverlay(LayerSheet* layer);
		void PopOverlay(LayerSheet* layer);

		std::vector<LayerSheet*>::iterator begin() { return Layers.begin(); }
		std::vector<LayerSheet*>::iterator end() { return Layers.end(); }
	private:
		std::vector<LayerSheet*> Layers;
		std::vector<LayerSheet*>::iterator LayerIn;
	};
}