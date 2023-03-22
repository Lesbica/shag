#include <iostream>

class Recursion {
public:
    static int Count(float* A, int size) {
        if (size == 0) {
            return 0;
        }
        else if (A[size - 1] > 0) {
            return 1 + Count(A, size - 1);
        }
        else {
            return Count(A, size - 1);
        }
    }

    static double Summ(double* A, int size) {
        if (size <= 0) {
            return 0;
        }
        else if (size % 2 == 0) {
            return A[size - 1] + Summ(A, size - 2);
        }
        else {
            return Summ(A, size - 1);
        }
    }
};

int main()
{
    float arr1[] = {1, -2, 3, -4, 5, -6, 7, -8};
    int count1 = Recursion::Count(arr1, 8); // count1 = 4
    std::cout << count1 << std::endl;

    double arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    double sum1 = Recursion::Summ(arr2, 8); // sum1 = 20
    std::cout << sum1 << std::endl;
    
    double arr3[] = {1, 2, 3, 4, 5, 6, 7};
    double sum2 = Recursion::Summ(arr3, 7); // sum2 = 12
    std::cout << sum2 << std::endl;
    return 0;
}