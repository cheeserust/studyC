// https://mojan3543.github.io/ShortCodingInC/
// 숏코딩 예시 10950번

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count =0, i;
    char str[1000000];
    if (str == NULL){
        printf("xxxxxxxx");
        exit(1);
    }
    scanf("%s", str);
    char* ptr = strtok(str, " ");
    while (ptr != NULL)
    {
        str[i] = ptr;
        ptr = strtok(NULL, " ");
        i++;
        count++;
    }
    printf("%d", count);
    
    return 0;
} 