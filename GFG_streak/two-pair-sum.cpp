#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        // code here
        unordered_map<int, int> umap;
        for (int i : arr)
        {
            if (umap[target - i] == 1)
            {
                return true;
            }
            else if (target - i > 0)
            {
                umap[i] = 1;
            }
        }
        return false;
    }
};











//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends

// 3
// 16
// 1 4 45 6 10 8
// 11
// 1 2 4 3 6
// 165
// 142 712 254 869 548 645 663 758 38 860 724 742 530 779 317 36 191 843 289 107 41 943 265 649 447 806 891 730 371 351 7 102 394 549 630 624 85 955 757 841 967 377 932 309 945 440 627 324 538 539 119 83 930 542 834 116 640 659 705 931 978 307 674 387 22 746 925 73 271 830 778 574 98 513