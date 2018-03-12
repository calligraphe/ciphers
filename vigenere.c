#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./vigenere k\n");
        return 1;
    }
    string key = argv[1];
    int ikey = strlen(key);
    int nkey[ikey];
    for (int i = 0; i < ikey; i++)
    {
        if (! isalpha(key[i]) )
        {
            printf("Alphabetic characters only.\n");
            return 1;
        }
        else if ( isupper(key[i]) )
        {
            nkey[i] = key[i] - 'A';
        }
        else
        {
            nkey[i] = key[i] - 'a';
        }
    }
    printf("plaintext: ");
    string pt = get_string();
    printf("ciphertext: ");

    int j = ikey; // or j = 0;
    for (int i = 0, ipt = strlen(pt); i < ipt; i++)
    {
        int ptkey = pt[i] + nkey[j % ikey];
        if ( isupper(pt[i]) )
        {
            if (ptkey > 'Z')
            {
                printf("%c", ptkey - 26);
                j++;
            }
            else
            {
                printf("%c", ptkey);
                j++;
            }
        }
        else if ( islower(pt[i]) )
        {
            if (ptkey > 'z')
            {
                printf("%c", ptkey - 26);
                j++;
            }
            else
            {
                printf("%c", ptkey);
                j++;
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