#include <iostream>
using namespace std;

class String{
private:
    char* str;
    int size;
public:
    String(const char* _str){
        int i = 0;
        while(_str[i] != '\0') i++;
        size = i;
        str = new char[size+1];
        for(int i = 0; i <= size; i++)
            str[i] = _str[i];
    }
    String(){
        str = nullptr;
        size = 0;
    }
    
    int GetSize() const {
        return size;
    }
    ~String(){
        if(str != nullptr && size > 0){
            delete[] str;
            size = 0;
        }
    }
    
    void Print(string msg){
        cout << msg << " => ";
        for(int i = 0; i < size; i++)
            cout << str[i];
        cout << endl;
    }
    
    String(const String& obj) : String(obj.str){}
    
    String& operator=(const String& obj){
        if(this != &obj){
            if (str != nullptr){
                delete[] str;
                size = 0;
            }
            if(obj.str != nullptr){
                size = obj.size;
                str = new char[size];
                for(int i = 0; i < size; i++)
                    str[i] = obj.str[i];
            }
            else{
                str = nullptr;
                size = 0;
            }
        }
        return *this;
    }
    
    String& operator*(int count){
        if(str != nullptr){
            char* Buff = new char[size];
            for(int i = 0; i < size; i++)
                Buff[i] = str[i];
            delete[] str;
            size = size * count;
            str = new char[size];
            int x = 0;
            for(int i = 0; i < count; i++){
                for(int j = 0; j < size/count; j++){
                    str[x] = Buff[j];
                    x++;
                }
            }
        }
        return *this;
    }
    
    bool operator==(const String& obj){
        if(size == obj.size){
            for(int i = 0; i < size; i++)
                if(str[i] != obj.str[i])
                    return 0;
            return 1;
        }
        return 0;
    }
    
    bool operator!=(const String& obj){
        if(size == obj.size){
            for(int i = 0; i < size; i++)
                if(str[i] != obj.str[i])
                    return 1;
            return 0;
        }
        return 1;
    }
    
    String(String&& obj) noexcept{
        str = obj.str;
        size = obj.size;
        obj.size = 0;
    }
    
    String operator=(String&& obj) noexcept{
        if(str != nullptr){
            delete[] str;
            str = new char[size];
        }
        str = obj.str;
        size = obj.size;
        obj.size = 0;
        return *this;
    }
};

String CS(){
    String reS("buff");
    return reS;
}
int main() {

    String obj("pon");
    obj.Print("obj");
    obj.operator*(4);
    obj.Print("obj");

    return 0;
}
