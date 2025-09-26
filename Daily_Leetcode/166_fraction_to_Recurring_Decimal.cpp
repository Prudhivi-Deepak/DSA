#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {

        if(numerator1==0) return "0";

        string ans = "";
        // 0 0 = 0
        // 1 1 = 0
        // 0 1 = 1
        // 1 0 = 1
        
        if(numerator1<0 ^ denominator1<0) ans += "-";

        long long numerator = abs((long long)numerator1);
        long long denominator = abs((long long)denominator1);

        ans += to_string(numerator/denominator); 

        long long remainder = numerator % denominator;

        if(remainder == 0) return ans;

        // = 10/2 = 5
        // = 11/2 = 5.5

        // 2|11
        //  |5 - 1*10 = 10 = 2|10
        //                    |5 - 0

        ans +=".";

        unordered_map<long long, int> remainder_map;

        while(remainder!=0){
            cout << remainder << " : " << denominator << endl;
            if(remainder_map.find(remainder)!=remainder_map.end()){
                ans.insert(remainder_map[remainder], "(");
                ans += ")"; break;
            }

            remainder_map[remainder] = ans.size();
            remainder *= 10;
            ans += to_string(remainder / denominator);
            remainder %= denominator;
        }

        return ans;
    }
};