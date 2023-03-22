#include <iostream>
using namespace std;

class PDouble
{
private:
    double* p{};
public:
    PDouble(double value)
    {
        p = new double;
        *p = value;
    }

    PDouble() : PDouble(0.0){ }
    
    ~PDouble()
    {
        delete p;
    }

    

    PDouble(const PDouble& obj) //: PDouble(*obj.p)
    {
        p = new double;
        *p = *obj.p;
    }

    void Print()
    {
        cout << "=>" << *p << endl;
    }

    double Get()
    {
       return *p; 
    }

    void Set(double value)
    {
        *p = value;
    }

    PDouble operator=(const PDouble& obj)
    {
        *p = *obj.p;
        return *this;
    }

    PDouble operator+(const PDouble& obj) const
    {
        PDouble obj2(*p + *obj.p);
        return obj2;
    }

    friend PDouble operator-(PDouble obj, PDouble obj2);
    friend PDouble operator*(PDouble obj, PDouble obj2);
    friend PDouble operator+(double obj1, PDouble obj2);
    friend PDouble operator+(PDouble obj1, double value);
};

PDouble operator-(PDouble obj, PDouble obj2)
{
    PDouble obj3(*obj.p - *obj2.p);
    return obj3;
}

PDouble operator*(PDouble obj, PDouble obj2)
{
    return PDouble(*obj.p * *obj2.p);
}

PDouble operator+(double obj1, PDouble obj2)
{
    return PDouble(obj1 + *obj2.p);
}

PDouble operator+(PDouble obj1, double value)
{
    return PDouble(*obj1.p + value);
}

int main()
{
    PDouble x1;
    x1.Set(34.5);
    x1.Print();

    PDouble x2 = x1;
    x2.Print();

    x2 = x1;

    PDouble x3;
    x3.Set(77.8);
    x1 = x3;
    x1.Print();

    x1 = x2 + x3;
    x1.Print();

    PDouble x4;
    x4 = x3 - x1 - x2 + x1 + x1;
    x4.Print();
    
    x4 = x1 * x2;
    x4.Print();

    x4 = 2.8 + x1;
    x4.Print();

    x4 = x3 + 7.9;
    x4.Print();
}
