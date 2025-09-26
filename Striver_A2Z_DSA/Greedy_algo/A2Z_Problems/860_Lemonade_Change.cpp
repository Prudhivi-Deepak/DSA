#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Revision
    bool lemonadeChange(vector<int>& bills){
        //your code goes here
        int five = 0, ten = 0;

        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(five>0) {
                    five--;ten++;
                }
                else return false;
            }
            else{
                if(ten>0 && five>0){
                    five--; ten--;
                }
                else if(five>2) five -= 3;
                else return false;
            }
        }
        return true;
    }
    bool lemonadeChangeFirstTry(vector<int>& bills) {
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