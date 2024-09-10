// if the input string has 'aaa' as substring then print 1 otherwise 0
#include <stdio.h>
#include <string.h>

// Moore machine states
#define START 0
#define A 1
#define AA 2
#define AAA 3

// Function to process the input string
int process_string(const char *str)
{
    int state = START;
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        switch (state)
        {
        case START:
            if (str[i] == 'a')
            {
                state = A;
            }
            break;
        case A:
            if (str[i] == 'a')
            {
                state = AA;
            }
            else
            {
                state = START;
            }
            break;
        case AA:
            if (str[i] == 'a')
            {
                state = AAA;
                printf("1"); // Print 1 as soon as "aaa" is found
                return 0;    // Exit the function
            }
            else
            {
                state = A;
            }
            break;
        case AAA:
            // Do nothing, we've already printed 1
            break;
        }
    }
    printf("0"); // Print 0 if "aaa" is not found
    return 0;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    process_string(str); // Process the string
    printf("\n By Saroj Dhakal [79010253]");
    return 0;
}
