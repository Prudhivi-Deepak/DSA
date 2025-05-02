//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    // vector<string> powerset(string &s, string &n, int pos, vector<string> &ans){
        
    //     if(pos == s.size()) {
    //         // cout << n << " ";
    //         return vector<string>(1,n);
    //     }
    //     else{
    //         string n1 = n+s[pos];
    //         vector<string> left = powerset(s, n1, pos+1);
    //         vector<string> right = powerset(s, n, pos+1);
    //         left.insert(left.end(), right.begin(), right.end());
    //         return left;
    //     }
        
    // }
    
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		  //  string n = "";
		  //  vector<string> ans = powerset(s, n, 0);
		  //  sort(ans.begin(), ans.end());
		  //  return ans;
		  int n = s.size();
		  vector<string> ans{""};
		  for(int num = 0; num<(1<<n); num++){
		      string v="";
		      for(int i=0; i<n; i++){
		          if(num&(1<<i)) {
		              v+=s[i];
		          }
		      }
		      ans.push_back(v);
		  }
		  sort(ans.begin(), ans.end());
    	  return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends