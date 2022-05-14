/*
- In merge sort we were merging 2 arrays of similar length, m
    - O(2m) --> O(m)
- What if the arrays were of different lengths?
    - We would have O(a+b), where a and b are the lengths of each array
    - We could also say it is O(n), where n = a + b (a and b are the array lengths)
- What is the runtime complexity of comparing 2 strings?
    - Best: first character is different, 1 comparison --> O(1)
    - Worst: last character is different, a or b comparisons, O(min(a, b)) where a and b are the lengths
            of each string
- Always define your variables!
- For a fixed n, what are the best/worst configuration of the inputs?

- Quicksort (ex. sorting smallest to largest)
    - Divide and conquer
    - Set an element to be the pivot element --> move elements smaller than pivot to left, larger to right
        - Have 2 indexes starting from either side moving inwards
        - Find one smaller find one larger and swap
        - Once the indexes cross, it's done so insert the pivot there
    - Pivot element will be sorted --> repeat on left and right sections
    - The element you choose doesn't really matter 
        - (ex. you can just always choose the right most element in each section)

- Quick sort complexity
    - Best case: O(nlogn)
        - Pivot is always the median element, all partitions are balanced
        - Top level: n elements to handle at once then divide by 2 each time
            - O(n) at each level --> O(nlogn)
    - Worst case: O(n^2)
        - Pivot is always the smallest or largest element so subsequent partitions
          are unbalanced the entire time
        - n + (n-1) + .. + 2 + 1 comparisons. swaps across all partitions --> O(n^2)

    - Pivotal component of the alg is choice of pivot element
    - Alternatives:
        - First element (same problems)
        - Middle element, random (avoid choosing extreme if sorted)
        - Median of small set of elements (ex. median of front, back, and middle)

- Nice summary table of complexity in slides

- Worst case runtime: merge sort is fastest
    - Quick sort can usually avoid the worst case scenario for random data
    - Space complexity: quick sort is normally done in-place, while merge sort is normally done using extra arrays
        - Quick sort takes less space
- Best case runtime: insertion and bubble sort are the fastest
    - Rarely expect data to be naturally sorted already
    - Should probably use merge sort or quick sort (next fastest) unless the dataset is small
- Comparison sorts are limited to O(n) for best case and O(nlogn) for worst cases
    - See radix sorts which takes advantage of other operations
- Always consider the characteristics of the data when choosing an algorithm
    - Python's list.sort uses Tim Sort, a hybrid of Merge/Insertion Sort


*/