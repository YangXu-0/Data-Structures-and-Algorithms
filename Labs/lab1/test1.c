#include <stdio.h>
#include "lab1.h"

int main() {

    // PART 1
    printf("Part 1\n");

    double test_1 = split_bill(50.01, 0.13, 0.15, 2);
    printf("The first split will be: $%.2f.\n", test_1);
    // $32.50

    double test_2 = split_bill(5, 0.13, 0.15, 3);
    printf("The second split will be: $%.2f.\n", test_2);
    // $2.17

    double test_3 = split_bill(8, 0.23, 1.3, 10);
    printf("The third split will be: $%.2f.\n", test_3);
    // $2.27

    double test_4 = split_bill(80.32, 0.21, 0.0005, 3);
    printf("The fourth split will be: $%.2f.\n", test_4);
    // $32.42

    
    // PART 2
    printf("\nPart 2\n");

    double test_5 = adjust_price(25.00);
    printf("The adjusted price is $%.2f.\n", test_5);
    // $50.00

    double test_6 = adjust_price(0.32);
    printf("The adjusted price is $%.2f.\n", test_6);
    // $5.66

    double test_7 = adjust_price(5.0);
    printf("The adjusted price is $%.2f.\n", test_7);
    // $22.36

    double test_8 = adjust_price(32.42);
    printf("The adjusted price is $%.2f.\n", test_8);
    // $56.94


    // PART 3
    printf("\nPart 3\n");

    char test_food_1[] = "Three Cheese Pizza";
    int test_9 = sandy_eats(test_food_1);
    if (test_9 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_1);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_1);
    }
    // Sandy would eat 'Three Cheese Pizza'.

    char test_food_2[] = "Juicy Steak";
    int test_10 = sandy_eats(test_food_2);
    if (test_10 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_2);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_2);
    }
    // Sandy would NOT eat 'Juicy Steak'.

    char test_food_3[] = "French Fries";
    int test_11 = sandy_eats(test_food_3);
    if (test_11 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_3);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_3);
    }
    // Sandy would NOT eat 'French Fries'.

    char test_food_4[] = "French Fries Fish";
    int test_16 = sandy_eats(test_food_4);
    if (test_16 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_4);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_4);
    }
    // Sandy would NOT eat 'French Fries Fish'.

    char test_food_5[] = "eee";
    int test_17 = sandy_eats(test_food_5);
    if (test_17 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_5);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_5);
    }
    // Sandy would NOT eat 'eee'.

    char test_food_6[] = "fish";
    int test_18 = sandy_eats(test_food_6);
    if (test_18 == 0) {
        printf("Sandy would NOT eat '%s'. \n", test_food_6);
    }
    else {
        printf("Sandy would eat '%s'. \n", test_food_6);
    }
    // Sandy would NOT eat 'fish'


    // Part 4
    printf("\nPart 4\n");

    char test_12[30] = "zebra";
    imagine_fish(test_12);
    printf("Just imagine, a %s!\n", test_12);

    char test_13[30] = "fish";
    imagine_fish(test_13);
    printf("Just imagine, a %s!\n", test_13);

    char test_14[30] = "pizza";
    imagine_fish(test_14);
    printf("Just imagine, a %s!\n", test_14);

    char test_15[30] = "lettuce";
    imagine_fish(test_15);
    printf("Just imagine, a %s!\n", test_15);

    return 0;
}