class Solution{
    public:
        vector<int> maxHeap;
        void initializeHeap(){
            maxHeap.clear();
        }

        void heapifyUp(int ind){
            while(ind>0){
                int parent = (ind-1)/2;
                if(parent>=0 && maxHeap[ind] > maxHeap[parent]){
                    swap(maxHeap[ind], maxHeap[parent]);
                    ind = parent;
                }
                else break;
            }
        }

        void heapifyDown(int ind){
            while(ind < maxHeap.size()){
                int child1 = 2*ind+1, child2 = 2*ind+2;
                int largest_one = ind;

                if(child1 < maxHeap.size() && maxHeap[child1] > maxHeap[largest_one]) largest_one = child1;
                if(child2 < maxHeap.size() && maxHeap[child2] > maxHeap[largest_one]) largest_one = child2;

                if(largest_one == ind) break;
                swap(maxHeap[largest_one], maxHeap[ind]);
                ind = largest_one;
            }
        }

        void insert(int key){
            maxHeap.push_back(key);
            heapifyUp(maxHeap.size()-1);
        }

        void changeKey(int index, int new_val){
            maxHeap[index] = new_val;

            int parent = (index-1)/2;

            if(parent>=0 && maxHeap[index] > maxHeap[parent]){
                heapifyUp(index);
            }
            else{
                heapifyDown(index);
            }
        }

        void extractMax(){
            if(maxHeap.empty()) return;
            swap(maxHeap[0], maxHeap.back());
            maxHeap.pop_back();
            heapifyDown(0);
        }

        bool isEmpty(){
            return maxHeap.empty();
        }

        int getMax(){
            return maxHeap[0];
        }

        int heapSize(){
            return maxHeap.size();
        }
};