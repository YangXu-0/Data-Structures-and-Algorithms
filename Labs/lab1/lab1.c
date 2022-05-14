#include <stdio.h>
#include <math.h>
#include <string.h>

// Part 1
double split_bill(double base_amount, double tax_rate, double tip_rate, int num_people) {

    double bill = ((base_amount * (tax_rate + 1)) * (tip_rate + 1)) / num_people;   // just does the math

    return ceil(bill * 100) / 100;   // rounds the value up and returns
}

// Part 2
double adjust_price(double original_price) {
    return 10 * pow(original_price, 0.5);
}

// Part 3
int sandy_eats(char menu_item[]) {

    const char j[] = "j";
    const char k[] = "k";
    const char l[] = "l";

    char *location_j = strstr(menu_item, j);
    char *location_k = strstr(menu_item, k);
    char *location_l = strstr(menu_item, l);

    const char cap_j[] = "J";
    const char cap_k[] = "K";
    const char cap_l[] = "L";

    char *location_cap_j = strstr(menu_item, cap_j);
    char *location_cap_k = strstr(menu_item, cap_k);
    char *location_cap_l = strstr(menu_item, cap_l);

    const char fish[] = "fish";
    char *location_fish = strstr(menu_item, fish);

    const char Fish[] = "Fish";
    char *location_Fish = strstr(menu_item, Fish);

    int num_letters = 0;
    for (int i = 0; i < strlen(menu_item); i++) {
        if (menu_item[i] != ' ') {
            num_letters += 1;
        }
    }

    if (location_j == NULL && location_k == NULL && location_l == NULL && 
    location_cap_j == NULL && location_cap_k == NULL && location_cap_l == NULL
    && location_fish == NULL && location_Fish == NULL) {
        if (num_letters % 2 != 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

// Part 4
const char* imagine_fish(char thing[]) {
    char fish[] = "fish";
    return strcat(thing, fish);
}


/* Questions
Part 1
1. If result is an int var and num is a float var, what does "result = (int) (num + 0.5);" do?
        0.5 will be added to the num variable and then it will be converted into an int (decimals are removed)

2. When and how did you handle the rounding the split amount?
    I used the ceil function from math.h to round the value. By first multiplying the value by 100, I make sure
    the second decimal place (cents) is in the single digit place. Then, ceil will round up the value to make it
    a whole number. Finally, dividing by 100 resets the cents value back to the second decimal place.
    This was done in the split_bill function (return statement)

Part 3
3. How would you solve this problem with and without using string.h functions? Explain.
    Create char array of size thing[] + 4, loop through thing[] and add every character to the new array and then 
    add fish (with a loop). Finally add a null terminator.
*/