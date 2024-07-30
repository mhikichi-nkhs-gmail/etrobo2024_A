#include "FileWalker.h"

extern Process *gProcess;

FileWalker::FileWalker(Odometry *odo):
    Walker(odo)
{

}

void FileWalker::execStart()
{
    //printf("GO\n");
    //int check = mPro->writing();
    //printf("check%f,,\n", check);
}

void FileWalker::init()
{
    
    printf("a\n");
    switch(mNo){
        case SNAP:
            printf("snap\n");
            mPro->writing1(mComment);
            break;
        case BLOCK:
            printf("block\n");
            mPro->writing2(mComment);
            break;
        case IOT:
            printf("iot\n");
            mPro->writing3(mComment);
            break;
        default:
            break;
    }
    //mPro->writing();
    
}

void FileWalker::setParam(double flwk[]) //??��?��g??��?��??��?��??��?��??��?��??��?��??��?��??��?��p??��?��C??��?��v??��?��A??��?��??��?��??��?��e
{
    //三つの中から選ぶ
    mNo = flwk[0];
    //どの処理を行うか
    mComment = flwk[1];
}