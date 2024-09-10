// containing substring "01"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(const char *input)
{
    // Track current states
    bool states[3] = {false, false, false};
    states[0] = true; // Start in state S0

    while (*input)
    {
        bool nextStates[3] = {false, false, false};

        if (states[0])
        {
            if (*input == '0')
            {
                nextStates[1] = true; // Transition from S0 to S1
            }
        }

        if (states[1])
        {
            if (*input == '1')
            {
                nextStates[2] = true; // Transition from S1 to S2
            }
            if (*input == '0')
            {
                nextStates[1] = true; // Stay in S1
            }
        }

        if (states[2])
        {
            if (*input == '0')
            {
                nextStates[1] = true; // Transition from S2 to S1
            }
            if (*input == '1')
            {
                nextStates[2] = true; // Stay in S2
            }
        }

        // Move to next character
        input++;

        // Update current states
        states[0] = nextStates[0];
        states[1] = nextStates[1];
        states[2] = nextStates[2];
    }

    return states[2]; // Accept if in state S2
}

int main()
{
    char input[100];

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
        printf("The string is accepted.\n");
    }
    else
    {
        printf("The string is not accepted.\n");
    }
    printf("By Saroj Dhakal [79010253]");

    return 0;
}
