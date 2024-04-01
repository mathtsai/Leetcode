#include<bits/stdc++.h>
using namespace std;

class Animal
{
public:
    Animal(int age = 0)
    {
        this->age = age;
    }
    virtual void Eat()
    {
        cout << "Animal Eats food\n";
    }
    int get_Age()
    {
        return age;
    }
protected:
    int age;
};

class Dog: public Animal
{
public:
    Dog(int age) : Animal(age)
    {

    }
    void Eat() override
    {
        cout << "Dog Eats food\n";
    }
};

class Cat: public Animal
{
public:
    Cat(int age) : Animal(age)
    {

    }
    void Eat() override
    {
        cout << "Cat Eats food\n";
    }
};

int main()
{
    Animal *a;
    Dog dog(8);
    Cat cat(3);

    a = &dog;
    a->Eat();
    cout << "dog age = " << a->get_Age() << '\n';

    a = &cat;
    a->Eat();
    cout << "cat age = " << a->get_Age() << '\n';
}
