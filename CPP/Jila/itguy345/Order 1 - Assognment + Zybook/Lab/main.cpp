#include <iostream>
#include <iomanip>               //For setprecision
using namespace std;

int main() {
   double milesPerGallon =0.0;
   double dollarsPerGallon = 0.0;
   
   double price20;
   double price75;
   double price500;
   
   /* Type your code here. */
   cin >> milesPerGallon;
   cin >> dollarsPerGallon;
   
   price20  = ( 20 / milesPerGallon ) * dollarsPerGallon ;
   price75  = ( 75 / milesPerGallon ) * dollarsPerGallon ;
   price500 = ( 500 / milesPerGallon ) * dollarsPerGallon ;
   
   cout << fixed << setprecision(2) << price20 <<" " <<price75<< " " << price500;
   

   return 0;
}
