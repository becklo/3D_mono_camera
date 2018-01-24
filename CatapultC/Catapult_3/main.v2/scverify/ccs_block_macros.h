// ccs_block_macros.h
#include "mc_testbench.h"
extern void mc_testbench_capture_IN( int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200]);
extern void mc_testbench_capture_OUT(int _retvalue, int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200]);
extern void mc_testbench_wait_for_idle_sync();
#ifdef CCS_DESIGN_FUNC_main
#define ccs_intercept_main_14 \
  ccs_real_main(int mask[316][216],double filtre[17][17],int image_net[300][200],int image_floue[300][200],int image_error[316][216],int depth[300][200]);\
  int main(int mask[316][216],double filtre[17][17],int image_net[300][200],int image_floue[300][200],int image_error[316][216],int depth[300][200])\
{\
    static bool ccs_intercept_flag = false;\
    if (!ccs_intercept_flag) {\
      std::cout << "SCVerify intercepting C++ function 'main' for RTL block 'main'" << std::endl;\
      ccs_intercept_flag=true;\
    }\
    mc_testbench_capture_IN(mask,filtre,image_net,image_floue,image_error,depth);\
    int _retvalue = ccs_real_main(mask,filtre,image_net,image_floue,image_error,depth);\
    mc_testbench_capture_OUT(_retvalue,mask,filtre,image_net,image_floue,image_error,depth);\
    return _retvalue;\
}\
  int ccs_real_main
#else
#define ccs_intercept_main_14 main
#endif
#define ccs_intercept_creation_mask_9 creation_mask
#define ccs_intercept_reconstruction_error_5 reconstruction_error
