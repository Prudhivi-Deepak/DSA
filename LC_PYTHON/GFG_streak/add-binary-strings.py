#User function Template for python3
class Solution:
    def addBinary(self, s1, s2):
        # code here
        carry = '0'
        s1_char = '0'
        s2_char = '0'
        n1 = len(s1)-1
        n2 = len(s2)-1
        
        while(n1>=0 or n2>=0):
            if(n1<0):
                s1_char = '0'
            else:
                s1_char = s1[n1]
            
            if(n2<0):
                s2_char = '0'
            else:
                s2_char = s2[n2]

            if(carry == '1'):
                if(s1_char == '1' and s2_char == '1'):
                    if(n1<0):
                        s1 = '1' + s1
                    else:
                        s1 = s1[:n1]+'1'+s1[n1+1:]
                    carry = '1'
                
                elif((s1_char == '0' and s2_char == '1') or (s1_char == '1' and s2_char == '0')):
                    if(n1<0):
                        s1 = '0' + s1
                    else:
                        s1 = s1[:n1]+'0'+s1[n1+1:]
                    carry = '1'
                
                else:
                    if(n1<0):
                        s1 = '1' + s1
                    else:
                        s1 = s1[:n1]+'1'+s1[n1+1:]
                    carry = '0'
            else:
                if(s1_char == '1' and s2_char == '1'):
                    if(n1<0):
                        s1 = '0' + s1
                    else:
                        s1 = s1[:n1]+'0'+s1[n1+1:]
                    carry = '1'
                
                elif((s1_char == '0' and s2_char == '1') or (s1_char == '1' and s2_char == '0')):
                    if(n1<0):
                        s1 = '1' + s1
                    else:
                        s1 = s1[:n1]+'1'+s1[n1+1:]
                    carry = '0'
                
                else:
                    if(n1<0):
                        s1 = '0' + s1
                    else:
                        s1 = s1[:n1]+'0'+s1[n1+1:]
                    carry = '0'
            n1-=1
            n2-=1

        if(carry == '1'):
            return carry+s1
        else:
            index = 0
            while(index<len(s1) and s1[index]=='0'):
                index+=1
            if(index >= len(s1)):
                return "0"
            
            return s1[index:]

#: 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        answer = ob.addBinary(a, b)

        print(answer)
        print("~")

#  Driver Code Ends