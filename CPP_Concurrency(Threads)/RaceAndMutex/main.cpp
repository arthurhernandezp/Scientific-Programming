#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
std::mutex mtx;

void shared_function(const std::string& s, const int & i)
{
    std::lock_guard<std::mutex> lock(mtx);      // RAII and protect from expections
    //mtx.lock();
    std::cout << s << i << std::endl;
    //mtx.unlock();
}

// std::cout is still available to use by other functions, but LogFile is a safe output to multithread
class LogFile
{
    std::mutex mtx;
    std::ofstream f;
public:
    LogFile()
    {
        f.open("log.txt", std::ios::app);
    }
    void write(const std::string& s, const int & i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        f << s << i << std::endl;
    }
    // Never return f to the outside world
    std::ofstream& getStream()
    {
        return f;
    }
    // Never pass f as an argument to user provided function
    void processf(void fun(std::ofstream&))
    {
        fun(f);
    }

};

void function_1()
{
    for (int i=0; i>-100;--i)
    {
        shared_function("from t1: ",i);
    }
}

int main()
{
    std::thread t1(function_1);

    for (int i=0; i>-100;--i)
    {
        shared_function("from main: ",i);
    }
    t1.join();

    return 0;
}