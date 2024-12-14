#include <stdio.h>
#include <stdlib.h>

//Robot defintion
typedef struct ROBOT{
    int robot_num;
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
}ROBOT;

ROBOT init_robot(ROBOT *robot, int num, int pos_x, int pos_y, int vel_x, int vel_y){
    robot->robot_num = num;
    robot->pos_x = pos_x;
    robot->pos_y = pos_y;
    robot->vel_x = vel_x;
    robot->vel_y = vel_y;
}

void move_robot(){


    
}

int main(){

    ROBOT robot0, robot1, robot2, robot3, robot4, robot5, robot6, robot7, robot8, robot9, robot10, robot11;
    init_robot(&robot0, 0, 0, 4, 3, -3);
    init_robot(&robot1, 1, 6, 3, 1, -3);
    init_robot(&robot2, 2, 10, 3, -1, 2);
    init_robot(&robot3, 3, 2, 0, 2, -1);
    init_robot(&robot4, 4, 0, 0, 1, 3);
    init_robot(&robot5, 5, 3, 0, -2, -2);
    init_robot(&robot6, 6, 7, 6, 1, -3);
    init_robot(&robot7, 7, 3, 0, -1, -2);
    init_robot(&robot8, 8, 9, 3, 2, 3);
    init_robot(&robot9, 9, 7, 3, -1, 2);
    init_robot(&robot10, 10, 2, 4, 2, -3);
    init_robot(&robot11, 11, 9, 5, -3, -3);

    printf("TEST: num=%d posx=%d posy=%d velx=%d vely=%d\n",robot0.robot_num, robot0.pos_x,robot0.pos_y,robot0.vel_x,robot0.vel_y);
    return 0;
}