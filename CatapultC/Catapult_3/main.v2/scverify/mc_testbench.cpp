// ----------------------------------------------------------------------------
// SystemC Testbench Body
//
//    HLS version: 10.0a/269363 Production Release
//       HLS date: Wed Nov  9 17:38:00 PST 2016
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 8.0a
//
//   Generated by: xph3sle509@ocaepc57
// Generated date: Tue Jan 16 14:33:17 CET 2018
//
// ----------------------------------------------------------------------------
// 
// -------------------------------------
// testbench
// User supplied testbench
// -------------------------------------
// 
#include "mc_testbench.h"
#include <mc_testbench_util.h>
#include <mc_simulator_extensions.h>

testbench* testbench::that;
std::vector<mc_end_of_testbench*> testbench::_end_of_tb_objs;
bool testbench::mask_ignore;
bool testbench::mask_skip;
bool testbench::mask_skip_quiet;
bool testbench::mask_skip_once;
bool testbench::mask_skip_noerr;
void mc_testbench_mask_skip(bool v) { testbench::mask_skip = v; }
int testbench::mask_array_comp_first;
int testbench::mask_array_comp_last;
int testbench::mask_wait_cycles;
mc_wait_ctrl testbench::mask_wait_ctrl;
bool testbench::filtre_ignore;
bool testbench::filtre_skip;
bool testbench::filtre_skip_quiet;
bool testbench::filtre_skip_once;
bool testbench::filtre_skip_noerr;
void mc_testbench_filtre_skip(bool v) { testbench::filtre_skip = v; }
int testbench::filtre_array_comp_first;
int testbench::filtre_array_comp_last;
int testbench::filtre_wait_cycles;
mc_wait_ctrl testbench::filtre_wait_ctrl;
bool testbench::image_net_ignore;
bool testbench::image_net_skip;
bool testbench::image_net_skip_quiet;
bool testbench::image_net_skip_once;
bool testbench::image_net_skip_noerr;
void mc_testbench_image_net_skip(bool v) { testbench::image_net_skip = v; }
int testbench::image_net_array_comp_first;
int testbench::image_net_array_comp_last;
int testbench::image_net_wait_cycles;
mc_wait_ctrl testbench::image_net_wait_ctrl;
bool testbench::image_floue_ignore;
bool testbench::image_floue_skip;
bool testbench::image_floue_skip_quiet;
bool testbench::image_floue_skip_once;
bool testbench::image_floue_skip_noerr;
void mc_testbench_image_floue_skip(bool v) { testbench::image_floue_skip = v; }
int testbench::image_floue_array_comp_first;
int testbench::image_floue_array_comp_last;
int testbench::image_floue_wait_cycles;
mc_wait_ctrl testbench::image_floue_wait_ctrl;
bool testbench::image_error_ignore;
bool testbench::image_error_skip;
bool testbench::image_error_skip_quiet;
bool testbench::image_error_skip_once;
bool testbench::image_error_skip_noerr;
void mc_testbench_image_error_skip(bool v) { testbench::image_error_skip = v; }
int testbench::image_error_array_comp_first;
int testbench::image_error_array_comp_last;
int testbench::image_error_IN_wait_cycles;
mc_wait_ctrl testbench::image_error_IN_wait_ctrl;
bool testbench::image_error_use_mask;
int testbench::image_error_output_mask;
int testbench::image_error_wait_cycles;
mc_wait_ctrl testbench::image_error_wait_ctrl;
bool testbench::depth_ignore;
bool testbench::depth_skip;
bool testbench::depth_skip_quiet;
bool testbench::depth_skip_once;
bool testbench::depth_skip_noerr;
void mc_testbench_depth_skip(bool v) { testbench::depth_skip = v; }
int testbench::depth_array_comp_first;
int testbench::depth_array_comp_last;
bool testbench::depth_use_mask;
int testbench::depth_output_mask;
int testbench::depth_wait_cycles;
mc_wait_ctrl testbench::depth_wait_ctrl;
bool testbench::return_ignore;
bool testbench::return_skip;
bool testbench::return_skip_quiet;
bool testbench::return_skip_once;
bool testbench::return_skip_noerr;
void mc_testbench_return_skip(bool v) { testbench::return_skip = v; }
int testbench::return_array_comp_first;
int testbench::return_array_comp_last;
bool testbench::return_use_mask;
int testbench::return_output_mask;
int testbench::return_wait_cycles;
mc_wait_ctrl testbench::return_wait_ctrl;
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
extern "C++" int main( int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200]);
#endif

