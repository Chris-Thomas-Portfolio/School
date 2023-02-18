onerror {exit -code 1}
vlib work
vlog -work work Lab5Part3.vo
vlog -work work Part3.vwf.vt
vsim -novopt -c -t 1ps -L fiftyfivenm_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate_ver -L altera_lnsim_ver work.Lab5Part3_vlg_vec_tst
vcd file -direction Lab5Part3.msim.vcd
vcd add -internal Lab5Part3_vlg_vec_tst/*
vcd add -internal Lab5Part3_vlg_vec_tst/i1/*
proc simTimestamp {} {
    echo "Simulation time: $::now ps"
    if { [string equal running [runStatus]] } {
        after 2500 simTimestamp
    }
}
after 2500 simTimestamp
run -all
quit -f

