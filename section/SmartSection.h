#ifndef _SMART_SECTION_H_
#define _SMART_SECTION_H_
#include "SectionManager.h"
#include "HackEv3.h"

class SmartSection : public SectionManager
{
    public: //変数宣言

        SmartSection();
        bool run();
        void course(int direct);

        enum COURSNO{
            SET_VIR_LINE,
            END
        };
    
    protected:
        COURSNO NO;

#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
#endif
    private:
        int num1;

        SecParam VIR[2] = {
            //{Section::VIRSLINE,{60, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

};
#endif