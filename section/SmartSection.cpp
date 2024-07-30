#include "Section.h"
#include "SmartSection.h"

SmartSection::SmartSection()
{

}

bool SmartSection::run()
{
    printf("スマートきゃりー\n");
    switch(NO)
    {
    case SET_VIR_LINE:
        printf("VIRキャリー\n");
        set(VIR);
        NO = END;
        break;
    case END:
        printf("ENDキャリー\n");
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

