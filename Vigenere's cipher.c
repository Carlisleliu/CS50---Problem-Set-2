```
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // make sure the programme is executed with 2 command-line arguments, otherwise exit the programme with an exit code of 1
    if (argc != 2)
    {
        printf("The key is missing. Please re-execute the programme with 2 command-line arguments.\n");
        return 1;
    }
    
    // keylength stores the a number representing the number of characters contained in the argument
    // create an array keycode with the size of keylength
    int keylength = strlen(argv[1]), keycode[keylength];
    
    // iterate through the characters in the argument
    for (int i = 0; i < keylength; i++)
    {
        // make sure the argument contains nothing but alphabetical characters
        if (!isalpha(argv[1][i]))
        {
            // if the argument contains non-alphabetical character, warn the user the exit the programme with exit code of 1
            printf("Your argument contains illegal character, please use only alphabet.");
            return 1;
        }
        else 
        {
            // convert the alphabetical characters to encoding key
            keycode[i] = toupper(argv[1][i]) - 'A';
        }
    }
    
    string p;
    
    // prompt the user to provide a non-empty plaintext to be encoded
    do
    {
        printf("plaintext: ");
        p = get_string();
    }
    while (p == NULL);
    
    printf("ciphertext: ");
    
    // iterate through the characters in the plaintext
    // count determines which code in keycode to use
    for (int i = 0, n = strlen(p), count = 0; i < n; i++)
    {
        // identify the alphabetical characters
        if (isalpha(p[i]))
        {
            // identify the uppercase characters
            if (isupper(p[i]))
            {
                // cipher the character using key, wrapping around 'A' and 'Z' 
                printf("%c", (p[i] - 'A' + keycode[count]) % 26 + 'A');
                
                // the next code in keycode will only be used when the current one is used to encode alphabetical character in plaintext
                if (count < keylength - 1)
                {
                    count++;
                }
                else
                {
                    // the codes in keycode is wrapped around the 1st and the last
                    count = 0;
                }
            }
            // identify the lowercase characters
            else if (islower(p[i]))
            {
                // cipher the character using key, wrapping around 'a' and 'z' 
                printf("%c", (p[i] - 'a' + keycode[count]) % 26 + 'a');
                
                if (count < keylength - 1)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
            }
        }
        else
        {
            // if the character is not alphabetical, do not cipher it.
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
    
}
```
