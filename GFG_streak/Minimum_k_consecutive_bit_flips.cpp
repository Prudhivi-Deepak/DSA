#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        
        queue<int> q;
        int i=0, n=arr.size(), flip=0, TotalOperations = 0;
        
        while(i<n){
            
            if(!q.empty() && q.front()==i){
                q.pop();
                flip ^= 1;
            }
            
            if(arr[i]^flip == 0){ // bit is 0 after considering all flips we need to flip again(i to i+k-1 indices)
                // push i+k index
                if(i+k>n) return -1;
                q.push(i+k);
                flip ^= 1;
                
                TotalOperations++;
            }
            i++;
        }
        return TotalOperations;
        
        // queue<int> q;
        // int i=0, n = arr.size(), TotalOperations = 0;
        
        // while(i<n){
        //     if(q.empty() && arr[i]==0) q.push(arr[i]);
        //     else if(q.size()!=0 && q.size()<k) q.push(arr[i]);
            
        //     if(q.size()==k){
                
        //         while(!q.empty() && q.front()==0) q.pop();
                
        //         int size = q.size();
                
        //         for(int i=0; i<size; i++){
        //             q.push(!q.front()); q.pop();
        //         }
                
                
        //         TotalOperations +=1;
        //     }
        //     i++;
        // }
        
        // while(!q.empty() && q.front()) q.pop();
        
        // if(!q.empty()) return -1;
        
        // return TotalOperations;
    //flips    0 1 push index untill where filp happend into the queue
        // 0 1 2 3 4 5 6 7 8   9   10 11 12 13 14 15 16 17 18 19
        // 1 1 0 0 0 1 1 1 0   1   1  1  0  1  1  1  0  1  1  1
        //     0 ....K     
//queue//      5/          11 12
// flip//      1/0         1  0
        
        
        // 1 1 0 0 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1
        //                 0 1 1
        //                   0 0 1
        //                       0 0 1
        //                           0 1 1
        //                             0 0 0
        //                             1 1 1
                                    
    
        // multiple of k group of zeros --> zeroCount/k operations
        // not multiple of k group of zeroes --> zeroCount/k operations +
                            // remaining zeroes = zeroCount%k 
                            
        // 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1
        // 0  1  2  3  4  5  6  7  8  9 10
        // 1  1  1  1  0  1  1  0  1  1  1
        // 4 7 (7-4-1)=(2)+1
        
        // int prev = -1, i = 0, n = arr.size(), currZeroes = 0, TotalOperations = 0, remZeroes = 0;
        
        // while(i < n){
        //     while(i<n && arr[i]==0) {currZeroes++; i++;}
        //     TotalOperations += (currZeroes/k);
        //     remZeroes += (currZeroes%k);
            
        //     if(currZeroes != 0){
        //         cout << "TotalOperations : " << TotalOperations << endl;
        //         cout << "remZeroes : " << remZeroes << endl;
        //     }
        //     // cout << "currZeroes : " << currZeroes << endl;
            
        //     if(remZeroes!=0){
        //         prev = i;
        //         while(i<n && arr[i]==1) {i++;}
        //         TotalOperations += (i-prev+1);
        //         // remZeroes = 0;
        //     }
        //     currZeroes = 0;
        //     i++;
        // }
        
        // if(remZeroes!=0) return -1;
        
        // return TotalOperations;
    }
};