#include <iostream>
#include <vector>
#include <initializer_list>
#include <assert.h>
/*
*  1.Initializer List
*/
//Define your own initialize_list constructor
class myVector
{
    std::vector<int> vec;
public:
    myVector(const std::initializer_list<int>& v)
    {
        for (std::initializer_list<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};

/*
*  2.Uniform Initialization
*/

//Uniform Initialization Search Order:

/* 1. Initializer_list constructor
*  2. Regular constructor that takes the appropriete parameters
*  3. Aggregate initializer
*/

class Dog
{
public:
    int age;                                        //  3rd choice

    Dog(int a)                                      //  2nd choice
    {
        age = a;
    }
    Dog(const std::initializer_list<int>& vec)      //1st choice
    {
        age = *(vec.begin());
    }

};

/*
*  3.nullptr
*/
void foo(int i){ std::cout << "foo_int" << std::endl; }
void foo(char *pc){ std::cout << "foo_char*" << std::endl; }

int main()
{
    /*
    *  1.Initializer List
    */

        //C++ 03 initializer list
        int arr[4] = {1,2,3,4};

        //C++ 11 extended the support to STL containers

        std::vector<int> vec = {1,2,3,4};               //Cailling initializer_list constructor

        myVector vec2{1,2,3,4,5};
        myVector vec3 = {1,2,3,4,5};

    /*
    *  2.Uniform Initialization
    */

        Dog dog{3};

    /*
    *  3.auto type
    */

        std::vector<int> vect = {1,2,3,4,5};

        // C++ 03
        for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        {
            vec.push_back(*it);
        }

        //C++ 11
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            vec.push_back(*it);
        }

        auto a = 6;             //a is integer
        auto b = 2.8;           //b is double
        auto c = a + b;   //c is double

    /*
    *  3.nullptr
    */
       //foo(NULL);               //Error: Ambiguos
       //foo(nullptr);           //Call: foo(char *)

    /*
    *  4.enum class
    */
        //C++ 03
        enum apple{green_a, red_a};
        enum orange{big_o,small_o};
        apple ap = green_a;
        orange o = big_o;                                       //ap = o

        //C++ 11
        enum class appleClass{green, red};
        enum class orangeClass{big, small};
        appleClass apC = appleClass::green;
        orangeClass oC = orangeClass::big;                      //APC != Oc

    /*
    *  5. static_assert
    */
        int * myPointer = NULL;
        //run-time assert
        assert(myPointer != NULL);

        //Compile time assert
        static_assert(sizeof(int) == 4);
    return 0;
}