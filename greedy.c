#include <stdio.h>
#include <string.h>
#include <cs50.h>



float valid_change();
void coins(int);

int main(void)
{
    float change;

    change = valid_change();
    coins((int) change);

}

// repeat prompt to type in value amount until condition is met.


float valid_change()
{
    float input;

// obtainig a floating variable
// continous prompting to type valid variable.
// assumption that the variable will always have 2 decimal place values at most.

    do
    {
        input = get_float("Type in the customer's change in Dollars \n$");
    }
    while (input < 0.00);


// convert the amount from dollars to cents.
    return (input * 100);
}

// counting number for coin.

void coins(change)
{
    int number_of_coin = 0;

// using the largest possible coin values first

    if (change >= 25)
    {
        number_of_coin = ((change - (change % 25)) / 25);
        change = change % 25;
    }

    if (change >= 10)
    {
        number_of_coin += ((change - (change % 10)) / 10);
        change = change % 10;
    }

    if (change >= 5)
    {
        number_of_coin += ((change - (change % 5)) / 5);
        change = change % 5;
    }

    if (change >= 1)
    {
        number_of_coin += change ;

    }
// print out the least amount of coin  possible.

    printf("total of %i coins \n", number_of_coin);
}