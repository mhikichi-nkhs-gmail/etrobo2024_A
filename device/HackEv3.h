#ifndef __HACKEV3_H__
#define __HACKEV3_H__

#define SP 1//speedcourse
#define PATARN 3//snap

#if defined(MAKE_SIM)
const double D_RIGHT=9.00;
const double D_LEFT=9.0;
const double TREAD=14.3;
#else
const double D_RIGHT=5.5;
const double D_LEFT=5.5;
const double TREAD=12.5;
#endif

#endif
