// C++ Input/Output library -- Stream

#include <bitset>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <complex>

int main()
{
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";
    // std::cout: É um objeto global de ostream que está no namespace de std, (typedef basic_ostream<char> ostream)
    // <<:   É um member function de ostream, implementado como ostream& ostream::operator<<(std::string);
    // std::endl: '\n' + flush

    // Definição de stream: Serial IO Interface para disposivos externos(file,stdin,stdout,network,...)
    std::string s("Hello");
    s[3] = 't';             //Random access interface

    // RAII File
    {
        //File stream
        std::ofstream of("../MyLog.txt"); // Cria um novo arquivo para escrita se o arquivo mão exister
        of << "testando escrita em arquivos" << std::endl;
        of << 2234 << std::endl;
        of << 2.3 << std::endl;

        of << std::bitset<8>(14) << std::endl; //  00001110
        of << std::complex<int>(2, 3) << std::endl; //  (2,3)
    }
    // Escrever algo no final do arquivo sem perder o conteúdo anterior
    {
        // std::ofstream of("MyLog.txt");  //Open the file for write, clear the content of the file
        std::ofstream of2("../MyLog.txt",std::ofstream::app);  // Move o ponteiro para o final do arquivo
        of2 << "mostrando como funciona o modo append" << '\n';
    }

    // Para escrever algo no meio do arquivo
    {
        std::ofstream of2("../MyLog.txt",std::ofstream::in | std::ofstream::out);
        of2.seekp(10, std::ios::beg);   // Move o ponteiro para 10 posições depois do começo
        of2 << "12345"; //Sobreescreve 5 characters
        of2.seekp(-5,std::ios::end);    // Move o ponteiro para 5 posições antes do final
        of2 << "Testando escrita com -5 posições do final" << std::endl;
        of2.seekp(-5,std::ios::cur);    // Move o ponteiro para 5 posições antes da posição atual
        of2 << "alooo";
    }

    // Input

    std::ifstream info("../MyLog.txt");
    int i;
    info >> i;  //read one word
    // Error status: goodbit,badbit, failbit, eofbit
    info.good();    // Tudo está ok             (goodbit == 1)
    info.bad();     // Non-recoverable error    (badbit == 1)
    info.fail();    // failed stream operation  (failbit ==1, badbit == 1)
    info.eof();     // End of file              (eofbit == 1)

    info.clear();   // Clear all the error status
    info.clear(std::ios::badbit);   //sets a new value to the error flag

    info.rdstate(); // Read the current status flag

    if (info)
        std::cout << "Read successfully";

    if (info >> i)
        std::cout << "Read successfully";

    //Handle the error with exceptions
    info.exceptions(std::ios::badbit | std::ios::failbit);  //setting the exception mask
    // when badbit or failt set to 1, exception of std::ios::failure will thrown
    // When eofbit set to 1, no exception
    info.exceptions(std::ios::goodbit); // No exeception

    return 0;
}
