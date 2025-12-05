#include <iostream>
#include <cstdlib>   // for atoi
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;

    /*
     Exercise 1:
     - If argument is 'x' → pop
     - Otherwise → push number
    */

    for(int i = 1; i < argc; i++){
        if(argv[i][0] == 'x'){
            s.pop();
        } else {
            s.push(atoi(argv[i]));
        }
    }

    return 0;
}
