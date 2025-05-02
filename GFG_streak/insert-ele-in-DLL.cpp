//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        // 3 <-> 5 <-> 8 <-> 10 <-> 12
        // temp = 8
        //  newnode =  9
        // 3 <-> 5 <-> 8 <-> 9 <-> 10 <-> 12
        // newnode -> next = temp -> next;
        // newnode -> prev = temp
        // newnode -> next -> prev = newnode
        // temp -> next = newnode
        // 
        // 3 <-> 5 <-> 8 <- 9 -> 10 <-> 12
        // 1 4 10 11
        // 15 = newnode
        // temp = 11
        //  1 4 10 11
        // newnode -> next = NULL;
        //newnode

        Node *temp = head;
        Node *newnode = getNode(x);    
        
        while(temp->data <= x && temp->next!= NULL){
            temp = temp->next;
        }
        
        if(temp->data <= x && temp->next == NULL){
            newnode -> next = NULL;
            newnode -> prev = temp;
            temp -> next = newnode;
        }      
        else if(head == temp && temp->next == NULL){                
            temp -> prev = newnode;
            newnode -> next = temp;
            temp -> next = NULL;
            head = newnode;
        }
        else if(temp->data >=x && temp->prev == NULL){
            newnode -> next = temp;
            temp->prev = newnode;
            head = newnode;
        }
        else{
            temp = temp->prev;
            newnode -> next = temp -> next;
            newnode -> prev = temp;
            newnode -> next -> prev = newnode;
            temp -> next = newnode;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends