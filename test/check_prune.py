import subprocess
import sys

CCS_REGEX = (
    "output_current_rise|output_current_fall|"
    "receiver_capacitance1_rise|receiver_capacitance1_fall|"
    "receiver_capacitance2_rise|receiver_capacitance2_fall|"
    "output_current_power_rise|output_current_power_fall|"
    "noise_immunity_high|noise_immunity_low|"
    "noise_immunity_above_high|noise_immunity_below_low|"
    "propagated_noise_high|propagated_noise_low|"
    "steady_state_current_high|steady_state_current_low|"
    "steady_state_current_tristate|"
    "ccsn_first_stage|ccsn_last_stage|dc_current|"
    "output_current_template|ccsn_first_stage_template|"
    "ccsn_last_stage_template|dc_current_template|"
    "noise_lut_template|propagation_lut_template"
)

cmd = f"grep -nE '{CCS_REGEX}' prune_*.lib"

proc = subprocess.run(
    cmd,
    shell=True,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

# grep exit codes:
# 0 = match found
# 1 = no match
# 2 = error

if proc.returncode == 0:
    print("ERROR: Forbidden CCS keyword found in prune_*.lib files")
    print(proc.stdout)   # shows file:line:number:match
    sys.exit(1)

elif proc.returncode == 1:
    print("OK: No CCS keywords found in prune_*.lib files")
    sys.exit(0)

else:
    print("GREP FAILED:")
    print(proc.stderr)
    sys.exit(2)

