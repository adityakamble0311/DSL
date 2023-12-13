def binary_search(arr, k):  
    low = 0  
    high = len(arr) - 1  
    mid = 0  
  
    while low<=high:  
           
        mid = (high+low)//2  
   
        if arr[mid] < k:  
            low = mid+1  
     
        elif arr[mid] > k:  
            high = mid-1  
            
        else:
            return 1
            
    return 0  
  
    
arr = [13, 19, 42, 48, 49, 57, 84]  
key = 42
result = binary_search(arr, key)  
  
if result == 1 :
    print("Element is present \n  :) \n")  
else:  
    print("Element is not present \n   :(  \n")