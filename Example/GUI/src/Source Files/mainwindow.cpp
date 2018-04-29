#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtconcurrentrun.h>
#include <QApplication>
#include <qpen.h>
#include "MNIST.h"
#include "ControllersManager.h"

using namespace std;


MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->write("loading ...", false);
	ui->spinBoxNeurons->setValue(0);
	this->refreshDataUI();
	this->write("data loaded", false);
}

MainWindow::~MainWindow()
{
	delete ui;
}

unsigned char MainWindow::getImages(int number, int x, int y)
{
	if (displayedSet == testing)
		return (unsigned char)((this->manager->getController(indexMNIST).getData().sets[testing].data[number][y * 28 + x] + 1.0) *
			127.4);
	else
		return (unsigned char)((this->manager->getController(indexMNIST).getData().sets[training].data[number][y * 28 + x] + 1.0)
			* 127.4);
}

void MainWindow::write(std::string text, bool onlyConsole)
{
	ui->lineEditInformation->setText(QString::fromStdString(text));
}

void MainWindow::refreshDataUI()
{
	ui->comboBoxLayer->setCurrentIndex(0);

	//const int neuronsNumber = currentController->getNeuralNetwork().getNumberOfNeuronsInLayer(0);
	//ui->spinBoxNeurons->setValue(neuronsNumber);

	//const int function = currentController->getNeuralNetwork().getActivationFunctionInLayer(0);
	//ui->comboBoxActivationfunction->setCurrentIndex(function);
}

void MainWindow::displayImage(int value)
{
	const int size = 28;
	const int multiple = 10;
	QImage picture(size, size, QImage::Format_RGB32);
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			picture.setPixel(x, y, qRgb(getImages(value, x, y),
			                            getImages(value, x, y),
			                            getImages(value, x, y)));
		}
	}
	QImage scalePicture = picture.scaled(size * multiple, size * multiple, Qt::KeepAspectRatio);
	ui->Image->setPixmap(QPixmap::fromImage(scalePicture));

	if (displayedSet == training)
		ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(value, this->displayedSet))));
	else
		ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(value, this->displayedSet))));
}

int MainWindow::getLabel(int value, DisplayedSet displayedSet)
{
	for (int i = 0; i > 10; i++)
	{
		if (this->manager->getController(indexMNIST).getData().sets[displayedSet].labels[value][i] == 1) return i;
	}
	return -1;
}

/**************************************************
 *				  	    SLOTS				  	  *
 **************************************************/

void MainWindow::on_pushButton_clicked()
{
	auto future = QtConcurrent::run(currentController, &Controller::compute);
}

void MainWindow::on_comboBoxSet_currentIndexChanged(int index)
{
	if (index == 0)
	{
		this->displayedSet = testing;
		ui->spinBoxImageId->setMaximum(9999);
		ui->labelImage->setText(
			QString::fromStdString(
				(string)"Label : " + to_string(getLabel(ui->spinBoxImageId->value(), this->displayedSet))));
	}
	if (index == 1)
	{
		this->displayedSet = training;
		ui->spinBoxImageId->setMaximum(59999);
		ui->labelImage->setText(
			QString::fromStdString(
				(string)"Label : " + to_string(getLabel(ui->spinBoxImageId->value(), this->displayedSet))));
	}

	displayImage(ui->spinBoxImageId->value());
}

void MainWindow::on_spinBoxImageId_valueChanged(int value)
{
	displayImage(value);
}

void MainWindow::on_pushButtonConsole_clicked()
{
	console->show();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
	currentController = &this->manager->getController(index);
}

void MainWindow::graphClusteringRate()
{
	QApplication::processEvents();
	if (flag_graph)
	{
		ui->customPlot->addGraph();
		ui->customPlot->addGraph();
		ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
		ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
		// first graph will be filled with translucent blue
		ui->customPlot->graph(1)->setPen(QPen(Qt::red));
		connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
		connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
		ui->customPlot->yAxis->setRange(0, 100); // (0, 100)
		flag_graph = false;
	}
	// make left and bottom axes always transfer their ranges to right and top axes:
	x.clear();
	for (auto i = 0; i < clusteringRates.size(); i++)
	{
		x.push_back(i);
	}
	ui->customPlot->graph(0)->setData(x, clusteringRates);
	ui->customPlot->xAxis->setRange(0, clusteringRates.size() - 1);
	ui->customPlot->replot();
}
