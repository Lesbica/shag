#include <iostream>
#include <list>
#include <algorithm> // потрібна для функції sort

using namespace std;

int main() {
    srand(time(NULL));
    // Створюємо список L з 10 випадкових чисел в діапазоні [10;20]
    list<int> L;
    for (int i = 0; i < 10; i++) {
        L.push_back(rand() % 11 + 10); // генеруємо випадкове число з діапазону [10;20] і додаємо його в кінець списку
    }

    // Виводимо список L на екран
    cout << "List L before sorting:" << endl;
    for (int num : L) {
        cout << num << " ";
    }
    cout << endl;

    // Сортуємо список L за допомогою алгоритму sort
    L.sort();

    // Виводимо відсортований список L на екран
    cout << "List L after sorting:" << endl;
    for (int num : L) {
        cout << num << " ";
    }
    cout << endl;

    // Створюємо список L2 з 5 випадкових чисел в діапазоні [30;35]
    list<int> L2;
    for (int i = 0; i < 5; i++) {
        L2.push_back(rand() % 6 + 30); // генеруємо випадкове число з діапазону [30;35] і додаємо його в кінець списку
    }

    L2.sort();
    // Додаємо список L2 до списку L за допомогою функції merge
    L.merge(L2);

    // Виводимо список L після додавання списку L2 на екран
    cout << "List L after merging with list L2:" << endl;
    for (int num : L) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
