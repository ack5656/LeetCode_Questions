#include<iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

Node(int val){
    data = val;
    next = NULL;
}
};


class LinkedList{
public:
Node* head = NULL;

// INSERTION AT THE BEGINING
void InsertAtBegining(int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


// INSERTION AT THE END
void InsertAtEnd(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display LinkedList

void DisplayLL(){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

};

int main(){
    LinkedList ll;
    ll.InsertAtBegining(1);
    ll.InsertAtBegining(0);
    ll.InsertAtEnd(3);
    ll.DisplayLL();
}