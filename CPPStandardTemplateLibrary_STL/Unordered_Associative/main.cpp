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
 *  Unordered Containers: Implemented with hash table( array of linked list )
 *  Array of buckets and the linked list is Entries
 */

int main()
{
    /*
     *  unordered set
     */
        std::unordered_set<std::string> mySet   =   {"red","green","blue"};
        std::unordered_set<std::string>::iterator it = mySet.find("green");     //O(1)
        if (it != mySet.end())              // Very important check
            std::cout << *it << std::endl;

        mySet.insert("yellow");     //O(1)
        std::vector<std::string> vec = {"purple","blue"};
        mySet.insert(vec.begin(),vec.end());

        // Hash table specific APIs:
        std::cout << "load_factor =  " << mySet.load_factor() << std::endl;
        std::string x = "red";
        std::cout << x << " is in bucket #" << mySet.bucket(x) << std::endl;
        std::cout << "Total bucket #" << mySet.bucket_count() << std::endl;

    //  unordered multiset: unordered set that allows duplicated elements
    //  unordered map:  unordered set of pairs
    //  unordered multimap: unordered map that allows duplicated elements

    //  hash collision => performance degrade
    //  hash collision: Many items are inserted at the same bucket, so they created a hash table
    //  so the time to search will grow to linear time o(n)

    /*
     *  Properties of Unordered Containers:
     *  1.  Fastest search/insert at any place: O(1)
     *      Associative container takes O(log(n))
     *      vector, deque takes O(n)
     *      lists takes O(1) to insert, O(n) to search
     *
     *  2.  Unordered set/multiset: element value cannot be changed
     *      Unordered map/multimap: element key cannot be changed
     */

    return 0;
}