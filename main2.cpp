#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){

    Stack s;

    cout << "Checking the parentheses in argv arguments" << endl;

    for(int i = 1; i < argc; i++){
        for(int j = 0; j < strlen(argv[i]); j++){
            char c = argv[i][j];

            // Opening brackets → push
            if(c == '(' || c == '{' || c == '['){
                s.push(c);
            }

            // Closing brackets → pop & check
            else if(c == ')' || c == '}' || c == ']'){
                int top = s.pop();

                if( (c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[') ){
                    cout << "Unbalanced parentheses" << endl;
                    return 0;
                }
            }
        }
    }

    // If stack not empty → unbalanced
    if(s.pop() != -1){
        cout << "Unbalanced parentheses" << endl;
    } else {
        cout << "Balanced parentheses" << endl;
    }

    return 0;
}
