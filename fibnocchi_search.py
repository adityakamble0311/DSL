def fibonacci_serach(arr,user):
    n = len(arr)

    fib1 , fib2 = 0,1
    fib  = fib1+fib2

    while fib<n:
        fib1 = fib2
        fib2 = fib
        fib = fib1+fib2
    
    offset = -1
    while fib>n:
        i = min(offset + fib2, n-1)
        if arr[i]<user:
            fib2 = fib1
            fib1 = fib - fib2
            fib = fib1 + fib2
        elif arr[i]>user:
            fib1 = fib2
            fib2 = fib - fib1
            fib = fib1 + fib2
        else:
            return i
    if fib1 and arr[offset+1]==x:
        return offset + 1
    return -1

arr = [10,30,40,100,90,50,70]
user = 20
index = fibonacci_serach(arr,user)
if index != -1:
    print("Element is present at index",index)
else :
    print("Element is not present in array")