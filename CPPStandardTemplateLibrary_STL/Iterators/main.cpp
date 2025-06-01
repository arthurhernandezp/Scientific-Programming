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
#include <forward_list>
#include <numeric>          //  some numeric algorithm
#include <functional>
#include <ranges>

int main()
{
    /*
     *  Iterators
     */
    //  1.Random Acess Iterator: vector, deque, array
        std::vector<int>::iterator vecIt;
        std::vector<int>::iterator vecIt2;
        // vecIt = vecIt + 5;      //advance itr by 5
        // vecIt = vecIt - 4;
        if (vecIt > vecIt2)     // . . .
        // ++vecIt;
        // --vecIt;

    //  2. Bidirectional Iterator: list,set/multiset, map/multiset
        std::list<int>::iterator listIt;
        // ++listIt;
        // --listIt;

    //  3. Forward Iterator: foward_list
        std::forward_list<int>::iterator forwardListIt;
        // ++forwardListIt;

    //  Unordered containers provide "at least" forward iterators

    //  4.  Input Iterator: read and process values while iterating forward
        // int x = *vecIt;

    //  5. Output Iterator: output values while iterating forward.
        // *vecIt = 100;

    //  Every container has a iterator and a const_iterator
        std::set<int>::iterator itr;
        std::set<int>::const_iterator citr;

        std::set<int> mySet = {1,3,2,6,8,4};
        for (citr = mySet.begin(); citr != mySet.end(); ++citr)
            std::cout << *citr << std::endl;
        // auto myFunct = [](){};
        // std::for_each(mySet.begin(), mySet.end(), myFunct);

        // std::ranges::advance(itr, 1);
        itr = mySet.find(4);
        citr = mySet.find(1);
        std::vector<int> myVect {1,2,3,4,5,6};
        auto it = std::ranges::find(myVect, 1);
        auto it2 = std::ranges::find(myVect, 4);
        auto distance = std::distance(it, it2);
        std::cout << distance << std::endl;

    /*
     *  Iterator Adaptor (Predefined Iterator
     *  1.  Insert iterator
     *  2.  Stream iterator
     *  3.  Reverse iterator
     *  4.  Move iterator   (C++ 11)
     */

    //  1.Insert Iterator
        std::vector<int> myVect2 = {4,5};
        std::vector<int> myVect3 = {12,14,16,18};
        std::vector<int>::iterator iter = std::find(myVect3.begin(), myVect3.end(), 16);
        std::insert_iterator<std::vector<int> > i_itr(myVect3,iter);
        std::copy(myVect2.begin(), myVect2.end(),         //  source
            i_itr);                                       //  destination
        //  myVec3 = {12,14,4,5,16,18}
        //  Other insert iterators: back_insert_iterator, front_insert_iterator

    //  2. Stream Iterator
        std::vector<std::string> vec4;
        // Copy everything from input and copy to vec4
        copy(std::istream_iterator<std::string>(std::cin),std::istream_iterator<std::string>(),
             std::back_inserter(vec4));
        //Copy everything from vec4 and copy to output
        std::copy(vec4.begin(), vec4.end(), std::ostream_iterator<std::string>(std::cout, "Alo"));

        //  Make it terse;
        std::copy(std::istream_iterator<std::string>(std::cin),std::istream_iterator<std::string>(),
            std::ostream_iterator<std::string>(std::cout," \n"));

    //  3. Reverse Iterator:
        std::vector<int> vec5 = {1,2,3,4};
        std::reverse_iterator<std::vector<int>::iterator> reverseIter;
        for (reverseIter = vec5.rbegin(); reverseIter != vec5.rend(); ++reverseIter)
            std::cout << *reverseIter << std::endl;

    /*
     *  Algorithms
     *      - mostly loops
     */
        std::vector<int>vec6 = {4,2,5,1,3,9};
        std::vector<int>::iterator iterX = std::min_element(vec6.begin(), vec6.end()); // iterX -> 1

        //Note 1: Algorithm always process ranges in a half-open way:   [begin,end)
        std::sort(vec6.begin(), iterX);    //  vec6:   {2,4,5,1,3,9}
        std::reverse( iterX, vec6.end());  //  vec6:   {2,4,5,9,3,1}   iterX -> 9

        //Note 2:
        std::vector<int> vec7(3);
        std::copy(iterX, vec6.end(),        // Source
            vec7.begin());                     // Destination
        // vec7 needs to have at least space for 3 elements


    return 0;
}