#include <functional>
#include <iostream>
#include <string>
/*
 *  Function Objects (functors)
 *
 *  Example:
 */
class X
{
public:
    void operator()(std::string str)
    {
        std::cout << "Calling functor X with parameter " << str << std::endl;
    }
};
int main()
{
    X foo;
    foo("Hi");          // Calling functor X with parameter Hi;
    return 0;
}
/*
 *  Benefits of functor:
 *  1.  Smart function: capabilities beyond operator ()
 *      It can remember state.
 *  2.  It can have its own type.
 */