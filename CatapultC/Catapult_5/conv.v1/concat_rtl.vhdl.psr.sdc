set sdc_version 1.6 

create_clock -name clk -period 50.0 -waveform { 0.0 25.0 } [get_ports {clk}]
set_clock_uncertainty 0.0 [get_clocks {clk}]

# These constraints prevent the Precision 'No initialized timing analysis; 
# cannot define a Clock.' error message in combinational designs
set hls_design_clk [lindex [concat [find_clocks -top] [all_clocks]] 0]
set_input_delay 0.0 -clock $hls_design_clk [all_inputs]
set_output_delay 0.0 -clock $hls_design_clk [all_outputs]

## IO TIMING CONSTRAINTS
set_input_delay -clock [get_clocks {clk}] 0.0 [get_ports {rst}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_rsc_addr*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_rsc_re}]
set_input_delay -clock [get_clocks {clk}] 1.85 [get_ports {image_rsc_data_out*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_rsc_triosy_lz}]
set_input_delay -clock [get_clocks {clk}] 0.0 [get_ports {rows_rsc_z*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {rows_rsc_triosy_lz}]
set_input_delay -clock [get_clocks {clk}] 0.0 [get_ports {cols_rsc_z*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {cols_rsc_triosy_lz}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {kernel_rsc_addr*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {kernel_rsc_re}]
set_input_delay -clock [get_clocks {clk}] 1.85 [get_ports {kernel_rsc_data_out*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {kernel_rsc_triosy_lz}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {sortie_rsc_data_in*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {sortie_rsc_addr*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {sortie_rsc_re}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {sortie_rsc_we}]
set_input_delay -clock [get_clocks {clk}] 1.85 [get_ports {sortie_rsc_data_out*}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {sortie_rsc_triosy_lz}]

