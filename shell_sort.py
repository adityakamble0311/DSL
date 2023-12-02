def shell_sort(arr):
    n = len(arr)

    gap = n // 2

    while gap>0:
        for i in range(gap,n):
            temp = arr[i]
            j = i
            while j>=gap and arr[j-gap]>temp:
                arr[j]=arr[j - gap]
                j-=gap
                arr[j]=temp
        

        gap //= 2

arr = [90,30,10,20,40,80,100]
shell_sort(arr)
print("Sorted array is:",arr)