// #include <stdio.h>

// /*Create an array or string and insert each number at this relevant point 
// and print the following :

//     All of the bytes as binary
//     All of the bytes as hex
//     All of the bytes as decimal 
//     All of the bytes as an ASCII
//     */

// int main() {
//     unsigned  bytes [14] ={};
    
//     bytes[1] =0b01001101;
//     bytes[2] =79;
//     bytes[3] =0b00100000;;
//     bytes[4] =0b01101110;
//     bytes[5] =61;
//     bytes[6] =0x6D;
//     bytes[7] =0b01100101;
//     bytes[8] =20;
//     bytes[9] =69;
//     bytes[10] =73;
//     bytes[11] =0b00101110;
//     bytes[12] ='.';
//     bytes[13] =0b00101110;
//     bytes[14] =0b00100000;
//     printf("Idx\tDec\tHex\t     Bin\tAscii\n");
//     printf("---\t---\t---\t--------\t------\n");
//     for(int i=1 ;i<=14 ;i++){
//         printf("[%2u]\t %3d\t %2X\t", i , bytes[i] , bytes[i] );
//         for (int b=7 ;b >=0 ; b--){
//             int bit = (bytes[i]>> b) &0b00000001;
//             printf("%u",bit);
//         }
//     printf("\t%c\n", bytes[i]);
//     }
// }

// #include <stdio.h>

// void printBinary(unsigned int n) {
//     for (int b = 7; b >= 0; b--) {
//         printf("%u", (n >> b) & 1);
//     }
// }

// int main() {
//     unsigned bytes[15] = {0};

//     // Initialisation des valeurs
//     bytes[1] = 0b01001101;  // 'M'
//     bytes[2] = 79;           // 'O'
//     bytes[3] = 0b00100000;   // (space)
//     bytes[4] = 0b01101110;   // 'n'
//     bytes[5] = 61;           // '='
//     bytes[6] = 0x6D;         // 'm'
//     bytes[7] = 0b01100101;   // 'e'
//     bytes[8] = 20;           // Non imprimable (Device Control 4)
//     bytes[9] = 69;           // 'E'
//     bytes[10] = 73;          // 'I'
//     bytes[11] = 0b00101110;  // '.'
//     bytes[12] = '.';         // '.'
//     bytes[13] = 0b00101110;  // '.'
//     bytes[14] = 0b00100000;  // (space)

//     printf("Idx\tDec\tHex\t     Bin\tAscii\n");
//     printf("---\t---\t---\t--------\t------\n");

//     for (int i = 1; i <= 14; i++) {
//         printf("[%2u]\t%3d\t%2X\t", i, bytes[i], bytes[i]);
//         printBinary(bytes[i]);

//         // Gestion des caractères non imprimables
//         if (bytes[i] < 32 || bytes[i] > 126) {
//             printf("\t<CTRL>\n");
//         } else {
//             printf("\t%c\n", bytes[i]);
//         }
//     }

//     return 0;
// }


#include <stdio.h>

/*the purpose of this programme is to get the different bases of all the input numbers
the input  can be 
 */
int main () {
unsigned char bytes[15];
 bytes[1]=0b01001101;
 bytes[2]=79;
 bytes[3]=0b00100000;
 bytes[4]=0b01101110;
 bytes[5]=61;
 bytes[6]=0x6D;
 bytes[7]=0b01100101;
 bytes[8]=20;
 bytes[9]=69;
 bytes[10]=73;
 bytes[11]=0b00101110;
 bytes[12]='.';
 bytes[13]=0b00101110;
 bytes[14]=0b00100000;

printf("Index\tDec\tHex\tOct\t     Bin\tAsci\n");
printf("-----\t---\t---\t---\t--------\t----\n");

 for (int i=1 ;i<15; i ++) {
    printf("[%2u]\t%2d\t%3X\t%3o\t", i , bytes[i] , bytes[i]  ,bytes[i]);

    for (int b=7 ; b>=0 ; b--) {
         int bit=(bytes[i] >>b) & 0b00000001;
         printf("%u" ,bit);
    }
    printf("\t%c\n",bytes[i]);
 }
 return 0;

}

