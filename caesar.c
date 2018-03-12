#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> // ctype.h possible instead of stdlib

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    string k = argv[1];
    int key = atoi(k);

    if (key > 25)
    {
        key %= 26;
    }
    else if (key < 0)
    {
        printf("Please provide non-negative integer.\n");
        return 1;
    }

    printf("plaintext: ");
    string pt = get_string();
    printf("ciphertext: ");

    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        int ckey = pt[i] + key;

        if (pt[i] >= 'A' && pt[i] <= 'Z') // isupper
        {
            if (ckey > (int) 'Z')
            {
                printf("%c", ckey - (int) 'Z' + (int) 'A' - 1); // ckey - 26
            }
            else
            {
                printf("%c", ckey);
            }
        }
        else if (pt[i] >= 'a' && pt[i] <= 'z')
        {
            if (ckey > (int) 'z')
            {
                printf("%c", ckey - (int) 'z' + (int) 'a' - 1);
            }
            else
            {
                printf("%c", ckey);
            }
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}