#include<iostream>
#define MAX 100
#include<bits/stdc++.h>
using namespace std;
//using stack for conversion
char stackk[MAX];
//top used to indicate stack top position value
int top=-1;
//push() use for push value into top of the stack
void push(char ch){
    stackk[++top]=ch;
}
//pop() use for pop value from top of the stack
char pop(){
    return stackk[top--];
}
//isOperand() check input is operand or not
bool isOperend(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return true;
    }else{
        return false;
    }
}
//precedence() method return precedence of operator
//precedence of +,- is 1
//precedence of *,/ is 2
//precedence of ^ is 3
//otherwise 0
int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }else if(ch=='*'||ch=='/'){
        return 2;
    }else if(ch=='^'){
        return 3;
    }else{
        return 0;
    }
}
//this method convert infix to postfix
void Infix2Postfix(char *infix,char *postfix){
    //i indicate infix expression
    //j indicate postfix expression
    int i=0,j=0;
    //loop iterate until input have
    while(infix[i]!='\0'){
        char ch=infix[i];
        //if left parentheses than push into stack
        if(ch=='('){
           push(infix[i++]);
        }
        //if operand than add into postfix
        else if(isOperend(ch)){
            postfix[j++]=infix[i++];
        }
        //if right parentheses than pop from stack and add into postfix until we
        //get left parentheses
        else if(ch==')'){
            while(stackk[top]!='('){
                postfix[j++]=pop();
            }
            pop();
            i++;
        }
        //if operator found then enter into else part
        else{
            //stack operator precedence less than input operator than push into stack
            if(precedence(ch)>precedence(stackk[top])){
                push(infix[i++]);
            }
            //stack operator precedence greater than input operator than pop from
            //stack and add into postfix
            else if(precedence(ch)<precedence(stackk[top])){
                postfix[j++]=pop();
            }
            //if precedence same than enter into else part
            else{
                //right associative operator(^) than push into stack
                if(ch=='^'){
                    push(infix[i++]);
                }
                //left associative operator found than pop from stack and add into
                //postfix expression
                else{
                    postfix[j++]=pop();
                }
            }
        }
    }
    //pop from stack until stack not empty(#)
    while(stackk[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    //or,, char *infix="a+b*(c^d-e)^(f+g*h)-i";
    //output==abcd^e-fgh*+^*+i-
    char infix[]="x^y/(5*z)+2";//infix expression
    //output==> xy^5z*/2+
    char postfix[MAX];//store postfix expression
    push('#');//# for check stack empty or not
    Infix2Postfix(infix,postfix);
    cout<<postfix<<endl;
}
