//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sort_array_0_1_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            int a[] = new int[inputArray.length];

            for (int i = 0; i < a.length; i++) a[i] = Integer.parseInt(inputArray[i]);

            Solution ob = new Solution();
            ob.sort012(a);

            for (int num : a) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to sort an array of 0s, 1s, and 2s
    public void sort012(int[] arr) {
        // code here
        int p_0 = 0;
        int p_2 = arr.length-1;
        int p_1 = 0;
        int temp = 0;

        while(p_1 <= p_2){
            if(arr[p_1] == 1){
                p_1++;
            }
            else if(arr[p_1] == 0){
                temp = arr[p_1];
                arr[p_1] = arr[p_0];
                arr[p_0] = temp;
                p_0++;
                p_1++;
            }
            else if(arr[p_1] == 2){                
                temp = arr[p_1];
                arr[p_1] = arr[p_2];
                arr[p_2] = temp;
                p_2--;
            }
        }
    }
}