// ============================================
// Function: wait_for_idle_sync
// --------------------------------------------

void testbench::wait_for_idle_sync()
{
   std::cout << "mc_testbench STOPPING   @ " << sc_time_stamp() << std::endl;
   that->cpp_testbench_active.write(false);
   while (that->design_is_idle.read())  that->wait(that->design_is_idle.value_changed_event());
   while (!that->design_is_idle.read()) that->wait(that->design_is_idle.value_changed_event());
   that->cpp_testbench_active.write(true);
   std::cout << "mc_testbench CONTINUING @ " << sc_time_stamp() << std::endl;
}
// ============================================
// Function: set_enable_stalls
// --------------------------------------------

void testbench::set_enable_stalls(bool flag)
{
   if (flag) {
     std::cout << "Enabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_1);
   } else {
     std::cout << "Disabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_0);
   }
}
// ============================================
// Function: register_end_of_testbench_obj
// --------------------------------------------

void testbench::register_end_of_testbench_obj(mc_end_of_testbench* obj)
{
   _end_of_tb_objs.push_back(obj);
}
// ============================================
// Function: capture_mask
// --------------------------------------------

void testbench::capture_mask( int mask[316][216])
{
   if (mask_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_mask && !mask_ignore)
   {
      int cur_iter = mask_iteration_count;
      ++mask_iteration_count;
      mgc_sysc_ver_array1D<int,68256> mask_tmp;
      int mask_linear_idx = 0;
      for (int mask_idx_0 = 0; mask_idx_0 < 316; ++mask_idx_0)
         for (int mask_idx_1 = 0; mask_idx_1 < 216; ++mask_idx_1)
            mask_tmp[mask_linear_idx++] = mask[mask_idx_0][mask_idx_1];
      ccs_mask->put(mask_tmp);
      ++mask_capture_count;
      mc_testbench::process_wait_ctrl("mask",mask_wait_cycles,mask_wait_ctrl,ccs_wait_ctrl_mask.operator->(),cur_iter,mask_capture_count,0);
   }
   mask_ignore = false;
}
// ============================================
// Function: capture_filtre
// --------------------------------------------

void testbench::capture_filtre( double filtre[17][17])
{
   if (filtre_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_filtre && !filtre_ignore)
   {
      int cur_iter = filtre_iteration_count;
      ++filtre_iteration_count;
      mgc_sysc_ver_array1D<double,289> filtre_tmp;
      int filtre_linear_idx = 0;
      for (int filtre_idx_0 = 0; filtre_idx_0 < 17; ++filtre_idx_0)
         for (int filtre_idx_1 = 0; filtre_idx_1 < 17; ++filtre_idx_1)
            filtre_tmp[filtre_linear_idx++] = filtre[filtre_idx_0][filtre_idx_1];
      ccs_filtre->put(filtre_tmp);
      ++filtre_capture_count;
      mc_testbench::process_wait_ctrl("filtre",filtre_wait_cycles,filtre_wait_ctrl,ccs_wait_ctrl_filtre.operator->(),cur_iter,filtre_capture_count,0);
   }
   filtre_ignore = false;
}
// ============================================
// Function: capture_image_net
// --------------------------------------------

void testbench::capture_image_net( int image_net[300][200])
{
   if (image_net_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_image_net && !image_net_ignore)
   {
      int cur_iter = image_net_iteration_count;
      ++image_net_iteration_count;
      mgc_sysc_ver_array1D<int,60000> image_net_tmp;
      int image_net_linear_idx = 0;
      for (int image_net_idx_0 = 0; image_net_idx_0 < 300; ++image_net_idx_0)
         for (int image_net_idx_1 = 0; image_net_idx_1 < 200; ++image_net_idx_1)
            image_net_tmp[image_net_linear_idx++] = image_net[image_net_idx_0][image_net_idx_1];
      ccs_image_net->put(image_net_tmp);
      ++image_net_capture_count;
      mc_testbench::process_wait_ctrl("image_net",image_net_wait_cycles,image_net_wait_ctrl,ccs_wait_ctrl_image_net.operator->(),cur_iter,image_net_capture_count,0);
   }
   image_net_ignore = false;
}
// ============================================
// Function: capture_image_floue
// --------------------------------------------

