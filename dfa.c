//string ends with '01'
#include <stdio.h>
#include <string.h>

int isAccepted(const char *input)
{
    int state = 0; // Start in state S0

    while (*input)
    {
        switch (state)
        {
        case 0:
            if (*input == '0')
            {
                state = 1; // Transition to S1
            } // Else stay in S0
            break;
        case 1:
            if (*input == '1')
            {
                state = 2; // Transition to S2
            }
            else if (*input == '0')
            {
                // Stay in S1
            }
            break;
        case 2:
            if (*input == '0')
            {
                state = 1; // Transition to S1
            } // Stay in S2 on '1'
            break;
        }
        input++;
    }

    return (state == 2); // Accept if in state S2
}

int main()
{
    char input[50];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    if (isAccepted(input))
    {
        printf("The string is ACCepted.\n");
    }
    else
    {
        printf("The string is not ACCepted.\n");
    }
    printf("By Saroj Dhakal [79010253]");
    return 0;
}
