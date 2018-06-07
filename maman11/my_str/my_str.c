
int substr(char str[],char ch ,int start)
/*
   gets: string, character, and index for start to scan.
   print the first suffix of string that starts with character
   return the character's index.(first found)
*/
{
    int len = strlen(str);
    int i;
    int index_char=-1; /* -1 its mean => no matching character found. index_char save the index of matched character */


    for(i=start; i<len; i++){
        /* check if char is match and not matched before */
        if ((str[i]==ch) && index_char==-1)
        {
            index_char=i;
            printf("%c",str[i]);
        }

        else{
            /* Check if a compatible character is already found, printable to the end of the string */
            if (index_char!=-1)
                printf("%c",str[i]);
        }
    }
    printf("\n");
    return index_char;
}

int suffix(char str[],char ch)
/* gets: string and character
return the number of suffixes */
{

    int len = strlen(str);
    int count = 0; /* count of suffix */
    int i=0;

    while(i<len){
        i = substr(str,ch,i); /* Character index is found */

        if (i == -1) /* dosent exist suffix */
            return count;
        i++;
        count++;

    }
    return count;
}

int main()
/*
inputs: ask for char and string
and print the number of string suffixes that starts with char
*/
{
    char str[80];
    printf("Insert char: ");
    char ch    = getchar();
    getchar();

    printf("Insert string: ");
    scanf("%s",str);
    getchar();
    printf("\n");

    int suffixes = suffix(str,ch);
    printf("There are %i", suffixes);
    printf(" suffixes of '%s' that starts with ",str);
    printf("'%c'\n",ch);
    return 0;
}
