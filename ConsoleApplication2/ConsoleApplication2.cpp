#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Mult2(int& value)
{
    value = value * 2;
}

template<class T>
void ShowVector(const vector<T>& V, string msg)
{
    cout << msg << ": ";
    for (T item : V)
        cout << item << "  ";
}

void main()
{
    // Оголосити массив
    vector<int> V = { 4, 9, 8, 2, 10,11,7 };

    // Вызов алгоритма for_each
    for_each(V.begin(), V.end(), Mult2);
}
