#include<iostream>

using namespace std; 

/* Types of continers
 * Sequence (array and Linkedlist)
 * Associative (binary trees) They are always sorted
 * Unordered (hash table)
*/

// STL headers (mostly self explanatory)

#include <vector>
#include <deque>
#include <list>
#include <set> // set and multiset
#include <map> // map and multimap
#include <unordered_set> // unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm> // Most algorithms
#include <numeric> // some numeric algorithms
#include <functional>

int main() {
    // Vector
    // It is a dynamically allocated contiguous array that grows in one direction
    vector<int> vec; // vec.size() == 0
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3); // vec.size() == 3

    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) 
        cout << *it << " ";
    cout << endl;

    // you can have fun with pointers too
    int *p = &vec[0];
    cout << *(p+2) << endl;

    /* Some common APIs 
     * vec.size()               gives size of the container
     * Vector<int> vec2(vec)    Copy constructor
     * vec.clear()              Removes all items in vec
     * vec2.swap(vec)           swaps the elemets of two vectors
    */

    // Deque
    // Can add data in front as well as the back

    deque<int> dq = {6,9,12};
    dq.push_back(15); // dq: {6,9,12,15}
    dq.push_front(3); // dq: {3,6,9,12,15}

    for(auto i:dq) 
        cout << i << " ";
    cout << endl;

    // Deque is not contiguous but does provide random access to the elements

    // List
    // It is a doubly linked linked list

    list<int> lst = {2,4,6};
    lst.push_back(8);
    lst.push_front(0); 
    cout << endl;
    // List: {0,2,4,6,8}
    // Does not have random accessing

    list<int>::iterator li = find(lst.begin(),lst.end(),4);
    lst.insert(li,5); // {0,2,5,4,6,8} apparently inserts at the previous pos
    li++; // points to 6
    lst.erase(li); // {0,2,5,4,8}
    for(auto i:lst) cout << i << " ";
    // Do not used an erased iterator again

    list<int> ls2;
    // splice moves data from one list to another in constant time
    ls2.splice(ls2.begin(),lst,find(lst.begin(),lst.end(),5),lst.end());

    // lst {0,2}
    // ls2 {5,4,8}

    cout << endl;
    for(auto i: lst)  cout << i << " ";
    cout << endl; 
    for(auto i: ls2)  cout << i << " ";

    // Forward list is similar to list but only points forward

    // Array is a thin layer on normal arrays
    // Helps use all the cool stuff that comes with stl on a normal array
    // However, size is fixed and two arrays may be of different types
    // array<int,4> and array<int,3> are of different types and a functions would treat them as different 

}