# Container adaptors

## Stack

### Definition
A *stack* is a container adaptor with LIFO access method implemented. A new element is added at the
top and the top element is also removed from the top.

### Complexity
Complexity of all stack operations is O(1).

### Operations
* empty() - check if stack is empty
* size() - return stack size
* push() - add an element to the top
* pop() - remove the element from the top.

## Queue

### Definition
A _queue_ is a container adaptor with FIFO access method implemented. Elements are inserted at the
back and deleted from the front.

### Complexity
Complexity of all queue operations is O(1).

### Operations
* empty()
* size()
* front() - first element
* back() - last element
* push() - add an element at the end of the queue
* pop() - delete the first element of the queue

## Priority queue

### Definition
A priority queue is a container adaptor where the first element of the queue is the greatest of all
elements in the queue and elements are in a non-decreasing order.

### Complexity 
Priority queue insertion and deletion is O(n log n).

### Operations
Same as in queue.
