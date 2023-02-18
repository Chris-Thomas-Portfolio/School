onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /clk_FSM_tb/clk
add wave -noupdate -label RESET -radix hexadecimal /clk_FSM_tb/reset
add wave -noupdate -label SET -radix hexadecimal /clk_FSM_tb/set
add wave -noupdate -label HOUR -radix hexadecimal /clk_FSM_tb/hour
add wave -noupdate -label MINUTE -radix hexadecimal /clk_FSM_tb/minute
add wave -noupdate -divider CLK_FSM
add wave -noupdate -label AM /clk_FSM_tb/U1/am
add wave -noupdate -label STATE /clk_FSM_tb/U1/state
add wave -noupdate -label SECONDS /clk_FSM_tb/U1/seconds
add wave -noupdate -label MINUTES /clk_FSM_tb/U1/minutes
add wave -noupdate -label HOURS /clk_FSM_tb/U1/hours
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {20000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 73
configure wave -valuecolwidth 64
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {350 ns}
