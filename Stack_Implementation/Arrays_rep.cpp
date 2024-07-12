#include <iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    bool isFull();
    bool isEmpty();
    void Display();
    int Stacktop();
};

Stack::Stack(int size){
    this->size = size;
    top = -1;
    arr = new int[size]; }

Stack::~Stack(){
    delete[] arr;}

void Stack::push(int x){
    if(isFull()){
        cout<<"stack Overflow"<<endl; } 
    else{
        top++;
        arr[top] = x; } }

int Stack::pop(){
    int x = -1;
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl; } 
    else {
        x = arr[top];
        top--; }
    return x; }

int Stack::peek(int index){
    int x = -1;
    if(top-index + 1 < 0 || top-index +1 == size){
        cout<<"Invalid position"<<endl;
    }  else {
        x = arr[top - index + 1];
    }
    return x; }

bool Stack::isFull(){
    if(top == size -1){
        return true;
    }
    return false; }

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;  }

int Stack::Stacktop(){
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top]; }

void Stack::Display(){
    for(int i = top ; i >= 0 ; i--){
        cout<<arr[i]<<"|"<<flush;
    }
    cout<<endl; }

int main(){
    int arr[] = {2,4,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Stack st(n);
    for(int i = 0 ; i < n ;i++){
        st.push(arr[i]);
    }
    st.pop();
    cout<<st.peek(3)<<endl;
    st.Display();
    cout<<st.Stacktop()<<endl;
    cout<<st.isFull()<<endl;
    cout<<st.isEmpty();

    return 0; }