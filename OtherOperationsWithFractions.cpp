#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int den = denominator_ * other.denominator_;
   
        int divisor = gcd(num, den);

        int new_num = num / divisor;
        int new_den = den / divisor;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int den = denominator_ * other.denominator_;

        int divisor = gcd(num, den);
        int new_num = num / divisor;
        int new_den = den / divisor;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator_ * other.numerator_;
        int den = denominator_ * other.denominator_;

        int divisor = gcd(num, den);
        int new_num = num / divisor;
        int new_den = den / divisor;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator_ * other.denominator_;
        int den = denominator_ * other.numerator_;

        int divisor = gcd(num, den);
        int new_num = num / divisor;
        int new_den = den / divisor;
        return Fraction(new_num, new_den);
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction operator++() {
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction old = *this;
        ++(*this);
        return old;
    }

    Fraction operator--() {
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int) {
        Fraction old = *this;
        --(*this);
        return old;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator_ << "/" << f.denominator_;
        return out;
    }
};
bool set_num(int n) { if (n == 0) return false; else return true; }

int main() {

    setlocale(LC_ALL, "Russian");

    int num1, den1, num2, den2;

    do {
        cout << "Введите числитель дроби 1: ";
        cin >> num1;
        if (!set_num(num1)) cout << "Для облегчения решения мы не будем использовать числитель ноль, ведь тогда дробь будет равна 0, " << endl <<
            "прошу ввести другое число" << endl;
      
    } while (!set_num(num1));
        do {
            cout << "Введите знаменатель дроби 1: ";
            cin >> den1;
            if (!set_num(den1)) cout << "Знаменатель не может быть равен 0" << endl;
        } while (!set_num(den1));
        do{
                cout << "Введите числитель дроби 2: ";
                cin >> num2;
                if (!set_num(num2)) cout << "Для облегчения решения мы не будем использовать числитель ноль, ведь тогда дробь будет равна 0, " << endl <<
                    "прошу ввести другое число" << endl;

        } while (!set_num(num2));
        do {
            cout << "Введите знаменатель дроби 2: ";
            cin >> den2;
            if (!set_num(den2)) cout << "Знаменатель не может быть равен 0" << endl;
        } while (!set_num(den2));


    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;

    cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << endl;
    cout << "Значение дроби 1 = " << f1 << endl;
    cout << f1 << "--" << " * " << f2 << " = " << (f1-- * f2) << endl;
    cout << "Значение дроби 1 = " << f1 << endl;

}
