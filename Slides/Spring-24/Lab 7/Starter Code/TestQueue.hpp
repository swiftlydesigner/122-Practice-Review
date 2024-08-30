//
//  TestQueue.hpp
//  122 Lab 7
//
//  Created by main on 2/24/24.
//

#ifndef TestQueue_hpp
#define TestQueue_hpp

#include <string>

#include "Queue.hpp"

using std::string;

class TestQueue {
    Queue<string> * queue;
    
    void resetQueue();
    
    void teardownQueue();
    
    void setupEmptyQueue();
    
public:
    TestQueue();
    
    ~TestQueue();
    
    void testEnqueueEmpty();
    
    void testEnqueueNonEmpty();
    
    void testDequeueEmpty();
    
    void testDequeueNonEmpty();
    
    void testIsEmptyEmpty();
    
    void testIsEmptyNonEmpty();
};

#endif /* TestQueue_hpp */
