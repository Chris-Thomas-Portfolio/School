onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /top_tb/clk
add wave -noupdate -label RESET -radix hexadecimal /top_tb/reset
add wave -noupdate -label OPCODE -radix hexadecimal /top_tb/opcode
add wave -noupdate -label DATA -radix hexadecimal /top_tb/data
add wave -noupdate -divider ALU Module
add wave -noupdate -label WAIT_LED /top_tb/U1/wait_led
add wave -noupdate -label LED_IDLE /top_tb/U1/led_idle
add wave -noupdate -label LED_READY /top_tb/U1/led_ready
add wave -noupdate -label LED_DONE /top_tb/U1/led_done
add wave -noupdate -label RESULT /top_tb/U1/result
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
