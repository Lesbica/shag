#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    double price;
    int year;
public:
    Book()
    {
        title = "0";
        price = 0;
        year = 0;
    }

    Book(string _title, double _price, int _year)
    {
        title = _title;
        price = _price;
        year = _year;
    }

    Book(const Book &book) : title(book.title), price(book.price), year(book.year){}
    

    Book& operator= (const Book &book)
    {
        title = book.title;
        price = book.price;
        year = book.year;
        
        return *this;
    }

    ~Book()
    {
    }

    void SetTitle(string _title)
    {
        title = _title;
    }

    string GetTitle(){return title;}

    void SetPrice(double _price){price = _price;}

    double GetPrice(){return price;}

    void SetYear(int _year){year = _year;}

    int GetYear(){return year;}

    void SetBook(Book book)
    {
        title = book.title;
        price = book.price;
        year = book.year;
    }

    Book *Clone1()
    {
        Book* b;
        b->price = price;
        b->title = title;
        b->year = year;
        return b;
    }

    Book &Clone2()
    {
        Book b;
        b.price = price;
        b.title = title;
        b.year = year;
        return b;
    }

    bool EqualPrice(Book& book){return book.price == price;}

    void Print()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    Book book1;
    Book book2("story", 19.20, 2000);
    Book book3("book2", 18.20, 2005);
    book1.Print();
    book2.Print();
    book3.Print();
    cout << book2.EqualPrice(book3) << endl;
    
    return 0;
}
