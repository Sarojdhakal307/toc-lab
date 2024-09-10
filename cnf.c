//This program checks if the input string conforms to a simplified CFG representing balanced 'a's and 'b's with specific starting and ending characters. take input as (aaabbb)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define maximum sizes
#define MAX_RULES 10
#define MAX_STRING_LENGTH 100

// Grammar Rule Structure
typedef struct
{
    char lhs;                    // Left-hand side of the rule
    char rhs[MAX_STRING_LENGTH]; // Right-hand side of the rule
} Rule;

// Define the CFG
Rule grammar[MAX_RULES] = {
    {'S', "aSb"},
    {'S', ""},
    {'a', "a"},
    {'b', "b"}};

int num_rules = 4; // Number of rules in the grammar
// Check if a string can be derived from the given rule
bool matches_rule(char lhs, const char *str)
{
    for (int i = 0; i < num_rules; i++)
    {
        if (grammar[i].lhs == lhs)
        {
            return strcmp(grammar[i].rhs, str) == 0;
        }
    }
    return false;
}

// Check if a string is valid according to the grammar
bool is_valid_string(const char *str)
{
    int length = strlen(str);
    if (length == 0)
        return true; // Empty string is valid

    if (str[0] != 'a' || str[length - 1] != 'b')
        return false;

    // Check if the string is of the form 'aSb' where S can be empty or nested
    int balance = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'a')
            balance++;
        else if (str[i] == 'b')
            balance--;
        else
            return false; // Invalid character

        if (balance < 0)
            return false; // More b's than a's
    }

    return balance == 0; // Must be balanced
}
int main()
{
    char test_string[MAX_STRING_LENGTH];

    printf("Enter a string to check: ");
    scanf("%s", test_string);

    if (is_valid_string(test_string))
    {
        printf("The string '%s' is valid according to the CFG.\n", test_string);
    }
    else
    {
        printf("The string '%s' is not valid according to the CFG.\n", test_string);
    }
    printf("By Saroj Dhakal [79010253]");

    return 0;
}
