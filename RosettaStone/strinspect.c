#include <stdio.h>
#include <string.h>

// /*Create command line tool called strinspect
// It should take one argument: a string
// It should then print the string in the following formats:
//     *Each byte as ASCII
//     *Each byte as hex
//     *Each byte as binary 
// If I like, I can also:
// Line each byte up in columns 
// Also show the decimal value of each byte 
// Add it to my PATH so I can use it as a tool myself*/



// // Convert and print the byte in binary

// void Calculate_Binary(int number){
//    for (int i = 7; i >= 0 ; i --){
//     printf("%d", (number >> i) & 1);
//    }    
//    printf(" ");
// }

// // Main function

// int main (){
//     char bytes[10000];
    
//     printf("Enter the string : \n");
    
//     scanf("%9999s", bytes);
    
//     int lengeth= strlen(bytes);  //Using the builtin strlen function of the stting.h library
    

//     // print Ascii

//     printf ("ASCII:\t");
//     for (int i =0 ;i < lengeth ; i ++) {
//         printf("%8c",bytes[i]);
//     }

//     // Print the Hex    
//     printf ("\nHex:\t");
//     for (int i =0 ;i < lengeth ; i ++) {
//         printf("%8X",bytes[i]);
//     }
    
//     // Print the Decimals 

//     printf ("\nDec:\t");
//     for (int i =0 ;i < lengeth ; i ++) {
//         printf("%8d",bytes[i]);
//     }
//     //Calling the calculate binary function to print the binary 
//     printf ("\nBin:\t");
//     for (int i =0 ;i < lengeth ; i ++) {
        
        
//         Calculate_Binary(bytes[i]);
    
//     }
//    printf("\n");
//    return 0;
// }


// ; ./strinspect "Hello"
// ASCII:       H        e        l        l        o
// Hex:        48       65       6C       6C       6F
// Dec:        72      101      108      108      111
// Bin:  01001000 01100101 01101100 01101100 01101111



/// Another way


// void calculate_binary (int number){
//     for (int i =7 ; i>=0; i --){
//         printf("%d",(number >> i) & 1);
//     }

// }


// int main( int argc ,char * argv[]){
//     if (argc != 2){
//         printf ("Usage: %s <string>\n",argv[0]);
//         return 1;
//     }
//     char *input = argv[1];
//     int lengeth= strlen(input);

//     //ASCII 
//     printf("ASCII: ");
//     for (int i =0 ;i <lengeth; i++){
//         printf("%8c", input[i]);
//     }
        
//     printf("\nHex:   ");
//     for (int i =0 ;i <lengeth; i++){
//         printf("%8X", (unsigned char) input[i]);
//     }
        
//     printf("\nDec:   ");
//     for (int i =0 ;i <lengeth; i++){
//         printf("%8d", (unsigned char) input[i]);
//     }
        
//     printf("\nBin:  ");
//     for (int i =0 ;i <lengeth; i++){
//         printf(" ");
//         calculate_binary((unsigned char) input[i]);
//     }
//     printf("\n");    
//     return 0;
// }



#include <stdio.h>
#include <string.h>

// Fonction pour afficher la représentation binaire d'un octet
void calculate_binary(int number, char *output) {
    for (int i = 7; i >= 0; i--) {
        output[7 - i] = ((number >> i) & 1) ? '1' : '0';
    }
    output[8] = '\0'; // Terminer la chaîne binaire
}

void quaternary(int number , char * output){
    for (int i=0 ;i < 4 ; i++){
        output[3-i] = (number % 4) +'0';
        number /=4;
    }
    output[4]='\0';
  
}

void to_dna_base(int number , char* output){
    char dna_base[]={'A' , 'C' , 'G' , 'T' };
    for (int i= 0; i<4; i++){
        output[i]=dna_base[number %4];
        number/=4;

    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char res[5];
    char *input = argv[1];
    char *output=  res;
    int length = strlen(input);
    char binary_output[9]; // Stocker les 8 bits + le caractère de fin '\0'

    // Affichage ASCII
    printf("ASCII: ");
    for (int i = 0; i < length; i++) {
        printf("%7c ", input[i]);
    }

    // Affichage Hexadécimal
    printf("\nHex:   ");
    for (int i = 0; i < length; i++) {
        printf("%7X ", (unsigned char)input[i]);
    }

    // Affichage Décimal
    printf("\nDec:   ");
    for (int i = 0; i < length; i++) {
        printf("%7d ", (unsigned char)input[i]);
    }

    // Affichage Binaire
    printf("\nBin:   ");
    for (int i = 0; i < length; i++) {
        calculate_binary((unsigned char)input[i], binary_output);
        printf("%8s ", binary_output);
    }
    
    printf("\nBase4: ");
    for (int i = 0; i < length; i++) {
        quaternary(input[i], res);
        printf("%8s",res);
        printf(" ");
    }
    char  re[5];
    printf("\nDNA:   ");
    for (int i=0; i < length ; i++){
    to_dna_base(input[i] , re);
    printf("%8s", re);
    }
    printf("\n");

    return 0;
}