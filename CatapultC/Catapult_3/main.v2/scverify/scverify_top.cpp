#include <string>
#include <fstream>
#include <iostream>
#include "mc_testbench.h"
#include <mc_reset.h>
#include <mc_transactors.h>
#include <mc_scverify.h>
#include <mc_stall_ctrl.h>
#include "mgc_ioport_trans_rsc_v1.h"
#include "ram_fpga_singleport_RF_trans_rsc.h"
#include <mc_monitor.h>
#include <mc_simulator_extensions.h>
#include "mc_dut_wrapper.h"
#include "ccs_probes.cpp"
#include <mt19937ar.c>
#ifndef TO_QUOTED_STRING
#define TO_QUOTED_STRING(x) TO_QUOTED_STRING1(x)
#define TO_QUOTED_STRING1(x) #x
#endif
#ifndef TOP_HDL_ENTITY
#define TOP_HDL_ENTITY main
#endif
// Hold time for the SCVerify testbench to account for the gate delay after downstream synthesis in pico second(s)
// Hold time value is obtained from 'top_gate_constraints.cpp', which is generated at the end of RTL synthesis
#ifdef CCS_DUT_GATE
extern double __scv_hold_time;
extern double __scv_hold_time_RSCID_1;
extern double __scv_hold_time_RSCID_2;
extern double __scv_hold_time_RSCID_3;
extern double __scv_hold_time_RSCID_4;
extern double __scv_hold_time_RSCID_5;
extern double __scv_hold_time_RSCID_6;
extern double __scv_hold_time_RSCID_7;
#else
double __scv_hold_time = 0.0; // default for non-gate simulation is zero
double __scv_hold_time_RSCID_1 = 0;
double __scv_hold_time_RSCID_2 = 0;
double __scv_hold_time_RSCID_3 = 0;
double __scv_hold_time_RSCID_4 = 0;
double __scv_hold_time_RSCID_5 = 0;
double __scv_hold_time_RSCID_6 = 0;
double __scv_hold_time_RSCID_7 = 0;
#endif

