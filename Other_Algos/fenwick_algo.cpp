// C++ code to demonstrate operations of Binary Index Tree
#include <iostream>

using namespace std;

/*         n --> No. of elements present in input array. 
    BITree[0..n] --> Array that represents Binary Indexed Tree.
    arr[0..n-1] --> Input array for which prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        cout << index << " : " << BITree[index] << endl;
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{   
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
    // cout << "update i : " << index << endl;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // cout << 
    // "while : " << 
    // index << " -> " ;
    // << " val : " << val 
    // << endl;
    // Add 'val' to current node of BI Tree
    BITree[index] += val;

    // Update index to that of parent in update View
    index += index & (-index);
    }
    // for(int j=1; j<=n; j++){
    //     cout << BITree[j] << " ";
    // }
    // cout << endl;
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++){
        // cout << "--------------------------------\n" ;
        // for(int j=0; j<n; j++) cout << arr[j] << " ";
        // cout << endl;
        updateBIT(BITree, n, i, arr[i]);
    }

    // Uncomment below lines to see contents of BITree[]
    for (int i=1; i<=n; i++)
        cout << BITree[i] << " ";

    return BITree;
}


// Driver program to test above functions
int main()
{
    // int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    //            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  10, 11, 12, 13, 14, 15
    int freq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    //            0  1  3  3 10  5 11  7 36  9   19  11  42  13  27 15   
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << endl;
    cout << "Sum of elements in arr[0..5] is "
        << getSum(BITree, 5);

    // Let use test the update operation
    freq[3] += 6;
    // updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(BITree, 5);
    
    cout << "\nSum of elements in arr[0..3] after update is "
        << getSum(BITree, 3);
    
    cout << "\nSum of elements in arr[0..9] after update is "
        << getSum(BITree, 9);
    cout << "\nSum of elements in arr[0..17] after update is "
        << getSum(BITree, 17);
    cout << "\nSum of elements in arr[0..16] after update is "
        << getSum(BITree, 16);
    cout << "\nSum of elements in arr[0..100] after update is "
        << getSum(BITree, 100);

    return 0;
}