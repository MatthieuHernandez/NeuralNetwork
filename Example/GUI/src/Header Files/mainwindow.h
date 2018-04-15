#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "neuralNetwork.h"
#include "Data.h"

using namespace std;

namespace Ui {
class MainWindow;
}

enum DisplayedSet
{
    testing,
    training
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:

        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();


    private:

        Ui::MainWindow *ui;

        data::MNIST_struct MNIST;
        std::unique_ptr<NeuralNetwork> neuralNetwork;

        vector<float> input;
        vector<float> desired;

        list<vector<float>> desired_outputs;

        DisplayedSet displayedSet = testing;

        void compute();
        void initialize();
        void initializeNeuralNetwork();
        void displayImage(int value);
        int getLabel(int value, DisplayedSet displayedSet);
        void graphClusteringRate();

        unsigned char getImages(int number, int x, int y);
        bool flag_graph = true;

        QVector<double> clusteringRateVector;

        QVector<double> x;

    private slots:

        void on_spinBoxImageId_valueChanged(int value);
        void on_pushButton_clicked();
        void on_comboBoxSet_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H