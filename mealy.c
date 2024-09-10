//it prints 1 if it contains substring 'aaa'
#include <stdio.h>
#include <string.h>

// Mealy machine states
#define START 0
#define A 1
#define AA 2

// Function to process the input string
void process_string(const char *str)
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
                printf("1"); // Print 1 when "aaa" is found
                state = AA;
            }
            else
            {
                state = (str[i] == 'b') ? START : A;
            }
            break;
        }
    }
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    process_string(str);
    printf("\n By Saroj Dhakal [79010253]");
    return 0;
}
