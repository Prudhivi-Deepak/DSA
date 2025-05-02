#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    public:
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        MedianFinder() {
            max_heap = {};
            min_heap = {};
        }
        
        void addNum(int num) {
            max_heap.push(num);
            if(!min_heap.empty() && max_heap.top() > min_heap.top()){
                min_heap.push(max_heap.top()); max_heap.pop();
                max_heap.push(min_heap.top()); min_heap.pop();
            }
            if(max_heap.size()-min_heap.size() > 1){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            // max_heap.push(num);
        }
        
        double findMedian() {
            // cout << max_heap.size()-min_heap.size() << endl;
            if(max_heap.size()-min_heap.size() == 0){
                return ((double)max_heap.top()+min_heap.top())/2;
            }
            else{
                return max_heap.top();
            }
    
            // int ans, mInd;
            // priority_queue<int> max_temp_heap = max_heap;
            // if(max_heap.size()%2 == 1){
            //     mInd = max_heap.size()/2;
            //     while(mInd>0){
            //         max_temp_heap.pop();
            //         mInd--;
            //     }
            //     return max_temp_heap.top();
            // }
            // else{
            //     mInd = max_heap.size()/2-1;
            //     while(mInd>0){
            //         max_temp_heap.pop();
            //         mInd--;
            //     }
            //     mInd = max_temp_heap.top(); max_temp_heap.pop();
            //     return ((double)mInd + max_temp_heap.top())/2;
            // }
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */