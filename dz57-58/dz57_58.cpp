#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Student {
private:
    string name;   // ім'я та прізвище студента
    int course;    // курс навчання
    double rating; // рейтинг студента (від 1 до 5)
public:
    // конструктор з 3 параметрами
    Student(string n, int c, double r) {
        name = n;
        course = c;
        rating = r;
    }
    
    // методи доступу до полів класу
    string GetName() { return name; }
    void SetName(string n) { name = n; }
    int GetCourse() { return course; }
    void SetCourse(int c) { course = c; }
    double GetRating() { return rating; }
    void SetRating(double r) { rating = r; }
};

class ListStudent
{
private:
    list<Student> AS; // масив студентів типу list<Student>
public:
    // конструктор без параметрів
    ListStudent() {}

    // перевантажений метод Add для додавання нового студента
    void Add(const Student& s) {
        AS.push_back(s);
    }

    // перевантажений метод Add для додавання нового студента з параметрами
    void Add(string n, int c, double r) {
        Student s(n, c, r);
        AS.push_back(s);
    }

    // метод для виведення списку студентів на екран
    void Print() {
        for (auto& s : AS) {
            cout << "Name: " << s.GetName() << ", Course: " << s.GetCourse() << ", Rating: " << s.GetRating() << endl;
        }
    }

    // метод для формування масиву з прізвищами студентів заданого курсу
    vector<string> GetStudentsByCourse(int course) {
        vector<string> result;
        for (auto& s : AS) {
            if (s.GetCourse() == course) {
                result.push_back(s.GetName());
            }
        }
        return result;
    }

    // метод, що повертає true, якщо є студент з заданим прізвищем
    bool IsName(string name) {
        for (auto& s : AS) {
            if (s.GetName() == name) {
                return true;
            }
        }
        return false;
    }

    // метод, що повертає список прізвищ студентів з рейтингом у заданих межах
    list<string> GetStudentsByRankingRange(double min, double max) {
        list<string> result;
        for (auto& s : AS) {
            if (s.GetRating() >= min && s.GetRating() <= max) {
                result.push_back(s.GetName());
            }
        }
        return result;
    }

    // метод для видалення студента (студентів) з заданим ім'ям
    void DeleteByName(string name) {
        for (auto it = AS.begin(); it != AS.end(); ) {
            if (it->GetName() == name) {
                it = AS.erase(it);
            } else {
                ++it;
            }
        }
    }

    // метод, який визначає кількість студентів, які навчаються на заданому курсі
    int CountStudentsByCourse(int course) {
        return count_if(AS.begin(), AS.end(), [course](auto& s) { return s.GetCourse() == course; });
    }

    // метод, який визначає кількість студентів, які мають рейтинг не нижче значення minRating
    int CountStudentsByRating(double minRating)
    {
        return count_if(AS.begin(), AS.end(), [minRating](auto& s) { return s.GetRating() >= minRating; });
    }

};

int main() {
    // створення списку студентів
    ListStudent list;

    // додавання студентів
    list.Add("John Smith", 2, 4.5);
    list.Add("Jane Doe", 1, 3.7);

    // виведення списку студентів на екран
    list.Print();
    cout << list.CountStudentsByRating(4.5) << endl;
    cout << list.CountStudentsByCourse(1) << endl;

    list.DeleteByName("Jane Doe");
    list.Print();
    return 0;
}