#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct{
    Node* top;
    int count;
}Stack;

Stack* create_stack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    if (stack==NULL){
        printf("memory allocation fail");
        exit(-1);
    }
    stack->count=0;
    stack->top=NULL;
    return stack;
}
int is_empty(Stack* stack){
    return stack->count==0;
}
void push(Stack* stack, int data){
    Node* node=(Node*)malloc(sizeof(Node));
    if (node==NULL){
        printf("Stack is full");
    }else{
        node->data=data;
        node->next=stack->top;
        stack->top=node;
        stack->count++;
    }
}
int pop(Stack* stack){
    if (is_empty(stack)){
        printf("Stack is empty, Cannot pop, \n");
        return -1;
    }
    Node* temp =stack->top;
    stack->top=stack->top->next;
    int data=temp->data;
    free(temp);
    stack->count--;
    return data;
}
int peek(Stack* stack){
    if (is_empty(stack)){
       printf("Stack is empty, Cannot peek \n");
       return -1; 
    }
    return stack->top->data;
}
int get_size(Stack* stack){
    return stack->count;
}
void destroy_stack(Stack* stack){
    while (! is_empty(stack)){
        pop(stack);
    }
    
    free(stack);
}
int main(){
    Stack* stack=create_stack();
    push(stack,10);
    push(stack,20);
    printf("Top element:- %d\n",peek(stack));
    printf("size is:-%d\n",get_size(stack));
    pop(stack);
    destroy_stack(stack);
    return 0;
}