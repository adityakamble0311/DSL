def quick_sort(arr):
    n= len(arr)
    if n<= 1:
        return arr
    
    pivot = arr[n// 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

my_array = [27, 76, 17, 9, 57, 90, 45, 100, 79]
sorted_array = quick_sort(my_array)
print("Sorted Array:", sorted_array)
