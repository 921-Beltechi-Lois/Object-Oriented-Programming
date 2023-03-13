//
// Created by loisb on 23.02.2022.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void read_vector(int len, const int *b);

int comb(int n , int k)
{
    int p = 1;
    for(int i = 1 ; i <= k ; i ++)
        p = p * (n-i+1) / i;
    return p;
}


char getStr(char *h) {
    /*
     * reads a given character which will be used as an option (return type char)
     */
    printf("\n");


    while((*h) != '1' && (*h) != '2' && (*h) != '3' && (*h)!='4'){
        printf("Your option: ");
        scanf("%s", h);
        if ((*h) != '1' && (*h) != '2' && (*h) != '3' && (*h)!='4'){
            printf("wrong usage of command\n");
        }
    }
    return (*h);
}

int relatively_prime(int a, int b) {
    /*
     input 2 given int numbers
     relatively prime = the greatest common divisor of 2 numbers
     Return: True if numbers are rel prime (gcd(a,b)=1), otherwise False
     */
    // gcd (a,b)= 1 -> true
    while(a!=b){
        if (a>b)
        {a-=b;}
        else
        {b-=a;}
    }
    if (a==1) return 1;
    else {return 0;}
}

int prime_number(int number){
    /* input: given number
     * output: Return true if number is prime, otherwise false
     */
    int prime = 1; // true
    for(int d=2;d*d<=number;d++){
        if (number % d==0){prime = 0;}
    }
    if (prime == 1)
        return 1;   // is prime
    return 0;
}

int generate_first_n_prime_numbers(unsigned int n, int a[]){
    /*
     * input: n(first n numbers generated), a - array in which the prime numbers will be stored
     * return : none
     * If a number has only 2 divisors (1 and himself) --> number is a prime number & also this will be checked in the interval
     * [2,n]
     */
    int j=0, value ; // index of the generated numbers
    for (int number=2; number<=n;number++) {
        value = prime_number(number);
        if (value == 1){
            a[j++] = number;}
    }
    return j;
}

// 13
// 6 8 3 7 49 51 53 61 122 37 159 31 201
void longest_subsequence(int a[], int len, int res[]){
    /*
     * input: a - given vector of numbers, len - length of the given vector a, res - vector of 2 values which will contain the [...]
     * [...] initial index and the final index of the longest consequent subsequence
     * return: none
     * We compare each 2 consecutive numbers from the given array: if they are relatively_prime, we increase the length [...]
     * of the current subsequence found until there, and when the condition is not respected we check the MAX subsequence found [...]
     * and we save it in max_len, also with the initial and finale index of the subsequence; (if no subsequence found initial and finale will have value -1)
     */
    int rel_prime = 0, counted_len=-1, max_len=-1, initial=-1, final=-1,new_subseq=0;
    for(int i=0;i<len-1;i++){
        rel_prime = relatively_prime(a[i], a[i+1]);
        if (rel_prime == 1 && new_subseq==0){
            initial = i;
            final = i+1;
            counted_len=2;
            new_subseq = 1; // new subseq started
        }
        else if(rel_prime==1){
            counted_len=counted_len+1;
            final+=1;
        }
        else{
            new_subseq=0; // subseq dropped
            if (counted_len > max_len){
                max_len = counted_len;
                res[0] = initial;
                res[1]= final;
            }
        }
    }
    if (counted_len > max_len){
        max_len = counted_len;
        res[0] = initial;
        res[1]= final;
    }
}

//2.
void print_menu()
{
    printf("a) Generate the first n prime numbers (n is a given natural number).\n");
    printf("b) Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.\n");
    printf("Type '1' for opt. a), '2' for opt. b)\n");
    printf("Type '3' for exit mode \n");
    printf("Type '4' for pascal triangle problem");
}

int main(){

    do {
        print_menu();
        char h = '0';
        h = getStr(&h);


        switch (h) {
            case '1': {
                //a)
                unsigned int n;
                printf("Enter n: ");
                scanf("%d", &n);

                int* arr = malloc(n * sizeof(int));

                int j = generate_first_n_prime_numbers(n,arr);
                printf("Generated first n prime numbers are: \n");
                for (int i = 0; i < j; i++)
                    printf("%d\n", arr[i]);
                free(arr);
                break;
            }
            case '2': {
                //b)
                int len, res[2] = {-1, -1};
                printf("how many numbers in the given array?: ");
                scanf("%d", &len);
                int* b = malloc(len * sizeof(int));
                read_vector(len, b);

                longest_subsequence(b, len, res);
                if (res[0] == -1 && res[1] == -1) {
                    printf("no such subsequence found\n");
                    break;
                }
                printf("Longest contiguous subsequence is:\n ");
                for (int i = res[0]; i <= res[1]; i++) {
                    printf("%d ", b[i]);
                }
                printf("\n");
                free(b);
                break;
            }
            case '3':
            {
                return 0;
            }
            case '4':
            {
                int nn;
                printf("n=");
                scanf("%d", &nn);
//                printf("%d\n");
                nn-=1;
                do {
                    for (int i = 0; i <= nn; i++) {
                        int number = comb(nn, i);
                        printf("%d", number);
                        printf(" ");
                    }
                    nn=nn-1;
                    printf("\n");
                }while(nn!=0);
                printf("1\n");
                break;

            }
            default:
            {
                printf("wrong usage of command\n");
            }
        }
    }while(1);
}

void read_vector(int len, const int *b) {
    for (int i = 0; i < len; i++) {
        scanf("%d", &b[i]);
    }
}