#include <stdio.h>
#define MAX_N 16

void classify_by_threshold(const int value[], int label[], int N, int threshold){
    for (int i = 0; i < N; i++) {
        if (value[i] < threshold) 
            label[i] = 1;
        else 
            label[i] = 0;
    }
}

int count_line(const int label[], int N){
    int count = 0;
    for (int i = 0; i < N; i++) count += label[i];

    return count;
}

double average_line_index(const int label[], int N){
    int sum_index = 0;
    double avg;
    for (int i = 0; i < N; i++)
    {
        sum_index += (i * label[i]); // 라인 중심 위치 계산
    }
    avg = (double)sum_index / (double)count_line(label, N);
    return avg;
}

int main() {
    int N, threshold, data, line_count;
    printf("센서 개수 입력(1 - %d): ", MAX_N);
    scanf("%d", &N);
    printf("임계값 입력: ");
    scanf("%d", &threshold);

    int label[N], value[N];
    printf("센서값 %d개 입력: ", N);  // 나중에 센서에서 값 받는 코드로 대체
    for (int i = 0; i < N; i++){
        scanf("%d", &value[i]);
    }

    double centre;

    classify_by_threshold(value, label, N, threshold);
    line_count = count_line(label, N);
    centre = average_line_index(label, N);

    printf("label: ");
    for (int i = 0; i < N; i++) {
      printf("%d ", label[i]);
    }
    printf("\n");
    printf("line count: %d\n", line_count);
    printf("centre : %.1lf\n", centre);

    return 0;
}