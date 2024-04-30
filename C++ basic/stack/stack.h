#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//template<typedef T> for templates
//stack is implemented with deque in STL
class stack
{
public:
    //Default constructor/destructor.
    stack();
    ~stack();

    //Copy constructor/assignment.
    stack(const stack& other);
    stack& operator=(const stack& other);

    //Move constructor/assignment.
    stack(stack&& other);
    stack& operator=(stack&& other);

    //Member functions.
    void push(const int k);
    void pop();
    int top();
    int size();
    bool empty();
    int get_capacity();

    //bonus
    //int get_max();

protected:
    //m for "member".
    //p for "pointer".
    int mSize;
    int mCapacity;

    //Try smart pointers next time?
    int *pNum;
};

#endif // STACK_H_INCLUDED
