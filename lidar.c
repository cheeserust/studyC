#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCAN_N 360/40


int main()
{
    srand(time(NULL));
    int i, j, k, a, initial_d, motor_rotation, timeS;
    printf("몇초동안 가동?: ");
    scanf("%d", &timeS);

    printf("초당 몇회전?: ");
    scanf("%d", &motor_rotation);

    printf("최초 거리는?");
    scanf("%d", &initial_d);

    printf("처음 거리 = %d", initial_d);


    for (i = 0; i < timeS; i++){
        printf("---------------%d초---------------\n", i + 1);
        for (j = 0; j < motor_rotation; j++)
        {
            int* distance = malloc(sizeof(int) * SCAN_N);
            
            // NULL check
            if (distance == NULL) {
                printf("메모리 부족!!\n");
                break;
            } else
                printf("정상 작동합니다ㅏㅏㅏㅏ\n");

            printf("--------%d초 %d번째 회전---------\n", i + 1, j + 1);

            for (k = 1; k <= SCAN_N; k++)
            {
                distance[0] = initial_d;

                distance[k] = distance[k - 1] + rand() % 21 - 10;
                printf("%d\n", distance[k]);
            }
            int min_d = distance[0], min_index = 0;
            for (a = 1; a < SCAN_N; a++){
                if (distance[a] < min_d){
                    min_d = distance[a];
                    min_index = min_d;
                }
            }
            printf("\nmin_d = %d, angle = %d\n", min_d, a);
            free(distance);
        }
        
    }
    return 0;
}