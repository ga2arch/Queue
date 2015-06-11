//
//  Queue.h
//  Queue
//
//  Created by Gabriele Carrettoni on 04/06/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#ifndef __Queue__Queue__
#define __Queue__Queue__

#include <stdio.h>
#include <cstddef>
#include <stdexcept>

struct empty: public std::runtime_error {
    empty(): std::runtime_error("Queue is empty") {}
};

template <typename T>
class Queue {
    
private:
    /**
     Comodity function to easily display the content of a SparseMatrix.
     @param os stream to write on
     @param sm reference of the matrix to write
     @return output stream
     */
    friend std::ostream& operator<<(std::ostream &os, const Queue &q) {
        for (const T& elem: q) {
            os << elem << "\n";
        }
        return os;
    }
    
public:
    struct Node {
        T* elem;
        Node* next;
        
        Node(): elem(NULL), next(NULL) {}
        Node(T* elem): elem(elem), next(NULL) {}
        
        ~Node() {
            delete elem;
        }
    };
    
    class const_iterator;
    
    class iterator {
        //
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T                         value_type;
        typedef ptrdiff_t                 difference_type;
        typedef value_type*               pointer;
        typedef value_type&               reference;
        
        /**
         Copy constructor
         @param other reference to the iterator to copy.
         */
        iterator(const iterator &other) {
            head = other.head;
        }
        
        /**
         Assignment
         @param other reference to the iterator to copy.
         */
        iterator& operator=(const iterator &other) {
            head = other.head;
            return *this;
        }
        
        /**
         Dereference pointer
         */
        reference operator*() const {
            return *head->elem;
        }
        
        /**
         Return pointer
         @returns pointer to the current element.
         */
        pointer operator->() const {
            return head->elem;
        }
        
        /**
         Post-increment operator;
         @returns iterator not incremented;
         */
        iterator operator++(int) {
            head = head->next;
            return iterator(head);
        }
        
        /**
         Pre-increment operator;
         @returns iterator incremented;
         */
        iterator& operator++() {
            head = head->next;
            return *this;
        }
        
        /**
         Equality operator, check if the two iterators point to the same element
         @param other reference to the other iterator
         */
        bool operator==(const iterator &other) const {
            return head == other.head;
        }
        
        /**
         Inequality operator, check iif the two iterators
         don't point to the same element
         @param other reference to the other iterator
         */
        bool operator!=(const iterator &other) const {
            return head != other.head;
        }
        
        friend class const_iterator;
        
        /**
         Equality operator, check if the two iterators point to the same element.
         @param other reference to the other const_iterator
         */
        bool operator==(const const_iterator &other) const {
            return head == other.head;
        }
        
        /**
         Inequality operator, check if the two iterators
         don't point to the same element.
         @param other reference to the other const_iterator
         */
        bool operator!=(const const_iterator &other) const {
            return head != other.head;
        }
        
        
    private:
        Node* head;
        size_t pos;
        
        friend class Queue;
        
        explicit iterator(Node* h): head(h), pos(0) {}
        explicit iterator(Node* h, size_t p): head(h), pos(p) {}

    };
    
    class const_iterator {
        //
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef const T                   value_type;
        typedef ptrdiff_t                 difference_type;
        typedef value_type*               pointer;
        typedef value_type&               reference;
        
        /**
         Copy constructor
         @param other reference to the iterator to copy.
         */
        const_iterator(const iterator &other) {
            head = other.head;
        }
        
        /**
         Assignment
         @param other reference to the iterator to copy.
         */
        const_iterator& operator=(const iterator &other) {
            head = other.head;
            return *this;
        }
        
        /**
         Dereference pointer
         */
        reference operator*() const {
            return *head->elem;
        }
        
        /**
         Return pointer
         @returns pointer to the current element.
         */
        pointer operator->() const {
            return head->elem;
        }
        
        /**
         Post-increment operator;
         @returns iterator not incremented;
         */
        const_iterator operator++(int) {
            head = head->next;
            return iterator(head);
        }
        
