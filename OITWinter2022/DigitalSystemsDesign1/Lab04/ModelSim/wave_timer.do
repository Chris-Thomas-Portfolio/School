onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLOCK -radix hexadecimal /timer_tb/clk
add wave -noupdate -label ENABLE -radix hexadecimal /timer_tb/enable
add wave -noupdate -label RESET -radix hexadecimal /timer_tb/reset
add wave -noupdate -divider Output
add wave -noupdate -label TIME_UP hexadecimal /timer_tb/time_up
add wave -noupdate -divider TIMER Module
add wave -noupdate -label TIME_UP /timer_tb/U1/time_up
add wave -noupdate -label COUNT /timer_tb/U1/count
add wave -noupdate -label LIMIT /timer_tb/U1/limit
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
