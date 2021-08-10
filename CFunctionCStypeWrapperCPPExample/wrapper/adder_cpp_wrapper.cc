#include "adder_cpp_wrapper.h"

//***********************************************************
//**** C Wrappers for methods called from Simulink model ****
//***********************************************************

int increment_ = 2;
void *createAdder()
{
    return new adder(increment_);
}

void deleteAdder(void *obj)
{
    delete (adder *) obj;
}

int adderOutput(void *obj, int increment)
{
    increment_ = increment;
    ((adder *)obj)->update();
    return ((adder *)obj)->get_val();
//    return increment_;
}
