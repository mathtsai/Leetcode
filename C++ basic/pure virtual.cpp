#include<bits/stdc++.h>
using namespace std;

class Shape
{
public:
    Shape()
    {

    }
    virtual int Area()=0; //abstract
};

class Square : public Shape
{
public:
    Square(int l)
    {
        side = l;
    }
    int Area()
    {
        return side*side;
    }

protected:
    int side;
};

class Rectangle : public Shape
{
public:
    Rectangle(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int Area()
    {
        return a*b;
    }

protected:
    int a, b;
};

int main()
{
    Shape *s;
    Square square(10);
    Rectangle rec(30,4);

    //Shape s1 -> Shape is abstract
    //s->Area() -> Area() is pure virtual

    s = &square;
    cout << "Area of square: " << s->Area() << '\n';

    s = &rec;
    cout << "Area of Rectangle: " << s->Area() << '\n';
}
