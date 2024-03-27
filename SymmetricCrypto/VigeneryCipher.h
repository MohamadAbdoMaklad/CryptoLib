#ifndef VIGENERYCIPHER_H
#define VIGENERYCIPHER_H

typedef enum
{
    done = 0,
    error1 = 1,
} returnState;

char EncryptChar(char Pt, int key);
char DecryptChar(char Ct, int key);
returnState EncryptString(char Pt[], char Ct[], char Key[]);
returnState DecryptString(char Ct[], char Pt[], char Key[]);
#endif // !VIGENERYCIPHER_H#define "" "" 