#include <iostream>
#include <string>

// Para struct data members são public por padrão.
// Usada para estruturas de dados pequenas que carregam dados publicos que possuem nenhuma
// ou poucas members functions basicamente usadas como Data Container
struct Person_t {
    std::string name;
    unsigned int age;
};

//Para Classes data members são private por padrão.
// Usada para objetos maiores que carregam dados privados, acessados através de uma interface
// com public member functions.
// Complex Data Structure
class Person {
    unsigned int age;   //private
public:
    unsigned int getAge() const {return age;}           //getter    / accessor
    void setAge(unsigned int age) {this->age = age;}    //setter    / mutator
};

int main()
{
    Person_t person;
    person.name = "John";
    person.age = 20;
    std::cout << person.name << '\n';
    std::cout << person.age << '\n';

    Person person2;
    person2.setName("dasA");
    person2.setAge(30);

    std::cout << person2.getName() << '\n';
    std::cout << person2.getAge() << '\n';
    return 0;
}