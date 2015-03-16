#include <string>
#include "Rational.h"

using namespace std;
Rational::Rational()
   : mNumerator(0), mDenominator(1) {

}

Rational::Rational(int numerator, int denominator)
   : mNumerator(numerator), mDenominator(denominator) {
   Normalize();
}

void Rational::Normalize() {
   if (mDenominator < 0) {
      mNumerator *= -1;
      mDenominator *= -1;
   }
   if (mDenominator == 0)
      mDenominator = 1;
   int x = mNumerator, y = mDenominator, t;
   while (y != 0) {
      t = y;
      y = x % y;
      x = t;
   }

   mNumerator /= x;
   mDenominator /= x;
}

bool Rational::Equals(const Rational &other) const {
   return mNumerator / mDenominator ==
      other.mNumerator / other.mDenominator;
}

void Rational::SetNumerator(int newNum) {
   mNumerator = newNum;
   Normalize();
}

void Rational::SetDenominator(int newDenom) {
   mDenominator = newDenom;
   Normalize();
}

int Rational::GetNumerator() const {
   return mNumerator;
}

int Rational::GetDenominator() const {
   return mDenominator;
}

Rational Rational::add(const Rational &other) const {
   int sumNumerator = (mNumerator * other.mDenominator) + (other.mNumerator * mDenominator);
   int sumDenominator = mDenominator * other.mDenominator;
   Rational sum(sumNumerator, sumDenominator);
   return sum;
}

string Rational::ToString() const {
   if (mDenominator == 0 || mDenominator == 1)
      return to_string(mNumerator);
   else {
      return to_string(mNumerator) + "/" + to_string(mDenominator);
   }
}

