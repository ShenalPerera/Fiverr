#include <iostream>

#include "Point.h"

int main(){

    int number_of_points;

    cout << "Enter the number of points : ";
    cin >> number_of_points;

    // Create the array for the number of points
    Point * points_array = new Point[number_of_points];

    // get x and y values from the users
    for (int i = 0; i < number_of_points ; ++i) {
        double x_val;
        double y_val;

        // Print the which points get current input
        cout << "Point " << i+1 << endl;

        //get the x value
        cout << "Enter the x-coordinate : " ;
        cin >> x_val;
        points_array[i].set_x(x_val);

        // get the y value
        cout << "Enter the y-coordinate : ";
        cin >> y_val;
        points_array[i].set_y(y_val);

        cout << endl;
    }


    // Option 1

    double total_dist = 0.0;

    for (int i = 0; i < number_of_points-1; ++i) {
        double current_length = points_array[i].dist_from(points_array[i+1]);
        cout << "Distance from point " << i+1 << " to point " << i +2 << " = " << current_length << endl;
        total_dist += current_length;
    }

    cout << "Total path distance = " << total_dist << endl;


    // free the memory
    delete[] points_array;
    points_array = nullptr;

    return EXIT_SUCCESS;
}