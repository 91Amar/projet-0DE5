#include <stdio.h>

/*Write a C programme in C that :
Prompt the user to input a single character 
Reads that character from STDIN (and the enter query)
Checks whether the character is 'Q'
If it is, logs "Welcome to 0DE5!"*/

int main(){
    printf("Enter the single character");
    scanf("%1c" , &input);
    if (input == 'Q') {
        printf("Welcome to 0DE5!");
    }
    else {
        printf("You input must be Q!");
    }
    return 0;
}