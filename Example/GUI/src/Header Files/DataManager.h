#pragma once
#include "DataVisualizationWidget.h"

enum indexData
{
	indexIris = 0,
	indexWine,
	indexMNIST,
	indexCIFAR_10,
	indexCurrencyRates,
	End
};

class DataManager
{
public:

	DataManager();
	virtual ~DataManager() = default;

	void initializeInputsNNs(int index);

	Controller* getController(int index);
	DataVisualizationWidget* getWidget(int index);

private:

	std::vector<Controller*> controllers;
	std::vector<DataVisualizationWidget*> widgets;
};