void testbench::capture_image_floue( int image_floue[300][200])
{
   if (image_floue_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_image_floue && !image_floue_ignore)
   {
      int cur_iter = image_floue_iteration_count;
      ++image_floue_iteration_count;
      mgc_sysc_ver_array1D<int,60000> image_floue_tmp;
      int image_floue_linear_idx = 0;
      for (int image_floue_idx_0 = 0; image_floue_idx_0 < 300; ++image_floue_idx_0)
         for (int image_floue_idx_1 = 0; image_floue_idx_1 < 200; ++image_floue_idx_1)
            image_floue_tmp[image_floue_linear_idx++] = image_floue[image_floue_idx_0][image_floue_idx_1];
      ccs_image_floue->put(image_floue_tmp);
      ++image_floue_capture_count;
      mc_testbench::process_wait_ctrl("image_floue",image_floue_wait_cycles,image_floue_wait_ctrl,ccs_wait_ctrl_image_floue.operator->(),cur_iter,image_floue_capture_count,0);
   }
   image_floue_ignore = false;
}
// ============================================
// Function: capture_image_error_IN
// --------------------------------------------

void testbench::capture_image_error_IN( int image_error[316][216])
{
   if (image_error_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_image_error_IN && !image_error_ignore)
   {
      int cur_iter = image_error_IN_iteration_count;
      ++image_error_IN_iteration_count;
      mgc_sysc_ver_array1D<int,68256> image_error_IN_tmp;
      int image_error_linear_idx = 0;
      for (int image_error_idx_0 = 0; image_error_idx_0 < 316; ++image_error_idx_0)
         for (int image_error_idx_1 = 0; image_error_idx_1 < 216; ++image_error_idx_1)
            image_error_IN_tmp[image_error_linear_idx++] = image_error[image_error_idx_0][image_error_idx_1];
      ccs_image_error_IN->put(image_error_IN_tmp);
      ++image_error_IN_capture_count;
      mc_testbench::process_wait_ctrl("image_error_IN",image_error_IN_wait_cycles,image_error_IN_wait_ctrl,ccs_wait_ctrl_image_error_IN.operator->(),cur_iter,image_error_IN_capture_count,0);
   }
   image_error_ignore = false;
}
// ============================================
// Function: capture_image_error
// --------------------------------------------

void testbench::capture_image_error( int image_error[316][216])
{
   if (_capture_image_error)
   {
      int cur_iter = image_error_iteration_count;
      ++image_error_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<int,68256>, int > image_error_tmp(image_error_ignore, false, image_error_iteration_count);
      image_error_tmp._data.mc_testbench_process_array_bounds("image_error",image_error_array_comp_first,image_error_array_comp_last,68255,0);
      // BEGIN: testbench output_mask control for field_name image_error
      if ( image_error_use_mask ) {
         image_error_tmp._use_mask = true;
         image_error_tmp._mask = image_error_output_mask ;
      }
      // END: testbench output_mask control for field_name image_error
      int image_error_linear_idx = 0;
      for (int image_error_idx_0 = 0; image_error_idx_0 < 316; ++image_error_idx_0)
         for (int image_error_idx_1 = 0; image_error_idx_1 < 216; ++image_error_idx_1)
            image_error_tmp._data[image_error_linear_idx++] = image_error[image_error_idx_0][image_error_idx_1];
      if (!image_error_skip) {
         image_error_golden.put(image_error_tmp);
         ++image_error_capture_count;
      } else {
         if (!image_error_skip_quiet || !image_error_skip_once) {
            std::ostringstream msg; msg.str("");
            msg << "image_error_skip=true for iteration=" << image_error_iteration_count << " @ " << sc_time_stamp();
            SC_REPORT_WARNING("User testbench", msg.str().c_str());
            image_error_skip_once = true;
         }
      }
      mc_testbench::process_wait_ctrl("image_error",image_error_wait_cycles,image_error_wait_ctrl,ccs_wait_ctrl_image_error.operator->(),cur_iter,image_error_capture_count,0);
      image_error_use_mask = false;
   }
   image_error_ignore = false;
   image_error_skip = false;
}
// ============================================
// Function: capture_depth
// --------------------------------------------

