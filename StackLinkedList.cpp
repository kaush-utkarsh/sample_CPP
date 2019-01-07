#include <iostream>

using namespace std;

// Define node pointer
struct node {
    int data;
    node* next;
};

// Head and tail pointers
node* head;
node* tail;

// Functions
int menu();
void push(node *& head, node *&tail, int data);
void pop(node *&head, node *& tail);
void top(node *& head);
bool isEmpty(node *& head);

//Main function
int main() {
    
    node* head;
    node* tail;
    
    head = NULL;
    tail = NULL;
    int choice;
    
    do {
        choice = menu();
        
        switch(choice) {
            case 1:
                int data;
                cout<<"Enter value to be stored in stack: ";
                cin>>data;
                push(head,tail,data);
                break;
            case 2:
                pop(head,tail);
                break;
            case 3:
                top(head);
                break;
            case 4:
                printf("Not implemented");
                break;
            case 5:
                isEmpty(head);
                break;
            case -1:
                choice = -1;
                break;
                
            default: printf("\nEnter a valid choice!!");
        }
    } while(choice != -1);
    
    return 0;
}

//Menu function
int menu() {
    int ch;
    printf("\nStack");
    printf("\n1.Push\n2.Pop\n3.Top element\n4.Is Full\n5.Is Empty\n6.Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&ch);
    return ch;
}

//Push element in stack
void push(node *& head, node *&tail, int data) {
    if (head == NULL) {
        node* n= new node;
        
        n->data = data;
        n->next = NULL;
        
        head = n;
        tail = n;
        
    } else {
        node* n = new node;
        n->data = data;
        n->next = head;
        head = n;
    }
}

// Pop first element in stack
void pop(node *&head, node *& tail) {
    if (head == NULL) {
        printf("\nThe stack is empty.");
        
    } else if (head == tail) {
        // Case when there is only 1 element in the stack
        printf("The value %d was popped", head->data);
        delete head;
        head = NULL;
        tail = NULL;
        
    } else {
        node* n = new node;
        n = head;
        head = head->next;
        printf("\nThe value %d was popped", n->data);
        delete n;
    }
}

//Show top-most element in stack
void top(node *& head) {
    if (head == NULL) {
        printf("\nThe stack if empty");
        
    } else {
        printf("\nTop number is %d", head->data);
    }
}

// Shows if the stack is empty
bool isEmpty(node *& head) {
    if(head == NULL) {
        printf("\nThe stack is empty");
        return true;
        
    } else {
        printf("\nThe stack is not empty");
        return false;
    }
}
