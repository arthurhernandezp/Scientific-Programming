#include <iostream>
#include <iostream>
/*
 *  STL Headers
 */
#include <vector>
#include <deque>
#include <list>
#include <set>              //  set and multiset
#include <map>              //  map and multimap
#include <unordered_set>    //  unordered set/multiset
#include <unordered_map>    //  unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric>          //  some numeric algorithm
#include <functional>

/*
 *  STL Algorithm Walkthrough:
 *      Non-modifying Algorithms
 *      count, min and max, compare, linear search, attribute
 */


int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v2 = {10,20,30,40,50,60,70,80,90,100};

    // C++ 11 Lambda Function:
    auto num = std::count_if(v.begin(),v.end(),[](int x){return x < 10;});
    std::cout << num << std::endl;

    std::pair<std::vector<int>::iterator,std::vector<int>::iterator> pairOfItr;

    // C++ 03: Some algorithms can be found in tr1 or boost

    std::vector<int> vec = {9,60,90,8,45,87,90,69,69,55,7};

    //  1.  Counting
        //      Algorithm                Data              Operation
        int n = std::count(vec.begin(),vec.end()-1,69);       // 2
        int m = std::count_if(vec.begin(),vec.end(),[](int x){return x < 10;}); //  3
        std::cout << n << " - " << m << std::endl;

    //  2.  Min and Max
        std::vector<int>::iterator it;
        it = std::max_element(vec.begin()+2,vec.end());    //  90
        //  It returns the first max value
        it = std::max_element(vec.begin(),vec.end(),
            [](int x, int y)
            {
                return (x%10)<(y%10);
            });                                                       //    9

        //  Most algorithms have a simple form and a generalized form

        it = std::min_element(vec.begin(),vec.end());       //  7
        //  Generalized form: min_element()

        pairOfItr = std::minmax_element(vec.begin(),vec.end(),
                                    [](int x, int y){return (x%10)<(y%10);});

        //  returns a pair, which contains first of min and last of max


    //  3.  Linear Searching( used when data is not sorted)
    //      Returns the first match

        it = std::find(vec.begin(),vec.end(),55);
        it= std::find_if(vec.begin(),vec.end(),[](int x){return x > 50;});
        it = std::find_if_not(vec.begin(),vec.end(),[](int x){return x > 80;});

        it = std::search_n(vec.begin(),vec.end(),2,69);         // consecutives 2 items of 69
        //  Generalized form: search_n()

        //  Search subrange
        std::vector<int> sub = {45,87,90};
        it = std::search(vec.begin(),vec.end(),sub.begin(),sub.end());
            //  search first subrange
        it = std::find_end(vec.begin(),vec.end(),sub.begin(),sub.end());
            //  search last rubrange
        //  Generalized form: search(), find_end()

        // Search any_of
        std::vector<int> items = {87,69};
        it = find_first_of(vec.begin(),vec.end(),items.begin(),items.end());
    return 0;
}