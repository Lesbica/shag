#include <iostream>
using namespace std;

template <class T>
class MyUniquePtr{
private:
    T* ptr;
public:
    MyUniquePtr(T p){
        ptr = new T;
        *ptr = p;
    }
    MyUniquePtr(){
        ptr = new T;
        ptr = nullptr;
    }
    
    ~MyUniquePtr(){
        delete ptr;
    }
    
    T* Get(){
        return ptr;
    }
    
    T* Release(){
        ptr = nullptr;
        return ptr;
    }
    
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;
    
    void Print(){
        cout << *ptr << endl;
    }
    void Reset(){
        ptr = nullptr;
    }
    
};
int main() {
    MyUniquePtr<int> my_ptr(10);
    my_ptr.Print();
    
    MyUniquePtr<int> my_ptr2;
    //    my_ptr2 = my_ptr;
    return 0;
}
