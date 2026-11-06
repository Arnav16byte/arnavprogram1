#include <stdio.h>
#include <ctype.h>
#include <string.h>

void charcounter(char *str)
{
    // Frequency array to store counts for all ASCII characters (initialized to 0)
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        // Check if the character is alphanumeric (letters and digits)
        if (isalnum(c))
        {
            // Convert to lowercase to make it case-insensitive
            c = tolower(c);

            // Increment the count for this character
            freq[(unsigned char)c]++;
        }
    }

    // Display the counts for each repeated/present alphanumeric character
    printf("\nAlphanumeric Character Counts:\n");
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }
}

int main()
{
    char str[256];
    int size = sizeof(str);

    printf("GIVE ME A STRING!!!!!!111 \n");

    if (fgets(str, size, stdin) != NULL)
    {
        // Remove the newline character added by fgets
        str[strcspn(str, "\n")] = '\0';

        charcounter(str);
    }

    return 0;
}
