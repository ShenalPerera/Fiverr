/*----
  header file for class: Point

  a Point represents a point in a 2-dimensional
      coordinate space

  by: Sharon Tuttle
  last modified: 2022-10-13
----*/

#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

class Point
{
    public:
        // constructors

        Point();
        Point(double init_x, double init_y);

        // accessors

        double get_x() const;
        double get_y() const;

        // modifiers

        void set_x(double new_x);
        void set_y(double new_y);

        // "other" methods

        /*---
            signature: display: void -> void
            purpose: expects nothing, has the side-
                effect of printing to the screen
                a tasteful display of the calling
                point, and returns nothing
        ---*/

        void display() const;

        /*---
            signature: to_string: void -> string
            purpose: expects nothing, and returns
                a string version of the
                calling point
        ---*/

        string to_string() const;

        /*---
            signature: dist_from: Point -> double
            purpose: expects a Point, and returns
                the distance from the calling Point
                to the given Point
        ---*/

        double dist_from(Point a_point) const;

    private:
        // data fields

        double x;
        double y;
};

#endif