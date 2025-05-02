#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ComputeLPS(string pat){
        int n = pat.size();
        int match = 0, i=1;
        vector<int> lps (n, 0);
        while(i < n){
            if(pat[i] == pat[match]){
                lps[i++] = ++match;
            }
            else{
                if(match==0){
                    i++;
                }
                else{
                    match -=1;
                }
            }
        }
        return lps;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        // cout << sentence << endl;
        // cout << searchWord << endl;
        vector<int> lps = ComputeLPS(searchWord);
        int n = sentence.size();
        int pn = searchWord.size();
        int i=0, j=0, wordcount = 1, flag = 0;
        while(i < n){
            if(sentence[i] == searchWord[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }

            if(j==pn && (i-j-1 <0 || sentence[i-j-1]==' ')){
                // cout << i << endl;
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            j = 0;
            while(j < n){
                if(sentence[j] == ' ' && j < i){
                    wordcount++;
                }
                j++;
            }

            return wordcount;
        }

        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string S, pat;
        // cin >> S >> pat;
        getline(cin, S);
        getline(cin, pat);
        // cin.ignore();
        Solution ob;
        int res = ob.isPrefixOfWord(S, pat);
        cout << res << endl;
        // if (res.size() == 0)
        //     cout << "[]" << endl;
        // else {
        //     for (int i : res)
        //         cout << i << " ";
        //     cout << endl;
        // }
    }
    return 0;
}

// } Driver Code Ends