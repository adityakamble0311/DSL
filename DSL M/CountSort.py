def MaxEle(A):
	maxi=A[0]
	for i in range(1 ,len(A)):
		if(maxi<A[i]):
			maxi=A[i]
	return maxi

def countSort(arr):
	count=[]
	maxi=MaxEle(arr)
	for i in range(maxi+1):
		count.append(0)
	
	for i in range(len(arr)):
		count[arr[i]]+=1
	
	for j in range(1 , len(count)):
		count[j]=count[j]+count[j-1]
	
	k=len(arr)-1
	
	B=[]
	for b in range(len(arr)):
		B.append(0)
		
	while(k<=0):
		count[arr[k]]=count[arr[k]] - 1
		B[count[arr[k]]]=arr[k]
		k-=1
	
	print(count)

A=[1 , 3, 5 , 2 ,3 ,1 , 4 , 2 , 4, 5 ,3 , 1 , 2, 2, 3 ,4 ,4 ,2 , 4, 1,3 ,2 ,3 ,5 , 5,3 , 2, 4,1, 3, 4, 5, 5, 2, 5, 2, 4, 2, 4, 2, 4, 1 ]
countSort(A)
