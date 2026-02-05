# Algorithms

1. Merge Sort

Aim
Efficiently sort an array using the divide-and-conquer approach by recursively dividing the array into halves, sorting them, and merging the sorted halves.

Algorithm
MergeSort(arr, start, end):
    IF start < end:
        mid = start + (end - start) / 2

        MergeSort(arr, start, mid)
        MergeSort(arr, mid + 1, end)

        Merge(arr, start, mid, end)


Merge(arr, start, mid, end):
    Create left[] and right[] subarrays

    Copy elements into left[] and right[]

    i = 0, j = 0, k = start

    WHILE i < size(left) AND j < size(right):
        IF left[i] <= right[j]:
            arr[k] = left[i]
            i++
        ELSE:
            arr[k] = right[j]
            j++
        k++

    Copy remaining elements of left[]
    Copy remaining elements of right[]
Complexity
Case	Time	Space
Best	O(n log n)	O(n)
Average	O(n log n)	O(n)
Worst	O(n log n)	O(n)

Merge Sort always takes O(n log n) time regardless of input.
Extra space is required for temporary arrays.

Use Case
Sorting large datasets efficiently
External sorting (files, databases)
When stable sorting is required
Used in divide-and-conquer based problems


2. Quick Sort

Aim
Efficiently sort an array by selecting a pivot element and partitioning the array such that elements smaller than the pivot come before it and larger elements come after.

Algorithm
QuickSort(arr, low, high):
    IF low < high:
        pivotIndex = Partition(arr, low, high)

        QuickSort(arr, low, pivotIndex - 1)
        QuickSort(arr, pivotIndex + 1, high)


Partition(arr, low, high):
    pivot = arr[low]
    i = low + 1
    j = high

    WHILE i <= j:
        WHILE arr[i] < pivot:
            i++
        WHILE arr[j] > pivot:
            j--

        IF i < j:
            swap(arr[i], arr[j])
            i++
            j--

    swap(arr[low], arr[j])
    RETURN j
Complexity
Case	Time	Space
Best	O(n log n)	O(log n)
Average	O(n log n)	O(log n)
Worst	O(n²)	O(n)

Quick Sort is very fast in practice but can degrade to O(n²) when the pivot selection is poor (e.g., already sorted array).

Use Case
 In-memory sorting (very fast in practice)
 Systems where space optimization is important
 Used in standard libraries (optimized versions)
 Good for random data