        /**
         Pre-increment operator;
         @returns iterator incremented;
         */
        const_iterator& operator++() {
            head = head->next;
            return *this;
        }
        
        /**
         Equality operator, check if the two iterators point to the same element
         @param other reference to the other iterator
         */
        bool operator==(const const_iterator &other) const {
            return head == other.head;
        }
        
        /**
         Inequality operator, check iif the two iterators
         don't point to the same element
         @param other reference to the other iterator
         */
        bool operator!=(const const_iterator &other) const {
            return head != other.head;
        }
        
    private:
        Node* head;
        
        friend class Queue;
        
        const_iterator(Node* h): head(h) {}
    };
    
    
    /**
     Costructor
     */
    Queue(): head(NULL), last(NULL), len(0) {}
    
    /**
     Copy Costructor
     @param q Queue to copy
     */
    Queue(const Queue<T>& q): head(NULL), last(NULL), len(0) {
        for (typename Queue<T>::const_iterator itr = q.begin(); itr != q.end(); itr++) {
            push(*itr);
        }
    }
    
    /**
     Costructor from iterator pair
     @param begin first iterator
     @param end second iterator
     */
    template <typename Iterator>
    Queue(Iterator begin, Iterator end): head(NULL), last(NULL), len(0) {
        for (; begin != end; begin++)
            push(*begin);
    }
    
    /**
     Assignment operator
     @param q Queue
     */
    Queue& operator=(const Queue<T>& q) {
        for(; len > 0; pop()) {}

        for(int i=0; i < q.size(); i++) {
            push(q.front());
        }
        
        return *this;
    }
    
    /**
     Decostructor
     */
    ~Queue() {
        for(; len > 0; pop()) {}
    }
    
    /**
     Put an element at the top of the queue
     @param elem T
     */
    void push(T elem) {
        T* p_elem = new T(elem);
        Node* node = new Node(p_elem);

        if (!head) {
            head = node;
            last = node;
            
        } else {
            last->next = node;
            last = node;
        }
        
        len++;
    }
    
    /**
     Pop an element from the top of the queue
     */
    void pop() {
        if (!size()) throw empty();
        
        Node* temp = head;
        head = temp->next;
        
        len--;
        
        delete temp;
    }
    
    /**
     Returns the number of element in the queue
     @returns size_t
     */
    size_t size() const {
        return len;
    }
    
    /**
     Returns a reference to the first element of the queue
     */
    T& front() const {
        if (!size()) throw empty();

        return *head->elem;
    }
    
    /**
     Returns a reference to the last element of the queue
     */
    T& back() const {
        if (!size()) throw empty();

        return *last->elem;
    }
    
    /**
     Return the const_iterator, pointing at the first element
     @returns the const_iterator
     */
    iterator begin() {
        return iterator(head);
    }
    
    /**
     Return the iterator, pointing at the last element
     @returns the iterator
     */
    iterator end() {
        return iterator(last->next);
    }
    
    
    /**
     Return the iterator, pointing at the first element
     @returns the const_iterator
     */
    const_iterator begin() const {
        return iterator(head);
    }
    
    /**
     Return the const_iterator, pointing at the last element
     @returns the const_iterator
     */
    const_iterator end() const {
        return iterator(last->next);
    }
    
private:
    size_t len;
    Node* head;
    Node* last;
    
};

/**
 Take a queue and two functions, returns a modified queue where the elements
 that pass the first function get modified by the second
 @param q Queue
 @param p The function that select the elements to modify
 @param f The function that modify an element
 */
template <typename T, typename P, typename F>
void transformif(Queue<T>& q, P pred, F func) {
    
    for (typename Queue<T>::iterator itr = q.begin(); itr != q.end(); ++itr) {
        if (pred(*itr)) {
            *itr = func(*itr);
        }
    }
}

#endif /* defined(__Queue__Queue__) */