void testbench::capture_depth( int depth[300][200])
{
   if (_capture_depth)
   {
      int cur_iter = depth_iteration_count;
      ++depth_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<int,60000>, int > depth_tmp(depth_ignore, false, depth_iteration_count);
      depth_tmp._data.mc_testbench_process_array_bounds("depth",depth_array_comp_first,depth_array_comp_last,59999,0);
      // BEGIN: testbench output_mask control for field_name depth
      if ( depth_use_mask ) {
         depth_tmp._use_mask = true;
         depth_tmp._mask = depth_output_mask ;
      }
      // END: testbench output_mask control for field_name depth
      int depth_linear_idx = 0;
      for (int depth_idx_0 = 0; depth_idx_0 < 300; ++depth_idx_0)
         for (int depth_idx_1 = 0; depth_idx_1 < 200; ++depth_idx_1)
            depth_tmp._data[depth_linear_idx++] = depth[depth_idx_0][depth_idx_1];
      if (!depth_skip) {
         depth_golden.put(depth_tmp);
         ++depth_capture_count;
      } else {
         if (!depth_skip_quiet || !depth_skip_once) {
            std::ostringstream msg; msg.str("");
            msg << "depth_skip=true for iteration=" << depth_iteration_count << " @ " << sc_time_stamp();
            SC_REPORT_WARNING("User testbench", msg.str().c_str());
            depth_skip_once = true;
         }
      }
      mc_testbench::process_wait_ctrl("depth",depth_wait_cycles,depth_wait_ctrl,ccs_wait_ctrl_depth.operator->(),cur_iter,depth_capture_count,0);
      depth_use_mask = false;
   }
   depth_ignore = false;
   depth_skip = false;
}
// ============================================
// Function: capture__TOP__return
// --------------------------------------------

void testbench::capture__TOP__return(int _TOP__return)
{
   if (_capture_return)
   {
      int cur_iter = return_iteration_count;
      ++return_iteration_count;
      mc_golden_info< int, int > return_tmp(_TOP__return, return_ignore, ~0, false, return_iteration_count);
      // BEGIN: testbench output_mask control for field_name return
      if ( return_use_mask ) {
         return_tmp._use_mask = true;
         return_tmp._mask = return_output_mask ;
      }
      // END: testbench output_mask control for field_name return
      if (!return_skip) {
         return_golden.put(return_tmp);
         ++return_capture_count;
      } else {
         if (!return_skip_quiet || !return_skip_once) {
            std::ostringstream msg; msg.str("");
            msg << "return_skip=true for iteration=" << return_iteration_count << " @ " << sc_time_stamp();
            SC_REPORT_WARNING("User testbench", msg.str().c_str());
            return_skip_once = true;
         }
      }
      mc_testbench::process_wait_ctrl("return",return_wait_cycles,return_wait_ctrl,ccs_wait_ctrl_return.operator->(),cur_iter,return_capture_count,0);
      return_use_mask = false;
   }
   return_ignore = false;
   return_skip = false;
}
// ============================================
// Function: wait_on_input_required
// --------------------------------------------

void testbench::wait_on_input_required()
{
   ++wait_cnt;
   wait(SC_ZERO_TIME); // get fifos a chance to update
   while (atleast_one_active_input) {
      if (_capture_mask && ccs_mask->used() == 0) return;
      if (_capture_filtre && ccs_filtre->used() == 0) return;
      if (_capture_image_net && ccs_image_net->used() == 0) return;
      if (_capture_image_floue && ccs_image_floue->used() == 0) return;
      if (_capture_image_error_IN && ccs_image_error_IN->used() == 0) return;
      that->cpp_testbench_active.write(false);
      wait(ccs_mask->ok_to_put() | ccs_filtre->ok_to_put() | ccs_image_net->ok_to_put() | ccs_image_floue->ok_to_put() | ccs_image_error_IN->ok_to_put());
      that->cpp_testbench_active.write(true);
   }
}
// ============================================
// Function: capture_IN
// --------------------------------------------

