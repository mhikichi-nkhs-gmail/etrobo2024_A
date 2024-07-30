#include "Section.h"
#include "SmartSection.h"

SmartSection::SmartSection()
{

}

bool SmartSection::run()
{
    print("スマートきゃりーぱみゅぱみゅ")
    switch(NO)
    {
    case SET_VIR_LINE:
        set(VIR);
        NO = END;
        break;
    case END:
        printf("END\n");
        return true;
    }
    return false;
}

void DoubleSection::course(int direct)
{
    if(direct == 0)
    {
        NO = SET_VIR_LINE;
        num1 = 0;
    }
    else
    {
        NO = SET_VIR_LINE;
        num1 = 4;
    }
}

