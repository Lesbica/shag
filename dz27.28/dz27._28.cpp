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
        // Знайти мінімальне значення по модулю
        int min = abs(nom);     // abs - модуль (int), fabs(double) => double.
        if (min > abs(denom))
            min = denom;

 

        // Цикл пошуку НСД => gcd - найбільший спільний дільник
        int i, gcd = 1;

 

        for (i = 2; i <= min; i++)
            if ((nom % i == 0) && (denom % i == 0))
                gcd = i;

 

        nom /= gcd;
        denom /= gcd;
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
        Normal();
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
    
    Fraction& operator+(const Fraction& fraction) {
        nom = nom * fraction.denom + denom * fraction.nom;
        denom = denom * fraction.denom;
        Normal();
        return *this;
    }

    Fraction& operator*(const Fraction &fraction) {
        nom = nom * fraction.nom;
        denom = denom * fraction.denom;   
        Normal();
        return *this;
    }

    Fraction& operator-(const Fraction &fraction) {
        nom = nom * fraction.denom - denom * fraction.nom;
        denom = denom * fraction.denom;
        Normal();
        return *this;
    }

    Fraction& operator/(const Fraction &fraction) {
        nom = nom / fraction.denom;
        denom = denom / fraction.nom;
        Normal();
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

class ArrayFraction
{
private:
    int size;
    Fraction* AF;
public:
    ArrayFraction(Fraction* _AF, int _size)
    {
        AF = _AF;
        size = _size;
    }

    ArrayFraction() : ArrayFraction(0, 0){}

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << AF[i].GetNom() << "/" << AF[i].GetDemon() << endl;
        }
        cout << endl;
    }

    int GetSize()
    {
        return size;
    }

    Fraction* GetPArray()
    {
        return AF;
    }
    
    ArrayFraction(const ArrayFraction &ArrayFraction) : size(ArrayFraction.size), AF(ArrayFraction.AF){}

    ArrayFraction& operator=(const ArrayFraction& ArrayFraction)
    {
        if (ArrayFraction.AF != nullptr && ArrayFraction.size != 0){
            size = ArrayFraction.size;
            AF = new Fraction[size];
            for (int i = 0; i < size; i++)
                AF[i] = ArrayFraction.AF[i];
        }
        else{
            AF = nullptr;
            size = 0;
        }
        return *this;
    }
    
    ArrayFraction(ArrayFraction&& rObj) noexcept
    {
        AF = rObj.AF;
        size = rObj.size;
        rObj.size = 0;
    }

    ArrayFraction& operator=(ArrayFraction&& obj)
    {
        if (obj.AF != nullptr && obj.size != 0){
            size = obj.size;
            AF = new Fraction[size];
            for (int i = 0; i < size; i++)
                AF[i] = obj.AF[i];
        }
        else{
            AF = nullptr;
            size = 0;
        }
        return *this;
    }
    
    friend ArrayFraction operator+(ArrayFraction& A1, ArrayFraction& A2);
    friend ArrayFraction operator-(ArrayFraction& A1, ArrayFraction& A2);

    int CountFraction(Fraction& fr, ArrayFraction& _AF)
    {
        int k = 0;
        for(int i = 0; i < _AF.size; i++)
            if((fr.GetNom() == _AF.AF[i].GetNom()) && (fr.GetDemon() == _AF.AF[i].GetDemon()))
                    k++;
        return k;
    }

    
    
    /*void InsertionSort(Fraction** _AF, int* _size){
        
        double D_ARR_B[size];

        for (int i = 0; i < size; i++){
            D_ARR_B[i] = ((float)(AF[i].GetNom()) / (float)(AF[i].GetDemon()));
        }

        double buff = 0.0;
        Fraction BF;
        int i, j;
        for (i = 0; i < size; i++) {
            buff = D_ARR_B[i];
            BF = AF[i];
            for (j = i - 1; j >= 0 && D_ARR_B[j] > buff; j--) {
                D_ARR_B[j + 1] = D_ARR_B[j];
                AF[j + 1] = AF[j];
            }
            D_ARR_B[j + 1] = buff;
            AF[j + 1] = BF;
        }
        *_AF = new Fraction[size];
        *_size = size;
        for (int i = 0; i < size; i++)
            (*_AF)[i] = AF[i];

    }*/

    void Clone(Fraction** _AF2, int* _size2){
        *_AF2 = new Fraction[size];
        *_size2 = size;
        for (int i = 0; i < size; i++)
            (*_AF2)[i] = AF[i];
    }

    /*void BubbleSort(){
        double A[size];

        for (int i = 0; i < size; i++){
            A[i] = (float)((float)(AF[i].GetNom()) / (float)(AF[i].GetDemon()));
        }

        double buff = 0.0;
        Fraction BF(0, 0);
        
        int i, j;
        for (i = 0; i < size; i ++) {
            for (j = size - 1; j > i; j--) {
                if(A[j - 1] > A[j]){
                    buff = A[j];
                    BF = AF[j];
                    A[j] = A[j - 1];
                    AF[j] = AF[j - 1];
                    A[j - 1] = buff;
                    AF[j - 1] = BF;
                }
            }
        }
    }*/

    void Add(Fraction* AF2, int size2){
        Fraction* AB = new Fraction[size + size2];
        for(int i = 0; i < size; i++)
            AB[i] = AF[i];

    
        for(int i = 0; i < size2; i++){
            AB[i + size] = AF2[i];
        }
        cout << endl;
        
        cout << "AB = > ";
        for(int i = 0; i < size + size2; i++)
            cout << AB[i].GetNom() << '/' << AB[i].GetDemon() << "  ";
        cout << endl;
        
        delete[] AF;
        AF = new Fraction[size + size2];
        
        for(int i = 0; i < size + size2; i++)
            AF[i] = AB[i];
        size += size2;
        
        delete[] AB;
    }
    
    friend ofstream& operator<<(ofstream& stream, ArrayFraction& ARR);
    
    /*~ArrayFraction(){
        delete[] AF;
        size = 0;
    }*/
};
ofstream& operator<<(ofstream& stream, ArrayFraction& ARR){
    stream.open("/Users/alexh/Desktop/array_fraction.txt", ios::out);
    if (!stream.is_open()){
        cout << "Error opening file." << endl;
        return stream;
    }
    stream << "AF => ";
    for(int i = 0; i < ARR.GetSize(); i++)
        stream << ARR.AF[i].GetNom() << '/' << ARR.AF[i].GetDemon() << "  ";
    
    stream.close();
    return stream;
}

ArrayFraction operator+(ArrayFraction& A1, ArrayFraction& A2)
{
    int min = A1.size;
    A1.size > A2.size ? min = A2.size : min = A1.size;

    ArrayFraction AF3(A1.AF, min);
    for (int i = 0; i < min; i++)
    {
        AF3.AF[i] = A1.AF[i] + A2.AF[i];
    }
    return AF3;
}

ArrayFraction operator-(ArrayFraction& A1, ArrayFraction& A2)
{
    int min = A1.size;
    A1.size > A2.size ? min = A2.size : min = A1.size;

    ArrayFraction AF3(A1.AF, min);
    for (int i = 0; i < min; i++)
    {
        AF3.AF[i] = A1.AF[i] - A2.AF[i];
    }
    return AF3;
}

int main()
{
    Fraction A[3] = {{5,6},{2, 3}, {3,4}};
    Fraction B[3] = {{2, 3}, {9,10}, {11,12}};
    Fraction c = {11,12};
    Fraction find = {2,3};
    ArrayFraction AF(A, 3);
    AF.Print();
    cout<<"--------------------------------------------------"<<endl;
    return 0;
}
