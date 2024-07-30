#include "Section.h"
#include "SmartSection.h"

SmartSection::SmartSection()
{

}

bool SmartSection::run()
{
    printf("スマートきゃりーぱみゅぱみゅ\n");
    switch(NO)
    {
    case SET_VIR_LINE:
        printf("VIRぱみゅ\n");
        set(VIR);
        NO = END;
        break;
    case END:
        printf("END\n");
        return true;
    }
    return false;
}

void SmartSection::course(int direct)
{
    if(direct == 0)
    {
        printf("smartleft\n");
        NO = SET_VIR_LINE;
        num1 = 0;
    }
    else
    {
        printf("smartright\n");
        NO = SET_VIR_LINE;
        num1 = 4;
    }
}

