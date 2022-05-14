/*
Hash Tables
- A data structure that stores key/value data for fast lookup operations
    - Usually looks lke an array
- A hash function, h(x), maps a key value, x, to a bucket value (location in the data structure, e.g. index in an array)
    - If h(x) maps 1:1, then going to bucket b = h(x) (e.g. array[h(x)]) should give the value we're looking for in O(1)
- h(x) is often imperfect and may map multiple keys to the same bucket (collision), but it should still give us a head start one where to look
    - Need to define where to look next if we are not overwriting the buckets
- Collisions increase the lookup runtime when we have to keep looking
- We can try to reduce the number of collisions by:
    - Setting up more buckets than there are keys
        i.e. starting with a load factor alpha = (number of items/number of buckets) < 1
    - Choosing a hash function that reduces collisions
    Some ex of hash functions
        h(x) = {0, if x is "Banana". 1, otherwise} h(x) = x%b, where b = number of buckets
        h(x) = {ascii value of first letter of key} h(x) = x

Collision Handling
- Some collision handling strategies
    - Chaining - nesting structures inside the buckets
    - Open addressing - probing for another (empty) bucket
    - Dynamic resizing - resizing the hash table
    - Overwriting - new data overwrites the buckets contents
- There are subsets of possible strategies
- May want to combine strats

Chaining
- Idea: nesting structures inside the bucekts
    - The buckets are data structures (linked lists, binary trees, etc.) rather than one value
- Allows us to store multiple values at the same bucket but now we may hav eto search through the bucket data structure
- Not great when bucket data structures are large - takes time to search through nodes and consumes extra space for pointers
    - Fine if you don't care about these things and have data structures already

Open Addressing
- Idea probing for another (empty) bucket
- Linear probing
    - If h(x) = b is occupied, try the next bucket, b+i for i iterations as needed
    - Not that buckets b to b+i are now occupied (clustering)
- Quadratic probing
    - If h(x) = b is occupied, try b+i^2 for i iterations as needed
    - Items are more spread out, but implementation is more complicated
- Double hashing
    - If h(x) = b is occupied, try b+h2(x) where h2(x) is another hash function

Dynamic Resizing
- Idea: resizing the hash table when alpha close to 1 or some other threshold 
    - Increasing number of buckets when we can't reduce the number of items
- Keep track of number of items, and current size of the hash table as you add and remove items
- Decide what happens after resizing 
    - Do we change h(x) and re-hash all the items?
        - Should make subsequent look-ups fast and keeps h(x) simple
    - Do we leave the items and probe with a secondary hash function?
        - Lazier, slower, and can become more complicated
- May want to consider resizing down to a smaller hash table if you will be removing a lot of items

Overwriting
- Idea: new data overwrites bucket contents
- Advantages: don't need to change h(x) or the size of the hash table
- Disadvantages: data is lost by overwriting 
    - Okay if h(x) is 1:1 and you want to update/replace the data

Hash Tables General Overview
- Complexity summary in LEC0101 slides (depends on implementation)
- Initialize a hash table for N keys and B = 2^m buckets such that the load factor, alpha = N/B < 1 or some other threshould
- Choose a hash function, h(key), and collision handling method
- Iterate over the keys
    - Obtain the bucket value, b, by applying the hash function: b = h(key)
    - Insert key/value data at bucket b, handling collisions as needed
- Dynamically resize as needed 
- Lookup values by checking b = h(key) and searching/probing further than needed
*/