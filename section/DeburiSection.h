#ifndef _DEBRI_SECTION_H_
#define _DEBRI_SECTION_H_
#include "SectionManager.h"
#include "HackEv3.h"

class DeburiSection : public SectionManager
{
    public:

        DeburiSection();
        bool run();
        int i = 0;
        int g = 0;
        int kamera = 1;

    protected:

#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
    const int _OPPOSITION_EDGE = LineTracer::RIGHTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
    const int _OPPOSITION_EDGE = LineTracer::LEFTEDGE;
#endif
    private:
        //回転数
        double tw = 60;
        //pid
        double tp = 10;
        double ti = 20;
        double td = 2.5;
        int votol = 0;
        COLOR

        SecParam rain[2] = {
            {Section::TRACER,{40, -0.1, 15, 28.5, 6.5 ,0 , 0, _EDGE},Section::COLOR,{210,0.07, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam exclusion[3] ={
            {Section::TWALKER,{-tw,tp,ti,td},Section::TURNANGLE,{180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw,tp,ti,td},Section::TURNANGLE,{-180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam avoidance[1] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam move[1] = {

           
        SecParam fast_dans[5] = {
            {Section::TWALKER,{-tw,tp,ti,td},Section::TURNANGLE,{90, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw,tp,ti,td},Section::TURNANGLE,{-90, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
            

}
