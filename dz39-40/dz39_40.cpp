#include <iostream>
#include <type_traits>

template<typename T>
class ArrayNumbers {
private:
    T* A;
    int count;
public:
    ArrayNumbers(T* _A, int _count) : count(_count) {
        static_assert(!std::is_same<T, std::string>::value && !std::is_same<T, char>::value && !std::is_same<T, bool>::value,
                      "ArrayNumbers<T> is not allowed for string, char, or bool");
        A = new T[count];
        for (int i = 0; i < count; i++) {
            A[i] = _A[i];
        }
    }
    
    ~ArrayNumbers() {
        delete[] A;
    }

    // Конструктор копіювання
    ArrayNumbers(const ArrayNumbers& other) {
        count = other.count;
        A = new T[count];
        for (int i = 0; i < count; i++) {
            A[i] = other.A[i];
        }
    }

    // Оператор копіювання
    ArrayNumbers& operator=(const ArrayNumbers& other) {
        if (this != &other) {
            delete[] A;
            count = other.count;
            A = new T[count];
            for (int i = 0; i < count; i++) {
                A[i] = other.A[i];
            }
        }
        return *this;
    }

    // Метод для виведення елементів масиву
    void printArray() {
        for (int i = 0; i < count; i++) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    // Метод для виведення типу T
    void ShowType() {
        std::cout << "Type of A is " << typeid(T).name() << std::endl;
    }

    // Рекурсивна функція для порівняння масивів A
    bool Compare(ArrayNumbers<T>& obj, int i = 0) {
        if (i == count) {
            return true;
        }
        if (A[i] != obj.A[i]) {
            return false;
        }
        return Compare(obj, i + 1);
    }
};

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int a2[5] = {1, 2, 5, 4, 5};

    ArrayNumbers<int> ar(a, 5);
    ArrayNumbers<int> ar2(a2, 5);

    ar.printArray();

    ar.ShowType();
    std::cout << ar.Compare(ar2);
    return 0;
}