class scverify_top : public sc_module
{
public:
  sc_signal<sc_logic>                                                 rst;
  sc_signal<sc_logic>                                                 rst_n;
  sc_signal<sc_logic>                                                 SIG_SC_LOGIC_0;
  sc_signal<sc_logic>                                                 SIG_SC_LOGIC_1;
  sc_signal<sc_logic>                                                 TLS_design_is_idle;
  sc_signal<bool>                                                     TLS_design_is_idle_reg;
  sc_clock                                                            clk;
  mc_programmable_reset                                               rst_driver;
  sc_signal<sc_logic>                                                 TLS_rst;
  sc_signal<sc_lv<16> >                                               TLS_image_net_rsc_addr;
  sc_signal<sc_logic>                                                 TLS_image_net_rsc_re;
  sc_signal<sc_lv<32> >                                               TLS_image_net_rsc_data_out;
  sc_signal<sc_logic>                                                 TLS_image_net_rsc_triosy_lz;
  sc_signal<sc_lv<16> >                                               TLS_image_floue_rsc_addr;
  sc_signal<sc_logic>                                                 TLS_image_floue_rsc_re;
  sc_signal<sc_lv<32> >                                               TLS_image_floue_rsc_data_out;
  sc_signal<sc_logic>                                                 TLS_image_floue_rsc_triosy_lz;
  sc_signal<sc_lv<32> >                                               TLS_image_error_rsc_data_in;
  sc_signal<sc_lv<17> >                                               TLS_image_error_rsc_addr;
  sc_signal<sc_logic>                                                 TLS_image_error_rsc_re;
  sc_signal<sc_logic>                                                 TLS_image_error_rsc_we;
  sc_signal<sc_lv<32> >                                               TLS_image_error_rsc_data_out;
  sc_signal<sc_logic>                                                 TLS_image_error_rsc_triosy_lz;
  sc_signal<sc_lv<32> >                                               TLS_depth_rsc_data_in;
  sc_signal<sc_lv<16> >                                               TLS_depth_rsc_addr;
  sc_signal<sc_logic>                                                 TLS_depth_rsc_we;
  sc_signal<sc_logic>                                                 TLS_depth_rsc_triosy_lz;
  sc_signal<sc_lv<32> >                                               TLS_return_rsc_z;
  sc_signal<sc_logic>                                                 TLS_return_rsc_triosy_lz;
  ccs_DUT_wrapper                                                     main_INST;
  sc_signal<sc_lv<1> >                                                CCS_ADAPTOR_image_net_rsc_re;
  ccs_sc_logic_to_sc_lv1_adapter                                      CCS_ADAPTOR_CCS_ADAPTOR_image_net_rsc_re;
  sc_signal<sc_lv<32> >                                               TLS_image_net_rsc_data_in;
  sc_signal<sc_lv<1> >                                                TLS_image_net_rsc_we;
  ram_fpga_singleport_RF_trans_rsc<3,60000,32,16,0,1,0,0,0,1,1,1,0 >  image_net_rsc_INST;
  sc_signal<sc_lv<1> >                                                CCS_ADAPTOR_image_floue_rsc_re;
  ccs_sc_logic_to_sc_lv1_adapter                                      CCS_ADAPTOR_CCS_ADAPTOR_image_floue_rsc_re;
  sc_signal<sc_lv<32> >                                               TLS_image_floue_rsc_data_in;
  sc_signal<sc_lv<1> >                                                TLS_image_floue_rsc_we;
  ram_fpga_singleport_RF_trans_rsc<4,60000,32,16,0,1,0,0,0,1,1,1,0 >  image_floue_rsc_INST;
  sc_signal<sc_lv<1> >                                                CCS_ADAPTOR_image_error_rsc_we;
  ccs_sc_logic_to_sc_lv1_adapter                                      CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_we;
  sc_signal<sc_lv<1> >                                                CCS_ADAPTOR_image_error_rsc_re;
  ccs_sc_logic_to_sc_lv1_adapter                                      CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_re;
  ram_fpga_singleport_RF_trans_rsc<5,68256,32,17,0,1,0,0,0,1,1,1,0 >  image_error_rsc_INST;
  sc_signal<sc_lv<1> >                                                CCS_ADAPTOR_depth_rsc_we;
  ccs_sc_logic_to_sc_lv1_adapter                                      CCS_ADAPTOR_CCS_ADAPTOR_depth_rsc_we;
  sc_signal<sc_lv<1> >                                                TLS_depth_rsc_re;
  sc_signal<sc_lv<32> >                                               TLS_depth_rsc_data_out;
  ram_fpga_singleport_RF_trans_rsc<6,60000,32,16,0,1,0,0,0,1,1,1,0 >  depth_rsc_INST;
  mgc_out_stdreg_trans_rsc_v1<1,32 >                                  return_rsc_INST;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,68256> >                     TLS_in_fifo_mask;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_in_wait_ctrl_fifo_mask;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<double,289> >                    TLS_in_fifo_filtre;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_in_wait_ctrl_fifo_filtre;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,60000> >                     TLS_in_fifo_image_net;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_in_wait_ctrl_fifo_image_net;
  mc_trios_input_monitor                                              trios_monitor_image_net_rsc_triosy_lz_INST;
  mc_input_transactor<mgc_sysc_ver_array1D<int,60000>,32,true>        transactor_image_net;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,60000> >                     TLS_in_fifo_image_floue;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_in_wait_ctrl_fifo_image_floue;
  mc_trios_input_monitor                                              trios_monitor_image_floue_rsc_triosy_lz_INST;
  mc_input_transactor<mgc_sysc_ver_array1D<int,60000>,32,true>        transactor_image_floue;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,68256> >                     TLS_in_fifo_image_error;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_in_wait_ctrl_fifo_image_error;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,68256> >                     TLS_out_fifo_image_error;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_out_wait_ctrl_fifo_image_error;
  mc_trios_inout_monitor                                              trios_monitor_image_error_rsc_triosy_lz_INST;
  mc_inout_transactor<mgc_sysc_ver_array1D<int,68256>,32,true>        transactor_image_error;
  tlm::tlm_fifo<mgc_sysc_ver_array1D<int,60000> >                     TLS_out_fifo_depth;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_out_wait_ctrl_fifo_depth;
  mc_trios_output_monitor                                             trios_monitor_depth_rsc_triosy_lz_INST;
  mc_output_transactor<mgc_sysc_ver_array1D<int,60000>,32,true>       transactor_depth;
  tlm::tlm_fifo<int >                                                 TLS_out_fifo_return;
  tlm::tlm_fifo<mc_wait_ctrl>                                         TLS_out_wait_ctrl_fifo_return;
  mc_trios_output_monitor                                             trios_monitor_return_rsc_triosy_lz_INST;
  mc_output_transactor<int,32,true>                                   transactor_return;
  testbench                                                           testbench_INST;
  sc_signal<sc_logic>                                                 catapult_start;
  sc_signal<sc_logic>                                                 catapult_done;
  sc_signal<sc_logic>                                                 catapult_ready;
  sc_signal<sc_logic>                                                 in_sync;
  sc_signal<sc_logic>                                                 out_sync;
  sc_signal<sc_logic>                                                 inout_sync;
  sc_signal<unsigned>                                                 wait_for_init;
  sync_generator                                                      sync_generator_INST;
  catapult_monitor                                                    catapult_monitor_INST;
  ccs_probe_monitor                                                  *ccs_probe_monitor_INST;
  sc_event                                                            reset_deactivation_event;
  sc_event                                                            deadlock_event;
  sc_signal<sc_logic>                                                 deadlocked;
  sc_signal<sc_logic>                                                 TLS_enable_stalls;
  sc_signal<unsigned short>                                           TLS_stall_coverage;

