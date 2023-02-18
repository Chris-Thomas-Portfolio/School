onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /fsm_alu_tb/clk
add wave -noupdate -label OPCODE -radix hexadecimal /fsm_alu_tb/opcode
add wave -noupdate -label A -radix hexadecimal /fsm_alu_tb/a
add wave -noupdate -label B -radix hexadecimal /fsm_alu_tb/b
add wave -noupdate -label RESET -radix hexadecimal /fsm_alu_tb/reset
add wave -noupdate -label GO -radix hexadecimal /fsm_alu_tb/go
add wave -noupdate -divider FSM_ALU Module
add wave -noupdate -label RESULT -radix hexadecimal /fsm_alu_tb/U1/result
add wave -noupdate -label COUT -radix hexadecimal /fsm_alu_tb/U1/cout
add wave -noupdate -label LED_IDLE -radix hexadecimal /fsm_alu_tb/U1/led_idle
add wave -noupdate -label LED_READY -radix hexadecimal /fsm_alu_tb/U1/led_ready
add wave -noupdate -label LED_DONE -radix hexadecimal /fsm_alu_tb/U1/led_done
add wave -noupdate -label STATE -radix hexadecimal /fsm_alu_tb/U1/state
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
