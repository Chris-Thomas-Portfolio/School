onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /go_tb/clk
add wave -noupdate -label RESET -radix hexadecimal /go_tb/reset
add wave -noupdate -label GO -radix hexadecimal /go_tb/go
add wave -noupdate -label DATA_IN -radix hexadecimal /go_tb/data_in
add wave -noupdate -divider Key Scanner
add wave -noupdate -label DATA /go_tb/U1/data
add wave -noupdate -label WAIT_LED /go_tb/U1/wait_led
add wave -noupdate -label STATE_CHANGE /go_tb/U1/state_change
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
