# is_buffer property
read_liberty prune_sky130hd_tt.lib
read_verilog get_is_buffer.v
link_design dut
report_object_full_names [get_cells -filter is_buffer]
