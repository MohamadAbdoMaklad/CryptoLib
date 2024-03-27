#ifndef CAESERCIPHER_H
#define CAESERCIPHER_H
typedef enum
{
    done = 0,
    error1 = 1,
} returnState;

char EncryptChar(char Pt, int key);
char DecryptChar(char Ct, int key);
returnState EncryptString(char Pt[], char Ct[], int Key);
returnState DecryptString(char Ct[], char Pt[], int Key);
#endif // !CAESERCIPHER_H