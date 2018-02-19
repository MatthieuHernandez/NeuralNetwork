#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;

namespace Data
{
    struct Set
    {
        int size;
        vector<vector<float>> images;
        vector<vector<float>> labels;
    };

    struct MNIST_struct
    {
       int sizeOfImages;
       int numberOfLabel;
       Set testing;
       Set trainig;
    };

    MNIST_struct create_MNIST();
    MNIST_struct Initialize_MNIST();
    void readImages(MNIST_struct &MNIST);
    void readSet(Set &set, ifstream &images, ifstream &labels);

    template <typename T>
    string to_string_with_precision(const T value, const int n = 3)
    {
        ostringstream out;
        out << fixed << std::setprecision(n) << value;
        return out.str();
    }
}

#endif // DATA_H
