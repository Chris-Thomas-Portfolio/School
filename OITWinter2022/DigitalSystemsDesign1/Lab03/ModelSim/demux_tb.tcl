# stop any simulation that is currently running
quit -sim

# create the default "work" library
vlib work;

# compile the Verilog source code in the parent folder
vlog ../*.v

# compile the Verilog code of the demux_tb
vlog *.v

# start the Simulator, including some libraries
vsim work.demux_tb -Lf 220model -Lf altera_mf_ver -Lf verilog

# show waveforms specified in wave.do
do wave_demux.do

# advance the simulation the desired amount of time
run 100 ns
