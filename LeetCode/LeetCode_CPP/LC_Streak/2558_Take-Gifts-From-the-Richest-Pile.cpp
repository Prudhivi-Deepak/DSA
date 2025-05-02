// 2558. Take Gifts From the Richest Pile - https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // 25 64 9 4 100
        // max heap insert all elements
        // 25 64 9 4 100
        // priority_queue<int> max_heap(gifts.begin(), gifts.end());
        // i n-i-1
        // 0 4 5
        // 1 3 4
        // 2 2 3
        // 3 1 2
        // 4 0 1
        int i=0, n = gifts.size(), pile_gifts;
        long long gifts_count=0;
        // while(i < k){
        //     if(!is_heap(gifts.begin(), gifts.end())){
        //         make_heap(gifts.begin(), gifts.end());
        //     }

        //     gifts[0] = floor(sqrt(gifts[0]));
        //     pop_heap(gifts.begin(), gifts.end());
        //     i++;
        // }
        // priority_queue<int> max_heap(gifts.begin(), gifts.end());
        priority_queue<int> max_heap;

        for(int i:gifts){
            max_heap.push(i);
            gifts_count += i;
        }

        while(i < k){
            pile_gifts = floor(sqrt(max_heap.top()));
            gifts_count -= (max_heap.top() - pile_gifts);
            max_heap.pop();
            max_heap.push(pile_gifts);
            i++;
        }

        // while(i < k || !max_heap.empty()){
        //     if(i < k){
        //         pile_gifts = floor(sqrt(max_heap.top()));
        //         max_heap.pop();
        //         max_heap.push(pile_gifts);
        //         i++;
        //     }
        //     else{
        //         gifts_count += max_heap.top();
        //         max_heap.pop();
        //     }
        // }
        return gifts_count;
    }
};