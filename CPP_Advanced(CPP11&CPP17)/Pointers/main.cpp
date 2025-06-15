#include <iostream>
#include <string>
#include <memory>

class Dog
{
    std::string name;
    // std::shared_ptr<Dog> friendDog;          // Cyclic reference
    std::weak_ptr<Dog> friendDog;               // Cyclic reference solution
public:
    Dog(std::string name) : name(name){ std::cout << "Dog is created " << name << std::endl;}
    Dog(){ std::cout << "Nameless Dog is created" << std::endl;}
    ~Dog(){ std::cout << "Dog is destroyed: "<< name << std::endl;}
    void bark() const{ std::cout << "Dog: " << this->name << ", bark!" << std::endl; }
    void makeFriend(std::shared_ptr<Dog> other)
    {
        friendDog = other;
    }
};

void foo()
{
    std::shared_ptr<Dog> p = std::make_shared<Dog>("Gunner");       //    Count: 1
    p->bark();
    {
        std::shared_ptr<Dog> p2 = p;                                    //   Count: 2
        p2->bark();
        std::cout << p.use_count() << std::endl;
    }
    // Count: 1
    p->bark();
    std::cout << p.use_count() << std::endl;
}// Count: 0


int main()
{
    foo();

    std::shared_ptr<Dog> dog_pointer = std::make_shared<Dog>("Tibbers");

    (*dog_pointer).bark();

    //Point Cast
        /*
         * 1.static_pointer_cast
         * 2.dynamic_pointer_cast
         * 3.const_pointer_cast
         */

    //Delete Shared Pointer
        std::shared_ptr<Dog> p = std::make_shared<Dog>("Tig");          // using default deleter: operator delete
        std::shared_ptr<Dog> p2(new Dog("Tig2"),
            [](Dog *pArg)
            {
                std::cout << "Dog is custom destroyed" << std::endl;
                delete pArg;
            });

    std::shared_ptr<Dog> cachorro1 = std::make_shared<Dog>("Cachorro1");
    std::shared_ptr<Dog> cachorro2 = std::make_shared<Dog>("Cachorro2");
    cachorro1->makeFriend(cachorro2);
    cachorro2->makeFriend(cachorro1);

    return 0;
}