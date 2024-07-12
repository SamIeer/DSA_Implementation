#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*top = NULL;

void push(int x){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL){
        cout<<"Stack Overflow:"<<endl;
    } else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    struct Node *t;
    int x = -1;
    if(top == NULL){
        cout<<"Stack Underflow"<<endl;
    } else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<"|"<<flush;
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int arr[6] = {2,5,3,6,8,9};
    for(int i=0 ; i<6 ; i++){
        push(arr[i]);
    }
    pop();
    Display();
}