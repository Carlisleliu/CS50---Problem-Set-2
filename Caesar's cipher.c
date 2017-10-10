```
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    // make sure the programme is executed with 2 command-line arguments, otherwise exit the programme with an exit code of 1
    if (argc != 2)
    {
        printf("The key is missing. Please re-execute the programme with 2 command-line arguments.\n");
        return 1;
    }
    
    //  convert the 2nd argument from string to integer
    int argument = atoi(argv[1]), k;
    
    // make sure the value of 2nd argument is between 0 and 2^31 - 26, otherwise exit the programme with an exit code of 2
    if (argument >= 0 && argument <= pow(2, 31) - 26)
    {
        // set the value of key, which is used to cipher the plaintext, between 1 and 26
        k = argument % 26;
    }
    else
    {
        printf("The key is invalid\n");
        return 2;
    }
    
    string p;
    
    // prompt the user to key in the plaintext, which cannot be empty
    do
    {
        printf("plaintext: ");
        p = get_string();
    }
    while (p == NULL);
    
    // iterate through each character in the plaintext
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // identify the alphabetical characters
        if (isalpha(p[i]))
        {
            // identify the uppercase characters
            if (isupper(p[i]))
            {
                // cipher the character using key, wrapping around 'A' and 'Z' 
                printf("%c", (p[i] - 'A' + k) % 26 + 'A');
            }
            // identify the lowercase characters
            else if (islower(p[i]))
            {
                // cipher the character using key, wrapping around 'a' and 'z' 
                printf("%c", (p[i] - 'a' + k) % 26 + 'a');
            }
        }
        else
        {
            // if the character is not alphabetical, do not cipher it.
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
    // the exit code for succesful implementation is 0
    return 0;
}
```
