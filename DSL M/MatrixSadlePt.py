from __future__ import print_function

m= int(input("Enter the number of rows:"))
n = int(input("Enter the number of columns:"))

matrix = []
for i in range(m):          
	Row =[]
	for j in range(n):     
		Row.append(int(input()))
	matrix.append(Row)
  

for i in range(m):
    for j in range(n):
        print(matrix[i][j], end=" ")
    print()
    
#saddle point program
min=0
colm=0
max=0
row=0
for i in range(m):
	min=matrix[i][0]
	for j in range(n):
		if(min>matrix[i][j]):
			min=matrix[i][j]
			colm=j
			
   
	max=min
	for k in range(m):
		if(min<matrix[k][colm]):
			max=matrix[k][colm]
   
	row=i
	if(min==max):
		print("The saddle point of matrix is :  ",min)
		print("The index of saddle point is [",row ," ,",colm ,"]")
		break;
		
if(min!=max):
	print("there is no saddle point in matrix")
				

		
  
		
