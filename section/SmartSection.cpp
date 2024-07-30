#include "Section.h"
#include "SmartSection.h"

SmartSection::SmartSection()
{

}

bool SmartSection::run()
{
    
}

void DoubleSection::course(int direct)
{
    if(direct == 0)
    {
        NO = SET_LBLUE_MARKER;
        num1 = 0;
    }
    else
    {
        NO = SET_RBLUE_MARKER;
        num1 = 4;
    }
}