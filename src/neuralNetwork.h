#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "perceptron.h"
#include <time.h>

class NeuralNetwork
{
    private :

        static bool isTheFirst;

        float maxOutputValue;
        float maxOutputIndex;

        int lastError;
        float learningRate;
        float clusteringRate;
        float previousClusteringRate;
        float error;
        float momentum;

        int numberOfResultsClassifiedWell;
        int numberOfResultsMisclassefied;

        int lenghtOfShortRuns;
        int shortRunCounter;


        int numberOfHiddenLayers;
        int numberOfLayers;
        int numberOfInput;
        int numberOfOutput;

        vector<int> structureOfNetwork;


        bool classifiedWell;

        vector<vector<float>> results;
        vector<vector<float>> errors;
        void backpropagationAlgorithm(const vector<float> &inputs, const vector<float> &desired);
        void calculateError(const int neuronNumberLayer, const int neuronNumber);

        void resetAllNeurons();

        vector<vector<Perceptron>> neurons;

        vector<float> outputs;


    public :


        NeuralNetwork();
        //NeuralNetwork(int numberOfInput, int numberOfHiddenLayers, int numberOfNeuronsInHiddenLayers, int numberOfOutput = 1, float learningRate = 0.05f);
        NeuralNetwork(vector<int> structureOfNetwork, float learningRate = 0.05f);
        void train(const vector<float> &inputs, const vector<float> &desired);

        vector<float> calculateOutput(const vector<float> &inputs);

        void calculateClusteringRateForRegressionProblem(const vector<float> &inputs, const vector<int> &desired);
        void calculateClusteringRateForClassificationProblem(const vector<float> &inputs, const int classNumber);

        void addANeuron(unsigned int layerNumber);
        string display();

        int isValid();
        int getLastError();






        void setLearningRate(float learningRate);
        float getLearningRate() const;
        void setMomentum(float value);
        float getMomentum() const;
        void setNumberOfSameClusteringAfterReset(unsigned int number);
        int getNumberOfSameClusteringAfterReset() const;
        void setLenghtOfShortRuns(unsigned int lenght);


        int getLenghtOfShortRuns() const;
        int getShortRunCounter() const;
        int getNumberOfInputs() const;
        int getNumberOfHiddenLayers() const;
        int getNumberOfNeuronsInHiddenLayers(int layerNumber) const;
        int getNumberOfResultsClassifiedWell() const;
        int getNumberOfNegativeResultsMisclassefied() const;
        int getNumberOfOutputs() const;
        float getClusteringRate();

        bool operator==(const NeuralNetwork &neuralNetwork);
        bool operator!=(const NeuralNetwork &neuralNetwork);
};

#endif // NEURAL_NETWORK_H
