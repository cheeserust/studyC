#include <stdio.h>
#include <string.h>


typedef struct
{
    char ip[50];
    int count;
} IpCount;

int main(void)
{
    IpCount ipList[100];
    int uniqueIPs = 0;
    int maxCount = 0;
    char* maxIP;

    FILE* fp; 
    fp = fopen("fast.log", "r");
    char ch[500];
    int i;
    int pingCount = 0;

    if (fp == NULL)
    {
        printf("failed to open\n");
        return 1;
    }
    while (fgets(ch, sizeof(ch), fp) != NULL)
    {

        // printf("%s\n", ch);
        if (strstr(ch, "Ping"))
            pingCount += 1;
        if (strstr(ch, "{IPv6-ICMP}") || strstr(ch, "{ICMP}"))
        {
            // 다음 "->" 전 까지 읽어서 ip 배열에 새로 추가한 후 그 요소 카운트 ++
            char* start = strstr(ch, "} ");
            start += 2; // "} " 넘김

            char* end = strstr(start, " ->");
            int length = end - start; // ip + 포트번호 길이

            char ipWithPort[50];
            strncpy(ipWithPort, start, length); // 임시 버퍼에 주소 복사
            ipWithPort[length] = '\0';          // 끝에 null 넣어줌

            char* lastColon = strrchr(ipWithPort, ':');
            *lastColon = '\0';

            int found = -1;
            for (int j = 0; j < uniqueIPs; j++){
                if (strcmp(ipWithPort, ipList[i].ip) == 0){
                    found = j;
                    break;
                }
            }
            if (found != -1) {
                ipList[found].count++;
            } else {
                strcpy(ipList[uniqueIPs].ip, ipWithPort);
                ipList[uniqueIPs].count = 1;
                uniqueIPs++;
            }
        }
    }
        
    if (maxCount < ipList[i].count){
        maxCount = ipList[i].count;
        maxIP = ipList[i].ip;
    }
    printf("%s\n", maxIP);
    printf("%d\n", maxCount);
        
    printf("총 %d회 Ping 요청 \n", pingCount);
    printf("가장 많은 ping 요청은 %s로부터 %d회\n", maxIP, maxCount);

    for (i = 0;;)
    {
    }
    printf("");
    fputc('\n', fp);
    fclose(fp);
    return 0;
}