#define _USE_MATH_DEFINES
#include "SpikePort.h"
#include "Odometry.h"
#include "math.h"
#include "HackEv3.h"

#define M_PI 3.14159265358979323846

// test comment
Odometry::Odometry(//Motor *left, Motor *right,
					pup_motor_t *nleft,pup_motor_t *nright,
					Length *len,
					TurnAngle *angle,
					XPosition *xp,
					YPosition *yp):
	//mLeftMotor(left),
	mLeftMotor(nleft),
	//mRightMotor(right),
	mRightMotor(nright),
	mTurnAngle(angle),
	mLength(len),
	mXPosition(xp),
	mYposition(yp)
{
	//mLeftMotor->reset();
	pup_motor_reset_count(mLeftMotor);
	//mRightMotor->reset();
	pup_motor_reset_count(mRightMotor);

	x=y=th=0.0;
	sumlen=0;
	prev_rs1=current_rs1=0;
	prev_rs2=current_rs2=0;
}



void Odometry::reset() 
{
	resetLength();
	resetAngle();

}
void Odometry::resetLength()
{
	sumlen=0.0;	
}
void Odometry::resetAngle()
{
	th=0.0;
	x=y=0;
	deg = 0.0;
}

void Odometry::update()
{
	//current_rs1 = mLeftMotor->getCount();
	current_rs1 = pup_motor_get_count(mLeftMotor);
	//current_rs2 = mRightMotor->getCount();
	current_rs2 = pup_motor_get_count(mRightMotor);
	
	calc();

	prev_rs1=current_rs1;
	prev_rs2=current_rs2;
}

void Odometry::calc()
{

	static int count=0;

	double rs1 = current_rs1;
	double rs2 = current_rs2;

	//syslog(LOG_NOTICE,"rs1,rs2 = %d,%d <- %d,%d",(int)rs1,(int)rs2, prev_rs1,prev_rs2);

	double drs1=rs1-prev_rs1;
	double drs2=rs2-prev_rs2;

	double len_l = drs1*M_PI*D_LEFT/360.0;
	double len_r = drs2*M_PI*D_RIGHT/360.0;
	double dth=(len_r-len_l)/TREAD;
	
	x+= (len_r+len_l)/2.0*cos(th+dth/2.0); //進行方向 X軸 0度方向
	y+= (len_r+len_l)/2.0*sin(th+dth/2.0); //横	

	th+=dth; // 左旋回＋、右旋回-
	sumlen += (len_r+len_l)/2.0;

	//.printf("x%f,,y%f,,th%f\n", x,y,th);

	mLength->update(sumlen);
	mTurnAngle->update(th);
	//printf("mTurnAngle%f,,\n", th);
	mXPosition->update(x);
	mYposition->update(y);

}

/*void Odometry::setPwm(int left,int right)
{
	mLeftMotor->setPWM(left);
	mRightMotor->setPWM(right);
}
*/