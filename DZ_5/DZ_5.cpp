#include <iostream>
using namespace std;

class pInt{
public:
    int *p;
    pInt(){
        p = new int;
        *p = 0;
    }
    pInt(int i){
        p = new int;
        *p = i;
    }
    pInt (const pInt &rhs){
        p = new int;
        *p = *rhs.p;
    }
    pInt operator=(const pInt &rhs){
        *p = *rhs.p;
        return *this;
    }
    ~pInt(){
        delete p;
    }
    void print(string msg){
        cout<<msg<<" =>\n";
        cout<<"p = "<<*p<<endl;
    }
    
    void SetP(int value){
        *p = value;
    }
    
    friend class FriendPInt;
};

class arrayPInt{
public:
    pInt *arrp;
    int size;
    arrayPInt(int s, pInt arr[]){
        size = s;
        arrp = new pInt[size];
        for (int i = 0; i < size; i++){
            arrp[i] = arr[i];
        }
    }
    arrayPInt() : arrayPInt(0, nullptr){}
    
    arrayPInt(const arrayPInt &rhs){
        size = rhs.size;
        arrp = new pInt[size];
        for(int i = 0; i < size; i++){
            arrp[i] = rhs.arrp[i];
        }
    }
    arrayPInt operator=(const arrayPInt &rhs){
        size = rhs.size;
        arrp = new pInt[size];
        for(int i = 0; i < size; i++){
            arrp[i] = rhs.arrp[i];
        }
        return *this;
    }
    ~arrayPInt(){
        delete [] arrp;
    }
    void print(string msg) const{
        cout<<msg<<" =>\n";
        for(int i = 0; i < size; i++){
            cout << *arrp[i].p << " ";
        }
        cout << endl;
    }
    void SetArray(int s, pInt arr[]){
        size = s;
        delete[] arrp;
        arrp = new pInt[size];
        for (int i = 0; i < size; i++){
            arrp[i] = arr[i];
        }
    }
    
    friend class FriendPInt;
};

class FriendPInt{
public:
    int GetOccurs(pInt& obj_pInt, arrayPInt& obj_arrayPInt){
        int local_count = obj_arrayPInt.size;

        int count_true = 0;
        for (int i = 0; i < local_count; i++) {
            if(*obj_arrayPInt.arrp[i].p == *obj_pInt.p){
                count_true++;
            }
        }
        return count_true;
    }
    
    
    void Add(arrayPInt& obj_arrayPInt, pInt& obj_pInt){
        for (int i = 0; i < obj_arrayPInt.size; i++){
            *obj_arrayPInt.arrp[i].p+=*obj_pInt.p;
        }
    }
    
    arrayPInt Sub(arrayPInt& obj_arrayPInt, pInt& obj_pInt){
        arrayPInt a;
        a = obj_arrayPInt;
        for (int i = 0; i < a.size; i++){
            *a.arrp[i].p-=*obj_pInt.p;
        }
        return a;
    }
};




int main() {
    pInt p1(10), p2(4), p3(9);
    p1.print("p1");
    p1.SetP(2);
    p1.print("p1");
    pInt mass1[] = {p1, p2, p3};
    arrayPInt a(3, mass1);
    arrayPInt b =a;
    arrayPInt c;
    c = b;
    a.print("a");
    b.print("b");
    c.print("c");
    pInt mass2[] = {p2, p1, p3};
    cout<<"\n\n\n\n\n";
    arrayPInt v(3, mass2);
    v.print("v");
    p1.print("p1");
    FriendPInt gh;
    cout<<gh.GetOccurs(p1, v)<<endl;
    pInt p5(1);
    arrayPInt new_v(gh.Sub(v, p5));
    v.print("v");
    new_v.print("new v");
    gh.Add(new_v, p5);
    new_v.print("new v");
}