  void start_of_simulation();
  void setup_debug();
  void debug(const char* varname, int flags, int count);
  void generate_reset();
  void install_observe_foreign_signals();
  void deadlock_watch();
  void deadlock_notify();

  // Constructor
  SC_HAS_PROCESS(scverify_top);
  scverify_top(const sc_module_name& name)
    : rst("rst")
    , rst_n("rst_n")
    , SIG_SC_LOGIC_0("SIG_SC_LOGIC_0")
    , SIG_SC_LOGIC_1("SIG_SC_LOGIC_1")
    , TLS_design_is_idle("TLS_design_is_idle")
    , TLS_design_is_idle_reg("TLS_design_is_idle_reg")
    , CCS_CLK_CTOR(clk, "clk", 50, SC_NS, 0.5, 0, SC_NS, false)
    , rst_driver("rst_driver", 100.000000, false)
    , TLS_rst("TLS_rst")
    , TLS_image_net_rsc_addr("TLS_image_net_rsc_addr")
    , TLS_image_net_rsc_re("TLS_image_net_rsc_re")
    , TLS_image_net_rsc_data_out("TLS_image_net_rsc_data_out")
    , TLS_image_net_rsc_triosy_lz("TLS_image_net_rsc_triosy_lz")
    , TLS_image_floue_rsc_addr("TLS_image_floue_rsc_addr")
    , TLS_image_floue_rsc_re("TLS_image_floue_rsc_re")
    , TLS_image_floue_rsc_data_out("TLS_image_floue_rsc_data_out")
    , TLS_image_floue_rsc_triosy_lz("TLS_image_floue_rsc_triosy_lz")
    , TLS_image_error_rsc_data_in("TLS_image_error_rsc_data_in")
    , TLS_image_error_rsc_addr("TLS_image_error_rsc_addr")
    , TLS_image_error_rsc_re("TLS_image_error_rsc_re")
    , TLS_image_error_rsc_we("TLS_image_error_rsc_we")
    , TLS_image_error_rsc_data_out("TLS_image_error_rsc_data_out")
    , TLS_image_error_rsc_triosy_lz("TLS_image_error_rsc_triosy_lz")
    , TLS_depth_rsc_data_in("TLS_depth_rsc_data_in")
    , TLS_depth_rsc_addr("TLS_depth_rsc_addr")
    , TLS_depth_rsc_we("TLS_depth_rsc_we")
    , TLS_depth_rsc_triosy_lz("TLS_depth_rsc_triosy_lz")
    , TLS_return_rsc_z("TLS_return_rsc_z")
    , TLS_return_rsc_triosy_lz("TLS_return_rsc_triosy_lz")
    , main_INST("rtl", TO_QUOTED_STRING(TOP_HDL_ENTITY))
    , CCS_ADAPTOR_CCS_ADAPTOR_image_net_rsc_re("CCS_ADAPTOR_CCS_ADAPTOR_image_net_rsc_re")
    , TLS_image_net_rsc_data_in("TLS_image_net_rsc_data_in")
    , TLS_image_net_rsc_we("TLS_image_net_rsc_we")
    , image_net_rsc_INST("image_net_rsc", true)
    , CCS_ADAPTOR_CCS_ADAPTOR_image_floue_rsc_re("CCS_ADAPTOR_CCS_ADAPTOR_image_floue_rsc_re")
    , TLS_image_floue_rsc_data_in("TLS_image_floue_rsc_data_in")
    , TLS_image_floue_rsc_we("TLS_image_floue_rsc_we")
    , image_floue_rsc_INST("image_floue_rsc", true)
    , CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_we("CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_we")
    , CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_re("CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_re")
    , image_error_rsc_INST("image_error_rsc", true)
    , CCS_ADAPTOR_CCS_ADAPTOR_depth_rsc_we("CCS_ADAPTOR_CCS_ADAPTOR_depth_rsc_we")
    , TLS_depth_rsc_re("TLS_depth_rsc_re")
    , TLS_depth_rsc_data_out("TLS_depth_rsc_data_out")
    , depth_rsc_INST("depth_rsc", true)
    , return_rsc_INST("return_rsc", true)
    , TLS_in_fifo_mask("TLS_in_fifo_mask", -1)
    , TLS_in_wait_ctrl_fifo_mask("TLS_in_wait_ctrl_fifo_mask", -1)
    , TLS_in_fifo_filtre("TLS_in_fifo_filtre", -1)
    , TLS_in_wait_ctrl_fifo_filtre("TLS_in_wait_ctrl_fifo_filtre", -1)
    , TLS_in_fifo_image_net("TLS_in_fifo_image_net", -1)
    , TLS_in_wait_ctrl_fifo_image_net("TLS_in_wait_ctrl_fifo_image_net", -1)
    , trios_monitor_image_net_rsc_triosy_lz_INST("trios_monitor_image_net_rsc_triosy_lz_INST")
    , transactor_image_net("transactor_image_net", 0, 32, 0, false)
    , TLS_in_fifo_image_floue("TLS_in_fifo_image_floue", -1)
    , TLS_in_wait_ctrl_fifo_image_floue("TLS_in_wait_ctrl_fifo_image_floue", -1)
    , trios_monitor_image_floue_rsc_triosy_lz_INST("trios_monitor_image_floue_rsc_triosy_lz_INST")
    , transactor_image_floue("transactor_image_floue", 0, 32, 0, false)
    , TLS_in_fifo_image_error("TLS_in_fifo_image_error", -1)
    , TLS_in_wait_ctrl_fifo_image_error("TLS_in_wait_ctrl_fifo_image_error", -1)
    , TLS_out_fifo_image_error("TLS_out_fifo_image_error", -1)
    , TLS_out_wait_ctrl_fifo_image_error("TLS_out_wait_ctrl_fifo_image_error", -1)
    , trios_monitor_image_error_rsc_triosy_lz_INST("trios_monitor_image_error_rsc_triosy_lz_INST")
    , transactor_image_error("transactor_image_error", 0, 32, 0)
    , TLS_out_fifo_depth("TLS_out_fifo_depth", -1)
    , TLS_out_wait_ctrl_fifo_depth("TLS_out_wait_ctrl_fifo_depth", -1)
    , trios_monitor_depth_rsc_triosy_lz_INST("trios_monitor_depth_rsc_triosy_lz_INST")
    , transactor_depth("transactor_depth", 0, 32, 0)
    , TLS_out_fifo_return("TLS_out_fifo_return", -1)
    , TLS_out_wait_ctrl_fifo_return("TLS_out_wait_ctrl_fifo_return", -1)
    , trios_monitor_return_rsc_triosy_lz_INST("trios_monitor_return_rsc_triosy_lz_INST")
    , transactor_return("transactor_return", 0, 32, 0)
    , testbench_INST("user_tb")
    , catapult_start("catapult_start")
    , catapult_done("catapult_done")
    , catapult_ready("catapult_ready")
    , in_sync("in_sync")
    , out_sync("out_sync")
    , inout_sync("inout_sync")
    , wait_for_init("wait_for_init")
    , sync_generator_INST("sync_generator", true, false, false, false, 625186, 625186, 0)
    , catapult_monitor_INST("Monitor", clk, true, 0LL, 625186LL)
    , ccs_probe_monitor_INST(NULL)
    , deadlocked("deadlocked")
  {
    rst_driver.reset_out(TLS_rst);

    main_INST.clk(clk);
    main_INST.rst(TLS_rst);
    main_INST.image_net_rsc_addr(TLS_image_net_rsc_addr);
    main_INST.image_net_rsc_re(TLS_image_net_rsc_re);
    main_INST.image_net_rsc_data_out(TLS_image_net_rsc_data_out);
    main_INST.image_net_rsc_triosy_lz(TLS_image_net_rsc_triosy_lz);
    main_INST.image_floue_rsc_addr(TLS_image_floue_rsc_addr);
    main_INST.image_floue_rsc_re(TLS_image_floue_rsc_re);
    main_INST.image_floue_rsc_data_out(TLS_image_floue_rsc_data_out);
    main_INST.image_floue_rsc_triosy_lz(TLS_image_floue_rsc_triosy_lz);
    main_INST.image_error_rsc_data_in(TLS_image_error_rsc_data_in);
    main_INST.image_error_rsc_addr(TLS_image_error_rsc_addr);
    main_INST.image_error_rsc_re(TLS_image_error_rsc_re);
    main_INST.image_error_rsc_we(TLS_image_error_rsc_we);
    main_INST.image_error_rsc_data_out(TLS_image_error_rsc_data_out);
    main_INST.image_error_rsc_triosy_lz(TLS_image_error_rsc_triosy_lz);
    main_INST.depth_rsc_data_in(TLS_depth_rsc_data_in);
    main_INST.depth_rsc_addr(TLS_depth_rsc_addr);
    main_INST.depth_rsc_we(TLS_depth_rsc_we);
    main_INST.depth_rsc_triosy_lz(TLS_depth_rsc_triosy_lz);
    main_INST.return_rsc_z(TLS_return_rsc_z);
    main_INST.return_rsc_triosy_lz(TLS_return_rsc_triosy_lz);

    CCS_ADAPTOR_CCS_ADAPTOR_image_net_rsc_re.inSCALAR(TLS_image_net_rsc_re);
    CCS_ADAPTOR_CCS_ADAPTOR_image_net_rsc_re.outVECTOR(CCS_ADAPTOR_image_net_rsc_re);

    image_net_rsc_INST.data_out(TLS_image_net_rsc_data_out);
    image_net_rsc_INST.re(CCS_ADAPTOR_image_net_rsc_re);
    image_net_rsc_INST.addr(TLS_image_net_rsc_addr);
    image_net_rsc_INST.clk(clk);
    image_net_rsc_INST.a_rst(rst);
    image_net_rsc_INST.s_rst(TLS_rst);
    image_net_rsc_INST.en(SIG_SC_LOGIC_0);
    image_net_rsc_INST.data_in(TLS_image_net_rsc_data_in);
    image_net_rsc_INST.we(TLS_image_net_rsc_we);
    image_net_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_3)));

    CCS_ADAPTOR_CCS_ADAPTOR_image_floue_rsc_re.inSCALAR(TLS_image_floue_rsc_re);
    CCS_ADAPTOR_CCS_ADAPTOR_image_floue_rsc_re.outVECTOR(CCS_ADAPTOR_image_floue_rsc_re);

    image_floue_rsc_INST.data_out(TLS_image_floue_rsc_data_out);
    image_floue_rsc_INST.re(CCS_ADAPTOR_image_floue_rsc_re);
    image_floue_rsc_INST.addr(TLS_image_floue_rsc_addr);
    image_floue_rsc_INST.clk(clk);
    image_floue_rsc_INST.a_rst(rst);
    image_floue_rsc_INST.s_rst(TLS_rst);
    image_floue_rsc_INST.en(SIG_SC_LOGIC_0);
    image_floue_rsc_INST.data_in(TLS_image_floue_rsc_data_in);
    image_floue_rsc_INST.we(TLS_image_floue_rsc_we);
    image_floue_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_4)));

    CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_we.inSCALAR(TLS_image_error_rsc_we);
    CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_we.outVECTOR(CCS_ADAPTOR_image_error_rsc_we);

    CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_re.inSCALAR(TLS_image_error_rsc_re);
    CCS_ADAPTOR_CCS_ADAPTOR_image_error_rsc_re.outVECTOR(CCS_ADAPTOR_image_error_rsc_re);

    image_error_rsc_INST.data_out(TLS_image_error_rsc_data_out);
    image_error_rsc_INST.we(CCS_ADAPTOR_image_error_rsc_we);
    image_error_rsc_INST.re(CCS_ADAPTOR_image_error_rsc_re);
    image_error_rsc_INST.addr(TLS_image_error_rsc_addr);
    image_error_rsc_INST.data_in(TLS_image_error_rsc_data_in);
    image_error_rsc_INST.clk(clk);
    image_error_rsc_INST.a_rst(rst);
    image_error_rsc_INST.s_rst(TLS_rst);
    image_error_rsc_INST.en(SIG_SC_LOGIC_0);
    image_error_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_5)));

    CCS_ADAPTOR_CCS_ADAPTOR_depth_rsc_we.inSCALAR(TLS_depth_rsc_we);
    CCS_ADAPTOR_CCS_ADAPTOR_depth_rsc_we.outVECTOR(CCS_ADAPTOR_depth_rsc_we);

    depth_rsc_INST.we(CCS_ADAPTOR_depth_rsc_we);
    depth_rsc_INST.addr(TLS_depth_rsc_addr);
    depth_rsc_INST.data_in(TLS_depth_rsc_data_in);
    depth_rsc_INST.clk(clk);
    depth_rsc_INST.a_rst(rst);
    depth_rsc_INST.s_rst(TLS_rst);
    depth_rsc_INST.en(SIG_SC_LOGIC_0);
    depth_rsc_INST.re(TLS_depth_rsc_re);
    depth_rsc_INST.data_out(TLS_depth_rsc_data_out);
    depth_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_6)));

    return_rsc_INST.z(TLS_return_rsc_z);
    return_rsc_INST.clk(clk);
    return_rsc_INST.add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_7)));

    trios_monitor_image_net_rsc_triosy_lz_INST.trios(TLS_image_net_rsc_triosy_lz);
    trios_monitor_image_net_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_image_net.in_fifo(TLS_in_fifo_image_net);
    transactor_image_net.in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_image_net);
    transactor_image_net.bind_clk(clk, true);
    transactor_image_net.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_image_net.register_block(&image_net_rsc_INST, image_net_rsc_INST.basename(), TLS_image_net_rsc_triosy_lz,
        0, 59999, 1);

    trios_monitor_image_floue_rsc_triosy_lz_INST.trios(TLS_image_floue_rsc_triosy_lz);
    trios_monitor_image_floue_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_image_floue.in_fifo(TLS_in_fifo_image_floue);
    transactor_image_floue.in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_image_floue);
    transactor_image_floue.bind_clk(clk, true);
    transactor_image_floue.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_image_floue.register_block(&image_floue_rsc_INST, image_floue_rsc_INST.basename(), TLS_image_floue_rsc_triosy_lz,
        0, 59999, 1);

    trios_monitor_image_error_rsc_triosy_lz_INST.trios(TLS_image_error_rsc_triosy_lz);
    trios_monitor_image_error_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_image_error.in_fifo(TLS_in_fifo_image_error);
    transactor_image_error.in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_image_error);
    transactor_image_error.out_fifo(TLS_out_fifo_image_error);
    transactor_image_error.out_wait_ctrl_fifo(TLS_out_wait_ctrl_fifo_image_error);
    transactor_image_error.bind_clk(clk, true);
    transactor_image_error.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_image_error.register_block(&image_error_rsc_INST, image_error_rsc_INST.basename(), TLS_image_error_rsc_triosy_lz,
        0, 68255, 1);

    trios_monitor_depth_rsc_triosy_lz_INST.trios(TLS_depth_rsc_triosy_lz);
    trios_monitor_depth_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_depth.out_fifo(TLS_out_fifo_depth);
    transactor_depth.out_wait_ctrl_fifo(TLS_out_wait_ctrl_fifo_depth);
    transactor_depth.bind_clk(clk, true);
    transactor_depth.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_depth.register_block(&depth_rsc_INST, depth_rsc_INST.basename(), TLS_depth_rsc_triosy_lz, 0, 59999,
        1);

    trios_monitor_return_rsc_triosy_lz_INST.trios(TLS_return_rsc_triosy_lz);
    trios_monitor_return_rsc_triosy_lz_INST.register_mon(&catapult_monitor_INST);

    transactor_return.out_fifo(TLS_out_fifo_return);
    transactor_return.out_wait_ctrl_fifo(TLS_out_wait_ctrl_fifo_return);
    transactor_return.bind_clk(clk, true);
    transactor_return.add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", 0 )));
    transactor_return.register_block(&return_rsc_INST, return_rsc_INST.basename(), TLS_return_rsc_triosy_lz, 0,
        0, 1);

    testbench_INST.clk(clk);
    testbench_INST.ccs_mask(TLS_in_fifo_mask);
    testbench_INST.ccs_wait_ctrl_mask(TLS_in_wait_ctrl_fifo_mask);
    testbench_INST.ccs_filtre(TLS_in_fifo_filtre);
    testbench_INST.ccs_wait_ctrl_filtre(TLS_in_wait_ctrl_fifo_filtre);
    testbench_INST.ccs_image_net(TLS_in_fifo_image_net);
    testbench_INST.ccs_wait_ctrl_image_net(TLS_in_wait_ctrl_fifo_image_net);
    testbench_INST.ccs_image_floue(TLS_in_fifo_image_floue);
    testbench_INST.ccs_wait_ctrl_image_floue(TLS_in_wait_ctrl_fifo_image_floue);
    testbench_INST.ccs_image_error_IN(TLS_in_fifo_image_error);
    testbench_INST.ccs_wait_ctrl_image_error_IN(TLS_in_wait_ctrl_fifo_image_error);
    testbench_INST.ccs_image_error(TLS_out_fifo_image_error);
    testbench_INST.ccs_wait_ctrl_image_error(TLS_out_wait_ctrl_fifo_image_error);
    testbench_INST.ccs_depth(TLS_out_fifo_depth);
    testbench_INST.ccs_wait_ctrl_depth(TLS_out_wait_ctrl_fifo_depth);
    testbench_INST.ccs_return(TLS_out_fifo_return);
    testbench_INST.ccs_wait_ctrl_return(TLS_out_wait_ctrl_fifo_return);
    testbench_INST.design_is_idle(TLS_design_is_idle_reg);
    testbench_INST.enable_stalls(TLS_enable_stalls);
    testbench_INST.stall_coverage(TLS_stall_coverage);

    sync_generator_INST.clk(clk);
    sync_generator_INST.rst(rst);
    sync_generator_INST.in_sync(in_sync);
    sync_generator_INST.out_sync(out_sync);
    sync_generator_INST.inout_sync(inout_sync);
    sync_generator_INST.wait_for_init(wait_for_init);
    sync_generator_INST.catapult_start(catapult_start);
    sync_generator_INST.catapult_ready(catapult_ready);
    sync_generator_INST.catapult_done(catapult_done);

    catapult_monitor_INST.rst(rst);


    SC_METHOD(generate_reset);
      sensitive << reset_deactivation_event;

    SC_METHOD(deadlock_watch);
      sensitive << clk;
      dont_initialize();

    SC_METHOD(deadlock_notify);
      sensitive << deadlock_event;
      dont_initialize();


    testbench_INST._capture_mask = false;
    testbench_INST._capture_filtre = false;
    #if defined(CCS_SCVERIFY) && defined(CCS_DUT_RTL) && !defined(CCS_DUT_SYSC) && !defined(CCS_SYSC) && !defined(CCS_DUT_POWER)
        ccs_probe_monitor_INST = new ccs_probe_monitor("ccs_probe_monitor");
    ccs_probe_monitor_INST->clk(clk);
    ccs_probe_monitor_INST->rst(rst);
    #endif
    SIG_SC_LOGIC_0.write(SC_LOGIC_0);
    SIG_SC_LOGIC_1.write(SC_LOGIC_1);
    testbench::register_end_of_testbench_obj(&catapult_monitor_INST);
    mt19937_init_genrand(19650218UL);
    install_observe_foreign_signals();
  }
};
void scverify_top::start_of_simulation() {
  char *SCVerify_AUTOWAIT = getenv("SCVerify_AUTOWAIT");
  if (SCVerify_AUTOWAIT) {
    int l = atoi(SCVerify_AUTOWAIT);
    transactor_image_net.set_auto_wait_limit(l);
    transactor_image_floue.set_auto_wait_limit(l);
    transactor_image_error.set_auto_wait_limit(l);
    transactor_depth.set_auto_wait_limit(l);
    transactor_return.set_auto_wait_limit(l);
  }
}

