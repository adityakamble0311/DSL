def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
user = input("Enter  a elements :")
user_list = [x for x in user.split()]
bubble_sort(user_list)
print ("Sorted array is:",user_list)
