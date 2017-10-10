```#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

#define _XOPEN_SOURCE
#include <unistd.h>

int main (int argc, string argv[])
{
    // make sure the user provides a command-line input, otherwise exit the programme with error code 1
    if (argc != 2)
    {
        printf("Please provide a hashed password to be decrypted at the command line");
        return 1;
    }
    
    // declare string salt of size 3
    char salt[3];
    // copy the first 2 characters of user's command-line input to salt
    // the salt has a size of 3 instead of 2 is because there is no null byte in the first 2 characters of user's input, so that salt needs an additional space to place the null byte in order to make ti a string
    strncpy(salt, argv[1], 2);
    
    // the password can only be composed of characters from the following list. null byte is included in order to check passwords with different lengths
    char alphabet[53] = {'\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                               'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // declare the key as a size-5 string, terminated by null byte              
    char key[5];
    key[4] = '\0';
    
    int i, j, k, l;
    
    // loop through alphabets, but the first character of password cannot be null byte. the password will have length ranging from 1 to 4
    for (i = 1; i < 52; i++)
    {
        key[0] = alphabet[i];
        
        for (j = 0; j < 52; j++)
        {
            key[1] = alphabet[j];
            
            for (k = 0; k < 52; k++)
            {
                key[2] = alphabet[k];
                
                for (l = 0; l < 52; l++)
                {
                    key[3] = alphabet[l];
                    
                    // compare the key with the user's input - hashed password
                    if (strcmp(argv[1], crypt(key, salt)) == 0)
                    {
                        // if these two are identical, print the key as the password and exit the programme with success code 0
                        printf("%s\n", key);
                        return 0;
                    }
                }
            }
        }
    }
    
    // if a password cannot be found after looking into all possible combinations, prompt the user and exit the programme with error code of 2
    printf("The password cannot be be found\n");
    return 2;
}
```
