//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end, struct Node*& newHead,
                       struct Node*& newEnd) {
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == NULL)
                newHead = cur;

            prev = cur;
            cur = cur->next;
        } else { // If cur node is greater than pivot
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, pivot becomes the
    // head
    if (newHead == NULL)
        newHead = pivot;

    // Update newEnd to the current last node
    newEnd = tail;

    // Return the pivot node
    return pivot;
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    struct Node* quickSort(struct Node* head) {
        // code here

        struct Node *NewHead = NULL;
        struct Node *NewEnd = NULL;

        struct Node *end = head;
        while(end->next!= NULL){
            end=end->next;
        }

        struct Node *pivot = partition(head, end, NewHead, NewEnd);
        cout << "pivot : " << pivot->data << endl;

        struct Node *prev = head;
        while(prev->next!=pivot){
            prev = prev->next;
        }

        cout << prev->data << endl;

        // NewHead->next = pivot;
        // struct Node* temp = pivot;
        // while(temp->next!=NULL){
        //     temp = temp->next;
        // }
        // NewEnd = temp;

        
        cout << "head :" ;
        printList(head);
        cout << "end :" ;
        printList(end);
        cout << "NewHead :" ;
        printList(NewHead);
        cout << "NewEnd :" ;
        printList(NewEnd);
        cout << "pivot :" ;
        printList(pivot);
        cout << "prev : ";
        printList(prev);

        struct Node *NewHead1 = NULL;
        struct Node *NewEnd1 = NULL;

        // NewHead = NULL;
        // NewEnd = NULL;
        struct Node *pivot1 = partition(head, prev, NewHead1, NewEnd1);
        struct Node *pivot2 = NULL;

        struct Node *NewHead2 = NULL;
        struct Node *NewEnd2 = NULL;

        // if(pivot->next!=NULL){
        //     pivot2 = partition(pivot->next,  , NewHead2, NewEnd2);
        // }
        // NewHead->next = pivot1;
        // temp = pivot1;
        // while(temp->next!=NULL){
        //     temp = temp->next;
        // }
        // NewEnd = temp;        

        // NewHead = NULL;
        // NewEnd = NULL;
        // struct Node *pivot2 = NULL;
        // if(pivot->next!= NULL){
        //     pivot2 = partition(pivot->next, end, NewHead, NewEnd);
        // }

        // pivot1->next = pivot;
        // pivot->next = pivot2;

        cout << "\nhead :" ;
        printList(head);
        cout << "end :" ;
        printList(end);
        cout << "NewHead :" ;
        printList(NewHead);
        cout << "NewEnd :" ;
        printList(NewEnd);
        cout << "pivot :" ;
        printList(pivot);
        cout << "pivot1 :" ;
        printList(pivot1);
        cout << "pivot2 :" ;
        printList(pivot2);


        return head;



        // if(head->next!=NULL){
        //     struct Node *end = head;
        //     while(end->next!=NULL){
        //         end = end->next;
        //     }  
            
        //     struct Node *pivot = partition(head, end, end->next, end);
        //     cout << "pivot : " << pivot->data << endl;
        //     struct Node *prev = head;
        //     while(prev->next!=pivot){
        //         prev = prev->next;
        //     }

        //     quickSort(prev);

        //     if(pivot->next!=NULL){
        //         quickSort(pivot->next);
        //     }

        // }

        // return head;


        
        // if (left < right){
        //     int pivot = partition(h, left, right);

        //     quicksort(arr, left, pivot-1);
        //     quicksort(arr, pivot+1, right);
        // }

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends