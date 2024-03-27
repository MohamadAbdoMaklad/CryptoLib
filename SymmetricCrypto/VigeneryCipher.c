#include <stdio.h>
#include "VigeneryCipher.h"

int main(void)
{
    char Key[5]  = "ABab";
    char Pi1[10] = "ABabEFGZ";
    char Ci1[10] = "\0";
    char Pi2[10] = "\0";
    if (done == EncryptString(Pi1, Ci1, Key))
    {
        printf("Encryption Done\n");
    }
    else
    {
        printf("ERROR\n");
    }
    
    if (done == DecryptString(Ci1, Pi2, Key))
    {
        printf("Decryption Done\n");
    }
    else
    {
        printf("ERROR\n");
    }
    printf("Pi1 : %s \nCi1 : %s\nPi2 : %s", Pi1, Ci1, Pi2);
    return 0;
}

char EncryptChar(char Pt, int key)
{
    char Ct = 0;
    switch (Pt)
    {
    case 'A' ... 'Z':
        Ct = (Pt + (key % 26));
        if (Ct > 'Z')
        {
            char Rem = Ct - 'Z';
            Ct = 'A' + Rem - 1;
        }
        break;
    case 'a' ... 'z':
        Ct = (Pt + (key % 26));
        if (Ct > 'z')
        {
            char Rem = Ct - 'z';
            Ct = 'a' + Rem - 1;
        }
        break;
    case '0' ... '9':
        Ct = (Pt + (key % 26));
        if (Ct > '9')
        {
            char Rem = Ct - '9';
            Ct = '0' + Rem - 1;
        }
        break;
    default:
        break;
    }
    return Ct;
}
char DecryptChar(char Ct, int key)
{
    char Pt = 0;
    switch (Ct)
    {
    case 'A' ... 'Z':
        Pt = (Ct - (key % 26));
        if (Pt < 'A')
        {
            char Rem = Pt - 'A';
            Pt = 'Z' + Rem + 1;
        }
        break;
    case 'a' ... 'z':
        Pt = (Ct - (key % 26));
        if (Pt < 'a')
        {
            char Rem = Pt - 'a';
            Pt = 'z' + Rem + 1;
        }
        break;
    case '0' ... '9':
        Pt = (Ct - (key % 26));
        if (Pt < '0')
        {
            char Rem = Pt - '0';
            Pt = '9' + Rem + 1;
        }
        break;
    default:
        break;
    }
    return Pt;
}

returnState EncryptString(char Pt[], char Ct[], char Key[])
{
    static int K = 0;
    for (int i = 0; Pt[i] != '\0'; i++)
    {
        if(Key[i] == '\0')
        {
            K = 0;
        }
        switch (Key[K])
        {
        case 'A' ... 'Z':
        Ct[i] = EncryptChar(Pt[i], (Key[K]-'A'));
        Ct[i + 1] = '\0';
            break;
        case 'a' ... 'z':
        Ct[i] = EncryptChar(Pt[i], (Key[K]-'a'));
        Ct[i + 1] = '\0';
            break;
        case '0' ... '9':
        Ct[i] = EncryptChar(Pt[i], (Key[K]-'0'));
        Ct[i + 1] = '\0';
            break;
        default:
        return error1;
            break;
        }
        K++;
    }
    return done;
}

returnState DecryptString(char Ct[], char Pt[], char Key[])
{
    static int K = 0;
    for (int i = 0; Ct[i] != '\0'; i++)
    {
        if(Key[i] == '\0')
        {
            K = 0;
        }
        switch (Key[K])
        {
        case 'A' ... 'Z':
        Pt[i] = DecryptChar(Ct[i], (Key[K]-'A'));
        Pt[i + 1] = '\0';
            break;
        case 'a' ... 'z':
        Pt[i] = DecryptChar(Ct[i], (Key[K]-'a'));
        Pt[i + 1] = '\0';
            break;
        case '0' ... '9':
        Pt[i] = DecryptChar(Ct[i], (Key[K]-'0'));
        Pt[i + 1] = '\0';
            break;
        default:
        return error1;
            break;
        }

        K++;
    }
    return done;
}