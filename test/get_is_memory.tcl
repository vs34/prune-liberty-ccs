# Tests whether the is_memory attribute works for cells and libcells
read_liberty prune_gf180mcu_sram.lib
read_liberty prune_asap7_small.lib
read_verilog get_is_memory.v
link get_is_memory

# Test that the is_memory attribute is set correctly for cells
puts {[get_cells -filter is_memory]}
report_object_full_names [get_cells -filter is_memory]
puts {[get_lib_cells -filter is_memory]}
report_object_full_names [get_lib_cells -filter is_memory]
