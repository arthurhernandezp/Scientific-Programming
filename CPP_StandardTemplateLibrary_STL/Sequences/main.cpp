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
 *  Sequence Containers(array and linked list)
 *      --- vector, deque, list, forward list,array
 */

int main()
{
    /*
     *  Vector: Dynamic array thats grows in one direction
     *
     *  Properties of Vector:
     *   1. fast insert/remove at the end: O(1)
     *   2. slow insert/remove at the begining or in the middle: O(n)
     *   3. slow search: O(n)
     *
     */
        std::vector<int> vec;       //  vec.size() == 0
        vec.push_back(4);
        vec.push_back(1);
        vec.push_back(8);         //  vec: {4,1,8};     vec.size == 3

        // Vector specific operations;
        std::cout << vec[2] << std::endl;         // (no range check)
        std::cout << vec.at(2) << std::endl;    // (throw range_error exception of out of range)

        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << std::endl;

        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << std::endl;

        for (const auto & it: vec)      //C++ 11
            std::cout << it << std::endl;

        //  Vector is a dynamically allocated contiguous array in memory
        int *p = &vec[0];

        //  Commom member functions of all containers
        //  vec: {4,1,8}
        if (vec.empty()) { std::cout << "Not possible" << '\n'; }
        std::cout << vec.size() << std::endl;
        std::vector<int> vec2(vec);         //Copy constructor
        vec.clear();            // Remove all items in vec; vec.size() == 0
        vec2.swap(vec);      //vec2 becomes empty, and vec has 3 items

        //  Notes: No penalty of abstraction, very efficient

    /*
     *  Deque: Dynamic array thats grows in both direction
     *
     *  Properties of Deque:
     *   1. fast insert/remove at the begining and the end: O(1)
     *   2. slow insert/remove in the middle: O(n)
     *   3. slow search: O(n)
     *
     */

        std::deque<int> deq = {4,6,7};
        deq.push_front(2);              //  deq: {2,4,6,7}
        deq.push_back(3);               //  deq:{2,4,6,7,3}

        //  Deque has similar interface with vector
        std::cout << deq[1] << std::endl;

    /*
    *  List: Double linked list
    *
    *  Properties of Deque:
    *   1. fast insert/remove at any place: O(1)
    *   2. slow search: O(n)
    *   3. no random access, no [] operator
    */

        std::list<int> myList = {5,2,9};
        myList.push_back(6);            //  myList: {5,2,9,6}
        myList.push_front(4);           //  myList: {4,5,2,9,6}

        std::list<int>::iterator itr = find(myList.begin(), myList.end(), 2);   //itr: 2
        myList.insert(itr, 8);      //  myList: {4,5,8,2,9,6}
        itr++;
        myList.erase(itr);
    return 0;
}