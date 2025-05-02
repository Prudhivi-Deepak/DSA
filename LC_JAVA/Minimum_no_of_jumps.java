//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Minimum_no_of_jumps {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            System.out.println(new Solution().minJumps(arr));
            // System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static int minJumps(int[] arr) {
        // code here
        int destination = arr.length-1;
        int maxreach = 0;
        int windowend = arr[0];
        int jump = 0;
        
        for(int i=0;i<arr.length;i++){
            maxreach = Math.max(maxreach, arr[i] + i);
            if(windowend == i){
                jump++;
                windowend = maxreach;
            }

            if(windowend >= destination){
                return ++jump;
            }
        }

        return -1;        
    }
}