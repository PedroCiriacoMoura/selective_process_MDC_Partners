/*
    Selective Process MDC Partners - v1.0 - 2023-07-29
    Author: Pedro Moura

    To compile in the terminal (command prompt):
    Linux: gcc -o PedroMoura PedroMoura.c
    Windows: gcc -o PedroMoura PedroMoura.c

    To execute in the terminal (command prompt):
    Linux: ./PedroMoura
    Windows: PedroMoura
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Exercise 1: Simple Calculator
float calculate(float num1, float num2, char operator)
{
    switch (operator)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            printf("Division by zero is not allowed.\n");
            exit(EXIT_FAILURE);
        }
    default:
        printf("Invalid operator. Only +, -, *, and / are allowed.\n");
        exit(EXIT_FAILURE);
    }
}

// Exercise 2: Prime Numbers
bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printFirstNPrimes(int n)
{
    int count = 0;
    int num = 2;

    while (count < n)
    {
        if (isPrime(num))
        {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    printf("\n");
}

// Exercise 3: Factorial
unsigned long long factorial(int num)
{
    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        exit(EXIT_FAILURE);
    }

    if (num == 0)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

// Exercise 4: Palindrome
bool isPalindrome(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++)
    {
        if (tolower(word[i]) != tolower(word[len - i - 1]))
        {
            return false;
        }
    }

    return true;
}

// Exercise 5: Table
void displayMultiplicationTable(int number)
{
    for (int i = 1; i <= 10; i++)
    {
        int result = number * i;
        printf("%d x %d = %d\n", number, i, result);
    }
}

// Exercise 6: Vowel Counter
int countVowels(char *sentence)
{
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        char c = tolower(sentence[i]);
        for (int j = 0; j < sizeof(vowels) / sizeof(vowels[0]); j++)
        {
            if (c == vowels[j])
            {
                count++;
                break;
            }
        }
    }

    return count;
}

// Exercise 7: Grade Average
float calculateGradeAverage(int grades[], int numGrades)
{
    if (numGrades == 0)
    {
        printf("No grades provided.\n");
        exit(EXIT_FAILURE);
    }

    int total = 0;
    for (int i = 0; i < numGrades; i++)
    {
        total += grades[i];
    }

    return (float)total / numGrades;
}

// Exercise 8: Interest Calculation
float calculateFinalValue(float initialCapital, float interestRate, int investmentTimeInMonths)
{
    if (initialCapital <= 0 || investmentTimeInMonths <= 0)
    {
        printf("Initial capital and investment time must be greater than zero.\n");
        exit(EXIT_FAILURE);
    }

    float interestRatePerMonth = interestRate / 100.0 / 12.0;
    float finalValue = initialCapital * pow(1 + interestRatePerMonth, investmentTimeInMonths);

    return roundf(finalValue * 100) / 100; 
}

int main()
{
    int choice;
    bool control = true;
    
    do
    {
        printf("\n");
        printf("Select an exercise:\n");
        printf("1. Simple Calculator\n");
        printf("2. Prime Numbers\n");
        printf("3. Factorial\n");
        printf("4. Palindrome\n");
        printf("5. Table\n");
        printf("6. Vowel Counter\n");
        printf("7. Grade Average\n");
        printf("8. Interest Calculation\n");
        printf("0. EXIT\n");
        printf("Enter your choice (0-8): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
        {
            control = false;
            break;
        }
        case 1:
        {
            float num1, num2;
            char operator;

            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("Enter an operator (+, -, *, /): ");
            scanf(" %c", &operator);

            float result = calculate(num1, num2, operator);
            printf("Result: %f\n", result);
            break;
        }
        case 2:
        {
            printf("First 10 prime numbers: ");
            printFirstNPrimes(10);
            break;
        }
        case 3:
        {
            int num;

            printf("Enter a number: ");
            scanf("%d", &num);

            unsigned long long result = factorial(num);
            printf("Factorial: %llu\n", result);
            break;
        }
        case 4:
        {
            char word[100];

            printf("Enter a word: ");
            scanf("%s", word);

            if (isPalindrome(word))
            {
                printf("%s is a palindrome.\n", word);
            }
            else
            {
                printf("%s is not a palindrome.\n", word);
            }
            break;
        }
        case 5:
        {
            int number;

            printf("Enter a number: ");
            scanf("%d", &number);

            displayMultiplicationTable(number);
            break;
        }
        case 6:
        {
            char sentence[100];

            printf("Enter a sentence: ");
            scanf(" %[^\n]", sentence);

            int vowelCount = countVowels(sentence);
            printf("Number of vowels: %d\n", vowelCount);
            break;
        }
        case 7:
        {
            int grades[3];

            for (int i = 0; i < 3; i++)
            {
                printf("Enter grade %d: ", i + 1);
                scanf("%d", &grades[i]);
            }

            float average = calculateGradeAverage(grades, 3);
            printf("Average grade: %.2f\n", average);
            break;
        }
        case 8:
        {
            float capital, rate;
            int time;

            printf("Enter initial capital: ");
            scanf("%f", &capital);
            printf("Enter interest rate: ");
            scanf("%f", &rate);
            printf("Enter investment time in months: ");
            scanf("%d", &time);

            float finalValue = calculateFinalValue(capital, rate, time);
            printf("Final value: %.2f\n", finalValue);
            break;
        }
        default:
            printf("Invalid choice. Please select a number from 1 to 8.\n");
            break;
        }
    } while (control);

    return 0;
}