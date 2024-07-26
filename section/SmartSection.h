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

        };
    
    protected:
        COURSNO NO;

}
