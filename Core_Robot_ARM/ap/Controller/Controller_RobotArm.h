/*
 * Controller_RobotArm.h
 *
 *  Created on: Jan 9, 2026
 *      Author: 82109
 */

#ifndef AP_CONTROLLER_CONTROLLER_ROBOTARM_H_
#define AP_CONTROLLER_CONTROLLER_ROBOTARM_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "cmsis_os.h"
#include "usart.h"
#include "../Model/Model_RobotArm.h"

//로봇팔 길이
#define LINK_1_LENGTH 9.0f //Shoulder ~ Elbow 길이(cm)
#define LINK_2_LENGTH 11.0f  //Elbow    ~ Gripper 길이 (cm)

//수학 상수
#define RAD_TO_DEG    57.2957795f
#define PI            3.14159265f

//각도 제한 (모터 보호용)
#define BASE_MIN 0
#define BASE_MAX 180
#define SHOULDER_MIN 50
#define SHOULDER_MAX 120
#define ELBOW_MIN 20
#define ELBOW_MAX 90
#define GRIPPER_MIN 0 //잡기
#define GRIPPER_MAX 90//놓기

//로봇팔이 움직일 필드의 크기 = 카메라로 촬영되는 구역의 사이즈
#define REAL_FIELD_WIDTH_X   30.0f  // 가로 실제 길이
#define REAL_FIELD_HEIGHT_Y  20.0f  // 세로 실제 길이

//이 경우는 필드에서 로봇이 화면 왼쪽(x=0)에서 15cm 오른쪽, 화면 위(y=0)에서 40cm 아래 있다고 가정
#define CAMERA_OFFSET_X  -15.0f  // 로봇 기준으로 카메라 0점이 어디인지
#define CAMERA_OFFSET_Y  0.0f   // 로봇 팔 앞쪽으로 10cm 떨어진 곳부터 화면이 시작된다면

// FPGA 좌표 최대값
#define FPGA_MAX_X           320.0f
#define FPGA_MAX_Y           240.0f

//유틸리티 매크로
#define CLAMP(x, min, max)((x) < (min) ? (min) : ((x)>(max) ? (max) : (x)))


void Controller_RobotArm_Init();
void Controller_RobotArm_Excute();

void Controller_RobotArm_Manual();
void Controller_RobotArm_Auto();
void Controller_CalcIK(RobotArm_t *pRobot);

#endif /* AP_CONTROLLER_CONTROLLER_ROBOTARM_H_ */
