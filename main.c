/* Fragment search and replacement.
 * Highlight the replaced fragments with brackets.
 * Print out the old text and the new one.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void replace(char *orig, char *old, char *new, char *result){
    while(*orig){
        if(strncmp(orig, old, strlen(old)) == 0){
            strcpy(result, new);
            result += strlen(new);
            orig += strlen(old);
        }else{
            *result++ = *orig++;
        }
    }
    *result = '\0';
}

int main()
{
    printf("Enter the original string: \n");
    char text[MAXLINE];
    fgets(text, MAXLINE, stdin);
    printf("Enter the fragment to be replaced: \n");
    char fragment[MAXLINE];
    fgets(fragment, MAXLINE, stdin);
    printf("Enter the new fragment: \n");
    char new_fragment[MAXLINE];
    fgets(new_fragment, MAXLINE, stdin);

    char result[MAXLINE];
    strcpy(result, text);
    replace(text, fragment, new_fragment, result);

    printf("The original string is: \n");
    printf("%s", text);
    printf("The new string is: \n");
    printf("%s", result);

    return 0;
}
