/* bb.h -- declare global variables used for the bounded buffer */
#include <bb_prototypes.h>

#define BB_UNINIT 0
#define BB_INIT 1
#define BB_RUN 2
#define BB_OUTONLY 3

struct bbStruct {
    byte bbList[BB_SIZE];
    uint32 bbListHead;
    uint32 bbListTail;
    sid32 bbPsem;
    sid32 bbCsem;
    int32 bbState;
    int32 bbCount;
};

extern struct bbStruct bb;
