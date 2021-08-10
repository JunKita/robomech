/* Copyright 2006 The MathWorks, Inc. */

#include "adder_cpp.h"

/**********************************/
/**** Class method definitions ****/
/**********************************/

adder::adder(int &increment) : increment_(increment)
{
    int_state = 0;
}

int adder::update()
{
    int_state += increment_;
    return int_state;
}

int adder::get_val()
{
    return int_state;
}
