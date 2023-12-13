def bubble_sort(arr , n , j ):
	for i in range(n-j-1):
		if (arr[i]>arr[i+1]):
			temp=arr[i]
			arr[i]=arr[i+1]
			arr[i+1]=temp
			
			return bubble_sort(arr , n  , j+1)	
		else:
			return arr
			

def selection_sort(arr , n):
	for i in range(n):
		mindex=i
		for j in range(i+1 , n):
			if(arr[j]<arr[mindex]) :
				mindex=j
		
		temp=arr[i]
		arr[i]=arr[mindex]
		arr[mindex]=temp
	
	return arr

def top_5(arr , n):
	print("top 5 elements are")
	for i in range(5):
		print(arr[n-i-1])	

arr=[12,34,23,45,65,56,67,77]
n=len(arr)

Bs=bubble_sort(arr , n , 0)
print(Bs)
print("\n")

Ss=selection_sort(arr , n)
print(Ss)
print("\n")

top_5(Bs , n)
