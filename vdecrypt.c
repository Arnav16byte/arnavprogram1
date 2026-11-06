#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vdecrypt(char *garble, const char *key)
{
    int garblelen = strlen(garble);
    int keylen = strlen(key);
    int keyindex = 0;

    for(int i = 0; i < garblelen; i++)
    {
        char c = garble[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char k = key[keyindex % keylen];
            char kbase = isupper(k) ? 'A' : 'a';
            garble[i] = (c - base - (k - kbase) + 26) % 26 + base; //handles all negative cases
            keyindex++;
        }        
    }
}

int main() {
    char garblemsg[256];
    char key[256];

    printf("Enter encrypted message: ");
    fgets(garblemsg, sizeof(garblemsg), stdin);
    garblemsg[strcspn(garblemsg, "\n")] = 0;

    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    vdecrypt(garblemsg, key);
    printf("Decrypted text: %s\n", garblemsg);

    return 0;
}