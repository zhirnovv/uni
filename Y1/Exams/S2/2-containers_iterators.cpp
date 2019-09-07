// Containers are a collection of templates and algorithms that implement common data structures.

#include <iostream>

// ---Sequence containers: can be accessed sequentially.---

#include <array> // static array, O(1) access, O(n) search
// at(), get(), operator [] (similar to c-style arrays), 
// front() - first element, back() - last element, 
// size(), max_size(), 
// swap() - swap elements of one array with others, empty() - check if array is empty


#include <vector> // dynamic array, O(1) access, O(n) search, insertion and deletion
// Iterators
// begin() === rend(), end() === rbegin(), - returns an iterator to the first element or the
// theoretical element after the last element in the vector
// cbegin() === crend(), cend() === crbegin() - returns a constant iterator to the first element or the theoretical element
// after the last element in the vector
// 
// Capacity
// size() - returns the amount of elements
// max_size() - maximum number of elements the vector can hold
// capacity() - returns the amount of memory allocated to vector
// empty() - checks if vector is empty
// shrink_to_fit() - reduces the capacity of the vector to stated size and deletes the rest
// reserve() - sets the vector capacity to stated amount of elements
//
// Element access
// via operator[], at(), front(), back(), data()
//
// Modifiers
// assign() - assigns new value to vector elements via replacing old ones
// push_back(), pop_back() - adds/removes an element from the back
// insert(), erase() - adds/removes new elements before the element at specified position
// swap() - swaps contents of one vector with another
// clear() - remove all elements of vector


#include <deque> // double ended queue, O(n) search and access, O(1) insertion and deletion
// all the functions from std::vector + push_front, pop_front


#include <forward_list> // single linked list implementation, same complexity as deque
// Modifiers
// assign() - assign values to forward list or assign repeated elements, replacing others,
// push_front() - insert element at first position on forward list by copying the value before the
// first element
// emplace_front() - element is created directly at the memory before the first element
// pop_front() - delete first element of the list
// insert_after() - insert element at any position via copying
// emplace_after() - insert element at any position by direct memory access
// erase_after() - delete element at any position
// remove(), remove_if() - remove particular element
// splice_after() - move elements from one forward list to the other


#include <list> // doubly linked list, same complexity as deque
// same as forward_list + push_back(), pop_back(), emplace_back()


// Associative containers: data structures that can be searched in O(log n) complexity
#include <set> // associative data structure where the value of the element can be used to find the element in the set,
// begin(), end(), ...
// insert(), erase() - add or remove a new element to the set
// lower_bound(), upper_bound() - returns an iteration to the first element that is equivalent to
// the input or will go after the input in the set
// find() - returns an iteration to the element


#include <map> // collection of key-value pairs, sorted by keys, keys are unique
// Operations are similar to set


// multisets and multiamps operate at the same premise with one difference: multisets and multimaps
// can store multiple instances of the same value


// Unordered associative containers implement unsorted data structures that can be searched within
// O(1) to O(n) bounds.
//
#include <unordered_set> // this data structure is implemented using a hash table, where keys are hashed into indices of this hash table
// In an unordered set keys are stored in any order, while in the regular set keys are ordered in a
// tree structure, which allows to lower complexity of operation from O(log n) to O(1). Operations
// are the same as in set except lower_bound() and upper_bound(), which are not present, and the
// addition of hash_function() 

#include <unordered_map> // collection of key-value pairs, keys are hashed into indices of a hash table, referring to the key gives us a value
// Complexity is reduced to O(1), as it is with unordered_set
// Methods are the same as map
