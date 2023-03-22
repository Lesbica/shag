#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

class RecordBook
{
private:
    // Клас PhoneNumber, який описує телефонний номер
    class PhoneNumber {
    private:
        // Enum, що описує значення спеціальних символів, які можуть бути включені в номер телефону
        enum PhoneChars {
            Plus = '+',
            Minus = '-',
            OpenBracket = '(',
            CloseBracket = ')'
        };
        
        std::string number;  // телефонний номер

        public:
        // Конструктор
        PhoneNumber(std::string _number) throw(std::exception)
        {
            SetNumber(_number);
        }

        // Методи доступу
        std::string GetNumber() const {return number;}
        
        void SetNumber(std::string _number) throw(std::exception)
        {
            if (_number.empty() || _number.size() > 16)
                throw std::exception("Incorrect number");

            if (_number[0] == Plus) {
                if (_number.find(Plus, 1) != std::string::npos)
                    throw std::exception("Incorrect number");

                if (_number.find_first_not_of("0123456789-()+", 1) != std::string::npos)
                    throw std::exception("Incorrect number");
            } else {
                if (_number.find_first_not_of("0123456789-()", 0) != std::string::npos)
                    throw std::exception("Incorrect number");
            }
            number = _number;
        }
    };

    std::string name;
    std::string address;
    PhoneNumber number;
public:
    // Конструктор
    RecordBook(std::string _name, std::string _address, std::string _number) throw(std::exception) : number(_number)
    {
        name = _name;
        address = _address;
    }

    // Методи доступу
    std::string GetName() const
    {
        return name;
    }
    std::string GetAddress() const
    {
        return address;
    }
    std::string GetNumber() const
    {
        return number.GetNumber();
    }
    void SetName(std::string _name)
    {
        name = _name;
    }
    void SetAddress(std::string _address)
    {
        address = _address;
    }
    void SetNumber(std::string _number) throw(std::exception)
    {
        number.SetNumber(_number);
    }

    // Метод, що виводить інформацію про рядок
    void ShowBook(std::string msg)
    {
        std::cout << msg << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address <<std::endl;
        std::cout << "Phone number: " << number.GetNumber() << std::endl;
    }
    
};

class HandBook
{
private:
    std::vector<RecordBook> hBook;
public:
    // Конструктор - створює пустий список
    HandBook() {}

    // Вивести масив hBook у зручному вигляді
    void Show(std::string msg)
    {
        std::cout << msg << std::endl;
        for (int i = 0; i < hBook.size(); i++) {
            hBook[i].ShowBook(std::to_string(i + 1));
            std::cout << std::endl;
        }
    }

    // Метод, що додає новий рядок. Якщо номер телефону задано неправильно, 
    // то метод повертає false, інакше true.
    bool Add(std::string name, std::string address, std::string number)
    {
        try {
            RecordBook temp(name, address, number);
            hBook.push_back(temp);
            return true;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return false;
        }
    }

    // Метод, що видаляє всі записи з іменем name
    void DelByName(std::string name)
    {
        auto it = std::remove_if(hBook.begin(), hBook.end(), [&](const RecordBook& r) { 
            return r.GetName() == name; 
        });
        hBook.erase(it, hBook.end());
    }

    // Зберігає довідник у файлі з іменем filename у бінарному форматі.
    // Метод повертає true, якщо операція запису відбулась успішно.
    bool SaveToFile(const std::string& filename) const
    {
        std::ofstream file(filename, std::ios::out | std::ios::binary);
        if (!file.is_open()) {
            return false;
        }
        int size = hBook.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto& record : hBook) {
            int nameLen = record.GetName().length();
            int addressLen = record.GetAddress().length();
            int numberLen = record.GetNumber().length();
            file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
            file.write(record.GetName().c_str(), nameLen);
            file.write(reinterpret_cast<const char*>(&addressLen), sizeof(addressLen));
            file.write(record.GetAddress().c_str(), addressLen);
            file.write(reinterpret_cast<const char*>(&numberLen), sizeof(numberLen));
            file.write(record.GetNumber().c_str(), numberLen);
        }
        file.close();
        return true;
    }


    // Читає з файлу filename інформацію, яка була
    // попередньо збережена в методі SaveToFile()
    bool LoadFromFile(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (!file.is_open()) {
            return false;
        }
        int size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        hBook.clear();
        for (int i = 0; i < size; i++) {
            int nameLen = 0, addressLen = 0, numberLen = 0;
            file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            std::string name(nameLen, ' ');
            file.read(&name[0], nameLen);
            file.read(reinterpret_cast<char*>(&addressLen), sizeof(addressLen));
            std::string address(addressLen, ' ');
            file.read(&address[0], addressLen);
            file.read(reinterpret_cast<char*>(&numberLen), sizeof(numberLen));
            std::string number(numberLen, ' ');
            file.read(&number[0], numberLen);
            RecordBook RB(name, address, number);
            hBook.push_back(RB);
        }
        return true;
    }
};

int main()
{
    HandBook B;

    B.Add("Org-03", "Address-03", "099-7758001");
    B.Add("Org-01", "Address-01", "097-9358012");
    B.Add("Org-03", "Address-03", "099-6258031");
    B.Add("Org-02", "Address-02", "+38(095)-7778001");
    B.Add("Org-03", "Address-03", "099-5258001");

    if (B.SaveToFile("handbook.bin"))
        std::cout << "Save: Ok!" << std::endl;
    else
        std::cout << "Save: Error!" << std::endl;

    B.Show("B");
    B.DelByName("Org-03");
    B.Show("B");

    if (B.LoadFromFile("handbook.bin"))
        std::cout << "Load: Ok!" << std::endl;
    else
        std::cout << "Load: Error!" << std::endl;

    B.Show("B++");
    return 0;
}