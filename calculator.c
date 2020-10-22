/*
A calculator that accepts up to 5 numbers and performs
multiple mathematical operations on the given numbers.
*/

#include <stdio.h>
#include <stdlib.h>

// Add x and y
double add(double x, double y)
{
    return x + y;
}

// Subtract y from x
double subtract(double x, double y) {
    return x - y;
}

// Multipy x and y
double multiply(double x, double y)
{
    return x * y;
}

// Divide x by y
double divide(double x, double y)
{
    return x / y;
}


// Creating an operation data type for an array to hold the above math functions
typedef double (*operation)(double, double);

int main(void)
{
    double nums[5];
    char op;
    operation operators[5];
    double result;
    int i = 0;

    // Creating a banner and printing out instructions for how to use the program
    printf("\n ################################\n");
    printf(" ########## Calculator ##########\n");
    printf(" ################################\n\n");
    printf(" You may enter up to 5 numbers in you calculation.\n");
    printf(" If you wish to enter fewer than 5 numbers, type an \"=\" as the operator after your final number.\n\n");

    // Loop to recieve number and operator input from the user
    while (i < 5)
    {
        printf(" Enter a number: ");
        scanf("%lf", &nums[i]);

        if (i == 4)
        {
            operators[i] = NULL;
        }
        else
        {
            printf(" Enter an operator: ");
            scanf(" %c", &op);

            // Using the given operator to add its respective function to the operators array
            switch (op)
            {
                case '+':
                    operators[i] = add;
                    break;

                case '-':
                    operators[i] = subtract;
                    break;
            
                case '*':
                    operators[i] = multiply;
                    break;

                case '/':
                    operators[i] = divide;
                    break;    

                default:
                    operators[i] = NULL;
                    break;
            }
        }

        // If the current iteration of operators[] = NULL, break out of the loop
        if (!operators[i]) break;

        i++;
    }

    result = nums[0];


    // Applying the functions in the operators[] array to the numbers in the nums[] array
    for (i = 1; i < 5; i++)
    {
        if (operators[i - 1])
        {
            result = operators[i - 1](result, nums[i]);
        }
        else
        {
            break;
        }
    }
    

    // %.2f rounds the inputted double to 2 decimal places
    printf("Result: %.2f\n", result);
    
    return 0;
}
