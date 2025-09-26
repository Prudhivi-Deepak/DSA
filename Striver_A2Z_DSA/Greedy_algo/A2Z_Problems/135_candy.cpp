#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //your code goes here
        int sum = 1, i=1, n=ratings.size();

        while(i<n){
            while(i<n && ratings[i-1]==ratings[i]){
                sum+=1;i++;
            }

            int uppeak = 1;
            while(i<n && ratings[i-1]<ratings[i]){
                uppeak+=1;
                sum+=uppeak;i++;
            }

            int downpeak = 0;
            while(i<n && ratings[i-1]>ratings[i]){
                downpeak+=1;
                sum+=downpeak;i++;
            }

            if(downpeak+1>uppeak) sum = sum+(downpeak+1)-uppeak;
        }
        return sum;
    }
    int candy(vector<int>& arr) {
        int sum=1, i=1, n = arr.size();
        while(i<n){
            if(i<n &&  arr[i-1] == arr[i]){
                sum+=1;
                i++;
                continue;
            }

            int uppeak = 1;
            while(i<n && arr[i-1] < arr[i]){
                // uppeak +=1;
                sum += ++uppeak;
                i++;
            }

            int downpeak = 0;
            while(i<n && arr[i-1]>arr[i]){
                // downpeak+=1;
                sum+= ++downpeak;
                i++;
            }

            if(downpeak+1 > uppeak) sum += (downpeak+1 )-uppeak;
        }
        return sum;
    }
};