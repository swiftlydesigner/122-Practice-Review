//
//  QueueNode.cpp
//  122 Lab 7
//
//  Created by main on 2/24/24.
//

#include "QueueNode.hpp"


template <class T>
QueueNode<T>::QueueNode(T newData, QueueNode<T> * next) {
    // TODO: Must implement
    // Note: Both functions have default values
}


template <class T>
QueueNode<T>::QueueNode(QueueNode& other) {
    // Info: Low priority implementation
    // If you do not get to this, no problem.
}

template <class T>
T QueueNode<T>::getData() {
    // TODO: Implement this method
}

template <class T>
T QueueNode<T>::setData(T newData) {
    // TODO: Implement this method
    // Return the old pointer
}

template <class T>
QueueNode<T> * QueueNode<T>::getNext() {
    // TODO: Implement this method
}

template <class T>
QueueNode<T> * QueueNode<T>::setNext(QueueNode<T> * newNext) {
    // TODO: Implement this method
    // Return the old pointer
}
