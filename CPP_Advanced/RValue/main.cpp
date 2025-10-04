#include <iostream>

// C++ 11:Rvalue Reference
//  1.Moving Semantics
//  2.Perfect Forwarding
//
//  Prerequisite: understaing rvalue and lvalue

void printInt(int &i){ std::cout << i << std::endl; }
void printInt(int &&i){ std::cout << i << std::endl; }

// Example of use
class myVector
{
    int size;
    double *arr_;       //a big array
public:
    myVector(const myVector& lhs)            // Copy Constructor
    {
        size = lhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++)
        {
            arr_[i] = lhs.arr_[i];          // very cost, Deep copy
        }
    }
    myVector( myVector&& rhs)            // Move Constructor
    {
            size = rhs.size;
            arr_ = rhs.arr_;            // Shallow copy
            rhs.size = 0;
            rhs.arr_ = nullptr;
    }
    ~myVector()
    {
        delete arr_;
    }

    myVector& operator=(myVector const & rhs)
    {
        size = lhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++)
        {
            arr_[i] = lhs.arr_[i];          // very cost, Deep copy
        }
        return *this;
    }

    myVector& operator=(myVector &&rhs)
    {
        size = rhs.size;
        arr_ = rhs.arr_;            // Shallow copy
        rhs.size = 0;
        rhs.arr_ = nullptr;
    }


};

void foo_by_value(myVector vec);
void foo_by_reference(myVector& vec);

myVector createMyVector();

void foo(myVector arg);

/*
 * 1. No costly and unecessary copy construction of myVector is made;
 * 2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue
 */
template<typename  T>
void relay(T&& arg)
{
    foo(std::foward<T>(arg));
}

int main()
{
    // What is rvalue reference?
    int a = 5;          // a is a lvalue
    int &b = a;         // b is a lvalue reference
    printInt(a);     // Call printInt(int & i)
    printInt(6);      // Call printInt(int && i)

    myVector reusable = createMyVector();
    foo_by_reference(reusable);         // Call no constructor
    foo_by_value(reusable);             // Call copy constructor
    foo_by_value(std::move(reusable));     // Call move constructor  | resuable.arr_ = nullptr

    relay(reusable);
    relay(createMyVector());
    return 0;
}