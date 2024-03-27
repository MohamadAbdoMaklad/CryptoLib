#include <stdio.h>
#include <stdlib.h>
#include "PermutationCipher.h"
int getKetLength(char key[])
{
    int i=0;
    for (i = 0 ; key[i] != '\0';i++);
    return i;
}
returnState checkKey(char key[])
{
    for(int i = 0 ;key[i] != '\0';i++)
    {
        for(int j = i+1 ; key[j] != '\0';j++)
        {
            if (key[i] == key[j])
            {
                return error2;
            }
        }
    }
    return done;
}
int main(void)
{

    char Pt[25] = "meetmelatermeetmelater";
    char Ct[25] = "xxxxxxxxxxx";
    char Ptfc[25] = "xxxxxxxxxxx";
    char Key[11] = "1326089745";
    printf("************************\n");
    printf("%d\n",checkKey(Key));
    printf("************************\n");
    EncryptString(Pt,Ct,Key);
    printf("************************\n");
    DecryptString(Ct,Ptfc,Key);
    printf("Pt : %s\nCt : %s\nPt : %s",Pt,Ct,Ptfc);
    return 0;
}

returnState EncryptString(char Pt[], char Ct[], char Key[])
{
    if (error2 == checkKey(Key))
    {
        return error2;
    }
    int KeyLength = getKetLength(Key);
    int TextLength = getKetLength(Pt);
    int Row = TextLength/KeyLength + ((TextLength%KeyLength)/(TextLength%KeyLength));
    char (*arr)[Row][KeyLength] = malloc(sizeof *arr);
    int PtCounter = 0;
    char PaddingFlag = 0;
    for(int i = 0 ; i< Row ; i++)
    {
        for(int j = 0 ; j < KeyLength ; j++)
        {
            if ((Pt[PtCounter] != '\0') && (PaddingFlag == 0))
            {
                (*arr)[i][j]=Pt[PtCounter];
                PtCounter++;
            }
            else
            {
                PaddingFlag = 1;
                (*arr)[i][j]='@';
                PtCounter++;
            }
        }
    }

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < KeyLength; j++)
        {
            printf("%c ", (*arr)[i][j]);
        }
        printf("\n");
    }
    int index = 0;
    for (int i = 0; i < KeyLength; i++)
    {
        index = Key[i]-'0';
        for (int j = 0 ; j < Row; j++)
        {
            Ct[(index*Row)+j]=(*arr)[j][i];
        }
    }
    Ct[Row*KeyLength] = '\0';
    free(arr);
    return done;
}


returnState DecryptString(char Ct[], char Pt[], char Key[])
{
    if (error2 == checkKey(Key))
    {
        return error2;
    }
    int KeyLength = getKetLength(Key);
    int TextLength = getKetLength(Ct);
    int Row = TextLength/KeyLength;
    char (*arr)[Row][KeyLength] = malloc(sizeof *arr);

    int index = 0;
    for (int i = 0; i < KeyLength; i++)
    {
        index = Key[i]-'0';
        for (int j = 0 ; j < Row; j++)
        {
            (*arr)[j][i] = Ct[(index*Row)+j];
        }
    }

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < KeyLength; j++)
        {
            printf("%c ", (*arr)[i][j]);
        }
        printf("\n");
    }

    int PtCounter = 0;
    char PaddingFlag = 0;
    for(int i = 0 ; i< Row ; i++)
    {
        for(int j = 0 ; j < KeyLength ; j++)
        {
            if ((Pt[PtCounter] != '\0') || ((*arr)[i][j] != '@'))
            {
                Pt[PtCounter]=(*arr)[i][j];
                PtCounter++;
            }
        }
    }
    free(arr);
    return done;

}