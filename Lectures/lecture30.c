/*
- Number of bits used fo a data type can vary between computer systems
- Can be helpful to refer to relative bit positions
    MSB = most significant bit
        mask = (~0b0) ^ ((unsigned ...)(~0b0) >> 1);
    LSB = least significant bit
        mask = 0b01;
    n - the number of bits away from the bit

    Ex. n = 1 MSB means the bit is the bit adjacent to the MSB

Adder Circuits
- Modern computers use arithmetic logic units (ALUs) to carry out mathematical computations
- The adder circuit performs arithmetic addition using logic gates {and, or, xor, not}
- Can do addition with bits by adding bit by bit
    - Need to careful of carry overs don't overflow
- We want to two numbers a and b
- Let the bits of a be {an, an-1, ..., a1, a0} and b is the same thing
- The bits of the sum will be {rn, rn-1, r1, r0}
- The carry over for the ith place value will be ci
    - Set c0 = 0

- Make table of inputs and outputs, we see that:
    - At least two high inputs result in a carry-over high:
        ci = (ai & bi) | (ai &ci-1) | (bi & ci-1)
    - ri is high when exactly one input or all three inputs among {ai, bi, ci} are high
        ri = (ai ^ bi ^ ci) | (ai & bi & ci-1)
*/