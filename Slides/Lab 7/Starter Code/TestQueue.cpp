//
//  TestQueue.cpp
//  122 Lab 7
//
//  Created by main on 2/24/24.
//

#include <iostream> // cout, endl

#include "TestQueue.hpp"

// TODO: Implement the test functions

using std::cout;
using std::endl;

void TestQueue::resetQueue() {
    teardownQueue();
    setupEmptyQueue();
}

void TestQueue::teardownQueue() {
    // Destroy the queue
    
    delete queue;
}

void TestQueue::setupEmptyQueue() {
    queue = new Queue<string>();
}

TestQueue::TestQueue() {
    // Change this if you want to initally test non-empty queue
    setupEmptyQueue();
}

TestQueue::~TestQueue() {
    teardownQueue();
}

void TestQueue::testEnqueueEmpty() {
    resetQueue();
    
    // TODO: Call enqueue
    
    // TODO: Check value returned
    
    // TODO: Manually go through queue and check the values of each node
    // Hint: There should only be one and it needs to be the exact
    // data you inputted. You must use valid data.
}

void TestQueue::testEnqueueNonEmpty() {
    resetQueue();
    
    // TODO: Manually Add data to the queue and link head/tail
    
    // TODO: Call enqueue
    
    // TODO: Check value returned
    
    // TODO: Manually go through queue and check the values of each node
    // Hint: There should be two and they need to be the exact
    // data you inputted. You must use valid data.
}


void TestQueue::testDequeueEmpty() {
    resetQueue();
    
    // TODO: Call dequeue
    
    // TODO: Check value returned
    
    // TODO: Manually go through queue and check the values of each node
    // Hint: If you only have one node in the list, then it should be
    // empty at this point. But, we cannot call isEmpty!
}


void TestQueue::testDequeueNonEmpty() {
    resetQueue();
    
    // TODO: Manually add data to the queue and link head/tail
    
    // TODO: Call dequeue
    
    // TODO: Check value returned
    
    // TODO: Manually go through queue and check the values of each node
    // Hint: If you only have one node in the list, then it should be
    // empty at this point. But, we cannot call isEmpty!
}

void TestQueue::testIsEmptyEmpty() {
    resetQueue();
    
    // TODO: Check if isEmpty returns true
    
}

void TestQueue::testIsEmptyNonEmpty() {
    resetQueue();
    
    // TODO: Manually add data to the queue and link head/tail
    
    // TODO: Check if isEmpty returns false
    
}
