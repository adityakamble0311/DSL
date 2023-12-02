def bucket_sort(arr):
   
    max_val = max(arr)

    num_buckets = len(arr)
  
    buckets = [[] for i in range(num_buckets)]
    
    for num in arr:
        index = int(num * num_buckets / (max_val + 1))
        buckets[index].append(num)


    for bucket in buckets:
        bucket.sort()

    sorted_array = [num for bucket in buckets for num in bucket]

    return sorted_array

my_list = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
sorted_list = bucket_sort(my_list)
print("Sorted List:", sorted_list)
