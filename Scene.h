#ifndef _SCENE_H_
#define _SCENE_H_

#include "SpikePort.h"
#include "SpeedSectionManager.h"
#include "ColorSensor.h"
#include "MyColorSensor.h"
#include "DoubleSection.h"
#include "BlockSection.h"
#include "SmartSection.h"

//typedef enum _hub_button_t {
    //HUB_BUTTON_LEFT   = PBIO_BUTTON_LEFT,
    //HUB_BUTTON_CENTER = PBIO_BUTTON_CENTER,
    //HUB_BUTTON_RIGHT  = PBIO_BUTTON_RIGHT,
    //HUB_BUTTON_BT     = PBIO_BUTTON_RIGHT_UP,
 //} hub_button_t;


class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execCalibration();
        void execStart();
        void execSpeed();
        void execDoubleloop();
        void execBlock();
        void execSmartCarry();
        //void execBingo();
        //void execGarage();

    private:
        enum State {
            UNDEFINED,
            CALIBRATION,
            START,
            SPEED,
            DOUBLELOOP,
            BLOCK,
            SMART,
            //BINGO,
            //GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;

        MyColorSensor *mColor;

        DoubleSection *mDs;

        DoubleSection *mDs2;

        BlockSection *mBs;

        SmartSection *mSs;

        
};
#endif
