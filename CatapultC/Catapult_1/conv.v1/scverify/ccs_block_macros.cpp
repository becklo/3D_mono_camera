void mc_testbench_capture_IN( int image_in[320][209],  int image_out[320][209]) { testbench::capture_IN(image_in,image_out); }
void mc_testbench_capture_OUT( int image_in[320][209],  int image_out[320][209]) { testbench::capture_OUT(image_in,image_out); }
void mc_testbench_wait_for_idle_sync() {testbench::wait_for_idle_sync(); }
