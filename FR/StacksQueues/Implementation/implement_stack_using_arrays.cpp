class ArrayStack {
public:
    int arr[101], tp = -1;
    ArrayStack() {
    }
    
    void push(int x) {
        arr[++tp] = x;
    }
    
    int pop() {
        return arr[tp--];
    }
    
    int top() {
        if(tp==-1) return -1;
        return arr[tp];
    }
    
    bool isEmpty() {
        return tp==-1;
    }
};