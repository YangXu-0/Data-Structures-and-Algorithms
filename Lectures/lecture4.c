/*
- static arrays are arrays where the size does not change
- "ad" > "abc"
    - compares left to right
        -strcmp

- runtime is pain.
- paaaaaaiiiiiiin
- pain.

- Big O notation defines an upper bound for the runtime complexity
- Omega notation defines lower bound
- Theta notation defines upper and lower bounds
- We care about the time it takes for an algorithm to run but is not possible to directly compute
  so we consider units proportional to runtime (e.g. number of iterations, operations)
    - Write as a function of the size of input n e.g. length of array, value
- We care about what happens when the input is larger
    - Drop slow-growing (smaller) terms and constant coefficients
- Want to give a tight bound O(g(n))
    - f(n) (actual) needs to be growing slower than g(n) but closer the better

- Insertion sort
    - Iterate through array elements in the unsorted section, taking one element at a time and inserting
      it into the correct position of the sorted side of the array
    - Best case O(n)
        - Array is already sorted 
        - n-1 comparisons (to check) --> O(n)
    - Worst case O(n^2)
        - Array is sorted in reverse
        - 1 + 2 + ... + (n-1) comparisons = (n^2+n)/2 --> O(n^2)
        - 1 + 2 + (n-1) swaps = (n^2+n)/2 --> O(n^2)

- Selection sort
    - Iterate through array elements in the unsorted section, finding the smallest element and moving it to
      the front of the unsorted section
    - Best case: O(n^2)
        - Array is already sorted
        - (n-1)+..+2+1 comparisons --> O(n^2)
        - No swaps --> O(0)
    - Worst case O(n^2)
        - Array is sorted in reverse
        - (n-1)+...+2+1 comparisons --> O(n^2)
        - (n-1)+...2+1 swaps --> O(n^2)

- Bubble sort
    - Iterate through array elements in the unsorted section, swapping elements to move the largest
      element of the unsorted section to the sorted section.
    - Best case: O(n)
        - Array is already sorted
        - If 0 swaps after sweep break
            - O(n-1 + 0) --> O(n)
    - Worst case O(n^2)
        - Array is sorted in reverse
        - (n-1)+...+2+1 comparisons --> O(n^2)
        - (n-1)+...2+1 swaps --> O(n^2)

- Merge sort
    - Split array in halves repeatedly to form single element (sorted) arrays and merge subarrays to form
      one single sorted array
    - When merging 2 arrays, each with m elements, have roughly O(2m) -> O(m)
        - Each level we merge n/k elements k times so O(n)
        - Total merging complexity = number of levels x n
        - log2n + 1 --> logn
    - Splitting complexity
        - O(1) x n-1 elements -> O(n-1) --> O(n)
    - Merging complexity --> O(nlogn) because fastest term
*/