#include <stdio.h>

int main(){
    float i_load, vel, reserve, voltage, capacity, eta;
    float wattUsage, runtime, distance, usableE;
    int motorNumber;

    printf("-------- 사전 선정 정보 --------\n");
    printf("평균 전류 입력(A): ");
    scanf("%f", &i_load);
    printf("평균 속도 입력(km/h): ");
    scanf("%f", &vel);
    printf("예비율 입력(0 - 1): ");
    scanf("%f", &reserve);
    printf("모터 개수입력 : ");
    scanf("%d", &motorNumber);

    printf("-------- 배터리 정보 --------\n");
    printf("공칭전압 입력(V): ");
    scanf("%f", &voltage);
    printf("용량 입력(Ah): ");
    scanf("%f", &capacity);
    printf("시스템 효율 입력(0 - 1): ");
    scanf("%f", &eta);

    printf("\n전압강하와 온도 영향은 무시, 평균전류는 일정하다고 가정\n");
    usableE = voltage * capacity * eta * (1 - reserve);
    wattUsage = (voltage * i_load / eta) * motorNumber;
    runtime = usableE / wattUsage;
    distance = vel * runtime;

    printf("소비전력 = %.2fW\n", wattUsage);
    printf("런타임 = %.2fh\n", runtime);
    printf("주행거리 = %.2fkm\n", distance);

    return 0;
}