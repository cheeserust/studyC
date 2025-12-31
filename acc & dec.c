#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 4  
// 5  무한반복 -> 0 되면 종료

int main() {
    srand(time(NULL));

    int del_v;                           // 속도 증감폭
    int i, j, N;                         // 루프 관련 변수
    int acc_count = 0, dec_count = 0;    // 가속 & 감속 카운트 초기화
    int initial_v = rand() % 30 + 50;    // 처음 랜덤 속도 (주행중인 상황 가정)
    int random;

    printf("속도 데이터 갯수 입력: ");
    scanf("%d", &N);
    printf("처음 속도: %d\n", initial_v);

    int vLog[1000] = {0};
    vLog[0] = initial_v;
    for (i = 1; i < N;) {  //  총반복 카운트 i++ 는 각 구간 반복 시 증가
        int action = rand() % 2;

        if (vLog[i-1] < 15)      // 속도가 너무 느리면 
            action = 0;          // 강제로 가속시작

        if(vLog[i-1] > 135)      // 속도가 너무 빠르면 
            action = 1;          // 강제로 감속 시작

        random = rand() % 11 + 10;

        if (action == 0) { // 가속
            printf("\n--------가속 시작---------\n");
            for (j = 1; j <= random; i++)
            {
                vLog[i] = vLog[i - 1] + (rand() % 11 + 5);  // (바로 전 속도) + (5 에서 15 랜덤 속도 가속)

                if (vLog[i] >= 150)     // 속도가 150위로 올라가면 가속 강제 종료
                    break;

                printf("#%d : %d\n", i, vLog[i]);
                j++;  // 구간 반복 카운트
            }
            printf("\n--------가속 끝---------\n");

        } else {   // 감속
            printf("\n--------감속 시작---------\n");
            for (j = 1; j <= random; i++) {
                vLog[i] = vLog[i - 1] - (rand()%11 + 5); // (바로 전 속도) + (5 에서 15 랜덤 속도 감속)

                if (vLog[i] <= 0)   // 속도가 0 밑으로 떨어지면 감속 강제 종료
                    break;   

                printf("#%d : %d\n", i, vLog[i]);
                j++;
            }
            printf("\n--------감속 끝---------\n");
        }
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        del_v = vLog[i] - vLog[i - 1];
        if (del_v >= 10)
        {
            acc_count++;
        }
        if (del_v <= -10)
        {
            dec_count++;
        }
    }
    printf("급가속 횟수: %d회 / 급제동 횟수: %d회\n", acc_count, dec_count);
    return 0;
}