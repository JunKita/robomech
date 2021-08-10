/* Copyright 2006 The MathWorks, Inc. */

#ifndef _ADDER_CPP_
#define _ADDER_CPP_

class adder {
public:
    adder(int &increment);
    int update();
    int get_val();
private:
    int int_state;
    int increment_;
};

#endif /* _ADDER_CPP_ */
