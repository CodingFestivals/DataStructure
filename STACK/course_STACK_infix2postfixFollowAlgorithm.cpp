#include<iostream>
#define MAX 100
#include<bits/stdc++.h>
using namespace std;
char stackk[MAX];
int top=-1;
void push(char ch){
    stackk[++top]=ch;
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
void Infix2Postfix(char *infix,char *postfix){
    int i=0,j=0;
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(ch=='('){
           push(infix[i++]);
        }
        else if(isOperend(ch)){
            postfix[j++]=infix[i++];
        }else if(ch==')'){
            while(stackk[top]!='('){
                postfix[j++]=pop();
            }
            pop();
            i++;
        }else{
            if(precedence(ch)>precedence(stackk[top])){
                push(infix[i++]);
            }else if(precedence(ch)<precedence(stackk[top])){
                postfix[j++]=pop();
            }else{
                if(ch=='^'){
                    push(infix[i++]);
                }else{
                    postfix[j++]=pop();
                }
            }
            //same
            /*if(ch=='^'){
                push(infix[i++]);
            }
            else if(precedence(ch)>precedence(stackk[top])){
                push(infix[i++]);
            }else if(precedence(ch)<=precedence(stackk[top])){
                postfix[j++]=pop();
            }*/
        }
    }
    while(stackk[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    //or,, char *infix="a+b*(c^d-e)^(f+g*h)-i";
    //output==abcd^e-fgh*+^*+i-
    char infix[]="x^y/(5*z)+2";
    //output==> xy^5z*/2+
    char postfix[MAX];
    push('#');
    Infix2Postfix(infix,postfix);
    cout<<postfix<<endl;
}
