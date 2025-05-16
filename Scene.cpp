#include "Scene.h"
#include "MyColorSensor.h"
#include "SpikePort.h"
#include "spikeapi.h"

extern MyColorSensor *gColor;
        
extern Brightness *gBrightness;

extern HsvHue *gHsvHue;

extern HsvSatu *gHsvSatu;

extern pup_device_t *  gcolorsensor;
extern pup_device_t *  gforcesensor;

bool flag = false;



Scene::Scene():
    mState(UNDEFINED)
{
    //gColor = new MyColorSensor(PORT_2,gBrightness,gHsvHue,gHsvSatu);
    gColor = new MyColorSensor(gcolorsensor,gBrightness,gHsvHue,gHsvSatu);
    mSsm = new SpeedSectionManager();
    mDs = new DoubleSection();
    mDs2 = new DoubleSection();
    mBs = new BlockSection();
    mSs = new SmartSection();
    //int mv = ev3_battery_voltage_mV();
    int mv = hub_battery_get_voltage();
    printf("%d\n",mv);
    printf("作った\n");
}

bool Scene::run()
{
    //printf("%d\n",mState);
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case CALIBRATION:
            execCalibration();
            break;
        case START:
            execStart();
            break;
        case SPEED:
            execSpeed();
            break;
        case DOUBLELOOP:
            execDoubleloop();
            break;
        case BLOCK:
            execBlock();
            break;
        case SMART:
            execSmartCarry();
            break;
        /*
        case BINGO:
            execBingo();
            break;
        case GARAGE:
            execGarage();
            break;
        */
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
    //printf("Undefined_Start\n");
    //mState=START;
    mState=CALIBRATION;
    printf("Undefined\n");

}

void Scene::execCalibration()
{
    
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    //ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    //if(ev3_button_is_pressed(LEFT_BUTTON))
    if(pressed & HUB_BUTTON_LEFT)
    {
        printf("left\n");
        mSsm->course(0);
        mDs->course(0);
        mDs2->scircle(0);
        mBs->course(0);
        gColor->setRGB();
        mSs->course(0);
        mState=START;
    }

    //ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    //if(ev3_button_is_pressed(RIGHT_BUTTON))
    if(pressed & HUB_BUTTON_RIGHT)
    {
        printf("right\n");
        mSsm->course(1);
        mDs->course(1);
        mDs2->scircle(1);
        mBs->course(1);
        gColor->setRGB();
        mSs->course(1);
        mState=START;
    }
    /*
    printf("Calibration_Start\n");
    gColor->setRGB();
#if defined(MAKE_SIM)
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if (ev3_button_is_pressed(LEFT_BUTTON))
    {
        mState=START;
        printf("Calibration_Finish\n");
    }
#else
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        mState=START;
        printf("Calibration_Finish\n");
    }
#endif
*/
}

void Scene::execStart()
{
    hub_button_t pressed;
    pbio_error_t err = hub_button_is_pressed(&pressed); 
    //printf("Start_Start\n");
    /*ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        printf("left\n");
        mSsm->course(0);
        mDs->course(0);
        gColor->setRGB();
    }
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(RIGHT_BUTTON))
    {
        printf("right\n");
        mSsm->course(1);
        mDs->course(1);
        gColor->setRGB();
    }*/

#if defined(MAKE_SIM)
// とりあえず動かすだけなので、設計に基づ�?て書き直そう
    //msg_log("Press Touch Button to start.");
    //ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
      // if(pup_force_sensor_pressed(gforcesensor , 1))
    if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
        printf("DOUBLELOOP\n");
            mState=SMART;
    }
#else
    if(pup_force_sensor_pressed(gforcesensor , 1))
    {
        printf("SPEED\n");
        mState=SPEED;
        //mState=DOUBLELOOP;
        //mState=SMART;
    }
#endif
//printf("Start_Finish\n");
}
void Scene::execSpeed()
{
    if(mSsm->run()) {
        delete mSsm;
        mState=DOUBLELOOP;
        //printf("speed終わった\n");
        //mState = END;
    }
    //printf("Speed_Finish\n");
}
void Scene::execDoubleloop()
{
    if(flag != true)
    {
        if(mDs->run())
        {
            printf("大円終わった\n");
            delete mDs;
            flag = true;
        }
    }
    else
    {
        if(mDs2->run())
        {
            printf("double終わった\n");
            delete mDs2;
            //mState=END;
            mState=BLOCK;
        }
    }
}
void Scene::execBlock()
{
    if(mBs->run())
    {
        printf("block終わった\n");
        delete mBs;
        mState=END;
    }
}
void Scene::execSmartCarry()
{
    if(mSs->run())
    {
        printf("Smart終わった\n");
        delete mSs;
        mState=END;
    }
}
/*void Scene::execBingo()
{

}
void Scene::execGarage()
{

}
*/