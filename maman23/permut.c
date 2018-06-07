//
// Created by Ori Shinsholker on 6/6/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 120
#define ASCII_SIZE 256


int check_input(int);
FILE *open_file(char *, char *);
void Test_Permutation(FILE *file_p, char user_string[],int len);
int compare_strings(char *,char *, int);
void create_vector(char *, int , char *);
int mycmp(char a[], char b[], int);




int check_input(int argc)
/* check the command line arguments */
{
    int flag=TRUE;
    if (argc==1)
    {
        fprintf(stderr,"Missing arguments\n");
        flag=FALSE;
    }
    else if (argc==2)
    {
        printf("Missing string to inspect\n");
        flag=FALSE;
    }
    else if (argc>3)
    {
        printf("Too many input arguments\n");
        flag=FALSE;
    }
    return flag;
}


FILE *open_file(char *name, char *mode)
{
    FILE *fd;
    off_t file_size;

    fd=fopen(name,mode);
    if(fd==NULL)
    {
        fprintf(stderr,"%s No such file\n",name);
        exit(1);
    }

    file_size = ftello(fd);
    if (file_size == 0) { /* check if file is empty, by size */
        fprintf(stderr,"%s file is empty\n", name);
    }

    return (fd);
}

int mycmp(char a[], char b[],int length)
{
    int i=0;
    while(i<length && a[i]==b[i])
        i++;
    if (i==length)
        return TRUE;
    else return FALSE;
}


void create_vector(char *name, int len, char *vector)
{
    int i;
    // printf("string: %s\n",name);
    for ( i = 0; i <len; i++)
    {
        (vector[name[i]])++;
    }
}


int compare_strings(char *user_word,char *file_word, int len)
{
    char user_vector[ASCII_SIZE]={0}, current_vector[ASCII_SIZE]={0};
    create_vector(user_word, len, user_vector);
    create_vector(file_word, len, current_vector);
    return mycmp(user_vector,current_vector,ASCII_SIZE);
}


void Test_Permutation(FILE *file_p, char user_string[],int len)
{

    char tmp[len+1];
    char current_string[MAXSIZE];
    int i,current_len;
    while (!feof(file_p))
    {
        fscanf(file_p,"%s",current_string);
        current_len = strlen(current_string);
        if (len <= current_len) /*if the scanned word is smaller than the user word-scanf the next one*/
        {
            for (i = 0;i <= current_len - len; i++)
            {
                strncpy(tmp,current_string+i,(size_t)len);
                tmp[len]='\0';
                //printf("tmp len: %d\n",strlen(tmp));
                if(compare_strings(user_string,tmp,len))
                {
                    printf("%s\n",tmp);
                    i+=len-1;
                }


            }
        }

    }
}

int main(int argc, char *argv[])
{
    int flag = check_input(argc); /*check if command arguments are valid */

    if (flag == TRUE)
    {
        FILE *fd;
        int len=strlen(argv[2]);
        char user_word[len+1];

        strcpy(user_word,argv[2]);
        fd = open_file(argv[1], "r"); /* open the file */

        Test_Permutation(fd,user_word,len);

        fclose(fd); /* close file */
        return 0;
    }
    else
        return 1;
}