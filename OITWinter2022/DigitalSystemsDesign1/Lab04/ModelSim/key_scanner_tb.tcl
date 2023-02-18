# stop any simulation that is currently running
quit -sim

# create the default "work" library
vlib work;

# compile the Verilog source code in the parent folder
vlog ../*.v

# compile the Verilog code of the key_scanner_tb
vlog *.v

# start the Simulator, including some libraries
vsim work.key_scanner_tb -Lf 220model -Lf altera_mf_ver -Lf verilog

# show waveforms specified in wave.do
do wave_key_scanner.do

# advance the simulation the desired amount of time
run 200 ns
