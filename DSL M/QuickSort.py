def partition(arr , lb , ub):
	piv=arr[lb]
	start=lb
	end=ub
	
	while(start<end):
		while(arr[start] <= piv):
			start=start+1
			
		while(arr[end]>piv):
			end=end-1
			
		if(start<end):
			temp=arr[start]
			arr[start]=arr[end]
			arr[end]=temp

	if(start>end):
		temp=arr[end]
		arr[end]=piv
		arr[lb]=temp
   
	return end
	
def QuickSort(arr , lb , ub):
	if(lb<ub):
		loc=partition(arr , lb , ub)
		QuickSort(arr , lb , loc-1)
		QuickSort(arr , loc+1 , ub)
	
	return arr

A=[ 65 , 43 , 76 , 48 , 99  , 82 , 15 , 55 , 25 , 34]
lb=0
ub=len(A)-1

sortedarr=QuickSort(A , lb , ub)
print(sortedarr)






