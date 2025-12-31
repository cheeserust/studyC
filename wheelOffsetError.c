#include <stdio.h>
#include <math.h>

int main() {
    double radius, trackWidth, epsilL, epsilR, targetDistance;
    int rotation;
    double effective_radius_L, effective_radius_R, effective_distance_L, effective_distance_R, curvatureRadius, offset_deg, d_drift;

    

    printf("------ 정보 입력 ------\n");
    printf("바퀴 반지름 입력: ");
    scanf("%lf", &radius);

    printf("트랙 폭 입력: ");
    scanf("%lf", &trackWidth);

    printf("좌 바퀴 오차율: ");
    scanf("%lf", &epsilL);
    
    printf("우 바퀴 오차율: ");
    scanf("%lf", &epsilR);

    printf("목표 주행 거리: ");
    scanf("%lf", &targetDistance);

    effective_radius_L = radius * (1 + epsilL);
    effective_radius_R = radius * (1 + epsilR);
    effective_distance_L = 2 * 3.1415 * effective_radius_L;
    effective_distance_R = 2 * 3.1415 * effective_radius_R;
    curvatureRadius = (0.5 * trackWidth) * ((effective_distance_L + effective_distance_R) / (effective_distance_R - effective_distance_L));
    offset_deg = (targetDistance / curvatureRadius) * (180/3.1415);
    d_drift = curvatureRadius * (1 - cos(offset_deg));

    printf("------ 결과 ------\n");
    printf("좌/우 유효 반지름: L = %lfm, R = %lfm\n", effective_radius_L, effective_radius_R);
    printf("곡률반경: %.2lfm\n", curvatureRadius);
    printf("편류각: %.2lf deg\n", offset_deg);
    printf("최종 편류 거리: %.2lfm\n", d_drift);
}