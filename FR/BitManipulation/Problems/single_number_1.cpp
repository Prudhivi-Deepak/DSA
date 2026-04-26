class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        int xor_num = 0;
        for(int x : nums){
            xor_num ^= x;
        }
        return xor_num;
    }
};