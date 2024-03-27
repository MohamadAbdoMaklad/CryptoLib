#ifndef PERMUTATIONCIPHER_H
#define PERMUTATIONCIPHER_H
typedef enum
{
    done    = 0,    //Operation Done 
    error1  = 1,    //Error In Algorithm 
    error2  = 2,    //Error in Key
} returnState;
returnState EncryptString(char Pt[], char Ct[], char Key[]);
returnState DecryptString(char Ct[], char Pt[], char Key[]);

#endif // !PERMUTATIONCIPHER_H