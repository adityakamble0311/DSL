def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

my_array = [27, 76, 17, 9, 57, 90, 45, 100, 79]
insertion_sort(my_array)
print("Sorted Array:", my_array)
