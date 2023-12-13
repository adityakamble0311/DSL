def Insertion_sort(arr ):
	for i in range(1, len(arr)):
		temp=arr[i]
		j=i-1
		while( j>=0 and arr[j]>temp):
			arr[j+1]=arr[j]
			j=j-1
		arr[j+1]=temp
	return arr
		

arr=[12 , 54, 32 , 33 , 21 , 22, 45 , 56 , 87 ,65]
Sorted_arr=Insertion_sort(arr)
print("\n")
print(arr)
print("\n")


	
		 
