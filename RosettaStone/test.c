#include <stdio.h>
#include <string.h>

// Calculate binary

int Calculate_binary(int number) {
    for (int b=7 ; b >=7 ; b--){
        int bit = (number >> b )&1;
        printf ("%d", bit);
    }
}

int main (int argc , char *argv[]){
    if (argc != 2){
        printf("Usage : %s <string>\n",argv[0]);
        return 1;
    }
   char *input=argv[1];

    int len = strlen(input);
    printf("ASCII:");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8c",input[i]);
    } 
    printf("\nHex:  ");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8x",input[i]);
    } 
    printf("\nDec:  ");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8d",input[i]);
    } 
    printf("\nBin:  ");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8d",Calculate_binary(i));
    } 
}