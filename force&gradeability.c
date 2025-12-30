#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
// gcc try.c -o try -lm
// ./ try

/*
int clip(int x, int min, int max) {
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}
*/


int main() {
    const float g = 9.8;
    float mass, angle, motorTorque, eta, radius, rollingC, safetyFactor;
    int motorN, gearRatio;
    float totalTorque, availF, needF, sin_thetaMax, gradeRatio, radian_to_degree;
    

    // 입력
    printf("-------- 정보 입력 --------\n");
    printf("총 질량 (kg): ");
    scanf("%f", &mass);

    printf("모터 정격 토크 입력(N*m): ");
    scanf("%f", &motorTorque);

    printf("모터 수 입력: ");
    scanf("%d", &motorN);

    printf("기어 감속비 입력: ");
    scanf("%d", &gearRatio);

    printf("구동 효율 입력: ");
    scanf("%f", &eta);

    printf("바퀴 반지름 입력(m): ");
    scanf("%f", &radius);

    printf("구름 계수 입력: ");
    scanf("%f", &rollingC);

    printf("안전 계수 입력: ");
    scanf("%f", &safetyFactor);
    
    totalTorque = motorN * motorTorque * gearRatio * eta;
    availF = totalTorque/radius;
    sin_thetaMax = (availF / safetyFactor - (rollingC * mass * g)) / (mass * g);
    if (sin_thetaMax < 0.0)
        sin_thetaMax = 0.0;
    if (sin_thetaMax > 1.0)
        sin_thetaMax = 1.0;
    gradeRatio = tan(sin_thetaMax) * 100;
    radian_to_degree = sin_thetaMax * (180 / 3.14);

    printf("-------- 계산 결과 --------\n");
    printf("총 가용 견인력: %0.2f\n", availF);
    printf("최대각: %0.2f\n", radian_to_degree);
    printf("등판율: %.2f\n", gradeRatio);

    return 0;
}