#include <stdio.h>


int add (int a, int b){
    return a + b;
}

int mul (int a, int b){
    int result = a * b;
    return result;
    puts ("This wille not be executed");
    
    }

int fib (int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n-1) + fib (n-2);
}
// int main() {

//     printf ("Hello world %04X\n",3557);
//     int sum=add (5,3);
//     printf("add (5,3) est %d\n",sum);    
//     int mult=mul (10,4);
//     printf("mul (10,4) is %d\n",mult);
//     int fibo=fib(7);
//     printf ("la suite de fibo pour le 7 est %d\n",fibo);
// }

// The best way to print is to use it in this way

//  PRINTING

void printing() {
  puts ("welcome:");
  printf("3*4 =%d\n", mul(3,4));
  printf("Fibonacci number 10 is %d\n", fib(10));

}

// Quick specifier reference 
// %d -signed decimal integer (e.g. 99, -42)
// %f -decimal floating point (e.g 3.14, -0.01)
// %s -String (e.g. "hello")
// %% -literal % (e.g %)
// %p - pointer address (if given "hello " will print somthing like 0x7ffeefbff718)
// \n -newline character,Not automatically added to printf 


// LOOPS

void looping() {
  puts ("counting down from 1000 by 7s:");

  int c =100;
  while (c > 0) {
    printf("%d\n",c);
    c =c-7;
  }
  puts("counting up fom 0 by 7s:");
  for (int i=0 ; i<100; i +=7) {
    printf("%d\n", i);
  }
  
}

void conditionals(){
  puts("Fizzbuzing up to 20");

  for (int i =1; i <= 20; i++) {
    if (i % 15 == 0) {
      puts("Fizzbuzz");
    } else if (i %3 ==0) {
      puts("Fizz");
    }
    else if (i % 5 ==0){
      puts("Buzz");
    } else {
      printf("%d\n",i);
    }
  }

  if (1 && !0 || 1) {
    puts ("We made it!");
    }
  
  if (1 == 1 && 2 != 1 && 2 > 1 && 1<2 && 1<= 1 && 2 >= 1 ){
    puts ("We mad it again !");
  }
}


// Basic Data Types
void data_types(){
int integer= 42;
float decimal = 43.5;
char charcter ='a';
size_t whatever =1000;

}

// Types                   Taille*     Min                            Max 

// char                    1 octet     -128                           127
// unsigned char           1 octet     0                              255
// short                   2 octets    -32 768                        32 767
// unsigned short          2 octets    0                              65 535
// int                     4 octets    -2 147 483 648                 2 147 483 647
// unsigned int            4 octets    0                              4 294 967 295
// long                    4/8 octets  -2 147 483 648 (min)           2 147 483 647 (min)
// unsigned long           4/8 octets  0                              4 294 967 295 (min)
// long long               8 octets    -9 223 372 036 854 775 808     9 223 372 036 854 775 807
// unsigned long long      8 octets    0                              18 446 744 073 709 551 615

// * La taille peut varier selon l'architecture et le compilateur.
//   Les valeurs indiquées sont les plus courantes sur les systèmes 32/64 bits.


// lets check it in my server 
void data_types2() {
    printf("Tailles des types de données sur cette machine :\n");
    printf("char : %zu octets\n", sizeof (char));
    printf("unsigned char : %zu octets\n", sizeof(unsigned char));
    printf("short : %zu octets\n", sizeof(short));
    printf("unsigned short : %zu octets\n", sizeof(unsigned short));
    printf("int : %zu octets\n", sizeof(int));
    printf("unsigned int : %zu octets\n", sizeof(unsigned int));
    printf("long : %zu octets\n", sizeof(long));
    printf("unsigned long : %zu octets\n", sizeof(unsigned long));
    printf("long long : %zu octets\n", sizeof(long long));
    printf("unsigned long long : %zu octets\n", sizeof(unsigned long long));
    printf("float : %zu octets\n", sizeof(float));
    printf("double : %zu octets\n", sizeof(double));
    printf("long double : %zu octets\n", sizeof(long double));
    printf("size_t : %zu octets\n", sizeof(size_t));
}

// The size differ from archi to anothner

// int main(){
//   data_types2();
// }

// ARRAYS & Strings 

void arrays_and_strings(){
  int number1[5];
  int number2[]={1,2,3,4,5};
  char string[6]="Hello";
}

// When storing an array of 3 numbers 
// Type nums[3];
// nums[0]=10;
// nums[1]=20;
// nums[2]=30;
// the memory might look like this 
// char num[3]= 3*1bytes =10 20 30 
// int  num[3]= 3*2bytes =00 10 00 20 00 30 

// Structs

struct person
{
  char name[50];
  int height;
};

void structs(){
  struct person me = {"key", 176};
  struct person you = {.height = 180, .name = "Someone"};

printf("Person %s, height %dcm\n", me.name, me.height);
printf("Person %s, height %dcm\n", you.name, you.height);

}

int main(int argc, char **argv){

if (argc >1){
printf("hello, %s\n",argv[1]);

}else {
  puts ("No greeting for you!");
}
printing();
looping();
conditionals();
data_types();
arrays_and_strings();
structs();
return 0;
}