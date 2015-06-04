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

    string temp = "ciao";
    
    Queue<string> q1;
    
    q1.push(temp);
    q1.push("lol");
    
    
    cout << q1.front() << endl;
    cout << q1.back() << endl;

}
