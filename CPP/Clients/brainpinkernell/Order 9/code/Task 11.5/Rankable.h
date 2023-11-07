/*----
  header file for class: Rankable

    a pure abstract class

  by: Colton Boyd
  last modified: 2022-12-02
----*/

#ifndef Rankable_H
#define Rankable_H

#include <string>
using namespace std;
class Rankable
{
    public:

        virtual ~Rankable(){};
        virtual  double  compute_rank() = 0;

};

#endif