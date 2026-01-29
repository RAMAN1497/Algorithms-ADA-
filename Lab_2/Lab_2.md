# Algorithm 

1. Binary Search

Aim
Efficiently locate a target value in a sorted array by repeatedly halving the search space — comparing the target with the middle element and discarding the half where the target cannot exist.

Algorithm

BinarySearch(arr, low, high, target):
  IF low > high:
    RETURN -1             

  mid = low + (high - low) / 2

  IF arr[mid] == target:
    RETURN mid            
  ELSE IF arr[mid] > target:
    RETURN BinarySearch(arr, low, mid-1, target)   
  ELSE:
    RETURN BinarySearch(arr, mid+1, high, target)  



Complexity

| Case    | Time      | Space                              |
|---------|-----------|------------------------------------|
| Best    | O(1)      | O(log n) — recursive call stack    |
| Average | O(log n)  | O(log n)                           |
| Worst   | O(log n)  | O(log n)                           |

> Iterative binary search achieves O(1) space. The recursive version here uses O(log n) stack space.

Use case
 Dictionary / autocomplete lookups in sorted word lists
 Searching a sorted product catalogue by ID or price range
 Finding a version that introduced a bug (git bisect uses binary search)

---

2. Insertion Sort

Aim
Build a sorted array one element at a time by picking each new element and shifting larger sorted elements rightward until the correct insertion position is found.

Algorithm 

InsertionSort(arr, n):
  FOR i = 1 TO n-1:
    key = arr[i]         
    j = i - 1
    WHILE j >= 0 AND arr[j] > key:
      arr[j+1] = arr[j]   
      j = j - 1
    arr[j+1] = key        


Complexity

| Case    | Time  | Space | Input Condition          |
|---------|-------|-------|--------------------------|
| Best    | O(n)  | O(1)  | Already sorted array     |
| Average | O(n²) | O(1)  | Random order             |
| Worst   | O(n²) | O(1)  | Reverse sorted array     |


Use case

 Sorting a hand of playing cards — the natural human sorting strategy
 Online sorting — inserting new elements into an already-sorted live list
 Sorting small sub-arrays inside hybrid algorithms like TimSort and IntroSort


---

