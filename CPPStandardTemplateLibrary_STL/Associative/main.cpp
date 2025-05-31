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

int main()
{
    /*
     *  Associative Container
     *
     *  Always sorted, default criteria is <     ,less than
     *
     *  No push_back(), push_front()
     *
     */

    /*
     * set
     * - Insert item will be automatic sorted
     * - No duplicates
     */
        std::set<int> mySet;
        mySet.insert(3);                        // mySet:   {3}
        mySet.insert(1);                        // mySet:   {1,3}
        mySet.insert(7);                        // mySet:   {1,3,7},    O(log(n))

        std::set<int>::iterator it;
        it = mySet.find(7);                   // O(log(n)), it points to 7
                                            // Sequence containers don't even have find() member function

        std::pair<std::set<int>::iterator, bool> ret;
        ret = mySet.insert(3);                  // no new element inserted
        if (ret.second== false)
            it = ret.first;                         // "it" now points to 3

        mySet.insert(it,9);                 //  mySet: {1,3,7,9}
                                                   // it still points to 3
        mySet.erase(it);                        //  mySet: {1,7,9}
        mySet.erase(7);                      //  mySet: {1,7}

        // Note: none of sequences containers provide this king of erase;

    /*
     * multiset is a set that allows duplicated items
     */
        std::multiset<int> myMultiSet;

    // set/multiset: value of the elements cannot be modified
    //*it = 10;       //  *it is read-only
    /*
     *  Properties:
     *  1.  Fast search: O(log(n))
     *  2.  Traversing is slow  (compared to vector & deque)
     *  3.  No random acess, no [] operator
     */

    /*
     *  map
     *  - sorted by key
     *  - No duplicated key
     */
        std::map<char,int>  myMap;
        myMap.insert(std::pair<char,int>('a',100));
        myMap.insert(std::make_pair('z',200));
        //
        std::map<char,int>::iterator mapIt = myMap.begin();
        myMap.insert(mapIt,std::pair<char,int>('b',300));       //it is a hint
        //
        mapIt = myMap.find('z');       //O(log(n))
        //
        // //showing contents:
        for (mapIt = myMap.begin(); mapIt != myMap.end(); ++mapIt)
        {
            std::cout << (*mapIt).first << " => " << (*mapIt).second << std::endl;
        }

    return 0;
}