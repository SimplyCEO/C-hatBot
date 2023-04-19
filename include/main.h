#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

#define true 1;
#define false 0;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef unsigned char u8;
typedef unsigned char bool;
typedef unsigned short u16;
typedef unsigned int u32;

struct TwitchHeaders
{
  char client[255], bearer[255], oauth[255];
};

#endif
