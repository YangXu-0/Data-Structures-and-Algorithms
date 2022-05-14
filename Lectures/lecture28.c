/*
Dijkstra's Algorithm
- Initially assume that all vertices are very far away from the start vetex
- Update the costs of the nearby vertices to reflect the min distance from the start vertex
    - Either the current distance is the minimum or moving from the current vertex is the minimum
- Visit the closest unvisited vertex based on what the current distances are

Binary Representation
- Number system based on powers of 2 (base-2 number system)
- The numbers we are familiar with are in decimal representation (base-10)
- Each digit is called a bit (8bits in a byte) representing a coefficient of a power
    - In decimal (base-10), bits range from 0-9 and rperesent a coefficient of a power of 10
    - In binary (base-2), bits are either 0 or 1 and represent a coefficient of a power of 2
- Depending on representation, may need more or less bits to represent a value
- Might choose representation based on context, number of options, etc.
- Decimal to binary
    - Use the largest power as the leading bit (most-significant bit)
    - Determine the remaining bits in descending powers of the base until base 0 (least significant bit)
- Binary to hexidecimal
    - Convert 4 bits at a time

Bitwise Operators
- Operate on integer data at the bit level
- Fast since computer hardware systems are implemented in binary
<< - shift left, the value of i<<j is the result of shifting the bits of i to the left j times. 
     Zeros added on the right
>> - shift right, the value of i>>j is the result of shifting the bits of i to the right j times.
    - If i is an unsigned int or has a non-neg value, zeroes are added on the left
    - If i is a negative value (leading bit is a 1), it is unclear if zeroes will be added or if 1s 
      will be added to preserve the sign
~ - bitwise complement, the value of ~the result of changing the zero bits of i to 1s and the 1 bits to
    zeroes (logical inversion, logical not, similar to !)
    - Note that leading zeros will become 1s
& - bitwise and, the value of i&j is the result of performing logical and on the bits of i and j
^ - bitwise exculsive or, the value of i^j is the result of performing logical xor on the bits of i and j
| - bitwwise inclusive or, the value of i|j is the result of performing logical or on the bits of i and j

- Safest to work with unsigned ints
    - Signed ints use the leading/left-most bit to indicate sign
    - Be careful when shifting right, bitwise complement, etc.
- Bitwise operators may be combined, used with arithmetic, used with assignemnt, etc.
- Shifting has lower precendence than arithmetic operators
    i << 2+1 means i<<(2+1) and not (i<<2)+1
- Highest to lowest precedence: ~, &, ^, |

- Working with single bits:
    - Setting a bit to 1
        i |= i<<j; // set bit j of i to 1
    - Clearing a bit (setting a bit to 0)
        i &= ~(1<<j); // set bit j of i to 0
    - Testing a bit (check if it has been set to 1)
        if (i & 1<<j); // will be 0 (false if bit j is not 1)
*/