void scverify_top::setup_debug() {
#ifdef MC_DEFAULT_TRANSACTOR_LOG
  static int transactor_image_net_flags = MC_DEFAULT_TRANSACTOR_LOG;
  static int transactor_image_floue_flags = MC_DEFAULT_TRANSACTOR_LOG;
  static int transactor_image_error_flags = MC_DEFAULT_TRANSACTOR_LOG;
  static int transactor_depth_flags = MC_DEFAULT_TRANSACTOR_LOG;
  static int transactor_return_flags = MC_DEFAULT_TRANSACTOR_LOG;
#else
  static int transactor_image_net_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
  static int transactor_image_floue_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
  static int transactor_image_error_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
  static int transactor_depth_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
  static int transactor_return_flags = MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT;
#endif
  static int transactor_image_net_count = -1;
  static int transactor_image_floue_count = -1;
  static int transactor_image_error_count = -1;
  static int transactor_depth_count = -1;
  static int transactor_return_count = -1;

  // At the breakpoint, modify the local variables
  // above to turn on/off different levels of transaction
  // logging for each variable. Available flags are:
  //   MC_TRANSACTOR_EMPTY       - log empty FIFOs (on by default)
  //   MC_TRANSACTOR_UNDERFLOW   - log FIFOs that run empty and then are loaded again (off)
  //   MC_TRANSACTOR_READ        - log all read events
  //   MC_TRANSACTOR_WRITE       - log all write events
  //   MC_TRANSACTOR_LOAD        - log all FIFO load events
  //   MC_TRANSACTOR_DUMP        - log all FIFO dump events
  //   MC_TRANSACTOR_STREAMCNT   - log all streamed port index counter events
  //   MC_TRANSACTOR_WAIT        - log user specified handshake waits
  //   MC_TRANSACTOR_SIZE        - log input FIFO size updates

  std::ifstream debug_cmds;
  debug_cmds.open("scverify.cmd",std::fstream::in);
  if (debug_cmds.is_open()) {
    std::cout << "Reading SCVerify debug commands from file 'scverify.cmd'" << std::endl;
    std::string line;
    while (getline(debug_cmds,line)) {
      std::size_t pos1 = line.find(" ");
      if (pos1 == std::string::npos) continue;
      std::size_t pos2 = line.find(" ", pos1+1);
      std::string varname = line.substr(0,pos1);
      std::string flags = line.substr(pos1+1,pos2-pos1-1);
      std::string count = line.substr(pos2+1);
      debug(varname.c_str(),std::atoi(flags.c_str()),std::atoi(count.c_str()));
    }
    debug_cmds.close();
  } else {
    debug("transactor_image_net",transactor_image_net_flags,transactor_image_net_count);
    debug("transactor_image_floue",transactor_image_floue_flags,transactor_image_floue_count);
    debug("transactor_image_error",transactor_image_error_flags,transactor_image_error_count);
    debug("transactor_depth",transactor_depth_flags,transactor_depth_count);
    debug("transactor_return",transactor_return_flags,transactor_return_count);
  }
}

