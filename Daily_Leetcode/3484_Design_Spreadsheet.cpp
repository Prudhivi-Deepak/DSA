
#include<bits/stdc++.h>
using namespace std;

class Spreadsheet1 {
public:
    // { A: {1:0, 10:45}, B: {4:9}}
    unordered_map<char, unordered_map<int,int>> excel;

    Spreadsheet1(int rows) {
        for(int i=0; i<26; i++){
            unordered_map<int,int> row;
            excel[i+'A'] = row;

            for(int r=0; r<rows; r++){
                excel[i+'A'][r] = 0;
            }
        }
    }
    
    void setCell(string cell, int value) {
        // cout << "setcell" << endl;
        char column = cell[0];
        // cout << cell.substr(1,cell.size()) << endl;
        // int row = stoi(cell.substr(1,cell.size()));

        string operand2 = cell.substr(1, cell.size());
        // cout << operand2 << endl;
        int row = stoi(operand2);
        // cout << row << endl;

        excel[column][row] = value;
    }
    
    void resetCell(string cell) {
        // cout << "resetCell" << endl;
        char column = cell[0];
        int row = 0;
        // cout << cell.substr(1,cell.size()) << endl;
        // if(cell.size()==2)
        //     row = cell[1]-'0';
        // else
        //     row = stoi(cell.substr(1,cell.size()));
        string operand2 = cell.substr(1, cell.size());
        // cout << operand2 << endl;
        row = stoi(operand2);

        excel[column][row] = 0;
    }
    
    int getValue(string formula) {
        // cout << "getValue" << endl;
        int index = formula.find("+");
        string operand1 = formula.substr(1, index-1);
        string operand2 = formula.substr(index+1, formula.size());

        // cout << operand1 << " : " << operand2 << endl;

        int op1 = 0, op2 = 0;

        if(!isalpha(operand1[0])){
            // cout << operand1 << endl;
            op1 = stoi(operand1);
        }
        else if(excel[operand1[0]].find(stoi(operand1.substr(1,operand1.size())))!=excel[operand1[0]].end()){
            // cout << "inside" << endl;
            char column = operand1[0];
            // cout << operand1.substr(1,operand1.size()) << endl;
            int row = stoi(operand1.substr(1,operand1.size()));
            // cout << row << endl;
            if(excel[column].find(row)!=excel[column].end()){
                // cout << "row "<< row << endl;
                op1 = excel[column][row];
                // cout << "op1 "<< op1 << endl;

            }
        }

        if(!isalpha(operand2[0])){
            op2 = stoi(operand2);
        }
        else if(excel[operand2[0]].find(stoi(operand2.substr(1,operand2.size())))!=excel[operand2[0]].end()){
            char column = operand2[0];
            // cout << operand2.substr(1,operand2.size()) << endl;
            int row = stoi(operand2.substr(1,operand2.size()));
            
            if(excel[column].find(row)!=excel[column].end()){
                op2 = excel[column][row];
            }
        }

        // cout << "op1+op2 : " << op1 << " + " << op2 << endl;

        return op1+op2;
    }
};


class Spreadsheet {
public:
    // { A: {1:0, 10:45}, B: {4:9}}
    // 0(A)
    // [[r0, r1, r2...], [r0, r1, r3], ...]

    vector<vector<int>> excel;

    Spreadsheet(int rows) {
        excel = vector<vector<int>>(26, vector<int>(rows, 0));
    }
    
    void setCell(string cell, int value) {
        if(isupper(cell[0])){
            excel[cell[0]-'A'][stoi(cell.substr(1))-1] = value;
        }
    }
    
    void resetCell(string cell) {
        if(isupper(cell[0])){
            excel[cell[0]-'A'][stoi(cell.substr(1))-1] = 0;
        }
    }
    
    int getValue(string formula) {
        int index = formula.find("+");
        string operand1 = formula.substr(1, index-1);
        string operand2 = formula.substr(index+1);
        int op1 = 0, op2 = 0;

        if(isupper(operand1[0]))
            op1 = excel[operand1[0]-'A'][stoi(operand1.substr(1))-1];
        else
            op1 = stoi(operand1);

        if(isupper(operand2[0]))
            op2 = excel[operand2[0]-'A'][stoi(operand2.substr(1))-1];
        else
            op2 = stoi(operand2);

        return op1+op2;
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */