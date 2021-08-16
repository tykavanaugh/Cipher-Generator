#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int fix_key(string key);

int count_letters(string text, string key);

int main(int s, string substitution[])
{
    if (s !=2) {
        printf("No args supplied\n");
        return 1;
    };
    string key = substitution[1];
    int len = strlen(key);
    for (int i = 0 ; i < len ; i++){
        if (isalpha(key[i]) == 0){
            printf("Invalid chars");
            return 1;
        };
        int count = 0;
        for (int j = 0 ; j < len ; j++){
                if (key[i] == key[j] || key[i] == (key[j] +32 )|| key[i] == (key[j] - 32)){
                    count++;
                    if (count > 1)
                    {
                        printf("Duplicates detected\n");
                        return 1;

                    };
                };
            };
        };
    if (len != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    } else {
        fix_key(key) ;
        string text = get_string("plaintext: ");
        count_letters(text,key);
    };
    return 0;
}

int count_letters(string text, string key){
    int length = strlen(text);
    printf("ciphertext: ");
    for (int i = 0 ; i < length ; i++){
        int val = text[i];
        bool isLower = false;
        char c = val;
        if (isalpha(text[i])){
            if (val >= 65 && val < 91) {
                val -= 65;
                c = key[val];
                if (islower(c) == true){
                    c -= 32;
                };
            } else if (val >= 97 && val < 123) {
                val -= 97;
                isLower = true;
                c = key[val];
            } ;
        };
        if (isLower){
            c += 32;
        };
        printf("%c",c);
    };
    printf("\n");
    return 0;
};

int fix_key(string key){
    int len = strlen(key);
    for (int i = 0 ; i < len ; i++){
        key[i] = toupper(key[i]);
        };
    return 0;
};