void testbench::capture_IN( int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200])
{
   that->capture_mask(mask);
   that->capture_filtre(filtre);
   that->capture_image_net(image_net);
   that->capture_image_floue(image_floue);
   that->capture_image_error_IN(image_error);
}
// ============================================
// Function: capture_OUT
// --------------------------------------------

void testbench::capture_OUT(int _TOP__return,  int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200])
{
   that->capture_image_error(image_error);
   that->capture_depth(depth);
   that->capture__TOP__return(_TOP__return);
}
// ============================================
// Function: exec_main
// --------------------------------------------

int testbench::exec_main( int mask[316][216],  double filtre[17][17],  int image_net[300][200],  int image_floue[300][200],  int image_error[316][216],  int depth[300][200])
{
   #ifndef CCS_SCVERIFY_USE_CCS_BLOCK
   that->cpp_testbench_active.write(true);
   capture_IN(mask, filtre, image_net, image_floue, image_error, depth);
   int _TOP__return = main(mask, filtre, image_net, image_floue, image_error, depth);
   // throttle ac_channel based on number of calls to chan::size() or chan::empty() or chan::nb_read() (but not chan::available()) 
   if (1) {
      int cnt=0;
      if (cnt) std::cout << "mc_testbench.cpp: CONTINUES @ " << sc_time_stamp() << std::endl;
      if (cnt) that->cpp_testbench_active.write(true);
   }
   capture_OUT(_TOP__return, mask, filtre, image_net, image_floue, image_error, depth);
   return _TOP__return;
   #else
   int _TOP__return;
   return _TOP__return;
   #endif
}
// ============================================
// Function: start_of_simulation
// --------------------------------------------

void testbench::start_of_simulation()
{
   set_enable_stalls(false);
}
// ============================================
// Function: end_of_simulation
// --------------------------------------------

void testbench::end_of_simulation()
{
   if (!_checked_results) {
      SC_REPORT_INFO(name(), "Simulation ran into deadlock");
      check_results();
   }
}
// ============================================
// Function: check_results
// --------------------------------------------

