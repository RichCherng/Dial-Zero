#include <iostream>
#include <string>

class Rational {
   int mNumerator;
   int mDenominator;

   void Normalize();

public:
   Rational();

   Rational(int numerator, int denominator);

   Rational(const Rational &other);

   int GetNumerator() const;
   int GetDenominator() const;

   void SetNumerator(int newNum);
   void SetDenominator(int newDenom);

   bool Equals(const Rational &other) const;

   Rational add(const Rational &other) const;

   std::string ToString() const;

   Rational& operator=(const Rational &rhs);
 
   friend std::ostream& operator<<(std::ostream &lhs, const Rational &rhs);
   friend Rational operator+(const Rational &lhs, const Rational &rhs); 
   friend Rational operator-(const Rational &other); //Unary operator ie. -r1
   friend Rational operator-(const Rational &lhs, const Rational &rhs); //Binary operator r1 - r2s
   friend Rational operator*(const Rational &lhs, const Rational &rhs);
   friend Rational operator/(const Rational &lhs, const Rational &rhs);
   friend bool operator==(const Rational &lhs, const Rational &rhs);
   friend bool operator!=(const Rational &lhs, const Rational &rhs);
   friend bool operator<(const Rational &lhs, const Rational &rhs);
   friend bool operator>(const Rational &lhs, const Rational &rhs);
   friend bool operator<=(const Rational &lhs, const Rational &rhs);
   friend bool operator>=(const Rational &lhs, const Rational &rhs);
};