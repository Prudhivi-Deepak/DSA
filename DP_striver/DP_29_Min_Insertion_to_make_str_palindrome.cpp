#include<bits/stdc++.h>
using namespace std;

int minimumInsertions(string &str)
{
	// Write your code here.
	int n = str.size();
	string t = str;
	reverse(t.begin(), t.end());
	vector<int> prev(n+1, 0), curr(n+1, 0);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(str[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
			else curr[j] = max(curr[j-1], prev[j]);
		}
		prev = curr;
	}

	return n-prev[n];
}
