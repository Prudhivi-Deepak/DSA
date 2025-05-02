//{ Driver Code Starts
// Initial Template for Java
// package LC_JAVA;
import java.io.*;
import java.lang.*;
import java.util.*;

class Reverse_the_string {
    public static void main(String args[]) throws IOException {        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String str = read.readLine();
            System.out.println(Reverse.reverseString(str));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Reverse {
    // Complete the function
    // str: input string
    public static String reverseString(String s) {
        // Reverse the string str
        int front_pointer = 0;
        int end_pointer = s.length()-1;
        char temp ='a';
        StringBuilder s1 = new StringBuilder(s);
        
        while(front_pointer < end_pointer){
            temp = s1.charAt(front_pointer);
            s1.setCharAt(front_pointer, s1.charAt(end_pointer));
            s1.setCharAt(end_pointer, temp);
            
            front_pointer++;
            end_pointer--;
        }
        return s1.toString();
    }
}