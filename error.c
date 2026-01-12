#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* fp;
    fp = fopen("log.txt", "r");
    char ch[30][100];
    int i;
    int errorCnt = 0, SO = 0, MO = 0;

    if (fp == NULL) {
        printf("안열림~\n");
        return 1;
    }
    while (fgets(ch, sizeof(ch), fp) != NULL)
    {
        
        printf("%s\n", ch);
        
        if (strstr(ch, "[ERROR]"))
            errorCnt += 1;

        if (strstr(ch, "Sensor failed"))
            SO += 1;
        else if (strstr(ch, "Motor overload"))
            MO += 1;
    }
    printf("총 %d회 Error 발견: \n", errorCnt);
    printf("Sensor failed: %d회, Motor overload: %d회\n", SO, MO);
    fputc('\n', fp);
    fclose(fp);
    return 0;
}