
struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedListStack {
public:
    Node *head = nullptr;
    LinkedListStack() {
        head = nullptr;
    }
    
    void push(int x) {
        Node *currNode = new Node(x);
        if(head == nullptr) head = currNode;
        else{
            currNode -> next = head;
            head = currNode;
        }
    }
    
    int pop() {
        if(head == nullptr) return -1;
        int tp = head->data;
        head = head->next;
        return tp;
    }
    
    int top() {
        return head->data;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
};