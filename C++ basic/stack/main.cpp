#include<iostream>
#include"stack.h"
int main()
{
    stack original;

    std::cout<<"-----Test for member functions(push/pop/top/size/empty)-----\n";
    std::cout << "Is stack empty? " << original.empty() << '\n';
    for(int i=0; i<10; i++)
        original.push(i);

    std::cout << "Is stack empty? " << original.empty() << '\n';
    std::cout << "Before pop: size = " << original.size() << ", capacity = " << original.get_capacity() << ", top = " << original.top() << '\n';
    original.pop();
    std::cout << "After pop: size = " << original.size() << ", capacity = " << original.get_capacity() << ", top = " << original.top() << '\n';
    std::cout << '\n';

    std::cout<<"-----Test for copy constructor/assignment-----\n";
    //stack copied = original; //Test for copy constructor.
    stack copied;
    copied = original;
    std::cout << "original: size = " << original.size() << ", capacity = " << original.get_capacity() << '\n';
    std::cout << "copied: size = " << copied.size() << ", capacity = " << copied.get_capacity() << '\n';

    std::cout << '\n';

    std::cout<<"-----Test for move constructor/assignment-----\n";
    stack moved = std::move(original);
    //stack move_s2;
    //move_s2 = std::move(s1); //Test for move assignment
    std::cout << "original: size = " << original.size() << ", capacity = " << original.get_capacity() << '\n';
    std::cout << "moved: size = " << moved.size() << ", capacity = " << moved.get_capacity() << '\n';
}
