set sdc_version 1.6 

create_clock -name clk -period 50.0 -waveform { 0.0 25.0 } [get_ports {clk}]
set_clock_uncertainty 0.0 [get_clocks {clk}]

## IO TIMING CONSTRAINTS
set_input_delay -clock [get_clocks {clk}] 0.0 [get_ports {rst}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_radr[*]}]
set_input_delay -clock [get_clocks {clk}] 1.85 [get_ports {image_in_rsc_q[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_re}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_in_rsc_triosy_lz}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_out_rsc_wadr[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_out_rsc_d[*]}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_out_rsc_we}]
set_output_delay -clock [get_clocks {clk}] 0.0 [get_ports {image_out_rsc_triosy_lz}]

