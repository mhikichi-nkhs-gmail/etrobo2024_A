#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "HackEv3.h"

class SpeedSectionManager : public SectionManager {
    public:

        SpeedSectionManager();
        void course(int direct);

        
    protected:
#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
#endif

    


    private:

#if SP == 1
        SecParam Lcourse[20] = {
            {Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{0, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{315, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0, 13, 35, 4.5 ,17 , 0, 'LEFTEDGE'},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{90, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 14, 30, 4.5 ,17, 0, 'LEFTEDGE'},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::COLOR,{208,0.08, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Rcourse[25] = {
            {Section::TRACER,{90, 0, 9.9, 28, 4.4 , 0, 0, _EDGE},Section::LENGTH,{295, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{52, 0, 13, 35, 4.5 ,-14 , 0, _EDGE},Section::LENGTH,{345, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{40, 0, 13, 35, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{352, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{90, 0, 9.9, 28, 4.6 ,0 , 0, _EDGE},Section::LENGTH,{510, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{52, 0, 14, 35, 4.6 ,-14 , 0, _EDGE},Section::LENGTH,{560, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{52, 0, 13, 35, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{600, Section::FLNONE}, Section::EMNONE,{}},//LAPまで

            {Section::TRACER,{50, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{617, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{50, -0.2, 16, 30, 5.0 ,0 , 0, _EDGE},Section::COLOR,{190,0.3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{50, +0.9, 16, 30, 4.5 ,0, 0, _EDGE},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{50, -0.8, 15, 27, 4.7 ,0, 0, _EDGE},Section::LENGTH,{60, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, 0, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{230, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, +0.7, 16, 30, 4.7 ,0, 0, _EDGE},Section::LENGTH,{245, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, 0, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{355, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, +0.3, 21, 33, 4.7 ,0, 0, _EDGE},Section::LENGTH,{370, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, 0, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{455, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{35, -0.4, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{470, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{35, -0.2, 16, 30, 5.0 ,0 , 0, _EDGE},Section::COLOR,{190,0.3, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{40, +0.8, 20, 29, 4.9 ,0 , 0, _EDGE},Section::LENGTH,{23, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{40, -0.7, 16, 30, 4.5 ,0, 0, _EDGE},Section::LENGTH,{33, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{45, 0, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{185, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{35, -0.4, 15, 27, 4.7 ,0 , 0, _EDGE},Section::LENGTH,{200, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{35, -0.2, 16, 30, 5.0 ,0 , 0, _EDGE},Section::COLOR,{190,0.3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
        
            //{Section::TRACER,{50, +0.2, 13, 27, 4.5 ,0, 0, _EDGE},Section::LENGTH,{30, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::TRACER,{45, 0, 14, 35, 4.6 ,-15 , 0, _EDGE},Section::LENGTH,{120, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::TRACER,{45, 0, 14, 35, 4.6 ,-5 , 0, _EDGE},Section::LENGTH,{120, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::WALKER,{0,0},Section::LENGTH,{10000, Section::FLNONE}, Section::EMNONE,{}},
            //{Section::TRACER,{60, 0, 9.9, 27, 5.0 ,0 , 0, _EDGE},Section::COLOR,{208,0.08, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::WALKER,{0,0},Section::TIME,{10000000, Section::RESETLEN}, Section::EMNONE,{}},
           // {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        #endif

#if SP == 2
        SecParam Lcourse[20] = {
            {Section::TRACER,{70, 0, 9.9, 27, 4.55 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 13, 30, 4.5 ,17 , 0, 'LEFTEDGE'},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 14, 30, 4.5 ,17, 0, 'LEFTEDGE'},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::COLOR,{208,0.07, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Rcourse[20] = {
            {Section::TRACER,{70, 0, 9.9, 27, 4.55 , 0, 0, _EDGE},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 13, 30, 4.6 ,-17 , 0, _EDGE},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 14, 30, 4.6 ,-17 , 0, _EDGE},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::COLOR,{208,0.07, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        #endif
};

#endif
