//
//  Queue.hpp
//  122 Lab 7
//
//  Created by main on 2/24/24.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <ostream>

#include "QueueNode.hpp"

// We can references like to avoid including a header file
// when we simply need a symbol. We use this reference so
// the friend operator will work. Keep in mind that friend
// is typically not what we want to do, but it will work
// for this scenario.
class TestQueue;

template <class T>
class Queue {
    QueueNode<T> * tail;
    QueueNode<T> * head;
    
    void printQueue(QueueNode<T> * node);
    
public:
    Queue();
    // Default Constructor 
    // *Copy Constructor // This must be a deep copy constructor
    // *Copy from std::vector // This must also be a deep copy
    
    // isEmpty // returns if list is empty
    // enqueue // insert node at tail, optionally return data that was enqueued
    // dequeue // remove from head & return
    void printQueueRecursive(void);
    
    friend TestQueue;
};

template <class T>
std::ostream &operator<<(std::ostream& lhs, QueueNode<T> rhs) {
    // TODO: Print output
    // Hint: Use functions that already exist
    
    // although rhs is a template class, there is no difference
    // in the way we print stuff.
    
    return lhs;
}


#endif /* Queue_hpp */
