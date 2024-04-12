#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct{
    int items[MAX_SIZE];
    int top;
}Stack;

Stack* create_stack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    if (stack==NULL){
        printf("memory allocation fail");
        exit(-1);
    }
    stack->top=-1;
    return stack;
}
int is_empty(Stack* stack){
    return stack->top==-1;
}

int is_full(Stack* stack){
    return stack->top==MAX_SIZE-1;
}
void push(Stack* stack, int item){
    if (is_full(stack)){
        printf("Stack is Full, Cannot push %d. \n",item);
    }else{
        stack->items[++stack->top]=item;
    }
}
int pop(Stack* stack){
    if (is_empty(stack)){
        printf("Stack is empty, Cannot pop, \n");
        return -1;
    }
    return stack->items[stack->top--];
}
int peek(Stack* stack){
    if (is_empty(stack)){
       printf("Stack is empty, Cannot peek \n");
       return -1; 
    }
    return stack->items[stack->top];
}
int get_size(Stack* stack){
    return stack->top+1;
}
void destroy_stack(Stack* stack){
    free(stack);
}
int get_value(int* value_list,char* ch){
    return value_list[*ch-'A'];
}
void set_value(int* value_list,char ch,int value){
    value_list[ch-'A']=value;
}
int main(){
    Stack* stack=create_stack();
    int value_list[52];
    char experation[]="A B C * + D / E +";
    set_value(value_list,'A',1);
    set_value(value_list,'B',2);
    set_value(value_list,'C',1);
    set_value(value_list,'D',2);
    set_value(value_list,'E',5);
    char* token=strtok(experation," ");
    int temp1;
    int temp2;
    while (token!=NULL){
        switch (*token){
        case '+':
            temp2=pop(stack);
            temp1=pop(stack);
            push(stack,temp1+temp2);
            break;
        case '-':
            temp2=pop(stack);
            temp1=pop(stack);
            push(stack,temp1-temp2);
            break;
        case '*':
            temp2=pop(stack);
            temp1=pop(stack);
            push(stack,temp1*temp2);
            break;
        case '/':
            temp2=pop(stack);
            temp1=pop(stack);
            push(stack,temp1/temp2);
            break;
        
        default:
            push(stack,get_value(value_list,token));
            break;
        }
        printf("token:- %s\n",token);
        token=strtok(NULL," ");
    }
    printf("evaluated expresion is:- %d\n",pop(stack));
    
    return 0;
}