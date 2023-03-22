#include <iostream>
#include <fstream>
using namespace std;

class Fraction
{
    int nom, denom;
public:
    friend ofstream& operator<<(ofstream& out, Fraction& drob);
    friend ifstream& operator>>(ifstream& in, Fraction& drob);
    Fraction(int nominator, int denominator)
    {
        Set( nominator, denominator);
    }
    Fraction() : Fraction(0,0)
    {
    }
    int GetNom()
    {
        return nom;
    }
    int GetDemon()
    {
        return denom;
    }

    void Normal()
    {
        int nod = greatest_common_divisor(nom, denom);
        nom /= nod;
        denom /= nod;
    }
    
    unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
        if (a == b)
            return a;
        if (a > b)
            return greatest_common_divisor(a-b, b);
        return greatest_common_divisor(a, b-a);
    }
    void Set(int nominator, int denominator)
    {
        nom = nominator;
        if (denominator == 0)
        {
            denom = 1;
            return;
        }
        denom = denominator;
    }
    double Value()
    {
        double a, b;
        a =double(nom);
        b = double(denom);
        return a / b;
    }
    void Print()
    {
        cout << nom << "/" << denom << endl;
    }

    // Наибольший общий делитель
    int gcd(int a, int b) {
        while (b > 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    // Наименьшее общее кратное
    int lcm(int a, int b) {
        return gcd(a, b) * a * b;
    }

    void reduce() {
        int gcd1 = gcd(abs(nom), denom);
        if (gcd1 != 1) {
            nom = denom / gcd1;
            denom = denom / gcd1;
        }
    }
    
    Fraction& operator+(const Fraction& fraction) {
        nom = nom * fraction.denom + denom * fraction.nom;
        denom = denom * fraction.denom;
        reduce();
        return *this;
    }

    Fraction& operator*(const Fraction &fraction) {
        nom = nom * fraction.nom;
        denom = denom * fraction.denom;   
        reduce();
        return *this;
    }

    Fraction& operator-(const Fraction &fraction) {
        nom = nom * fraction.denom - denom * fraction.nom;
        denom = denom * fraction.denom;
        reduce();
        return *this;
    }

    Fraction& operator/(const Fraction &fraction) {
        nom = nom * fraction.denom;
        denom = denom * fraction.nom;
        reduce();
        return *this;
    }

    void SaveToFile()
    {
        ofstream out;
        out.open("D:\\Fraction.txt");
        if (out.is_open())
        {
            out << "nom=" << nom << endl;
            out << "denom=" << denom << endl;
        }
    }
};

ofstream& operator<<(ofstream& out, Fraction& drob)
{
    if (out.is_open())
    {
        out << drob.nom << endl;
        out << drob.denom << endl;
    }
    return out;
}

ifstream& operator>>(ifstream& in, Fraction& drob)
{
    if (in.is_open())
    {
        in >> drob.nom;
        in >> drob.denom;
    }
    return in;
}
