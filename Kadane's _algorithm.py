# Author :Prashant kumar
#  Kadane’s Algorithm for Largest Sum Contiguous Subarray\
# CONCEPT BELOW  I learn for love babber
'''Initialize:
    A = INT_MIN
    C = 0

Loop for each element of the array
  (a) C = C + a[i]
  (b) if(A < C)
            A= C
  (c) if(C < 0)
            C = 0
return A'''

# CODE BELOW
from sys import maxint
def maxSubArraySum(a,size):
      
    A = -maxint - 1
    C = 0
      
    for i in range(0, size):
        C = C + a[i]
        if (A < C):
            A = C
 
        if C < 0:
           C = 0  
    return A
# thank you