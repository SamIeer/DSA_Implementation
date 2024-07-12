#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;}
};

//A NODE FUNCTION FOR CREATING LINKED LIST
Node * create_list(int A[],int n){
    if(n==0)return NULL;

    Node *head = new Node(A[0]);
    Node *temp = head;
    
    for(int i=1 ; i<n ; i++){
        temp->next = new Node(A[i]);
        temp = temp->next;}
    return head;}

//VOID FUNCTION FOR DISPLAYING THE LINKED LIST
void print_list(Node *head){
    Node *temp = head;
    while( temp != nullptr){
    cout<<temp->data<<"<-";
    temp = temp->next;}

    cout<<endl;}

//NODE FOR INSERITNG THE NODDE AT A GIVEN POSITION
Node *insert_at(Node *head,int pos,int data){
    Node *t = new Node(data);
    if(head == NULL){return t;}
    Node *temp = head; Node *prev = NULL;

    if(pos == 1){
    t->next = head;
    head = t;
    return head;}

    for(int i=1 ; i<=pos-1 ; i++){
            temp = temp->next;
            prev = temp;}
    temp = temp->next;
    prev->next = t;
    t->next = temp;
    return head;}

//DELETION OF NODE WITH GIVEN POSITION
Node *delete_node(Node *head,int pos){
     if(head == NULL){return NULL;}
    if(head->next == NULL){ 
        delete head; 
        return NULL;}
    Node *temp = head; 

    //DELETING THE HEAD NODE
    if(pos == 1){
    head = temp->next;
    delete temp;
    return head;}

    int count = 0;
    while(temp != NULL){
        count++;
        if(count == pos-1){
            Node *real = temp->next;
            temp->next = real->next;
            delete real;
            break;
            }
        temp = temp->next;
    }
    return head;}   

//FUNCTION FOR COUNTING THE NUMBER OF NODES
int count_node(Node *head){
    Node *temp = head; 
    int count = 0;
    while (temp != NULL)
    {   count ++;
        temp = temp->next;}
    return count;
}

int main(){
    int  arr[6] = {1,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *head;
    head = create_list(arr,n);
    delete_node(head,6);
    head = insert_at(head,4,39);
    head = insert_at(head,6,39);
    head = insert_at(head,3,399);
    print_list(head);
    cout << count_node(head);
    return 0;
}