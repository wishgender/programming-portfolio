//
// File: stack.hpp
//
// Programmer: Lazuli Rogers | aroger52
// Date:       Fall 2024
//
//-----------------------------------------------------------------------------
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//-----------------------------------------------------------------------------
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <iostream>
#include <new>
#include <cassert>


template<typename T> 
class Node {
public:
	Node();
	Node (const T& val);
	T data;
	Node<T>* next;
};


// CLASS INV:
//
template <typename T>
class stack {
	public:
              stack     ();
              stack     (const stack<T>&);
              
              stack     (const T&);

              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>); 
    
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

    friend void printPopDebug(T&);
    friend void printPushDebug(T&);
    friend void printPostDebug(T&);

private:
	Node<T>   *tos;
};

//=========================================================================//
//=Node Constructors

template <typename T>
Node<T>::Node() {
    next = nullptr;
}

template <typename T>
Node<T>::Node(const T& val) {
    data = val;
    next = nullptr;
}


//=========================================================================//
//=Constructors

//default constructor
template <typename T>
stack<T>::stack() : tos() {
    tos = 0;
}

//constructor from T data
template <typename T>
stack<T>::stack(const T& val) {
    tos = 0;
    Node<T>* temp = new Node<T>(val);
    temp->next = tos;
    tos = temp;
}

//=========================================================================//
//=Big 4 (copy ctor, swap, overload assignment, dtor)

//copy constructor
template <typename T>
stack<T>::stack(const stack<T>& copy) : stack() {
    Node<T>* temp = copy.tos;
    Node<T>* bottom;

    while(temp != 0) {
        if (tos == 0) {
            tos = new Node <T>(temp->data);
            bottom = tos;
        }

        else {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }

        temp = temp->next;
    }

}

//swap method
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T>* temp = rhs.tos;
    rhs.tos = tos;
    tos = temp;
}

//overloaded assignment
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
    swap(rhs); return *this;
}

//destructor
template <typename T>
stack<T>::~stack<T>() {
    Node<T>* temp = tos;

    while(tos != nullptr) {
        tos = tos->next;
        delete temp;
        temp = tos;
    }
}

//=========================================================================//
//=Mutators

//push (add to stack)
template <typename T>
void stack<T>::push(const T& val) {
    assert(!full());
    Node<T>* temp = new Node<T>(val);
    temp->next = tos;
    tos = temp;
}

//pop (remove from stack) 
template <typename T>
T stack<T>::pop() {
	if(empty()) {
		std::cerr << "Error: stack is empty--cannot pop" << std::endl;
		exit(3);
	};
	
	Node<T>* temp = tos;
	T returnData = tos->data;
	tos = tos->next;
	delete temp;
	return returnData;
}

//=========================================================================//
//=Accessors

//access top element
template <typename T>
T stack<T>::top() const {
    assert(!empty());
    return tos->data;
}

//=========================================================================//

//check if full
template <typename T>
bool stack<T>::full() const {
    Node<T>* temp = new(std::nothrow) Node<T>();
    if(temp == 0) return true;
    delete temp;
    return false;
}

//check if empty
template <typename T>
bool stack<T>::empty() const {
    return tos == 0; 
}

//=========================================================================//
//=Debug Push/Pop (for use with test cases)

template <typename T>
void printPushDebug(T& obj) {
	if(obj.empty()) std::cout << "currently empty\n";
	else std::cout << "current tos: |" << obj.top() << '|' << std::endl;
	
};

template <typename T>
void printPopDebug(T& obj) {
	if(!obj.empty()) {
        std::cout << "current tos: |" << obj.top() << '|' << std::endl;
    }
    else std::cout << "currently empty\n";
    std::cout << "popping |" << obj.top() << "| off of the stack\n";

};

template <typename T>
void printPostDebug(T& obj) {
    if (!obj.empty()) std::cout << "new tos: |" << obj.top() << "|\n" << std::endl;
    else std::cout << "now empty\n";
}

#endif //CS2_STACK_HPP_
