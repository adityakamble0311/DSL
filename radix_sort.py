def radix_sort(arr):
    max_num = max(arr)
    max_digits=len(str(max(arr)))
    for digit_position in range(1, max_digits + 1):
        arr = sorted(arr, key=lambda x: (x // 10**(digit_position-1)) % 10)
    return arr
arr = [170, 45, 75, 90, 802, 24, 2, 66]
sorted_arr = radix_sort(arr)
print("Sorted array:", sorted_arr)
