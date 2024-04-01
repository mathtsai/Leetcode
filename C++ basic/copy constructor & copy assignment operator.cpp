#include<bits/stdc++.h>
using namespace std;

class student{
public:
    int id;
    student(int id=0)
    {
        this->id = id;
    }
    student(const student &b)
    {
        id = b.id;
        cout << "copy constructor!\n";
    }
    student& operator=(const student &b)
    {
        id = b.id;
        cout << "copy assignment operator!\n";
    }
};

int main(){
    student a(10);
    student b = a; //copy constructor

    student c;
    c = a; //copy assignment operator
}
