#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_STR 512

/**
 * compere between 2 range in string
 * @param b1 first pointer
 * @param b2 second pounter
 * @param len length for compere
 * @return 1 the byte length from both indexes are same, 0 otherwise
 */
int my_bcmp(const void *b1,const void *b2,size_t len){

    char *p1 = b1;
    char *p2 = b2;

    int i;

    for (i=0; i< len; i++){
        if (*p1 != *p2)
            return 0;
        p1++;
        p2++;
    }

    return 1;
  }


/**
 * check if the number is positive and whole
 * @param n number
 * @return 1 if number is valid, 0 otherwise
 */
int check_number(double n){
           if (n<0 || floor((double)n)!=n )
              return 1;
    return 0;
}

/**
 * check input value validation
 * @param len number
 * @param i1 number
 * @param i2 number
 * @return 1 all are valid, 0 otherwise
 */
int validation(double len,double i1,double i2){

  /* check if indexes and length are whole and positive number*/
    if (check_number(len)|| check_number(i1) || check_number(i2)){
        printf("*** Wrong value! Length and indexes must be whole and positive number. ***\n");
        return 0;
    }

    /* check the range given to compare, if not out of string range */
    if (i1 + len > MAX_STR || i2 + len > MAX_STR){
        printf("*** String range to compare is out of range ***\n");
         return 0;
     }

    return 1;
}


int main ()
{

    double len = 0;
    double i1=0;
    double i2=0;
    char str[MAX_STR];

    /* inputs */
    printf ("Insert a length: ");
    if (scanf("%lf",&len)!=1 || getchar()!='\n')
    {
        printf("*** Wrong value! Length must be a number. ***\n");
        printf("\nEnd of program.\n");
        return 0;
    }

    printf ("Insert a first index: ");
    if (scanf("%lf",&i1)!=1 || getchar()!='\n')
    {
        printf("*** Wrong value! Index must be a number. ***\n");
        return 0;
    }
    printf ("Insert a second index: ");
    if (scanf("%lf",&i2)!=1 || getchar()!='\n')
    {
        printf("*** Wrong value! Index must be a number. ***\n");
        return 0;
    }

    printf ("Insert a string: ");
    scanf ("%s]", str);
    getchar ();

    printf ("\n");
    /* validation */
    if (validation(len,i1,i2)){
        /* pinter */
        char *b1,*b2;

        /* convert the index number to pointer to index in string */
        b1 = &str[(int) i1];
        b2 = &str[(int) i2];

        printf("1 the byte length from both indexes are same, 0 otherwise\n");
        printf("The result value is: %d\n",my_bcmp(b1,b2,len));
    }

    printf("\n---End of program---\n");
    return 0;
}
