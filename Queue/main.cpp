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

    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    
    for (auto n: q1) {
        cout << n << endl;
    }
}
