#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a keyword
int is_keyword(char *word)
{
    char *keywords[] = {"auto", "break", "case", "char", "const", "continue",
                        "default", "do", "double", "else", "enum", "extern",
                        "float", "for", "goto", "if", "int", "long", "register",
                        "return", "short", "signed", "sizeof", "static", "struct",
                        "switch", "typedef", "union", "unsigned", "void", "volatile",
                        "while"};
    int i;
    for (i = 0; i < 32; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is a valid identifier
int is_identifier(char *word)
{
    if (is_keyword(word))
    {
        return 0;
    }
    if (!isalpha(word[0]) && word[0] != '_')
    {
        return 0;
    }
    int i;
    for (i = 1; i < strlen(word); i++)
    {
        if (!isalnum(word[i]) && word[i] != '_')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    if (is_keyword(word))
    {
        printf("%s is a keyword.\n", word);
    }
    else if (is_identifier(word))
    {
        printf("%s is a valid identifier.\n", word);
    }
    else
    {
        printf("%s is not a valid identifier or keyword.\n", word);
    }
    printf("\n By Saroj Dhakal [79010253]");

    return 0;
}