void testbench::check_results()
{
   for (std::vector<mc_end_of_testbench*>::iterator i = _end_of_tb_objs.begin(); i != _end_of_tb_objs.end(); ++i)
      (*i)->end_of_testbench();
   
   if (_checked_results) return;
   _checked_results = true;
   cout<<endl;
   cout<<"Checking results"<<endl;
   _failed = false;
   if (main_exit_code) _failed = true;
   int _num_outputs_checked = 0;
   
   if (!_capture_image_error) {
      cout<<"'image_error' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'image_error'"<<endl;
      cout<<"   capture count        = "<<image_error_capture_count<<endl;
      cout<<"   comparison count     = "<<image_error_comp->get_compare_count();
      if (image_error_comp->get_partial_compare_count()) 
         cout <<" ("<<image_error_comp->get_partial_compare_count()<<" partial)";
      if (image_error_comp->get_mask_compare_count()) 
         cout <<" ("<<image_error_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<image_error_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<image_error_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_image_error->used()<<endl;
      cout<<"   stuck in golden fifo = "<<image_error_golden.used()<<endl;
      if (image_error_comp->get_error_count() > 0) cout << "   Error: output 'image_error' had comparison errors"<<endl;
      if (image_error_comp->get_compare_count() < image_error_capture_count) cout << "   Error: output 'image_error' has incomplete comparisons"<<endl;
      if (image_error_skip_noerr) {
         if (image_error_capture_count == 0) cout << "   Warning: output 'image_error' has no golden values to compare against"<<endl;
      } else
         if (image_error_capture_count == 0) cout << "   Error: output 'image_error' has no golden values to compare against"<<endl;
      _failed = _failed || image_error_comp->get_error_count() > 0;
      _failed = _failed || image_error_comp->get_compare_count() < image_error_capture_count;
      if (!image_error_skip_noerr)
         _failed = _failed || image_error_capture_count == 0;
      cout<<endl;
   }
   if (!_capture_depth) {
      cout<<"'depth' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'depth'"<<endl;
      cout<<"   capture count        = "<<depth_capture_count<<endl;
      cout<<"   comparison count     = "<<depth_comp->get_compare_count();
      if (depth_comp->get_partial_compare_count()) 
         cout <<" ("<<depth_comp->get_partial_compare_count()<<" partial)";
      if (depth_comp->get_mask_compare_count()) 
         cout <<" ("<<depth_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<depth_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<depth_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_depth->used()<<endl;
      cout<<"   stuck in golden fifo = "<<depth_golden.used()<<endl;
      if (depth_comp->get_error_count() > 0) cout << "   Error: output 'depth' had comparison errors"<<endl;
      if (depth_comp->get_compare_count() < depth_capture_count) cout << "   Error: output 'depth' has incomplete comparisons"<<endl;
      if (depth_skip_noerr) {
         if (depth_capture_count == 0) cout << "   Warning: output 'depth' has no golden values to compare against"<<endl;
      } else
         if (depth_capture_count == 0) cout << "   Error: output 'depth' has no golden values to compare against"<<endl;
      _failed = _failed || depth_comp->get_error_count() > 0;
      _failed = _failed || depth_comp->get_compare_count() < depth_capture_count;
      if (!depth_skip_noerr)
         _failed = _failed || depth_capture_count == 0;
      cout<<endl;
   }
   if (!_capture_return) {
      cout<<"'return' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'return'"<<endl;
      cout<<"   capture count        = "<<return_capture_count<<endl;
      cout<<"   comparison count     = "<<return_comp->get_compare_count();
      if (return_comp->get_partial_compare_count()) 
         cout <<" ("<<return_comp->get_partial_compare_count()<<" partial)";
      if (return_comp->get_mask_compare_count()) 
         cout <<" ("<<return_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<return_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<return_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_return->used()<<endl;
      cout<<"   stuck in golden fifo = "<<return_golden.used()<<endl;
      if (return_comp->get_error_count() > 0) cout << "   Error: output 'return' had comparison errors"<<endl;
      if (return_comp->get_compare_count() < return_capture_count) cout << "   Error: output 'return' has incomplete comparisons"<<endl;
      if (return_skip_noerr) {
         if (return_capture_count == 0) cout << "   Warning: output 'return' has no golden values to compare against"<<endl;
      } else
         if (return_capture_count == 0) cout << "   Error: output 'return' has no golden values to compare against"<<endl;
      _failed = _failed || return_comp->get_error_count() > 0;
      _failed = _failed || return_comp->get_compare_count() < return_capture_count;
      if (!return_skip_noerr)
         _failed = _failed || return_capture_count == 0;
      cout<<endl;
   }
   cout<<endl;
   if (_num_outputs_checked == 0) {
      cout<<"Error: All outputs were optimized away. No output values were compared."<<endl;
      _failed = _failed || (_num_outputs_checked == 0);
   }
   if (main_exit_code) cout << "Error: C++ Testbench 'main()' returned a non-zero exit code ("<<main_exit_code<<"). Check your testbench." <<endl;
   cout<<(_failed ? "Error: ":"Info: ")<<"Simulation "<<(_failed ? "FAILED":"PASSED")<<" @ "<<sc_time_stamp()<<endl;
}
// ============================================
// Function: failed
// --------------------------------------------

bool testbench::failed()
{
   return _failed;
}
// ---------------------------------------------------------------
// Process: SC_METHOD wait_for_end
// Static sensitivity: sensitive << clk.pos() << testbench_end_event;

