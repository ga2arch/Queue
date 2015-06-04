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
    
public:
    Queue(): _queue(NULL), len(0) {}
    
    Queue(const Queue<T>& q) {
        if (_queue) delete[] _queue;
        
        _queue = new T[q.size()];
        
        for(int i=0; i < q.size(); i++) {
            _queue[i] = q._queue[i];
        }
        
        len = q.size();
        
        return;
    }
    
    Queue& operator=(const Queue<T>& q) {
        if (_queue) delete[] _queue;
        
        _queue = new T[q.length()];
        
        for(int i=0; i < q.length(); i++) {
            _queue[i] = q._queue[i];
        }
        
        len = q.size();
        
        return;
    }
    
    ~Queue() {
        delete[] _queue;
    }
    
    void push(T elem) {
        T* temp = new T[++len]; // 1
        
        for(int i=0; i < len-1; i++) { // 0 < 0
            temp[i] = _queue[i];
        }
        
        temp[len-1] = elem; // 0
        
        if (_queue) delete[] _queue;
        _queue = temp;
        
        return;
    }
    
    void pop() {
        if (!len) throw empty();
        
        T* temp = new T[--len]; // 4
        
        for(int i=1; i < len; i++) { //1 - 4
            temp[i-1] = _queue[i]; // 0 - 1 - 2 - 3
        }
        
        delete[] _queue;
        _queue = temp;
        
        return;
    }
    
    size_t size() const {
        return len;
    }
    
    T& front() {
        if (!len) throw empty();

        return _queue[0];
    }
    
    T& back() {
        if (!len) throw empty();

        return _queue[len-1];
    }
    
private:
    size_t len;
    T* _queue;
    
};

#endif /* defined(__Queue__Queue__) */
