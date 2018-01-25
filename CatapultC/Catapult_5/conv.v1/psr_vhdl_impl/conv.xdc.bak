
##########
# Clocks #
##########
create_clock [get_ports clk] -name clk -period 50 -waveform {0 25}

###############
# Input Delay #
###############
set_input_delay 0 -clock clk  [get_ports {clk cols_rsc_z* image_rsc_data_out* kernel_rsc_data_out* rows_rsc_z* rst sortie_rsc_data_out*}]
set_input_delay 0 -clock clk  [get_ports rst]
set_input_delay 1.85 -clock clk  [get_ports image_rsc_data_out*]
set_input_delay 0 -clock clk  [get_ports rows_rsc_z*]
set_input_delay 0 -clock clk  [get_ports cols_rsc_z*]
set_input_delay 1.85 -clock clk  [get_ports kernel_rsc_data_out*]
set_input_delay 1.85 -clock clk  [get_ports sortie_rsc_data_out*]

################
# Output Delay #
################
set_output_delay 0 -clock clk  [get_ports {cols_rsc_triosy_lz image_rsc_addr* image_rsc_re image_rsc_triosy_lz kernel_rsc_addr* kernel_rsc_re kernel_rsc_triosy_lz rows_rsc_triosy_lz sortie_rsc_addr* sortie_rsc_data_in* sortie_rsc_re sortie_rsc_triosy_lz sortie_rsc_we}]
set_output_delay 0 -clock clk  [get_ports image_rsc_addr*]
set_output_delay 0 -clock clk  [get_ports image_rsc_re]
set_output_delay 0 -clock clk  [get_ports image_rsc_triosy_lz]
set_output_delay 0 -clock clk  [get_ports rows_rsc_triosy_lz]
set_output_delay 0 -clock clk  [get_ports cols_rsc_triosy_lz]
set_output_delay 0 -clock clk  [get_ports kernel_rsc_addr*]
set_output_delay 0 -clock clk  [get_ports kernel_rsc_re]
set_output_delay 0 -clock clk  [get_ports kernel_rsc_triosy_lz]
set_output_delay 0 -clock clk  [get_ports sortie_rsc_data_in*]
set_output_delay 0 -clock clk  [get_ports sortie_rsc_addr*]
set_output_delay 0 -clock clk  [get_ports sortie_rsc_re]
set_output_delay 0 -clock clk  [get_ports sortie_rsc_we]
set_output_delay 0 -clock clk  [get_ports sortie_rsc_triosy_lz]

#####################
# Clock Uncertainty #
#####################
set_clock_uncertainty 0 [get_clocks clk]
