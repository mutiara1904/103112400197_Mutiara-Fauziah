#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define MaxEl 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);



#endif