#include <functional>
#include <iostream>
#include <thread>

void function_1(const std::string &s = "")
{
    std::cout << "Function 1 is called" << s << '\n';
}

class Fctor
{
public:
    void operator ()(const std::string &s = "")
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "from t1: " << s << std::endl;
        }
    }
};

class RAIIThread
{
public:
     explicit RAIIThread(const std::function<void(std::string)> &f, const std::string &s = "")
    {
        thread = std::thread(f,s);
    }
    ~RAIIThread()
    {
         if (thread.joinable())
            thread.join();
    }

    std::thread thread;
};

int main()
{
    Fctor f;
    std::thread t1(f);     //  t1 starts running
    // t1.join();      //  main thread waits for t1 to finish
    // t1.detach();      //    t1 will freely on its own -- daemon process
    std::thread t2(f,"com t2 testando essa porra");
    for (int i = 0; i < 100; ++i)
    {
        std::cout << "from main: " << i << std::endl;
    }
    t1.join();
    //Indicação de quantas threads devem rodar nesse hardware para evitar Oversubscription
    std::cout << std::thread::hardware_concurrency() << '\n';

    t2.join();

    RAIIThread thread_1(function_1, std::string("   1"));
    return 0;
}