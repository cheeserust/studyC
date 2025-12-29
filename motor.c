#include <stdio.h>
#include <string.h>

int main() {
    // double c, g, R, torque, G, SF, DM;  ???
    // int m, W, N, 

    // constants
    const double c = 0.018;      // 구름저항계수
    const double g = 9.81;       // 중력가속도 [N*m]
    int m;                       // 무게 [kg]
    printf("총 하중 입력 (kg): ");
    scanf("%d", &m);
    int weight = m * g;               // 중량 [N]


    // motor info
    double R;                    // 바퀴 반지름 [m]
    printf("바퀴 반지름 입력(m): ");
    scanf("%lf", &R);
    double torque;               // 토크
    printf("토크 입력 [N*m]: ");
    scanf("%lf", &torque);
    double G;                    // G, gear ratio
    printf("감속비 입력: ");
    scanf("%lf", &G);

    // 기획단계 선정 요소
    int N;                       // 바퀴 갯수
    printf("구동 바퀴 수 입력: ");
    scanf("%d", &N);
    double SF;                   // safety factor
    printf("안전계수 입력: ");
    scanf("%lf", &SF);
    double DM;                   // design margin
    printf("설계마진 입력: ");
    scanf("%lf", &DM);


    double Fmin = c * weight * SF *DM;           // 최소견인력

    double Fmotor = ((torque * G) / R) * N; // 모터 견인력

    printf("\n 최소 견인력: %.2f [N]\n", Fmin);
    printf("\n 모터 견인력: %.2f [N]\n\n", Fmotor);

    if (Fmin <= Fmotor) {
        printf("판정: 만족\n");
    }
    else printf("판정: 불만족 (더 큰 모터 or 감속비 필요)\n");
        

    return 0;
}
