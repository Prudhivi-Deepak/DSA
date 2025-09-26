#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> st;
            int i=0;
            while(i<asteroids.size()){
                // cout << "i : " << i << endl;
                //push in case of
                //positive element or 
                //negitive element and either stack is empty or the top element is negitve
                if(asteroids[i]>0) st.push_back(asteroids[i]);
                else{
                    //negitive element and inside stack positive element
                    while(!st.empty() && st.back()>0 && abs(asteroids[i]) > abs(st.back())){
                        // cout << "while i : " << i << endl;
                        st.erase(st.begin()+st.size()-1, st.end());
                    }
                    // <=
                    // < no need to do anything just leave it no push no pop
                    //  == then pop it no push
                    if(st.empty() || (!st.empty() && st.back()<0)){
                        st.push_back(asteroids[i]);
                    }
                    else if(!st.empty() && abs(asteroids[i]) == abs(st.back()) ){
                        // cout << "if i : " << i << endl;
                        st.erase(st.begin()+st.size()-1, st.end());
                    }
                     
                }
                i++;
            }
            return st;
        }
    
        //didn't work out first try - analyse on paper again
        vector<int> asteroidCollision1(vector<int>& asteroids) {
            // stack<int> st;
            vector<int> st;
    
            int i=0;
            while(i < asteroids.size()){
                if(st.empty()) st.push_back(asteroids[i]);
                else{
                    while(!st.empty()){
                        //same sign
                        if((st.back()<0 && asteroids[i]<0) || (st.back()>0 && asteroids[i]>0) || (st.back()<0)){
                            st.push_back(asteroids[i]); break;
                        }
                        else if(!st.empty() && abs(st.back()) < abs(asteroids[i]) ){
                            //  st.pop();
                            while(!st.empty() && abs(st.back()) < abs(asteroids[i]) ){
                                st.erase(st.begin()+st.size()-1, st.end());
                            }
                            if(!st.empty()) st.push_back(asteroids[i]);
                        }
                        else if(!st.empty() && abs(st.back()) == abs(asteroids[i]) ){
                            st.erase(st.begin()+st.size()-1, st.end());break;
                        }
                        else{
                            break;
                        }
                    }
                }
                i++;
            }
            return st;
        }
    };