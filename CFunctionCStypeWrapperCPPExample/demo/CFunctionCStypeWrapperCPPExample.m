%% Call C++ Class Methods Using a C-style Wrapper Function From a C Function Block
% This example shows how to use the C Function block to call C++ class
% methods using a C-style wrapper function. In this example, the C-style
% wrapper functions are defined in |adder_cpp.h|, and implemented in
% |adder_cpp.cpp|. To run this example model successfully, you must
% configure MATLAB(R) to use a C++ compiler.
%
% This can be done using the |mex -setup| command, and selecting a C++
% compiler.
%
% To enable calling of the C functions from the C Function block, in the
% model, specify the header file and the source file in the *Configuration
% Parameters* > *Simulation Target* pane. In this model the custom code
% header file |adder_cpp.h| declares an |adder| class along with the class
% member functions. The header file also contains the declaration of the
% C-style wrapper functions which are called in the C Function block. The
% prototypes of the C-style wrapper functions are:
%
% * |void *createAdder()|
% * |void deleteAdder(void *obj)|
% * |int adderOutput(void *obj, int increment)|
%
% where, |void *obj| is the class object pointer, and |int increment| is an
% input used by the adder function.
%
% The |createAdder| function is called in the *Start Code* section of the
% Block Parameters to construct an object of the |Adder| class. The
% |deleteAdder| function is called in the *Terminate Code* section to
% destruct the created Adder class object. In the *Output Code* section,
% the |adderOutput| function is called. In this example the ports of the C
% Function block are configured as follows:
%
% * The Adder class object, |obj|, return by the |createAdder| function is
% a persistent symbol of the C Function block.
% * The input of the C Function block is mapped to |increment|.
% * The output of the C Function block is mapped to the return value of the
% |adderOutput| function.
%

% Copyright 2019 The MathWorks, Inc.
%%
model = 'slexCFunctionAdder';
open_system(model);
sim(model);
slcc('clearCustomCodeModules');


