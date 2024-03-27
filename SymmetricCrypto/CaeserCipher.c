#include <stdio.h>
#include "CaeserCipher.h"

int main(void)
{

    printf("%c : B - %c : A\n", EncryptChar('A',1) ,DecryptChar('B',27) );
    printf("%c : N - %c : L\n", EncryptChar('L',28),DecryptChar('N',28));
    printf("%c : A - %c : Z\n", EncryptChar('Z',27),DecryptChar('A',1));
    printf("%c : b - %c : a\n", EncryptChar('a',1) ,DecryptChar('b',1) );
    printf("%c : n - %c : l\n", EncryptChar('l',2),DecryptChar('n',28));
    printf("%c : a - %c : z\n", EncryptChar('z',1),DecryptChar('a',27));
    printf("%c : 1 - %c : 0\n", EncryptChar('0',1) ,DecryptChar('1',1) );
    printf("%c : 4 - %c : 2\n", EncryptChar('2',2) ,DecryptChar('4',28));
    printf("%c : 0 - %c : 9\n", EncryptChar('9',1) ,DecryptChar('0',1) );
    char Pi1[10] = "AbBDEFGZ";
    char Ci1[10] = "\0";
    char Pi2[10] = "\0";
    if (done == EncryptString(Pi1, Ci1, 4))
    {
        printf("Encryption Done\n");
    }
    else
    {
        printf("ERROR\n");
    }
    
    if (done == DecryptString(Ci1, Pi2, 4))
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
returnState EncryptString(char Pt[], char Ct[], int Key)
{
    for (int i = 0; Pt[i] != '\0'; i++)
    {
        Ct[i] = EncryptChar(Pt[i], Key);
        Ct[i + 1] = '\0';
    }
    return done;
}
returnState DecryptString(char Ct[], char Pt[], int Key)
{
    for (int i = 0; Ct[i] != '\0'; i++)
    {
        Pt[i] = DecryptChar(Ct[i], Key);
        Pt[i + 1] = '\0';
    }
    return done;
}