void scverify_top::debug(const char* varname, int flags, int count) {
  sc_module *xlator_p = 0;
  sc_attr_base *debug_attr_p = 0;
  if (strcmp(varname,"transactor_image_net") == 0)
    xlator_p = &transactor_image_net;
  if (strcmp(varname,"transactor_image_floue") == 0)
    xlator_p = &transactor_image_floue;
  if (strcmp(varname,"transactor_image_error") == 0)
    xlator_p = &transactor_image_error;
  if (strcmp(varname,"transactor_depth") == 0)
    xlator_p = &transactor_depth;
  if (strcmp(varname,"transactor_return") == 0)
    xlator_p = &transactor_return;
  if (xlator_p) {
    debug_attr_p = xlator_p->get_attribute("MC_TRANSACTOR_EVENT");
    if (!debug_attr_p) {
      debug_attr_p = new sc_attribute<int>("MC_TRANSACTOR_EVENT",flags);
      xlator_p->add_attribute(*debug_attr_p);
    }
    ((sc_attribute<int>*)debug_attr_p)->value = flags;
  }

  if (count>=0) {
    debug_attr_p = xlator_p->get_attribute("MC_TRANSACTOR_COUNT");
    if (!debug_attr_p) {
      debug_attr_p = new sc_attribute<int>("MC_TRANSACTOR_COUNT",count);
      xlator_p->add_attribute(*debug_attr_p);
    }
    ((sc_attribute<int>*)debug_attr_p)->value = count;
  }
}

