#include<stdio.h>
#include<string.h>
//we have to create a infix to postfix converter
// we needed A stack,a string and a postfix string

// doing according to rules of conversion

char infix[20]; // a string where we will store our infix expression
char post[20]; // here we will store the final converted expression
char stack[20];// do stackoperation for the operator
int top = 0;//empty stack
int p=0;


int precedence(char c){
    if(c == '('||c == ')'){
        return 0; // it has least precendence bc if the element in the stack get over it it will not poped out
    }
    else if(c == '+'||c == '-'){
        return 1;
    }
    else if(c == '*'||c == '/'){
        return 2;
    }
    else if(c == '%'){
        return 3;
    }
    else if(c == '^'){
        return 4;
    }
    return 5;
}

void push(char c){
    top++;
    stack[top] = c;
}

void pop(char c){
    if(top == -1){
        printf("Empty stack: ");
        return ;
    }
    if(c ==')'){
        while((stack[top]!= '(')&&(top>=0)){
            post[p]= stack[top];
            p++;
            top--;
        }
        top--;
    }
    else{
    while(precedence(c)<= precedence(stack[top])){
        post[p++] = stack[top]; 
        top--;
    }
    push(c);
    }
}


int main(){
stack[0]= '(';
//now reading expression from user 
printf("Enter the infix expression: ");
fgets(infix,20,stdin);
// now we have entered the string;

int len = strlen(infix);
// getinf length of expression
infix[len-1]=')';
infix[len]='\0';

// here he had inserted the ending bracket at the end of string;
int i=0;//for indexing througout string
while(infix[i]!='\0'){
if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')){
    post[p] = infix[i];
    p++;
    i++;
}
else{
int prec = precedence(infix[i]);
switch(prec){
    case 0:
    if(infix[i]=='('){
        push(infix[i]);
    }
    else if(infix[i]==')'){
        pop(infix[i]);
    }
    break;
    case 1:pop(infix[i]);
    break;
    case 2:pop(infix[i]);
    break;
    case 3:pop(infix[i]);
    break;
    case 4:pop(infix[i]);
    break;
}
i++;
}
}
post[p]='\0';
printf("The infix expression is: ");
puts(post);
return 0;
}