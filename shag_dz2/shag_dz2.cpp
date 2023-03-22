#include <iostream>
using namespace std;
int countr = 0;
class Subscribe
{
private:
    string name;
    string number;
    int year;
public:
    Subscribe()
    {
        name = nullptr;
        number = nullptr;
        year = 2000;
        countr++;
    }

    Subscribe(string name, string number, int year)
    {
        this->year = year;
        this->name  = name;
        this->number = number;
        countr++;
    }

    string GetName()
    {
        return name;
    }

    string GetNumber()
    {
        return number;
    }

    int GetYear()
    {
        return year;
    }
    
    void SetName(string name)
    {
        this->name = name;
    }

    void SetNumber(string number)
    {
        this->number = number;
    }

    void SetYear(int year)
    {
        this->year = year;
    }

    void Print()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Number: " << this->number << endl;
        cout << "Year: " << this->year << endl;
        cout << "-----------------------------------------" << endl;
    }

    int CountObjects()
    {
        return countr;
    }

    ~Subscribe(){ }
};

int main()
{
    Subscribe subscribe1("Geniy Ivanovich", "+38095223584", 2004);
    subscribe1.Print();
    Subscribe subscribe2("Valentin Ivanovich", "+380951030166", 2005);
    subscribe2.Print();

    subscribe1.SetName("Pupkin Ivan");
    subscribe1.Print();

    Subscribe subscribe3("Valera Ivanovich", "+380951030166", 2005);
    subscribe3.Print();

    cout << subscribe1.CountObjects();
}
