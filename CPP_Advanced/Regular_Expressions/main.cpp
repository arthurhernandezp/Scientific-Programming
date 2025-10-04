#include <iostream>
#include <regex>
#include <string>

/*
 * Regular Expression: A regular expression is a specific pattern that provides concise and flexible means
 *  to "match" strings of text, such as particular characters, words, or patterns of characters. "
 */

int main()
{
    std::string str;
    while (true)
    {
        std::cin >> str;
        std::regex e("abc");
        std::regex dontCareUpperCase("abc",std::regex_constants::icase);
        std::regex startWith("abc.");                       //Exemplo: abcd(passa), abcdef(passa), aabcd(não)
        std::regex zeroOrOneC("abc?");                      //Exemplo: abc, ab
        std::regex zeroOrMoreC("abc?");                     //Exemplo: ab, abc, abccc,...
        std::regex oneOrMoreC("abc+");                      //Exemplo: abc,abcc,abccc,...
        std::regex dOrC("ab[cd]");                          //Exemplo: abc,abd
        std::regex zeroOrMore_d_OR_c("ab[cd]*");            //Exemplo:ab,abccc,abddd,abccdd,...
        std::regex cantBe_c_OR_d("ab[^cd]*");               //Exemplo:ab,abt, abgytt,...
        std::regex only3_c_or_d("ab[cd]{3}");               //Exemplo:abccc, abddd, abcdc,...
        std::regex threeOrMore_c_or_d("ab[cd]{3,}");        //Exemplo:abcccccccc, abcdcddd,...
        std::regex threeToFive_c_or_d("ab[cd]{3,5}");       //Exemplo:abccccc,abddddd,...
        std::regex leftOrRight("abc|de[fg]");               //Exemplo:abc,def,deg
        std::regex emailFilter("([[:w:]]+)@([[:w:]]+)\.com");   // [[:w:]] word character: digit,number, or underscore

        bool match = std::regex_match(str, e);
        bool find = std::regex_search(str, e);  ///cdvvcxabcxasdsada

        std::smatch m;          //typedef std::match_results<string>

        bool foundEmail = std::regex_search(str, m, emailFilter);

        for (int i = 0; i < m.size(); ++i)
        {
            std::cout << "m[" << i << "]: str()=" << m[i].str() <<std::endl;
        }
        auto username = m[1].str();
        auto domain = m[2].str();

        if (match | find | foundEmail) break;

    }
    return 0;
}