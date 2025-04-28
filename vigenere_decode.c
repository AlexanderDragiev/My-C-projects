#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

char* vigenere_decode(char* plaintext, char* key)
{
    int text_lenght = strlen(plaintext);
    int key_lenght = strlen(key);

    char* cipher = (char*)malloc(sizeof (char) * (text_lenght - 1));
    memset(cipher, '\0', sizeof (char) * (text_lenght - 1));
    

    for(int i = 0; i < text_lenght; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower (key[i%key_lenght])- 'a';
            if(islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' - shift + 26)%26;
                
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' - shift + 26)%26;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher [text_lenght] = '\0';
    return cipher;
}



int main()
{
       
    char text[MAXN];
    scanf("%s", text);
    char key[MAXN];
    scanf("%s", key);
    char * cipher = vigenere_encrypt(text, key);
    printf("%s", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}