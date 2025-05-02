//{ Driver Code Starts
import java.io.*;
import java.util.*;

class find_duplicates_in_array {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine()); // Number of test cases
        for (int g = 0; g < t; g++) {
            String[] str =
                (br.readLine()).trim().split(" "); // Reading input as a string array
            int arr[] = new int[str.length]; // Creating integer array from the input
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }

            // Getting the result from the Solution class
            List<Integer> result = new Solution().findDuplicates(arr);

            // Printing the result in the required format
            if (result.isEmpty()) {
                System.out.println("[]");
            } else {
                for (int i = 0; i < result.size(); i++) {
                    if (i != 0) System.out.print(" ");
                    System.out.print(result.get(i));
                }
                System.out.println();
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    public List<Integer> findDuplicates(int[] arr) {
        // code here
        // unordered_map<int,int> umap;
        // priority_queue<int, vector<int>, greater<int>> min_heap;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        HashMap<Integer, Integer> umap = new HashMap<>();


        for(int i: arr){

            if(umap.get(i)!=null){
                umap.put(i, 1);
            }
            else{

                if(umap.get(i)==2){
                    minHeap.
                }  
            }  
        }
  
        arr.clear();     
        while(min_heap.empty()!=true){           
            arr.push_back(min_heap.top());
            min_heap.pop();            
        }      

        return arr;  
    }
}
