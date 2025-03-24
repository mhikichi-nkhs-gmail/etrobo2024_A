#ifndef MOTORMANAGER_
#define MOTORMANAGER_

#include <math.h>
#include "util.h"

//#include "Motor.h"
#include "Odometry.h"

class MotorManager
{
    public:
		MotorManager(pup_motor_t *left,
					 pup_motor_t *right);

	void setPwm(int left,int right);
	void init();

	private:
		pup_motor_t *mLeftMotor;
		pup_motor_t *mRightMotor;

		int32_t current_lmotor;
		int32_t current_rmotor;
	
		int32_t prev_lmotor = 0;
		int32_t prev_rmotor = 0;

		double mlCount = 0;
		double mrCount = 0;

};

#endif
