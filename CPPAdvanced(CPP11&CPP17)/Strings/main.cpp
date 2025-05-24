#include <algorithm>
#include <iostream>
#include <string>
//String
int main()
{
    //Constructor
        std::string s1("Hello");
        std::string s2("World",3);    // s2: Wor
        std::string s3(s1);            // Copy constructor
        std::string s4 = s2;           // Copy assigment operator
        std::string s5(s1,2);         // s5: llo
        std::string s6(s1,3,2);     // s6: ll
        std::string s7(10,'a');       // s7: aaaaaaaaaa
        std::string s8({'a','b','c'});  // s8: abc
        std::string s9(s8.begin(),s8.begin()+2);

        std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << std::endl;
        std::cout << s7 << std::endl;
        std::cout << s8 << std::endl;

    //Size
        s1 = "GoodBye";
        s1.size(); s1.length();     //Synonymous, both return 7
        s1.capacity();              // Return the storage space currently allocated to s1
        s1.reserve(100);        //  Will alocate 100 caracters of space to this string
        s1.resize(9);             // s1: GoodBye\0\0
        s1.resize(12,'x');      // s1: GoodBye\0\0xxx
        s1.resize(3);             // s1: Goo


    //Single Element Acess

        s1 = "GoodBye";
        s1[2];                      // 'o'
        s1[2] = 'x';                //GoxdBye
        s1.at(2) = 'y';           //GoydBye
        // s1.at(20);                // Throw exception of out_of_range
        //s1[20];                     // undefined behavior

        s1.front();                 // return a reference to the first caracter: 'G'
        s1.back();                  // return a reference to the last caracter: 'e'
        s1.push_back('z');        // append 'z'
        s1.pop_back();
        s1.front() = 'A';           //

        s1.begin();                 // return pointer to the first position of our container
        s1.end();                   // return pointer to the end of container

    // Ranged Acess
    // assign, append, insert, replace

        //Assign
        std::string s10 = "Dragon Land";
        std::string s11;
        s11.assign(s10);                //s1=s2
        s11.assign(s10,2,4);      //s11: agon
        s11.assign("Wisdom");           //s11: Wisdom
        s11.assign("Wisdom",3);     //s11: Wis
        s11.assign(3,'x');          //s11: xxx
        s11.assign({'a','b','c'});      //s11: abc

        //Append(End of the container)
        s11.append(" def");             //s11:abc def

        //Insert(Any position)
        s11.insert(2,"mount");      //s11: abmountc def
        s11.insert(1,"insert",3); //s11: abinsmoutc def

        //Replace
        std::string replaceString("replace");
        s11.replace(0,1,replaceString,2,4);
        std::cout << s11 << std::endl;    //s11: placinsbmountc def

        //Erase
        s11.erase(0,8);                     //s11: mountc def
        auto substr = s11.substr(0,3); // return: mou
        std::cout << substr << std::endl;

    //Convert
        std::string convert = "abc";
        convert.c_str();            //return abc\0
        convert.data();             //return abc

    //Swap
        std::string swap = "edf";
        convert.swap(swap);      //swap = abc && convert = edf


    //Member functions Algorithms: copy,find,compare

        //Copy
        std::string p1("abcedfg");
        char buf[20];
        size_t len = p1.copy(buf,3);    //Essa função irá copiar 3 caracters de p1 para buf e retornar o tamanho dessa copia para len
        std::cout << len << std::endl;
        std::cout << p1 << std::endl;
        std::cout << buf << std::endl;
        len = p1.copy(buf,4,2);     //buf = cedf    //len = 4
        std::cout << buf << std::endl;

        //find
        p1 = "If a jobd is worth doing, it's worth doing well";
        size_t found = p1.find("doing");     //found = 17, 17 é o index onde foi encontrado "doing"
        found = p1.find("doing",20);     //found = 34, 34 é o index que foi encontrado "doing" a partir do index 20
        found = 0;
        found = p1.find("doing",0,1);  //found = 8, 8 é o index que foi encontrar 'd'
        std::cout << found << std::endl;

        //compare
        std::string compareS("testingCompareString");
        p1.compare(compareS);       //return positive if (p1 > compareS); negative if(p1 < compareS) ; 0 if(p1 == compareS)

        //concat
        std::string concat1("hello ");
        std::string concat2("world");
        std::string concat3 = concat1 + concat2;

    // Non member function
        std::string nonMemberFunctionString = "nonMemberFunctionString";
        std::cout << nonMemberFunctionString << std::endl;
        std::cin >> nonMemberFunctionString;
        std::cout << nonMemberFunctionString << std::endl;
        std::getline(std::cin,nonMemberFunctionString);                 //delimitor is default '\n'
        std::getline(std::cin,nonMemberFunctionString,';');        //delimeter is ';'
        std::cout << nonMemberFunctionString << std::endl;

        //Convert Number to string
        std::string numberToString = std::to_string(10);                    //"10"
        numberToString = std::to_string(2.3e7);         //23000000.00000
        numberToString = std::to_string(0xa4);
        numberToString == std::to_string(034);

        //Convert string to number
        int i = std::stoi(numberToString);
        numberToString = "111 pessoas";
        size_t pos;
        i = std::stoi(numberToString,&pos); //i = 111 | pos: 3

    // Strings and Algorithms

    std::string stringAndAlgorithms = "Variety is the spice of life";
    int num = std::count(stringAndAlgorithms.begin(),stringAndAlgorithms.end(),'e');
    std::cout << num <<std::endl;
    std::string stringAndAlgoritms2;
    std::transform(stringAndAlgorithms.begin(),stringAndAlgorithms.end(),stringAndAlgoritms2.begin(),
    [](char c)
    {
        if (c < 'n')
        {
            return 'a';
        }
        else
            return 'z';
    });
    return 0;
}