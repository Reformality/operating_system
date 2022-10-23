/* bb.h -- declare global variables used for the bounded buffer */
#include <bb_prototypes.h>

#define BB_UNINIT 0
#define BB_INIT

struct bbStruct {
    byte bbList[BB_SIZE];
    int32 bbListHead;
    int32 bbListTail;
    sid32 bbPsem;
    sid32 bbCsem;
    int32 bbState;
};

extern struct bbStruct bb;
