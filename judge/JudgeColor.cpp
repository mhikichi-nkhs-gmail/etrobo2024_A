#include "JudgeColor.h"

JudgeColor::JudgeColor()
{

}

void JudgeColor::setParam(double cocn[])
{
    mHRange = cocn[0];
    mSRange = cocn[1];
}

void JudgeColor::init()
{
    
}

bool JudgeColor::judgement()
{
    double value = mHsvHue->getValue() - mHRange;
    
    //printf("色みたい%f %f\n",value,mHsvSatu->getValue());

    value = fabs(value);//�Ԃւ̑Ή�
    //printf("colorvalue\n");

    if(value >=180)
    {
       value = 360 -value;
    }

    if(value < 40)
    {
        if(mSRange < mHsvSatu->getValue())
        {
            return true;
        }
    }
    return false;

}