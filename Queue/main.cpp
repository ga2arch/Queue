//
//  main.cpp
//  Queue
//
//  Created by Gabriele Carrettoni on 04/06/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include "Queue.h"

using namespace std;

void test_push_pop_primitive() {
    cout << "PUSH/POP: ";
    
    Queue<int> q1;
    queue<int> q2;
    
    q1.push(1);
    q2.push(1);
    
    q1.push(2);
    q2.push(2);
    
    q1.push(3);
    q2.push(3);
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_push_pop_complex() {
    cout << "PUSH/POP: ";
    
    Queue<string> q1;
    queue<string> q2;
    
    q1.push("ciao");
    q2.push("ciao");
    
    q1.push("come");
    q2.push("come");
    
    q1.push("va");
    q2.push("va");
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

int main(int argc, const char * argv[]) {
    
    test_push_pop_primitive();
    
}
