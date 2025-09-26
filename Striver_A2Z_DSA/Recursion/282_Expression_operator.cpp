#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void GenerateExpressions(int i, long expressionValue, long prevOperand, string expression, string num, int target, vector<string> &allExpressions) {
            if (i == num.size()) {
                if (expressionValue == target) {
                    allExpressions.push_back(expression);
                }
                return;
            }
    
            for (int j = i; j < num.size(); j++) {
                // Skip numbers with leading zero
                if (j != i && num[i] == '0') break;
    
                string currStr = num.substr(i, j - i + 1);
                long currNum = stol(currStr);
    
                if (i == 0) {
                    // First number in the expression, no operator
                    GenerateExpressions(j + 1, currNum, currNum, currStr, num, target, allExpressions);
                } else {
                    // Addition
                    GenerateExpressions(j + 1, expressionValue + currNum, currNum, expression + "+" + currStr, num, target, allExpressions);
    
                    // Subtraction
                    GenerateExpressions(j + 1, expressionValue - currNum, -currNum, expression + "-" + currStr, num, target, allExpressions);
    
                    // Multiplication
                    GenerateExpressions(j + 1,
                                        expressionValue - prevOperand + (prevOperand * currNum),
                                        prevOperand * currNum,
                                        expression + "*" + currStr,
                                        num, target, allExpressions);
                }
            }
        }
    
        vector<string> addOperators(string num, int target) {
            vector<string> allExpressions;
            GenerateExpressions(0, 0, 0, "", num, target, allExpressions);
            return allExpressions;
        }
    };