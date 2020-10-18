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
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
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
    }else{
        return 0;
    }
}
void Infix2Postfix(char *infix,char *postfix){
    int i=0,j=0;
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isOperend(ch)){
            postfix[j++]=infix[i++];
        }else{
            if(precedence(ch)>precedence(stackk[top])){
                push(infix[i++]);
            }else{
                postfix[j++]=pop();
            }
        }
    }
    cout<<"kak"<<endl;
    while(stackk[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main(){
    char infix[]="a+b*c-d/e";
    char postfix[MAX];
    push('#');
    cout<<"Hi"<<endl;
    Infix2Postfix(infix,postfix);
    cout<<postfix;
}
