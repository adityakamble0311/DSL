A=[7,3,5,2,1,6,8,9,4]

for i in range(len(A)):
    mindex=i
    
    for j in range(i+1,len(A)):
        if A[j]<A[mindex]:
            mindex=j
            
    (A[i], A[mindex]) = (A[mindex] , A[i])
    
print(A)