#include<stdio.h>
#include<string.h>
#define SIZE 20

void reverse(char *CPtr, char *OPtr); //C=change,O=original

int main()
{
    char arrayC[SIZE],arrayO[SIZE];
    gets(arrayC);
    strcpy(arrayO,arrayC);  //將C的內容複製到O

    reverse(arrayC, arrayO);

    return 0;
}

void reverse(char *CPtr, char *OPtr)
{
    int x=0,y;
    while(*CPtr != '\0'){
        x++;
        CPtr++;
    }

    CPtr--;

    for(y=x;y>0;y--){
        printf("%c",*CPtr);
        CPtr--;
    }
    puts("");

    for(y=x;y>0;y--){
        printf("%c",*OPtr);
        OPtr++;
    }
    puts("");
}