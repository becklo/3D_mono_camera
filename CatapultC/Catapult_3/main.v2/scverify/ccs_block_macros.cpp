void mc_testbench_capture_IN( int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200]) { testbench::capture_IN(mask,filtre,image_net,image_floue,image_error,depth); }
void mc_testbench_capture_OUT(int _retvalue, int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200]) { testbench::capture_OUT(_retvalue,mask,filtre,image_net,image_floue,image_error,depth); }
void mc_testbench_wait_for_idle_sync() {testbench::wait_for_idle_sync(); }
