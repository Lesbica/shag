#include <iostream>
#include <cmath>

template<typename T1, typename T2, typename T3>
class MathOperations {
public:
    static double Avg_2_Types(T1 a, T2 b, T3 c) {
        return (static_cast<double>(a) + static_cast<double>(b) + static_cast<double>(c)) / 3.0;
    }

    static double GeometricMean_3_Types(T1 a, T2 b, T3 c) {
        return std::pow(static_cast<double>(a * b * c), 1.0/3.0);
    }
};

int main() {
    int a = 10;
    float b = 5.5f;
    double c = 2.7;

    double avg = MathOperations<int, float, double>::Avg_2_Types(a, b, c);
    double geomMean = MathOperations<int, float, double>::GeometricMean_3_Types(a, b, c);

    std::cout << "Average: " << avg << std::endl;
    std::cout << "Geometric Mean: " << geomMean << std::endl;

    return 0;
}