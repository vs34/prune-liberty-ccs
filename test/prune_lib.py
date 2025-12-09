import subprocess

def run_prune(input_gz, output_lib):
    cmd = ["../build/prune", input_gz]

    with open(output_lib, "wb") as out_file:
        proc = subprocess.run(
            cmd,
            stdout=out_file,          # this is your ">"
            stderr=subprocess.PIPE   # this catches std::cerr
        )

    if proc.returncode != 0:
        return proc.stderr.decode().strip()  # return the error
    else:
        return None  # no error, all clean

def output_file_name(input_file):
    return "prune_" + input_file.split('.')[0] + ".lib"

lib_to_prune = [
    "asap7_ccsn.lib.gz" ,
    "liberty_backslash_eol.lib" ,
    "asap7_invbuf.lib.gz" ,
    "asap7_seq.lib.gz" ,
    "asap7_simple.lib.gz" ,
    "asap7_small.lib.gz" ,
    "liberty_float_as_str.lib" ,
    "gf180mcu_sram.lib.gz" ,
    "liberty_latch3.lib" ,
    "liberty_arcs_one2one_1.lib" ,
    "nangate45_fast.lib.gz" ,
    "nangate45_slow.lib.gz" ,
    "liberty_arcs_one2one_2.lib" ,
    "nangate45_typ.lib.gz" ,
    "prune_error.lib" ,
    "sky130hd_tt.lib.gz"
]

for a in lib_to_prune:
    print(run_prune(a,output_file_name(a)))
