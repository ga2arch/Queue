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
    
    class Node {
        
    public:
        T* elem;
        Node* next;
        Node* prev;
        
        Node(): elem(NULL), next(NULL), prev(NULL) {}
        Node(T* elem): elem(elem), next(NULL), prev(NULL) {}
        
        ~Node() {
            delete elem;
        }
    };
    
public:
    Queue(): head(NULL), last(NULL), len(0) {}
    
    Queue(const Queue<T>& q) {
        len = q.size();
        
        for(int i=0; i < len; i++) {
            push(*q.front());
            q.pop();
        }
    }
    
    Queue& operator=(const Queue<T>& q) {
        for(int i=0; i < len; i++) {
            pop();
        }
        
        len = q.size();
        
        for(int i=0; i < len; i++) {
            push(*q.front());
            q.pop();
        }
    }
    
    ~Queue() {
        Node* next = head;
        for(int i=0; i < len; i++) {
            Node* temp = next->next;

            delete next;
            
            next = temp;
        }
    }
    
    void push(T elem) {
        T* p_elem = new T(elem);
        Node* node = new Node(p_elem);

        if (!head) {
            head = node;  // [1]    [1]
            last = node;
            
        } else {
            last->next = node; // [1]-[2]  [1]-[2]
            node->prev = last;
            
            last = node;
        }
        
        len++;
    }
    
    void pop() {
        if (!len) throw empty();
        
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        
        len--;
        
        delete temp;
    }
    
    size_t size() const {
        return len;
    }
    
    T& front() {
        if (!len) throw empty();

        return *head->elem;
    }
    
    T& back() {
        if (!len) throw empty();

        return *last->elem;
    }
    
private:
    size_t len;
    Node* head;
    Node* last;
    
};

#endif /* defined(__Queue__Queue__) */
