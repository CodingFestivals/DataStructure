#define MAX 100
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int len;
int top=-1;
char stackk[MAX];
void push(char ch){
    top=top+1;
    stackk[top]=ch;
}
char pop(){
    return stackk[top--];
}
bool isOperend(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return true;
    }else{
        return false;
    }
}
int Exprecedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }else if(ch=='*'||ch=='/'){
        return 3;
    }else if(ch=='^'){
        return 6;
    }else if(ch=='('){
        return 7;
    }else if(ch==')'){
        return 0;
    }else{
        return -1;
    }
}int Stprecedence(char ch){
    if(ch=='+'||ch=='-'){
        return 2;
    }else if(ch=='*'||ch=='/'){
        return 4;
    }else if(ch=='^'){
        return 5;
    }else if(ch=='('){
        return 0;
    }else{
        return -1;
    }
}
void Infix2Postfix(char *infix,char *postfix){
    //i indicate infix expression and j indicate postfix expression
    int i=0,j=0;
    //loop until not reach end
    while(infix[i]!='\0'){
        char ch=infix[i];
        //if operend copy into postfix
        if(isOperend(ch)){
            postfix[j++]=infix[i++];
        }else{
            //if expression operator greater than stack operator than push
            //into stack
            if(Exprecedence(ch)>Stprecedence(stackk[top])){
                push(infix[i++]);
            }
            //if expression operator less than stack operator than pop
            //from stack and copy into postfix
            else if(Exprecedence(ch)<Stprecedence(stackk[top])){
                postfix[j++]=pop();
            }else{
                //if left expression operator is right parathesis ')'
                //and stack top is left paranthesis '(' than pop from
                //stack and scan next character
                pop();
                i++;
            }
        }
    }
    //pop operator from stack until having data in stack
    //and copy into postfix
    while(stackk[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    //char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    char infix[]="x^y/(5*z)+2";
    char postfix[MAX];
    //for initial convertion we push #
    push('#');
    Infix2Postfix(infix,postfix);
    cout<<postfix;
}
