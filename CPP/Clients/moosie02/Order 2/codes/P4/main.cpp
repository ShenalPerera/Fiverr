#include <iostream>
#include <fstream>
#include <cmath>

#include "linspace.h"
#include "sum_of_squares.h"
#include "get_square_error.h"

using namespace std;

int main(){
    ofstream fout_cos("cosine.txt");
    ofstream fout_sin("sine.txt");
    ofstream  fout_results("results.txt");


    if (fout_cos.fail() || fout_sin.fail() || fout_results.fail()){
        cerr << "Files cannot be opened" << endl;
        exit(1);
    }

    int sample_count;
    cout << "Enter the number of samples (minimum 50) : " ;
    cin >> sample_count;

    if (sample_count < 50) {
        cerr << "Invalid number of samples" << endl;
        exit(1);
    }

    vector<double> temp = linspace(0,2 * M_PI,sample_count);

    for (int i = 0; i < sample_count; ++i) {
        fout_sin << temp.at(i) << "\t" << sin(temp.at(i)) << endl;
        fout_cos << temp.at(i) << "\t" << cos(temp.at(i)) << endl;
    }

    fout_cos.close();
    fout_sin.close();


    ifstream fin_sin("sine.txt");
    ifstream fin_cos("cosine.txt");

    if (fin_sin.fail() || fin_cos.fail()){
        cerr << "File cannot be read" << endl;
        exit(1);
    }

    double angle1,angle2;
    double sin_value;
    double cos_value;
    double sum_of_square_error = 0.0;
    double square_sum;
    int count = 0;


    while (!fin_cos.eof() && !fin_sin.eof()){
        fin_sin >> angle1 >> sin_value;
        fin_cos >> angle2 >> cos_value;

        if (angle1 == angle2){
            square_sum = sum_of_squares(sin_value,cos_value);
            fout_results  << angle1 << "\t" << square_sum << endl;
            sum_of_square_error += get_square_error(1, square_sum);
            count++;
        }
    }

    cout << "root mean square error : " << sqrt(sum_of_square_error)/count << endl;

    fin_cos.close();
    fin_sin.close();
    fout_results.close();


    return 0;
}