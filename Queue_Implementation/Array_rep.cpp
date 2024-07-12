#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear , size;
    public:
       Queue(int size);
       ~Queue();
       void enqueue(int x);
       int dequeue();
       bool isEmpty();
       bool isFull();
       void display();
};

Queue::Queue(int size){
    this->size = size;
    front = rear = -1;
    arr  = new int[size]; }

Queue::~Queue(){
    delete [] arr; }

void Queue::enqueue(int x){
if(isFull()){
    cout << "Queue overflow"<<endl; }
else{
    rear++;
    arr[rear] = x; } }

int Queue::dequeue(){
    int x = -1;
    if(isEmpty()){
        cout<< "Queue is underflow"<<endl; }
    else{
        front++; 
        x = arr[front]; }
    return x; }

bool Queue::isFull(){
if(rear == size-1){
    return true; }
return false; }

bool Queue::isEmpty(){
    if(front == rear){
        return true; }
    return false; }

void Queue::display(){
    for(int i = front+1 ; i <= rear ; i++){
        cout<<arr[i]<<"|"<<flush; }

    cout<<endl; }

int main(){
    int arr[8] = { };
    Queue Qu(8);
    for(int i=0 ; i<8 ;i++){
            Qu.enqueue(arr[i]);
    }
    Qu.dequeue();
    cout<<Qu.isFull()<<endl;
    Qu.display();
    cout<<Qu.isEmpty()<<endl;

    return 0;
}