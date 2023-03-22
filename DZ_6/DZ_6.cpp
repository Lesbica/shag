#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
    T *value;
    int size;
    T znach;
public:
    Array(int size, T znach)
    {
        this->size = size;
        this->znach = znach;
        value = new T[size];
        for (int i = 0; i < size; i++)
        {
            value[i] = znach;
        } 
    }

    Array() : Array(0, 0){}

    int GetSize()
    {
        return size;
    }

    void SetSize(int _size)
    {
        delete []value;
        Array(_size, znach);
    }

    bool IsEmpty()
    {
        if (size == 0)
        {
            return 1;
        }
        return 0;
    }

    void RemoveAll()
    {
        for (int i = 0; i < size; i++)
        {
            delete value[i];
        }
        delete value;
    }

    T GetAt(int index)
    {
        if (IsEmpty())
        {
            return 0;
        }
        for (int i = 0; i < size; i++)
        {
            if (index == i)
            {
                return value[i];
            }
        }
    }

    void GetAt(int index, T at)
    {
        if (IsEmpty())
        {
            return 0;
        }
        for (int i = 0; i < size; i++)
        {
            if (index == i)
            {
                value[i] = at;
            }
        }
    }

    void Add(T at)
    {
        value = new T[size+1];
        value[size+1] = at;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << value[i] << " ";
        }
    }

    ~Array(){delete value;}
};

int main()
{
    Array<int> c(3, 2);
    c.Add(3);
    c.Print();
    return 0;
}
