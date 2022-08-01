#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    Integer_t,
    Add_T,
    Subtract_T,
    Multiply_T,
    Fibonacci_T
} TypeTag;

//You have a struct defined as:
typedef struct Node {
     TypeTag type;
     int num; 
     //Because when we pass left and right nodes to functions
     //we need to be able to access it's integer values
} Node;

//For this assignment, finish defining these structs:
typedef struct Integer {
     TypeTag type;
    //Finish
} Integer;

typedef struct Add {
     TypeTag type;
    //Finish
} Add;

typedef struct Subtract {
     TypeTag type;
    //Finish
} Subtract;

typedef struct Multiply {
     TypeTag type;
    //Finish
} Multiply;

typedef struct Fibonacci {
     TypeTag type;
    //Finish
} Fibonacci;

//and Implement the following functions:
Node *makeIntegerNode(int i){
    Node * ptrnode;
    ptrnode = malloc(sizeof(Node));
    //ptrnode = &newnode;
    ptrnode->type = Integer_t;
    ptrnode->num = i;
    return ptrnode;
}

Node *makeAddFunc(Node *left, Node *right){
    Node * ptrnode;
    ptrnode = malloc(sizeof(Node));
    //ptrnode = &newnode;
    ptrnode->type = Add_T;
    ptrnode->num = left->num + right->num;
    return ptrnode;
} 

Node *makeSubFunc(Node *left, Node *right){
    Node * ptrnode;
    ptrnode = malloc(sizeof(Node));
    //ptrnode = &newnode;
    ptrnode->type = Subtract_T;
    ptrnode->num = left->num - right->num;
    return ptrnode;
}

Node *makeMultipleFunc(Node *left, Node *right){
    Node * ptrnode;
    ptrnode = malloc(sizeof(Node));
    //ptrnode = &newnode;
    ptrnode->type = Multiply_T;
    ptrnode->num = left->num * right->num;
    return ptrnode;
}

Node *makeFibFunc(Node *node){
    //Assuming Fibonacci number is >=1
    Node * ptrnode;
    ptrnode = malloc(sizeof(Node));
    int fib[node->num + 1];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<node->num;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    
    
    //ptrnode = &newnode;
    ptrnode->type = Fibonacci_T;
    ptrnode->num = fib[node->num - 1];
    return ptrnode;
}

void calc(Node *node){
    //printf("%d", node->num);
    if(node->type == Add_T){
        printf("- add : %d\n", node->num);
    }
    else if(node->type == Subtract_T){
        printf("- sub : %d\n", node->num);
    }
    else if(node->type == Multiply_T){
        printf("- mul : %d\n", node->num);
    }
    else if(node->type == Integer_t){
        printf("- int : %d\n", node->num);
    }
    else{
        printf("- fibo : %d\n", node->num);
    }
}

//Such that the main function defined as:
int main(){
Node *ten = makeIntegerNode(10);
Node *six = makeIntegerNode(6);
Node *five = makeIntegerNode(6);
Node *four = makeIntegerNode(4);
Node *add = makeAddFunc(ten, six);
Node *mul = makeMultipleFunc(five, four);
Node *sub = makeSubFunc(mul, add);
Node *fibo = makeFibFunc(sub); // Get n-th from fibonacci numbers.

//printf("%d\n", ten->num);

//calc(ten);
calc(add);
calc(mul);
calc(sub);
calc(fibo);
}