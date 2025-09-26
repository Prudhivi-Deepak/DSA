#include<bits/stdc++.h>
using namespace std;

class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& student, vector<int>& cookie){
        //your code goes here
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        int i=0, j=0, n=student.size(), m=cookie.size(), cnt=0;
        while(i<n && j<m){
            if(cookie[j]>=student[i]){
                cnt++; i++; j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};