// ----------------------------------------------------------------------------
// SystemC Testbench Header
//
//    HLS version: 10.0a/269363 Production Release
//       HLS date: Wed Nov  9 17:38:00 PST 2016
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 8.0a
//
//   Generated by: xph3sle509@ocaepc57
// Generated date: Mon Jan 29 11:55:57 CET 2018
//
// ----------------------------------------------------------------------------
#ifdef CCS_SCVERIFY

// 
// -------------------------------------
// testbench
// User supplied testbench
// -------------------------------------
// 
#ifndef INCLUDED_TESTBENCH_H
#define INCLUDED_TESTBENCH_H

extern void mc_testbench_image_in_skip(bool v);
extern void mc_testbench_image_out_skip(bool v);

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include "../../var.h"
#include <systemc.h>
#include <tlm.h>
#include <mc_container_types.h>
#include <mc_typeconv.h>
#include <mc_transactors.h>
#include <mc_comparator.h>
#include <mc_end_of_testbench.h>
#include <vector>


class testbench : public sc_module
{
public:
   // Interface Ports
   sc_in< bool > clk;
   sc_port< tlm::tlm_fifo_put_if< mgc_sysc_ver_array1D<int,66880> > > ccs_image_in;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_image_in;
   sc_port< tlm::tlm_fifo_get_if< mgc_sysc_ver_array1D<int,66880> > > ccs_image_out;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_image_out;
   sc_in< bool > design_is_idle;
   sc_out< sc_logic > enable_stalls;
   sc_in< unsigned short > stall_coverage;
   
   // Data objects
   bool testbench_ended;
   int main_exit_code;
   bool atleast_one_active_input;
   sc_time last_event_time;
   sc_time last_event_time2;
   sc_signal< bool >                          cpp_testbench_active;
   sc_event testbench_end_event;
   int argc;
   const char* const *argv;
   bool _checked_results;
   bool _failed;
   static testbench* that;
   static std::vector<mc_end_of_testbench*> _end_of_tb_objs;
   int main();
   static bool image_in_ignore;
   static bool image_in_skip;
   static bool image_in_skip_quiet;
   static bool image_in_skip_once;
   static bool image_in_skip_noerr;
   static int image_in_array_comp_first;
   static int image_in_array_comp_last;
   bool _capture_image_in;
   static int image_in_wait_cycles;
   static mc_wait_ctrl image_in_wait_ctrl;
   int image_in_capture_count;
   int image_in_iteration_count;
   static bool image_out_ignore;
   static bool image_out_skip;
   static bool image_out_skip_quiet;
   static bool image_out_skip_once;
   static bool image_out_skip_noerr;
   static int image_out_array_comp_first;
   static int image_out_array_comp_last;
   static bool image_out_use_mask;
   static int image_out_output_mask;
   tlm::tlm_fifo< mc_golden_info< mgc_sysc_ver_array1D<int,66880>, int > > image_out_golden;
   bool _capture_image_out;
   static int image_out_wait_cycles;
   static mc_wait_ctrl image_out_wait_ctrl;
   int image_out_capture_count;
   int image_out_iteration_count;
   int wait_cnt;
   
   // Named Objects
   
   // Module instance pointers
   mc_comparator< mgc_sysc_ver_array1D<int,66880> , int > *image_out_comp;
   
   // Declare processes (SC_METHOD and SC_THREAD)
   void wait_for_end();
   void run();
   
   // Constructor
   SC_HAS_PROCESS(testbench);
   testbench(
      const sc_module_name& name
   )
      : clk("clk")
      , ccs_image_in("ccs_image_in")
      , ccs_wait_ctrl_image_in("ccs_wait_ctrl_image_in")
      , ccs_image_out("ccs_image_out")
      , ccs_wait_ctrl_image_out("ccs_wait_ctrl_image_out")
      , design_is_idle("design_is_idle")
      , enable_stalls("enable_stalls")
      , stall_coverage("stall_coverage")
      , cpp_testbench_active("cpp_testbench_active")
      , image_out_golden("image_out_golden",-1)
   {
      // Instantiate other modules
      image_out_comp = new mc_comparator< mgc_sysc_ver_array1D<int,66880> , int > (
         "image_out_comp",
         0,
         1
      );
      image_out_comp->data_in(ccs_image_out);
      image_out_comp->data_golden(image_out_golden);
      
      
      // Register processes
      SC_METHOD(wait_for_end);
      sensitive << clk.pos() << testbench_end_event;
      SC_THREAD(run);
      // Other constructor statements
      set_stack_size(64000000);
      argc = sc_argc();
      argv = sc_argv();
      _checked_results = false;
      that = this;
      testbench_ended = false;
      main_exit_code = 0;
      atleast_one_active_input = true;
      _capture_image_in = true;
      _capture_image_out = true;
      wait_cnt = 0;
   }
   
   ~testbench()
   {
      delete image_out_comp;
      image_out_comp = 0;
   }
   
   // C++ class functions
   public:
      static void wait_for_idle_sync() ;
   public:
      static void set_enable_stalls(bool flag) ;
   public:
      static void register_end_of_testbench_obj(mc_end_of_testbench* obj) ;
   public:
      void capture_image_in( int image_in[320][209]) ;
   public:
      void capture_image_out( int image_out[320][209]) ;
   protected:
      void wait_on_input_required() ;
   public:
      static void capture_IN( int image_in[320][209],  int image_out[320][209]) ;
   public:
      static void capture_OUT( int image_in[320][209],  int image_out[320][209]) ;
   public:
      static void exec_conv( int image_in[320][209],  int image_out[320][209]) ;
   protected:
      void start_of_simulation() ;
   protected:
      void end_of_simulation() ;
   public:
      void check_results() ;
   public:
      bool failed() ;
};
#endif
#endif