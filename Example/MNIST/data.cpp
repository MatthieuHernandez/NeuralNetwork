#include "data.h"

namespace Data
{

string path = "mnist/";

const string path_MNIST[4] = {path + "t10k-images.idx3-ubyte",
                              path + "t10k-labels.idx1-ubyte",
                              path + "train-images.idx3-ubyte",
                              path + "train-labels.idx1-ubyte",};



MNIST_struct create_MNIST()
{
   MNIST_struct MNIST = Initialize_MNIST();
   readImages(MNIST);

   return MNIST;
}

MNIST_struct Initialize_MNIST()
{
    MNIST_struct MNIST;
    MNIST.sizeOfImages = 784;
    MNIST.numberOfLabel = 10;
    MNIST.trainig.size = 60000;
    MNIST.testing.size = 10000;

    return MNIST;
}

void readImages(MNIST_struct &MNIST)
{

    ifstream imagesTestFile;
    ifstream labelsTestFile;
    ifstream imagesTrainFile;
    ifstream labelsTrainFile;

    imagesTestFile.open(path_MNIST[0], ios::in | ios::binary);
    labelsTestFile.open(path_MNIST[1], ios::in | ios::binary);
    imagesTrainFile.open(path_MNIST[2], ios::in | ios::binary);
    labelsTrainFile.open(path_MNIST[3], ios::in | ios::binary);

    readSet(MNIST.testing, imagesTestFile, labelsTestFile);
    readSet(MNIST.trainig, imagesTrainFile, labelsTrainFile);
}

void readSet(Set &set, ifstream &images, ifstream &labels)
{
    if(images.is_open() != true
    && labels.is_open() != true)
    {
        cout << "STEP FAILED" << endl;
        return;
    }
    int i = 0;
    unsigned char c = 0;

    for(i = 0; !labels.eof(); i++)
    {
        c = labels.get();

        vector<float> v;
        v.resize(10, 0.0);
        set.labels.push_back(v);

        if(!labels.eof())
            set.labels.back()[c] = 1.0;
    }
    int shift = 0;
    float value;
    for(i = 0; !images.eof(); i++)
    {
        vector<float> v;
        set.images.push_back(v);

        for(int j = 0; !images.eof() && j < 784;)
        {
            c = images.get();

            if(shift > 15)
            {
                value = (float)((int)(c)/255.0);
                set.images.back().push_back(value);
                j++;
            }
            else
                shift ++;
        }

    }
    images.close();
    labels.close();
}

}
