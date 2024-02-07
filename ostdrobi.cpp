#include <iostream>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction operator+(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int) {
        Fraction result = *this;
        numerator += denominator;
        simplify();
        return result;
    }

    Fraction& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    Fraction operator--(int) {
        Fraction result = *this;
        numerator -= denominator;
        simplify();
        return result;
    }

    void simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main() {
    int numerator1, denominator1, numerator2, denominator2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> numerator1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denominator1;
    Fraction fraction1(numerator1, denominator1);

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> numerator2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denominator2;
    Fraction fraction2(numerator2, denominator2);

    Fraction addition = fraction1 + fraction2;
    Fraction subtraction = fraction1 - fraction2;
    Fraction multiplication = fraction1 * fraction2;
    Fraction division = fraction1 / fraction2;

    std::cout << fraction1 << " + " << fraction2 << " = " << addition << std::endl;
    std::cout << fraction1 << " - " << fraction2 << " = " << subtraction << std::endl;
    std::cout << fraction1 << " * " << fraction2 << " = " << multiplication << std::endl;
    std::cout << fraction1 << " / " << fraction2 << " = " << division << std::endl;

    Fraction result = ++fraction1 * fraction2;
    std::cout << "++" << fraction1 << " * " << fraction2 << " = " << result << std::endl;
    std::cout << "Значение дроби 1 = " << fraction1 << std::endl;

    result = fraction1-- * fraction2;
    std::cout << fraction1 << "-- * " << fraction2 << " = " << result << std::endl;
      std::cout << "Значение дроби 1 = " << fraction1 << std::endl;

      return 0;
  }