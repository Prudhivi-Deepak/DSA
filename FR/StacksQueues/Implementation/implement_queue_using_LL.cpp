
struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedListQueue {
public:
    Node *head, *tail;
    LinkedListQueue() {
        head = nullptr;
        tail = nullptr;
    }
    
    void push(int x) {
        // insert at tail

        Node *currNode = new Node(x);
        if(head == nullptr && tail == nullptr){
            head = tail = currNode;
        }
        else{
            tail->next = currNode;
            tail = currNode;
        }
    }
    
    int pop() {
        if(head==nullptr) return -1;
        int front = head->data;

        if(head == tail && head!=nullptr){
            head = tail = nullptr;
        }
        else{
            head = head->next;
        }

        return front;
    }
    
    int peek() {
        if(head==nullptr) return -1;
        return head->data;
    }
    
    bool isEmpty() {
        return head==nullptr && tail==nullptr;
    }
};