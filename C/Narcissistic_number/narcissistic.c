#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void num_into_str(int num, char * string)
{
    sprintf(string,"%d", num);
}

int get_digits(char * num_turned_into_str)
{    
    return strlen(num_turned_into_str);
    
}

int get_exponent(int digits)
{
    return digits-1;
}

void array_of_digits(char * num_turned_into_str, int * array, int digits)
{
    for (int index = 0; index < digits; ++index)
    {
        char digit = num_turned_into_str[index];
        array[index] = atoi (&digit);
    }
}

int exponentiation_and_addittion(int * array, int exponent)
{
    int sum = 0;
    for (int index = 0; index < exponent + 1; ++index)
    {
        int base = array[index];

        for (int index1 = 0; index1 < exponent; ++index1)
        {
            array[index] = array[index] * base;
        }

        sum += array[index];
    }
    return sum;
}

bool narcissistic(int num)
{
    char num_str[num];
    num_into_str(num, num_str);
    int array[get_digits(num_str)];
    array_of_digits(num_str, array, get_digits(num_str));

    if (exponentiation_and_addittion(array, get_exponent(get_digits(num_str))) == num)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main (){

    int num;
    printf("Please type a number:\n");
    scanf("%d",&num);

    if (narcissistic(num) == true)
    {
        printf("%d is a narcissist number :p\n",num);
    }
    else 
    {
        printf("%d is not a narcissist number T-T\n",num);
    }
    return 0;
}