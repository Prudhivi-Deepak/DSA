
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            //  5 5 5 10 20
    
            int five_dollars = 0, ten_dollars = 0;
    
            for(int b: bills){
                if(b==5) five_dollars++;//5
                else if(b==10){//10
                    if(five_dollars>0){
                        five_dollars--;
                        ten_dollars++;
                    }
                    else{
                        return false;
                    }
                }
                else{//20
                    if(ten_dollars>=1 && five_dollars>=1){
                        ten_dollars-=1;
                        five_dollars-=1;
                    }
                    else if(five_dollars>=3){
                        five_dollars -= 3;
                    }
                    else{
                        return false;
                    }
                }
            }
            return true;
        }
    };