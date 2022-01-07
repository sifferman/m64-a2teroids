
#include "controllers.h"

uint8_t
    CONTROLLER_1_PREV,  CONTROLLER_2_PREV,
    CONTROLLER_1_PEDGE, CONTROLLER_2_PEDGE,
    CONTROLLER_1_NEDGE, CONTROLLER_2_NEDGE;

void controllers_reset(void) {
    CONTROLLER_1_PREV = 0;
    CONTROLLER_2_PREV = 0;
}

void controllers_update(void) {
    CONTROLLER_1_PEDGE = (~CONTROLLER_1_PREV) & (CONTROLLER_1);
    CONTROLLER_2_PEDGE = (~CONTROLLER_2_PREV) & (CONTROLLER_2);
    CONTROLLER_1_NEDGE = (CONTROLLER_1_PREV)  & (~CONTROLLER_1);
    CONTROLLER_2_NEDGE = (CONTROLLER_2_PREV)  & (~CONTROLLER_2);
    CONTROLLER_1_PREV = CONTROLLER_1;
    CONTROLLER_2_PREV = CONTROLLER_2;
}