def tsearch(arr, k):  
    low = 0  
    high = len(arr) - 1  
    mid = 0  
  
    while low<=high:  
           
        mid1 = low+(high-low)//3
        mid2 = high-(high-low)//3  
        
        if arr[mid1] == k:
            return 1
        
        elif arr[mid2] == k:
            return 1
   
        elif arr[mid2] < k:  
            low = mid2+1  
     
        elif arr[mid1] > k:  
            high = mid1-1  
            
        else:
            low = mid1+1
            high = mid2-1
            
    return 0  
  
    
arr = [13, 19, 42, 48, 49, 57, 84, 88 , 90 , 92 , 100 , 101]  
key = 42
result = tsearch(arr, key)  
  
if result == 1 :
    print("Element is present \n  :) \n")  
else:  
    print("Element is not present \n   :(  \n")