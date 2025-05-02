#User function Template for python3

class Solution:
    def segregateElements(self, arr):
        # Your code goes here
        temp = []
        for i in arr:
            if(i>=0):
                temp.append(i)

        for i in arr:
            if(i<0):
                temp.append(i)

        for i in range(len(temp)):
            arr[i] = temp[i]
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while (T > 0):
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        ob.segregateElements(a)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends