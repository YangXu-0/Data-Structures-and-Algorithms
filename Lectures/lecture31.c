/*
- Can use shifting as a tracker
    Ex. unsigned char width = (~0b0)
        if shift once everytime, after 8 times will be all 0s

Two's Complement
- A commonly used method for representing signed numbers
- Recall signed numbers use the MSB to indicate the sign (+/-)
    - MSB/leading bit of 1 indicates a negative value
- To represent a negative value, invert binary bits of the positive value and add 1
    - Note that leading zeros become 1s

Ex. 
    To represent -85, we invert binary bits of 85 and add 1
    

Look Up
- Worst-case runtime
    - Linked list
        - O(n), have to check n elements
    - Array
        - Unsorted: O(n) have to check n elements
        - Sorted: O(long), can skip ahead to different sections
    - Binary Search Tree
        - Unbalanced: O(n)
        - Balanced: O(n)

- Want something like dictionaries in Python
    - Use a index/key value that maps to the location of the value within the data structure

Hash Tables
- A data structure that stores key/value data
    - Usually an array. may include nested structures but we should aim to use all indexes in the array first
    - Keys are identifiers for the value data
- Uses a hash function, h(x), to map the key value, x, to some location (bucket, hash, hash value, hash code, etc.) in the data structure
- A hash function, h(x), maps a key value, x, to a bucket value (location in the data structure, e.g. index in an array)
- h(x) should always yield the same bucket result   
    - Ideally, h(x) is fast to compute
- H(x) is not necessarily one to one
    - Ideally, h(x) results in uniformly distributed spread of bucket values
- Need to define what to do when there is a collision - new data hashes to a bucket that already contains data
    - Find a new location, or overwrite existing data

Hash Table Load Factor
- A hash table with n items and b buckets has a load factor of n/b
- If we resize our hash table by doubling, b= 2^m, with some integer m
- What is the ideal load factor for O(1) lookup time?
    - Want there to be more buckets than items
    - Typically aim for n/b < 1 or n/b < a for some constant at to reduce the likihood of collisions
    - Still there may be collisions

Hash Tables and Collision Handling 
- Hash table lookup efficiency depends on:
    - Load factor (number of items, number of buckets)
    - Spread and uniformity of the hash functions
- These factors redcu
*/