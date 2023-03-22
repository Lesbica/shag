#include "Fraction.h"
using namespace std;

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
    
    ~ArrayFraction(){
        delete[] AF;
        size = 0;
    }
};

int main()
{
    Fraction A[3] = {{2, 3}, {3,4}, {5,6}};
    Fraction B[3] = {{7, 8}, {9,10}, {11,12}};
    ArrayFraction AF(A, 3);
    AF.Print();
    ArrayFraction BF(B, 3);
    BF.Print();
    cout << AF.GetPArray() << endl;
    cout << AF.GetSize() << endl;
    BF = AF;
    BF.Print();
    return 0;
}
