#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

typedef enum{FALSE =0, TRUE = 1} Boolean;

typedef struct{
    int size;
    int top;
    int *stacklist;
}stack;

stack *createS(int size){
    stack *s;
    s = (stack*)malloc(sizeof(stack));
    s->size =size;
    s->stacklist = (int*)malloc(size * sizeof(int));
    s->top = -1;
    return s;
}


Boolean IsFull(stack *s){
    if (s->top == s->size -1)
        return TRUE;
    else return FALSE;
}



Boolean IsEmpty(stack *s){
    if (s->top == -1)
        return TRUE;
    else return FALSE;
}


void push(stack *s, int e){
    if (!IsFull(s)){
        s->top++;
        s->stacklist[s->top] = e;
    }
}


char pop(stack *s){
    int i;
    if (!IsEmpty(s)){
        i = s-> stacklist[s->top];
        s->top--;
        return i;
    }else{printf("error\n"); return -1;}
}

char top(stack *s){ return s->stacklist[s->top];}


Boolean isMatching(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return TRUE;
    else if (character1 == '[' && character2 == ']')
        return TRUE;
    else
        return FALSE;
}

char* isValid(char A[], int A_len)
{   
    char* output;
    stack *stack_holder = createS(20000);
    
    for(int i = 0; i < A_len; i++){
        if(A[i] == '[' || A[i] == '(') push(stack_holder, A[i]);
        else if(A[i] == ']' || A[i] == ')'){
            if(IsEmpty(stack_holder)) return output = "invalid";
            else if(isMatching(top(stack_holder), A[i])){
                pop(stack_holder);
                continue;
            }
            else return output = "invalid";
        }
        else return output = "invalid";
    }
    
    if(IsEmpty(stack_holder)){
        output = "valid";
    }
    
    else if(!IsEmpty(stack_holder)){
        char tmp;
        int Bcounter = 0;
        char* B = malloc(stack_holder->top * sizeof(char));
    
        while(!IsEmpty(stack_holder)){
            tmp = pop(stack_holder);
            if(tmp == '[') B[Bcounter] = ']';
            else B[Bcounter] = ')';
            Bcounter++;
        }
        output = B;
    }
    
    return output;
}


int main()
{    
    char value;
    char A[MAX];
    int A_len;
    printf("Input the number of chars in A:\n");
    scanf("%d", &A_len);
    printf("Input these chars:\n");
    scanf("%s", A);
    printf("%s\n", isValid(A, A_len));

    return 0;
}

