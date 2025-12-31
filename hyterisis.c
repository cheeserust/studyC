#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
    srand(time(NULL));
    int N, battery, initial_value;
    int warning = 0;

    printf("data #: ");
    scanf("%d", &N);
    printf("initial value: ");
    scanf("%d", &initial_value);

    int battery_log[100];
    battery_log[0] = initial_value;
    for (int i = 0; i < N; i++)
    {
        battery_log[i] = battery_log[i - 1] + (rand() % 10 - 5);
    }
    printf("\n배터리 히스테리시스 경보 결과\n");
    for (int j = 0; j < N; j++)
    {
        if (warning == 0 && battery_log[j] <= 30){
            warning == 1;
            printf("배터리 잔량: %d, 경고 ON\n", battery_log[j]);
        } else if (warning == 1 && battery_log[j] >= 40) {
            warning == 0;
            printf("배터리 잔량: %d, 경고 OFF\n", battery_log[j]);
        }
    }

    return 0;
}