#include <iostream>
#include <fstream>
#include <string>

#include "calculate_area.hpp"
#include "is_square.hpp"

using namespace std;

int main(){

    // create an object of the fstream with given file name
    ifstream fin("data2.dat");

    // Check the status of the file
    if (fin.fail()){

        cerr << "Error opening input file!" << endl;
        exit(1);
    }

    // Define the output stream with the file name
    ofstream fout("data2report.dat");

    // check the status of the file
    if (fout.fail()){

        cerr << "Error opening output file!" << endl;
        exit(1);
    }

    // Hold the min and max values for the area
    double min;
    double max;

    // Hold the width and height of each line
    double width;
    double height;

    // Hold the current area of each line
    double currArea;

    // Hold the corresponding heights and widths of the minimum and maximum ares's
    double maxWidth;
    double maxHeight;

    double minWidth;
    double minHeight;

    double sumRectangle = 0.0;
    double sumSquare = 0.0;
    int rectCount = 0;
    int squareCount = 0;

    int line = 0;
    while (true){
        fin >> width >> height;
        // Terminate the loop
        if (width == -1 && height == -1){
            break;
        }

        // Skip the error lines
        if (width <0 || height < 0){
            continue;
        }

        //Calculate each line's area of the rectangle
        currArea = calculate_area(width,height);

        if (is_square(width,height)){
            sumSquare = sumSquare + currArea;
            squareCount++;
        }
        else{
            sumRectangle = sumRectangle + currArea;
            rectCount++;
        }

        // If the first line read assign the min and max value to same as the first line
        if (line == 0){
            min = currArea;
            max = currArea;

            maxHeight = height;
            maxWidth = width;

            minHeight = height;
            minWidth = width;

            line++;
            continue;
        }

        // For other lines if the min value is greater than current value change the min
        if (min > currArea){
            min = currArea;

            minHeight = height;
            minWidth = width;
        }

        // if the max value is smaller than the current area chage that max to current vlue
        if (max < currArea){
            max = currArea;

            maxHeight = height;
            maxWidth = width;
        }

        line++;
    }


    //Write the data
    fout << "Maximum Area               : " << max << " | width : " << maxWidth << "| height : " << maxHeight << endl;
    fout << "Minimum Area               : " << min << " | width : " << minWidth << "| height : " << minHeight << endl;
    fout << "Average area of rectangles : " << sumRectangle/rectCount << endl;
    fout << "Average area of squares    : " << sumSquare/squareCount << endl;

    // Close the files
    fin.close();
    fout.close();

    return 0;
}