// Process: SC_METHOD generate_reset
void scverify_top::generate_reset() {
  static bool first = true;
  if (first || sc_time_stamp() == SC_ZERO_TIME) {
    setup_debug();
    first = false;
    rst.write(SC_LOGIC_1);
    reset_deactivation_event.notify(100.000000 , SC_NS);
  } else {
    transactor_image_net.reset_streams();
    transactor_image_floue.reset_streams();
    transactor_image_error.reset_streams();
    transactor_depth.reset_streams();
    transactor_return.reset_streams();
    rst.write(SC_LOGIC_0);
  }
}

void scverify_top::install_observe_foreign_signals() {
#if !defined(CCS_DUT_SYSC) && defined(DEADLOCK_DETECTION)
#if defined(CCS_DUT_CYCLE) || defined(CCS_DUT_RTL)
#endif
#endif
}

void scverify_top::deadlock_watch() {
#if !defined(CCS_DUT_SYSC) && defined(DEADLOCK_DETECTION)
#if defined(CCS_DUT_CYCLE) || defined(CCS_DUT_RTL)
#if defined(MTI_SYSTEMC) || defined(NCSC) || defined(VCS_SYSTEMC)
#endif
#endif
#endif
}

void scverify_top::deadlock_notify() {
  if (deadlocked.read() == SC_LOGIC_1) {
    testbench_INST.check_results();
    SC_REPORT_ERROR("System", "Simulation deadlock detected");
    sc_stop();
  }
}

#if defined(MC_SIMULATOR_OSCI) || defined(MC_SIMULATOR_VCS)
int sc_main(int argc, char *argv[]) {
  sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
  scverify_top scverify_top("scverify_top");
  sc_start();
  return scverify_top.testbench_INST.failed();
}
#else
MC_MODULE_EXPORT(scverify_top);
#endif
