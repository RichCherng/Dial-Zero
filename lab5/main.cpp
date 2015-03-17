#include <iostream>
#include "Rational.h"

using namespace std;
int main(int argc, char argv[]) {
   Rational r1;
   const Rational r2(5, 12);

   cout << r2.ToString() << endl;

   r1.SetNumerator(48);
   r1.SetDenominator(36);

   cout << r1.GetNumerator() << endl;
   cout << r1.GetDenominator() << endl;

   cout << r1.Equals(r2) << endl;

   cout << r1.add(r2).ToString() << endl;

   Rational r3(r1);
   cout << "Value of r1 = " << r1 << endl;
   cout << "Value of r2 = " << r2 << endl;
   cout << "Value of r3 = " << r3 << endl; 
   cout << r1 + r3 << endl;
   cout << -r3 << endl;
   cout << r1 - r3 << endl;
   cout << r1 * r2 << endl;
   cout << r1 / r3 << endl;
   cout << (r1 == r2) << endl;
   cout << (r1 != r3) << endl;
   cout << (r1 < r2) << endl;
   cout << (r1 > r2) << endl;
   cout << (r1 <= r3) << endl;
   cout << (r1 >= r2) << endl;

   system("pause");
}