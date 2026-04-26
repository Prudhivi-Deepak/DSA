class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        //Your code goes here
        int cnt = 0, xor1 = start ^ goal;
        while(xor1){
            cnt += (xor1&1);
            xor1>>=1;
        }
        return cnt;
        // for(int i=31; i>=0; i--){
        //     if(((start >> i)&1) != ((goal >> i)&1)) cnt++;
        // }
        // return cnt;
    }
};