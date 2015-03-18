#include <string>
#include <sstream>
#include "Rational.h"

using namespace std;
Rational::Rational()
   : mNumerator(0), mDenominator(1) {

}

Rational::Rational(int numerator, int denominator)
   : mNumerator(numerator), mDenominator(denominator) {
   Normalize();
}

Rational::Rational(Rational const &other) 
   :mNumerator(other.mNumerator), mDenominator(other.mDenominator){
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

   mNumerator /= abs(x);
   mDenominator /= abs(x);
}

bool Rational::Equals(const Rational &other) const {
   return (mNumerator == other.mNumerator) 
      && (other.mDenominator == mDenominator);
     
   //mNumerator / mDenominator ==
     // other.mNumerator / other.mDenominator;
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
   if (mDenominator == 0 || mDenominator == 1) {
      ostringstream ss;
      ss << mNumerator;
      return ss.str();
   }
      //return ostringstream (mNumerator).str();
   else {
      ostringstream ss;
      ss << mNumerator << "/"<< mDenominator;
      return ss.str();
      //return to_string(mNumerator) + "/" + to_string(mDenominator);
   }
}

Rational& Rational::operator=(const Rational &rhs) {
   mNumerator = rhs.mNumerator;
   mDenominator = rhs.mDenominator;
   Normalize();
   return *this;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
   Rational newRational(lhs);
   return newRational.add(rhs);
}

Rational operator-(const Rational &rhs) {
   //Rational negRational(-rhs.mNumerator, rhs.mDenominator);
   //return negRational;
   return Rational(-rhs.mNumerator, rhs.mDenominator);
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
   int sumNumerator = (lhs.mNumerator * rhs.mDenominator) 
      - (rhs.mNumerator * lhs.mDenominator);
   int sumDenominator = lhs.mDenominator * rhs.mDenominator;
   return Rational (sumNumerator, sumDenominator);
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
   return Rational(lhs.mNumerator * rhs.mNumerator,
      lhs.mDenominator * rhs.mDenominator);
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
   return Rational(lhs.mNumerator * rhs.mDenominator,
      lhs.mDenominator * rhs.mNumerator);
}

bool operator==(const Rational &lhs, const Rational &rhs) {
   return lhs.Equals(rhs);
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
   return !(lhs == rhs);   
}

ostream& operator<<(ostream &lhs, const Rational &rhs) {
   return lhs << rhs.ToString();;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
   return (lhs - rhs).mNumerator < 0;
}

bool operator>(const Rational &lhs, const Rational &rhs) {
   return (lhs - rhs).mNumerator > 0;
}

bool operator<=(const Rational &lhs, const Rational &rhs) {
   return ((lhs - rhs).mNumerator < 0) || (lhs.Equals(rhs));
}

bool operator>=(const Rational &lhs, const Rational &rhs) {
   return (lhs - rhs).mNumerator < 0 || (lhs.Equals(rhs));
}

