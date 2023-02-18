onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /taillight_FSM_tb/clk
add wave -noupdate -label LEFT -radix hexadecimal /taillight_FSM_tb/left
add wave -noupdate -label RIGHT -radix hexadecimal /taillight_FSM_tb/right
add wave -noupdate -label BK -radix hexadecimal /taillight_FSM_tb/bk
add wave -noupdate -label HAZ -radix hexadecimal /taillight_FSM_tb/haz
add wave -noupdate -divider TAILLIGHT_FSM
add wave -noupdate -label LED /taillight_FSM_tb/U1/led
add wave -noupdate -label STATE /taillight_FSM_tb/U1/state
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
