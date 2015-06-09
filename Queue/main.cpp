//
//  main.cpp
//  Queue
//
//  Created by Gabriele Carrettoni on 04/06/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Queue<string> q1;
    q1.push("ciao");
    q1.push("come");
    
    transformif(q1, [](string x){ return x == "ciao"; }, [](string x){ return "bella"; });
    
    for (auto n: q1)
        cout << n << endl;
}
