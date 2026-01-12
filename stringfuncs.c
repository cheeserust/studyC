#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// strcpy strcat strlen strcmp 구현


//strlen 완
long unsigned int stringLength(char* string) {
    int i = 0, length = 0;
    while (string[i] != 0){
        length += 1;
        i++;
    }
}
    

//strcpy 완
char* stringCopy(char* destination, char* source){
    int i = 0;

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
//strcat 완
char* stringCat(char* destination, char* source){
    int end = 0;
    while (destination[end] != '\0'){
        end++;
    }
    
    int i = 0;
    while (source[i] != '\0')
    {
        destination[end + i] = source[i];
        i++;
    }
    destination[end + i] = '\0';
}


//strcmp 완
int stringCompare(char* str1, char* str2) {
    int i = 0, result;
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    if (str1[i] > str2[i]) return 1;
           
    else if (str1[i] < str2[i]) return -1;
           
    else return 0;
    }

int main()
{
    char str1[80] = "apple";
    char str2[80] = "apple";
    stringCompare(str1, str2);
    /*
    for (int i = 0; i < sizeof(str1); i++)
    {
        if (str1[i] == 0)
        printf("0 ");
        else printf("%c ", str1[i]);
    }
    */
    printf("\n");
    return 0;
}
