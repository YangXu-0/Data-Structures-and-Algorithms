/*
Collision Handling - Additional Notes
- Overwriting
    - Can return the old value or just quietly remove it
- Dynamic resizing
    - Resizing by *2 is just one option, can resize by a different amount
- Open addressing
    - During insert, if hashed bucket is not empty/null, iterate the OA method until an empty bucket is found
        - Should probably set an iteration limit
    - During lookup/delete, probably want to set a threshold for how many iterations
      to check or be sure that the item is there
- Chaining
    - Be careful with pointer/memory handling

Live coding
*/