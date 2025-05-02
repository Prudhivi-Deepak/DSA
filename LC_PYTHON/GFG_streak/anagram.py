#User function Template for python3


class Solution:
    
    #Function is to check whether two strings are anagram of each other or not.
    def areAnagrams(self, s1, s2):
        #code here

        from collections import Counter
        return Counter(s1) == Counter(s2)

        # sum1 = 0
        # sum2 = 0
        # pro1 = 1
        # pro2 = 1
        # if(len(s1) != len(s2)):
        #     return False
        # else :
        #     for i in range(len(s1)):
        #         s1_ord = ord(s1[i])-96
        #         s2_ord = ord(s2[i])-96
        #         sum1 += s1_ord
        #         pro1 *= s1_ord
        #         sum2 += s2_ord
        #         pro2 *= s2_ord
        # if(sum1==sum2 and pro1==pro2):
        #     return True
        
        # return False


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        a = input().strip()
        b = input().strip()
        if (Solution().areAnagrams(a, b)):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends