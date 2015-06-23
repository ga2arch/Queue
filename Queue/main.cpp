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

void test_copy_ctor_primitive() {
    cout << "COPY CTOR: ";
    
    Queue<int> q1;
    
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    Queue<int> q2(q1);
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_copy_ctor_complex() {
    cout << "COPY CTOR: ";
    
    Queue<string> q1;
    
    q1.push("ciao");
    q1.push("come");
    q1.push("va");
    
    Queue<string> q2(q1);
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_copy_assign_primitive() {
    cout << "COPY ASSIGN: ";
    
    Queue<int> q1;
    
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    Queue<int> q2 = q1;
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_copy_assign_complex() {
    cout << "COPY ASSIGN: ";
    
    Queue<string> q1;
    
    q1.push("ciao");
    q1.push("come");
    q1.push("va");
    
    Queue<string> q2 = q1;
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_from_iter_primitive() {
    cout << "FROM ITER: ";
    
    vector<int> v{1,2,3};
    
    queue<int> q1;
    
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    Queue<int> q2(v.begin(), v.end());
        
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void test_from_iter_complex() {
    cout << "FROM ITER: ";
    
    vector<string> v{"ciao", "come", "va"};
    
    queue<string> q1;
    
    q1.push("ciao");
    q1.push("come");
    q1.push("va");
    
    Queue<string> q2(v.begin(), v.end());
    
    while (q1.size() > 0) {
        assert(q1.front() == q2.front());
        q1.pop();
        q2.pop();
    }
    
    cout << "PASSED" << endl;
}

void t() {
    Queue<string> q1;
    q1.push("ciao");
    q1.push("topkek");
    std::cout << q1.front();
    q1.pop();
}

int main(int argc, const char * argv[]) {
    cout << "== TESTING PRIMITIVE TYPES ==\n" << endl;
    test_push_pop_primitive();
    test_copy_ctor_primitive();
    test_from_iter_primitive();
    test_copy_assign_primitive();
    
    cout << "\n== TESTING COMPLEX TYPES ==\n" << endl;
    
    test_push_pop_complex();
    test_copy_ctor_complex();
    test_from_iter_complex();
    test_copy_assign_complex();
    //test_transformif_complex();
}
