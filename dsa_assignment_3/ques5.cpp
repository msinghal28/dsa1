#include <bits/stdc++.h>   //includes everything,
#include <stdio.h>
#include <ctype.h>   
#include <stdlib.h>  
#define STACK_SIZE 100  
int myStack[STACK_SIZE];
int topIdx = -1;  

void push(int num) {
    if (topIdx >= STACK_SIZE - 1) {
        printf("!! Stack Overflow (oops)\n");
        return;  
    }
    myStack[++topIdx] = num;
}


int pop() {
    if (topIdx < 0) {
        printf("!! Stack Underflow\n");  
    }
    return myStack[topIdx--];
}

// Evaluates a postfix expression given as a string
// Example input: "231*+9-"
int evalPostfix(char *exp) {
    int i = 0; // note: I like explicit initialization here
    
    
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            
            int val = exp[i] - '0';
            push(val);
        } else {
            
            int right = pop();   
            int left = pop();    

           
            switch (exp[i]) {
                case '+': push(left + right); break;
                case '-': push(left - right); break;
                case '*': push(left * right); break;
                case '/': 
                    if (right == 0) {
                        printf("Divide by zero? Not allowed!\n");
                        push(0); 
                    } else {
                        push(left / right);
                    }
                    break;
                default: 
                    printf("Unknown operator: %c\n", exp[i]);
                    
            }
        }
        i++; 
    }

    
    return pop();
}

int main() {
  
    char exp[] = "231*+9-";  // ((2 + (3 * 1)) - 9)
    printf("Postfix Expression: %s\n", exp);

    int result = evalPostfix(exp);

    printf("Evaluated Result = %d\n", result);

    
    return 0;
}
