#include "i4pch.h"

#include "LayerStackSheet.h"

namespace I4GE {

	LayerStackSheet::LayerStackSheet()
	{
		LayerIn = Layers.begin();
	}

	LayerStackSheet::~LayerStackSheet()
	{
		for (LayerSheet* layer : Layers)
			delete layer;
	}

	void LayerStackSheet::PushLayer(LayerSheet* layer)
	{
		LayerIn = Layers.emplace(LayerIn, layer);
	}

	void LayerStackSheet::PopLayer(LayerSheet* layer)
	{
		auto it = std::find(Layers.begin(), Layers.end(), layer);
		if (it != Layers.end())
		{
			Layers.erase(it);
			LayerIn--;
		}
	}

	void LayerStackSheet::PushOverlay(LayerSheet* overlayer)
	{
		Layers.emplace_back(overlayer);
	}

	void LayerStackSheet::PopOverlay(LayerSheet* overlayer)
	{
		auto it = std::find(Layers.begin(), Layers.end(), overlayer);
		if (it != Layers.end())
			Layers.erase(it);
	}

}