#include "DataManager.h"
#include "Iris/Iris.hpp"
#include "MNIST/Mnist.hpp"
#include "Wine//Wine.hpp"
#include "CIFAR-10//Cifar10.hpp"
#include "CurrencyRatesEurToUsd.h"
#include "MnistVisualizationWidget.h"
#include "Cifar10VisualizationWidget.h"
#include "Fashion-MNIST/FashionMnist.hpp"
#include "FashionMnistVisualizationWidget.h"

using namespace std;
using namespace snn;

DataManager::DataManager()
{
    controllers.resize(numberOfIndex, nullptr);
    widgets.resize(numberOfIndex, nullptr);
}

void DataManager::initializeInputsNNs(int index)
{
    switch (index)
    {
    case indexIris:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(13, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, sigmoid)
        };
        controllers[index]->inputs.learningRate = 0.1f;
        controllers[index]->inputs.momentum = 0.0;
        break;

    case indexWine:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(20, sigmoid),
            FullyConnected(8, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, sigmoid)
        };
        controllers[index]->inputs.learningRate = 0.01f;
        controllers[index]->inputs.momentum = 0.0;
        break;

    case indexMNIST:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(150, sigmoid),
            FullyConnected(80, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, sigmoid)
        };
        controllers[index]->inputs.learningRate = 0.1f;
        controllers[index]->inputs.momentum = 0.0;
        break;

    case indexFashionMNIST:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(150, sigmoid),
            FullyConnected(80, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, sigmoid)
        };
        controllers[index]->inputs.learningRate = 0.1f;
        controllers[index]->inputs.momentum = 0.0;
        break;

    case indexCIFAR_10:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(150, sigmoid),
            FullyConnected(80, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, sigmoid)
        };
        controllers[index]->inputs.learningRate = 0.01f;
        controllers[index]->inputs.momentum = 0.85;
        break;

    case indexCurrencyRates:
        controllers[index]->inputs.structure = vector<LayerModel>
        {
            Input(controllers[index]->getDataset().data->sizeOfData),
            FullyConnected(250, sigmoid),
            FullyConnected(60, sigmoid),
            FullyConnected(controllers[index]->getDataset().data->numberOfLabel, snn::tanh)
        };
        controllers[index]->inputs.learningRate = 0.003f;
        controllers[index]->inputs.momentum = 0.0f;
        break;

    default:
        throw exception("Missing neural network configuration for this dataset");
    }
}

Controller* DataManager::getController(int index)
{
    if (controllers[index] == nullptr)
    {
        switch (index)
        {

        case indexIris:
            controllers[index] = new Controller(*new Iris("../../../Datasets-for-Machine-Learning/Iris"));
            break;

        case indexWine:
            controllers[index] = new Controller(*new Wine("../../../Datasets-for-Machine-Learning/Wine"));
            break;

        case indexMNIST:
            controllers[index] = new Controller(*new Mnist("../../../Datasets-for-Machine-Learning/MNIST"));
            break;

        case indexFashionMNIST:
            controllers[index] = new Controller(*new FashionMnist("../../../Datasets-for-Machine-Learning/Fashion-MNIST"));
            break;

        case indexCurrencyRates:
            controllers[index] = new Controller(*new CurrencyRatesEurToUsd());
            break;

        case indexCIFAR_10:
            controllers[index] = new Controller(*new Cifar10("../../../Datasets-for-Machine-Learning/CIFAR-10"));
            break;

        default:
            throw exception("The data doesn't exist !");
        }
        this->initializeInputsNNs(index);
    }
    return controllers[index];
}


DataVisualizationWidget* DataManager::getWidget(int index)
{
    if (widgets[index] == nullptr)
    {
        switch (index)
        {
        case indexMNIST:
            widgets[index] = new MnistVisualizationWidget(nullptr, this->getController(index));
            break;

        case indexFashionMNIST:
            widgets[index] = new FashionMnistVisualizationWidget(nullptr, this->getController(index));
            break;

        case indexIris:
            widgets[index] = new DataVisualizationWidget(nullptr, this->getController(index));
            break;

        case indexWine:
            widgets[index] = new DataVisualizationWidget(nullptr, this->getController(index));
            break;

        case indexCurrencyRates:
            widgets[index] = new DataVisualizationWidget(nullptr, this->getController(index));
            break;

        case indexCIFAR_10:
            widgets[index] = new Cifar10VisualizationWidget(nullptr, this->getController(index));
            break;

        default:
            throw exception("The widget doesn't exist !");
        }
    }
    return widgets[index];
}