void testbench::wait_for_end() {
   // If run() has not finished, we do nothing here
   if (!testbench_ended) return;
   // check for completed outputs
   if (image_error_comp->get_compare_count() < image_error_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (depth_comp->get_compare_count() < depth_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (return_comp->get_compare_count() < return_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   // If we made it here, all outputs have flushed. Check the results
   SC_REPORT_INFO(name(), "Simulation completed");
   check_results();
   sc_stop();
}
// ---------------------------------------------------------------
// Process: SC_THREAD run
// Static sensitivity: 

void testbench::run() {
   mask_ignore = false;
   mask_skip = false;
   mask_skip_quiet = false;
   mask_skip_once = false;
   mask_skip_noerr = false;
   mask_array_comp_first = -1;
   mask_array_comp_last = -1;
   mask_wait_cycles = 0;
   mask_wait_ctrl.clear();
   mask_capture_count = 0;
   mask_iteration_count = 0;
   filtre_ignore = false;
   filtre_skip = false;
   filtre_skip_quiet = false;
   filtre_skip_once = false;
   filtre_skip_noerr = false;
   filtre_array_comp_first = -1;
   filtre_array_comp_last = -1;
   filtre_wait_cycles = 0;
   filtre_wait_ctrl.clear();
   filtre_capture_count = 0;
   filtre_iteration_count = 0;
   image_net_ignore = false;
   image_net_skip = false;
   image_net_skip_quiet = false;
   image_net_skip_once = false;
   image_net_skip_noerr = false;
   image_net_array_comp_first = -1;
   image_net_array_comp_last = -1;
   image_net_wait_cycles = 0;
   image_net_wait_ctrl.clear();
   image_net_capture_count = 0;
   image_net_iteration_count = 0;
   image_floue_ignore = false;
   image_floue_skip = false;
   image_floue_skip_quiet = false;
   image_floue_skip_once = false;
   image_floue_skip_noerr = false;
   image_floue_array_comp_first = -1;
   image_floue_array_comp_last = -1;
   image_floue_wait_cycles = 0;
   image_floue_wait_ctrl.clear();
   image_floue_capture_count = 0;
   image_floue_iteration_count = 0;
   image_error_ignore = false;
   image_error_skip = false;
   image_error_skip_quiet = false;
   image_error_skip_once = false;
   image_error_skip_noerr = false;
   image_error_array_comp_first = -1;
   image_error_array_comp_last = -1;
   image_error_IN_wait_cycles = 0;
   image_error_IN_wait_ctrl.clear();
   image_error_IN_capture_count = 0;
   image_error_IN_iteration_count = 0;
   image_error_use_mask = false;
   image_error_output_mask = ~0;
   image_error_wait_cycles = 0;
   image_error_wait_ctrl.clear();
   image_error_capture_count = 0;
   image_error_iteration_count = 0;
   depth_ignore = false;
   depth_skip = false;
   depth_skip_quiet = false;
   depth_skip_once = false;
   depth_skip_noerr = false;
   depth_array_comp_first = -1;
   depth_array_comp_last = -1;
   depth_use_mask = false;
   depth_output_mask = ~0;
   depth_wait_cycles = 0;
   depth_wait_ctrl.clear();
   depth_capture_count = 0;
   depth_iteration_count = 0;
   return_ignore = false;
   return_skip = false;
   return_skip_quiet = false;
   return_skip_once = false;
   return_skip_noerr = false;
   return_array_comp_first = -1;
   return_array_comp_last = -1;
   return_use_mask = false;
   return_output_mask = ~0;
   return_wait_cycles = 0;
   return_wait_ctrl.clear();
   return_capture_count = 0;
   return_iteration_count = 0;
   main_exit_code = main();
   cout<<"Info: Execution of user-supplied C++ testbench 'main()' has completed with exit code = " << main_exit_code << endl;
   cout<<endl;
   cout<<"Info: Collecting data completed"<<endl;
   cout<<"   captured "<<mask_capture_count<<" values of mask"<<endl;
   cout<<"   captured "<<filtre_capture_count<<" values of filtre"<<endl;
   cout<<"   captured "<<image_net_capture_count<<" values of image_net"<<endl;
   cout<<"   captured "<<image_floue_capture_count<<" values of image_floue"<<endl;
   cout<<"   captured "<<image_error_IN_capture_count<<" values of image_error_IN"<<endl;
   cout<<"   captured "<<image_error_capture_count<<" values of image_error"<<endl;
   cout<<"   captured "<<depth_capture_count<<" values of depth"<<endl;
   cout<<"   captured "<<return_capture_count<<" values of return"<<endl;
   testbench_ended = true;
   testbench_end_event.notify(SC_ZERO_TIME);
}
#ifdef CCS_SCVERIFY_USE_CCS_BLOCK
#include "ccs_block_macros.cpp"
#endif