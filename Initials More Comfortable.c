```
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get user's name
    string name = get_string();
    
    // iterate through the username
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // identify the very first character or 1st character after a space in username
        if (i == 0 || name[i - 1] == ' ')
        {
            // make sure the character at the very beginning or immediately after a space is not a space
            if (name[i] != ' ')
            {
                // print the identified characters in uppercase
                printf("%c", toupper(name[i]));
            }
        }
    }
    
    printf("\n");
}
```
