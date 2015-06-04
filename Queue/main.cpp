//
//  main.cpp
//  Queue
//
//  Created by Gabriele Carrettoni on 04/06/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include <iostream>
#include "Queue.h"

using namespace std;

int main(int argc, const char * argv[]) {

    int temp = 2;
    
    Queue<int> q1;
    
    q1.push(1);
    q1.push(temp);
    
    
    cout << q1.front() << endl;
    cout << q1.back() << endl;

}
