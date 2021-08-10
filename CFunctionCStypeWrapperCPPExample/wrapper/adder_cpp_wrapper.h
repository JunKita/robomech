#include "adder_cpp.h"

// C Wrappers for methods called from Simulink model
extern void *createAdder();
extern void deleteAdder(void *obj);
extern int adderOutput(void *obj, int increment);

