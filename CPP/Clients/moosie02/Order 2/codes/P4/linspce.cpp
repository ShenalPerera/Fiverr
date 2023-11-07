#include "linspace.h"
#include <vector>

using namespace std;

vector<double> linspace(double start, double end, int sample_count){
    // create a vector of length num
    vector<double> samples;
    double tmp = 0.0;

    //int lala = num;

    // now assign the values to the vector
    for (int i = 0; i < sample_count; i++)
    {

        samples.push_back(start + i * ((end - start) / (double) sample_count));
    }
    return samples;
}
