#include <cmath>
#include <iostream>

class Area {
public:
    static double Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        double a = std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        double b = std::sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
        double c = std::sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
        double p = (a + b + c) / 2;
        triangleCount++;
        return std::sqrt(p * (p-a) * (p-b) * (p-c));
    }

    static double Rectangle(double x1, double y1, double x2, double y2) {
        double width = std::abs(x2 - x1);
        double height = std::abs(y2 - y1);
        rectangleCount++;
        return width * height;
    }

    static int CountTriangle() {
        return triangleCount;
    }

    static int CountRectangle() {
        return rectangleCount;
    }

private:
    static int triangleCount;
    static int rectangleCount;
};

int Area::triangleCount = 0;
int Area::rectangleCount = 0;

int main() {
    double triangleArea = Area::Triangle(0, 0, 3, 0, 0, 4);
    std::cout << "Triangle area: " << triangleArea << std::endl;

    double rectangleArea = Area::Rectangle(0, 0, 3, 4);
    std::cout << "Rectangle area: " << rectangleArea << std::endl;

    int triangleCount = Area::CountTriangle();
    std::cout << "Triangle count: " << triangleCount << std::endl;

    int rectangleCount = Area::CountRectangle();
    std::cout << "Rectangle count: " << rectangleCount << std::endl;

    return 0;
}