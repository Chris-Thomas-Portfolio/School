onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /transmit_tb/clk
add wave -noupdate -label BUT -radix hexadecimal /transmit_tb/but
add wave -noupdate -label DATA -radix hexadecimal /transmit_tb/data
add wave -noupdate -divider TRANSMIT_CONTROL
add wave -noupdate -label DATA_OUT /transmit_tb/U1/data_out
add wave -noupdate -label COUNT /transmit_tb/U1/count
add wave -noupdate -label STATE /transmit_tb/U1/state
add wave -noupdate -label MESSAGE -radix hexadecimal /transmit_tb/U1/message
add wave -noupdate -label MESSAGE_COUNT /transmit_tb/U1/message_count
add wave -noupdate -label DATA -radix hexadecimal /transmit_tb/U1/data
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
