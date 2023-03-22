#include <iostream>
using namespace std;

class Array
{
private:
    int countr;
    int *A;
public:
    Array(int countr, int value)
    {
        this->countr = countr;
        A = new int[this->countr];
        for (int i = 0; i < this->countr; i++)
        {
            A[i] = value;
        }
    }

    Array()
    {
        A = new int[0];
    }

    Array(int countr) : Array(countr, 0) {}

    int getN() {return countr;}

    void setN(int countr)
    {
        delete this->A;
        this->countr = countr;
        A = new int[this->countr];
        for (int i = 0; i < countr; i++)
        {
            A[i] = 0;
        }
    }

    int getAi(int index)
    {
        if(index >= countr || index < 0)
        {
            return 0;
        }
        return A[index];
    }

    int setAi(int index, int value)
    {
        if(index >= countr || index < 0)
        {
            return 0;
        }
        A[index] = value;
    }

    int Average()
    {
        int sum = 0;
        for (int i = 0; i < countr; i++)
        {
            sum += A[i];
        }

        return sum / countr;
    }

    int *Clone()
    {
        int *B = new int[countr];
        for (int i = 0; i < countr; i++)
        {
            B[i] = A[i];
        }
        
        return B;
    }

    int *getArray()
    {
        return A;
    }

    void setArray(int countr, int *newArray)
    {
        delete this->A;
        this->countr = countr;
        A = new int[countr];
        for (int i = 0; i < countr; i++)
        {
            A[i] = newArray[i];
        }

    }

    void Print()
    {
        for (int i = 0; i < countr; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    ~Array() { delete A; }
};

int main()
{
    Array a1(3);
    a1.setN(5);
    a1.setAi(4, 10);
    cout << a1.getAi(4) << endl;
    a1.Print();
    cout << a1.Average() << endl;
    int *c = a1.Clone();
    for (int i = 0; i < 5; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    delete []c;
    c = a1.getArray();
    for (int i = 0; i < 5; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    int *a2 = new int[6];
    for (int i = 0; i < 6; i++)
    {
        a2[i] = i+1;
    }
    a1.setArray(6, a2);
    delete a2;
    a1.Print();
}