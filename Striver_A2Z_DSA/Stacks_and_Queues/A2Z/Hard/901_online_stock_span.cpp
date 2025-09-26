#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<int> span;
    vector<int> stock;

    StockSpanner() {
        
    }
    
    int next(int price) {
        if(stock.empty()){
            stock.push_back(price);
            span.push(stock.size()-1);
            return 1;
        }

        while(!span.empty() && stock[span.top()] <= price ){
            span.pop();
        }

        if(span.empty()){
            stock.push_back(price);
            span.push(stock.size()-1);
            return stock.size();
        }
        else{
            int pge = span.top();
            stock.push_back(price);
            span.push(stock.size()-1);
            return (stock.size()-1 - pge); 
        }


        // int cnt=1;
        // for(int i=st.size()-1; i>=0; i--){
        //     if(st[i] <= price) cnt++;
        //     else break;
        // }
        // st.push_back(price);
        // return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */