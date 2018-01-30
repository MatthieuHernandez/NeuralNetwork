#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout << "STEP 00 finished : Start" << endl;
    this->initialize();
    cout << "STEP 01 finished : Initialize" << endl;

    displayImage(0);
    ui->comboBoxSet->addItem("Testing set");
    ui->comboBoxSet->addItem("Training set");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    this->MNIST = Data::create_MNIST();
}

unsigned char MainWindow::getImages(int number, int x, int y)
{
    if(displayedSet == testing)
        return (unsigned char)(this->MNIST.testing.images[number][y * 28 + x]*255.0);
    else
        return (unsigned char)(this->MNIST.trainig.images[number][y * 28 + x]*255.0);
}

void MainWindow::on_spinBoxImageId_valueChanged(int value)
{
    displayImage(value);
}

void MainWindow::displayImage(int value)
{
    int size = 28;
    int multiple = 10;
    QImage picture(size, size, QImage::Format_RGB32);
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            picture.setPixel(x, y, qRgb(getImages(value, x, y),
                                        getImages(value, x, y),
                                        getImages(value, x, y)));
        }
    }
    QImage scalePicture = picture.scaled(size*multiple, size*multiple, Qt::KeepAspectRatio);
    ui->Image->setPixmap(QPixmap::fromImage(scalePicture));

    if(displayedSet == training)
        ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(value, this->displayedSet))));
    else
        ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(value, this->displayedSet))));
}

int MainWindow::getLabel(int value, DisplayedSet displayedSet)
{
    if(displayedSet == training)
        if      (this->MNIST.trainig.labels[value][0] == 1) return 0;
        else if (this->MNIST.trainig.labels[value][1] == 1) return 1;
        else if (this->MNIST.trainig.labels[value][2] == 1) return 2;
        else if (this->MNIST.trainig.labels[value][3] == 1) return 3;
        else if (this->MNIST.trainig.labels[value][4] == 1) return 4;
        else if (this->MNIST.trainig.labels[value][5] == 1) return 5;
        else if (this->MNIST.trainig.labels[value][6] == 1) return 6;
        else if (this->MNIST.trainig.labels[value][7] == 1) return 7;
        else if (this->MNIST.trainig.labels[value][8] == 1) return 8;
        else if (this->MNIST.trainig.labels[value][9] == 1) return 9;
        else return -1;
    else
        if      (this->MNIST.testing.labels[value][0] == 1) return 0;
        else if (this->MNIST.testing.labels[value][1] == 1) return 1;
        else if (this->MNIST.testing.labels[value][2] == 1) return 2;
        else if (this->MNIST.testing.labels[value][3] == 1) return 3;
        else if (this->MNIST.testing.labels[value][4] == 1) return 4;
        else if (this->MNIST.testing.labels[value][5] == 1) return 5;
        else if (this->MNIST.testing.labels[value][6] == 1) return 6;
        else if (this->MNIST.testing.labels[value][7] == 1) return 7;
        else if (this->MNIST.testing.labels[value][8] == 1) return 8;
        else if (this->MNIST.testing.labels[value][9] == 1) return 9;
        else return -1;
}

void MainWindow::compute()
{
    this->initializeNeuralNetwork();

    clock_t numberOfClockCycle = clock();
    float clusteringRateMax = -1;
    float clusteringRate = -1;
    int epochMax = 0;


    for(int count = 1; ; count++)
    {
        for(int index = 0; index < MNIST.trainig.size; index ++)
        {
            neuralNetwork.train(MNIST.trainig.images[index], MNIST.trainig.labels[index]);
            if(index%500 == 0)
            {
                ui->labelCount->setText(QString::fromStdString((string)"Count : " + to_string(index)));
                QApplication::processEvents();
            }
        }

        for(int index = 0; index < MNIST.testing.size; index ++)
        {
            neuralNetwork.calculateClusteringRateForClassificationProblem(MNIST.testing.images[index], getLabel(index, testing));
        }
        clusteringRate = neuralNetwork.getClusteringRate();
        if(clusteringRate > clusteringRateMax)
        {
            clusteringRateMax = clusteringRate;
            epochMax = count;
        }
        cout << "clustering rate : " << clusteringRate << " epoch : " << count << " time : " << (float)numberOfClockCycle/CLOCKS_PER_SEC << " secondes" << endl;
        cout << "clustering rate max : " << clusteringRateMax << " epoch : " << epochMax << endl;
        //cout << neuralNetwork.display() << endl << endl;
    }
}

void MainWindow::initializeNeuralNetwork()
{
    this->neuralNetwork = NeuralNetwork(784, 1, 100, 10);
    neuralNetwork.setLearningRate(0.05f);

    if(neuralNetwork.isValid() != 0)
    {
        cout << "ERROR : " << neuralNetwork.getLastError() << endl;
        exit(0);
    }

    this->input.resize(784);
    this->desired.resize(10);
}

void MainWindow::on_pushButton_clicked()
{
    compute();
}

void MainWindow::on_comboBoxSet_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->displayedSet = testing;
        ui->spinBoxImageId->setMaximum(9999);
        ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(ui->spinBoxImageId->value(), this->displayedSet))));
    }
    if(index == 1)
    {
        this->displayedSet = training;
        ui->spinBoxImageId->setMaximum(59999);
        ui->labelImage->setText(QString::fromStdString((string)"Label : " + to_string(getLabel(ui->spinBoxImageId->value(), this->displayedSet))));
    }

    displayImage(ui->spinBoxImageId->value());
}
