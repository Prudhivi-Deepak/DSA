class ArrayQueue {
public:
    int arr[101], front = -1, back = -1;
    ArrayQueue() {
    }
    
    void push(int x) {
        arr[++back] = x;
        if(front == -1) front++;
    }
    
    int pop() {
        if(front == -1) return -1;
        return arr[front++];
    }
    
    int peek() {
        if(front == -1) return -1;
        return arr[front]; 
    }
    
    bool isEmpty() {
        return front==-1 || front > back;
    }
};