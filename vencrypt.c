    #include <stdio.h>
#include <string.h>
#include <ctype.h>

void vencrypt(char *msg, const char *key)
{
    int txtlen = strlen(msg);
    int keylen = strlen(key);
    int keyindex = 0;

    for(int i = 0; i < txtlen; i++)
    {
        char c = msg[i];
        if(isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char k = key[keyindex % keylen]; //inside for loop so that keyword characters loop bakk to first one for mapping
            //iterations of k is independent of i, they only stop when loop finishes
            char kbase = isupper(k) ? 'A' : 'a';
            msg[i] = (c - base + (k - kbase)) % 26 + base;
            keyindex++; //advances only for letters
        }
    }
}

int main(void)
{
    char msg[256];
    char key[256];

    printf("Enter message : \n");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = 0;
    
    printf("Enter keyword : \n");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    vencrypt(msg, key);
    printf("Ciphertext: %s\n", msg);

    return 0;
}