#include <iostream>
#include <string>
using namespace std;

class Number {
protected:
    string typeName;
    int size;
public:
    virtual string GetTypeName() = 0;
    virtual int GetSize() = 0;
};

class IntNumber : public Number {
protected:
    int value;
public:
    IntNumber(int val) {
        typeName = "int";
        size = sizeof(int);
        value = val;
    }
    string GetTypeName() override {
        return typeName;
    }
    int GetSize() override {
        return size;
    }
    int GetValue() {
        return value;
    }
    void SetValue(int val) {
        value = val;
    }
    void Print() {
        cout << "Type: " << typeName << endl;
        cout << "Size: " << size << endl;
        cout << "Value: " << value << endl;
    }
};

class IntNumberRange : public IntNumber {
protected:
    int minValue;
    int maxValue;
public:
    IntNumberRange(int _value, int _minValue, int _maxValue) : IntNumber(_value) {
        minValue = _minValue;
        maxValue = _maxValue;
        if (value < minValue) {
            value = minValue;
        }
        else if (value > maxValue) {
            value = maxValue;
        }
    }
    void Print() {
        cout << "Value: " << value << endl;
        cout << "Type: " << typeName << endl;
        cout << "Size: " << size << endl;
        cout << "Min value: " << minValue << endl;
        cout << "Max value: " << maxValue << endl;
    }
};


int main() {
    IntNumber num(42);
    num.Print();
    num.SetValue(123);
    num.Print();
    IntNumberRange ar(123, 14, 500);
    ar.Print();
    return 0;
}