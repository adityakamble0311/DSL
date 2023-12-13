def ShellSort(a  ):
	gap=len(a)//2
	while(gap>=1):
		for j in range(gap , len(a)):
			temp=a[j]
			i=j
			while(a[i-gap]>temp and i>=gap):
				a[i]=a[j-gap]
				i=i-gap
			a[i]=temp
		gap=gap//2
		
	return a
	
A=[12 , 3 , 45 , 76 , 84 , 22 , 34 , 51 , 88 , 90 , 52 , 1 , 69 , 49]
B=ShellSort(A)

print(B)	


	
