#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double left;
    double right;
} WheelSpeed;

typedef struct {
    double linear;
    double angular;
} RobotSpeed;

RobotSpeed computeSpeed(
    WheelSpeed w, 
    double wheel_radius, 
    double wheel_distance
) {
    RobotSpeed speed;
    speed.linear = (wheel_radius * (w.right + w.left)) / 2;
    speed.angular = (wheel_radius * (w.right - w.left)) / wheel_distance;
    return speed;
}

int main()
{
    double wheel_radius, wheel_distance;
    printf("바퀴 반지름: ");
    scanf("%lf", &wheel_radius);
    printf("바퀴 간 거리: ");
    scanf("%lf", &wheel_distance);

    WheelSpeed wheel_speed;
    printf("왼쪽 바퀴 속도 (rad/s): ");
    scanf("%lf", &wheel_speed.left);

    printf("오른쪽 바퀴 속도 (rad/s): ");
    scanf("%lf", &wheel_speed.right);

    RobotSpeed robot_speed;
    robot_speed = computeSpeed(wheel_speed, wheel_radius, wheel_distance);

    printf("\n");
    printf("왼쪽 바퀴 속도 (rad/s): %.1lf\n", wheel_speed.left);
    printf("오른쪽 바퀴 속도 (rad/s): %.1lf\n", wheel_speed.left);
    printf("바퀴 반지름 (m): %.2lf\n", wheel_radius);
    printf("바퀴 간 거리(m): %.2lf\n", wheel_distance);
    printf("\n");
    printf("linear velocity = %.2lf\n", robot_speed.linear);
    printf("angular velocity = %.2lf\n", robot_speed.angular);

    return 0;
}