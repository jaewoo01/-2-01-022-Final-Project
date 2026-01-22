/*
 * Presenter_RobotArm.h
 *
 * Created on: Jan 9, 2026
 * Author: 82109
 */

#ifndef AP_PRESENTER_PRESENTER_ROBOTARM_H_
#define AP_PRESENTER_PRESENTER_ROBOTARM_H_

#include "cmsis_os.h"
#include "../Model/Model_RobotArm.h"
#include "../Model/Model_Mode.h"     // 모드 확인용
#include "../../driver/servo_motor/servo_motor.h"
#include "../../driver/lcd/lcd.h"    // LCD 드라이버
#include "i2c.h"                     // I2C 핸들
#include "usart.h"

#define DEBUG_HEARTBEAT  0
#define FPGA_TICK_PULSE (1U)
#define IDLE_WAIT_TIMEOUT_MS (500U)

#define READY_BASE	   (0)
#define READY_SHOULDER (0)
#define READY_ELBOW    (0)
#define GRIP_OPEN      (100)
#define GRIP_CLOSE     (0)

#define LIFT_BASE      (0)
#define LIFT_SHOULDER  (0)
#define LIFT_ELBOW     (0)

#define PUT_BASE       (0)
#define PUT_SHOULDER   (0)
#define PUT_ELBOW      (0)

#define AT_TARGET_TOL_DEG     (2.0f)
#define STATE_TIMEOUT_MS      (4000U)  // 상태별 최대 4초 (원하면 조정)

#define SERVO_UPDATE_PERIOD_MS  (10U)
#define SERVO_UPDATE_DT_S       ((float)SERVO_UPDATE_PERIOD_MS / 1000.0f)


// CubeMX 설정에 맞게 변경 (예: TIM3)
extern TIM_HandleTypeDef htim3;
// I2C 핸들 (예: hi2c1)
extern I2C_HandleTypeDef hi2c1;


void Presenter_RobotArm_Init();
void Presenter_RobotArm_Excute();

// 내부적으로 사용할 화면 출력 함수
void Presenter_RobotArm_DispMode();

#endif /* AP_PRESENTER_PRESENTER_ROBOTARM_H_ */
