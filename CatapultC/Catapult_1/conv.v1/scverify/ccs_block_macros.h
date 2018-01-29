// ccs_block_macros.h
#include "mc_testbench.h"
extern void mc_testbench_capture_IN( int image_in[320][209],  int image_out[320][209]);
extern void mc_testbench_capture_OUT( int image_in[320][209],  int image_out[320][209]);
extern void mc_testbench_wait_for_idle_sync();
#ifdef CCS_DESIGN_FUNC_conv
#define ccs_intercept_conv_7 \
  ccs_real_conv(int image_in[320][209],int image_out[320][209]);\
  void conv(int image_in[320][209],int image_out[320][209])\
{\
    static bool ccs_intercept_flag = false;\
    if (!ccs_intercept_flag) {\
      std::cout << "SCVerify intercepting C++ function 'conv' for RTL block 'conv'" << std::endl;\
      ccs_intercept_flag=true;\
    }\
    mc_testbench_capture_IN(image_in,image_out);\
    ccs_real_conv(image_in,image_out);\
    mc_testbench_capture_OUT(image_in,image_out);\
}\
  void ccs_real_conv
#else
#define ccs_intercept_conv_7 conv
#endif
