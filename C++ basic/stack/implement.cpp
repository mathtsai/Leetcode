#include<iostream>
#include "stack.h"

//Constructor.
stack::stack()
{
    mSize = 0;
    mCapacity = 8;
    pNum = new int[8];
}

//Destructor.
stack::~stack()
{
    //Release resources.
    delete[] pNum;
}

//Copy constructor.
stack::stack(const stack& other)
{
    std::cout << "copy constructor!\n";
    //Copy from other.
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    pNum = new int[mCapacity];
    for(int i=0; i<mSize; i++)
        pNum[i] = other.pNum[i];
}

//Copy assignment.
stack& stack::operator=(const stack& other)
{
    std::cout << "copy assignment!\n";
    if(this != &other)
    {
        //Release current resources.
        delete[] pNum;

        //Copy from other.
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        pNum = new int[mCapacity];
        for(int i=0; i<mSize; i++)
            pNum[i] = other.pNum[i];
    }

    return *this;
}

//Move constructor.
stack::stack(stack&& other)
{
    std::cout << "move constructor!\n";
    //Take resources from other.
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    pNum = other.pNum;

    //Reset other.
    other.mSize = 0;
    other.mCapacity = 0;
    other.pNum = nullptr;
}

//Move assignment.
stack& stack::operator=(stack&& other)
{
    std::cout << "move assignment!\n";
    if(this != &other)
    {
        //Release current resources.
        delete[] pNum;

        //Take resources from other.
        mSize = other.mSize;
        mCapacity = other.mCapacity;
        pNum = other.pNum;

        //Reset other.
        other.mSize = 0;
        other.mCapacity = 0;
        other.pNum = nullptr;
    }

    return *this;
}

void stack::push(const int k)
{
    //If the stack is full.
    if(mSize == mCapacity)
    {
        std::cout << "stack is full when size = " << mSize << " !\n";
        //Create a temp memory with larger capacity.
        int *pTemp = new int[mCapacity*2];

        //Copy resources to temp, and then update the new capacity.
        for(int i=0; i<mCapacity; i++)
            pTemp[i] = pNum[i];

        mCapacity *= 2;

        //Restore resources from temp.
        std::swap(pTemp, pNum);

        //Release the resources from temp.
        delete[] pTemp;
    }

    pNum[mSize++] = k;
}

void stack::pop()
{
    if(mSize > 0)
        mSize--;
}

int stack::top()
{
    return pNum[mSize-1];
}

int stack::size()
{
    return mSize;
}

bool stack::empty()
{
    return mSize == 0;
}

int stack::get_capacity()
{
    return mCapacity;
}
