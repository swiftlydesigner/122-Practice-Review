//
//  QueueNode.hpp
//  122 Lab 7
//
//  Created by main on 2/24/24.
//

#ifndef QueueNode_hpp
#define QueueNode_hpp

template <class T>
class QueueNode {
    T data;
    QueueNode<T> * next;
    
public:
    QueueNode(T newData = T(), QueueNode<T> * next = nullptr);
    
    QueueNode(QueueNode& other);
    
    // Why have these getters and setters? Because this
    // is a way of data hiding so external entites cannot
    // directly modify these values. Also, we can easily
    // restrict access by remove one of these functions.
    // If we have a public var and want to change it later,
    // then we need to add a setter or getter (depending on
    // our change) then change every reference to it.
    //
    
    
    // FUNC_NAME -> RETURN_TYPE
    T getData();
    
    T setData(T newData);
    
    QueueNode<T> * getNext();
    
    QueueNode<T> * setNext(QueueNode<T> * newNext);
    
    // Good note on CWE 495 from https://stackoverflow.com/questions/32795005/reference-return-for-setter
    //
    // Note on returning references to private or protected members:
    // Returning a reference to your internal members in general
    // is not recommended since this way you give an easy access
    // to others so they could change your object internal state
    // without using any method provided by the object's class API.
    // Thus, it will be very difficult to track this kind of changes
    // in the code. In general changes in the internal state of an
    // object should only be possible through methods that belongs
    // to the class API.
};

#endif /* QueueNode_hpp */
