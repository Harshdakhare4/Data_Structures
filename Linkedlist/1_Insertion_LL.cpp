#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Function to insert a node at the beginning
void insertAtBeg(Node*& head, int val) {  // `head` passed by reference
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}


// Function to insert a node at the end/tail
void insertAtEnd(Node *head,int val){
    Node * new_node = new Node(val);
    Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;//temp has reached last node
    new_node->next=NULL;//optional
}
//-----------------------------------------------------------------------//
// Function to insert a node at the Arbitrary position

void insert_arbitrary(Node* head,int val,int position){
    if(position==0){
        insertAtBeg(head,val);
        return;
    }
   
    Node* new_node = new Node(val);
    Node * temp=head;
    int current_pos=0;
    while(current_pos!=position-1){
        temp=temp->next;
        current_pos++;
    }//here temp is pointing at (position -1)

    new_node->next =temp->next;
    temp->next = new_node;
}


// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL; // Initialize head pointer
    insertAtBeg(head, 2);  // Insert node with value 2
    display(head);
    insertAtBeg(head, 5);  // Insert another node with value 5
    display(head);
    insertAtBeg(head, 10); // Insert another node with value 10
    display(head); // Output: 10 -> 5 -> 2 -> NULL
    cout<<endl;
//---------------------------//-----------------------------//
    insertAtEnd(head , 15);
    display(head);
    insertAtEnd(head , 17 );
    display(head);
    cout<<endl;

//----------------------------//------------------------------//
    insert_arbitrary(head,44,3);
    display(head);
    insert_arbitrary(head,45,4);
    display(head);
    cout<<endl;

    return 0;
}
