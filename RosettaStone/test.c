#include <stdio.h>
#include <string.h>

// Calculate binary

void Calculate_binary(int number) {
    for (int b=7 ; b >=0 ; b--){
        int bit = (number >> b )&1;
        printf ("%d", bit);
    }
    
}

void To_base_4(int number , char *output){
   int index=3;
   while (index >= 0){
    output[index --] = (number % 4 ) +'0';
    number /= 4;
    }
    output[4]='\0';
    }

void To_base_DNA(int number , char *output){
    char dna_base[]={'A', 'C', 'G', 'T'};
    int index=3;
    while (index >= 0 ){
        output[index--]=dna_base[number %4 ];
        number/=4;
    }    
    output[4]='\0';
}

int main (int argc , char *argv[]){
    if (argc != 2){
        printf("Usage : %s <string>\n",argv[0]);
        return 1;
    }
   char *input=argv[1];
   char output[5];

    int len = strlen(input);
    printf("ASCII:");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8c",input[i]);
        printf(" ");
    } 
    printf("\nHex:  ");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8x",input[i]);
        printf(" ");
    } 
    printf("\nDec:  ");
    for (int i =0 ; i< len ; i ++ ){
        printf("%8d",input[i]);
        printf(" ");
    } 
    printf("\nBin:  ");
    for (int i =0 ; i< len ; i ++ ){
        Calculate_binary(input[i]);
        printf(" ");
    } 

    printf("\nBase4:");
    for (int i =0 ; i< len ; i ++ ){
        To_base_4(input[i], output);
        printf("%8s" , output);
        printf(" ");
    } 
    
    printf("\nDNA:  ");
    for (int i =0 ; i< len ; i ++ ){
        To_base_DNA(input[i], output);
        printf("%8s", output);
        printf(" ");
    } 
    printf("\n");
    return 0 ;
}
