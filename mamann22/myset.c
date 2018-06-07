/*
 * main.c
 *
 *  Created on: May 19, 2012
 *      Author: stas
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "set.h"
#include "set.c"


typedef struct{
    const char*name;
    const void*key;
}Tbl[];

Set SETA,SETB,SETC,SETD,SETE,SETF;



void*map(char*name,Tbl tbl){
    for( ; tbl->name && strcmp(name,tbl->name); tbl++)
        ;
    return (void*)tbl->key;
}

void read_set_io(char*args)
{
    char*token = strtok(args,", ");
    char*var_name[MAX_INPUT_SIZE];
    strcpy(var_name,token);

    token = strtok (NULL, ", ");
    if (token == NULL){
        return;
    }

    strcpy(args,token);



    const Tbl sets={{"SETA",&SETA},
                    {"SETB",&SETB},
                    {"SETC",&SETC},
                    {"SETD",&SETD},
                    {"SETE",&SETE},
                    {"SETF",&SETF},
                    {NULL,NULL}};
    void*(*f) = map(var_name,sets);

    while (token)
    {
        read_set(*f,atoi(token));
        token = strtok (NULL, ", ");

    }
}
void print_set_io(char*args)
{
    /* get set */

    char*token = strtok(args,",");
    char*var_name[MAX_INPUT_SIZE];
    strcpy(var_name,token);

    const Tbl sets={{"SETA",&SETA},
                    {"SETB",&SETB},
                    {"SETC",&SETC},
                    {"SETD",&SETD},
                    {"SETE",&SETE},
                    {"SETF",&SETF},
                    {NULL,NULL}};
    void*(*f) = map(var_name,sets);
    print_set(*f);

}



void union_set_io(char*args)
{
    char*token = strtok(args,",");
    char*group_1[5];
    strcpy(group_1,token);

    token = strtok(NULL,",");
    char*group_2[5];
    strcpy(group_2,token);

    token = strtok(NULL,",");
    char*group_3[5];
    strcpy(group_3,token);

    const Tbl sets={{"SETA",&SETA},
                    {"SETB",&SETB},
                    {"SETC",&SETC},
                    {"SETD",&SETD},
                    {"SETE",&SETE},
                    {"SETF",&SETF},
                    {NULL,NULL}};


    void*(*g1) = map(group_1,sets);
    void*(*g2) = map(group_2,sets);
    void*(*g3) = map(group_3,sets);
    *g3 = union_set(*g1,*g2);
}
void intersect_set_io(char*args)
{
    char*token = strtok(args,",");
    char*group_1[5];
    strcpy(group_1,token);

    token = strtok(NULL,",");
    char*group_2[5];
    strcpy(group_2,token);

    token = strtok(NULL,",");
    char*group_3[5];
    strcpy(group_3,token);

    const Tbl sets={{"SETA",&SETA},
                    {"SETB",&SETB},
                    {"SETC",&SETC},
                    {"SETD",&SETD},
                    {"SETE",&SETE},
                    {"SETF",&SETF},
                    {NULL,NULL}};


    void*(*g1) = map(group_1,sets);
    void*(*g2) = map(group_2,sets);
    void*(*g3) = map(group_3,sets);
    *g3 = intersect_set(*g1,*g2);
}
void sub_set_io(char*args)
{
    char*token = strtok(args,",");
    char*group_1[5];
    strcpy(group_1,token);

    token = strtok(NULL,",");
    char*group_2[5];
    strcpy(group_2,token);

    token = strtok(NULL,",");
    char*group_3[5];
    strcpy(group_3,token);

    const Tbl sets={{"SETA",&SETA},
                    {"SETB",&SETB},
                    {"SETC",&SETC},
                    {"SETD",&SETD},
                    {"SETE",&SETE},
                    {"SETF",&SETF},
                    {NULL,NULL}};


    void*(*g1) = map(group_1,sets);
    void*(*g2) = map(group_2,sets);
    void*(*g3) = map(group_3,sets);
    *g3 = sub_set(*g1,*g2);
}

void stop()
{
    /* clear memory */
    free(SETA);
    free(SETB);
    free(SETC);
    free(SETD);
    free(SETE);
    free(SETF);
    exit(0);
}

void read_command(char*input,char*command, char*args)
{

    char*token = strtok(input," ");
    strcpy(command,token); /*read_set*/

    token = strtok (NULL, "-");
    strcpy(args,token);

}


int main()
{

    /* init commands */
    /*Set SETA,SETB,SETC,SETD,SETE,SETF;*/

    const Tbl cmds={{"read_set",read_set_io},
                    {"print_set",print_set_io},
                    {"union_set",union_set_io},
                    {"intersect_set",intersect_set_io},
                    {"sub_set",sub_set_io},
                    {"stop",stop},
                    {NULL,NULL}};


    /* init sets */
    SETA=new_set();
    SETB=new_set();
    SETC=new_set();
    SETD=new_set();
    SETE=new_set();
    SETF=new_set();


    char*input = malloc(sizeof(char)*MAX_INPUT_SIZE);
    char*command = malloc(sizeof(char)*MAX_COMMAND_SIZE);
    char*args = malloc(sizeof(char)*(MAX_INPUT_SIZE-MAX_COMMAND_SIZE));

    while(1)
    {
        printf(PROMPT);
        gets(input);
        read_command(input,command,args);

        void*(*f)(void*) = map(command,cmds);
        if(f==NULL)
            printf("No such command‬‬ '%s'\n",command);
        else
            f(args);
    }


    return 0;
}