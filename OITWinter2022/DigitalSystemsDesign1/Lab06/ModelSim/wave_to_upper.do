onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /to_upper_tb/clk
add wave -noupdate -label DATA_IN -radix hexadecimal /to_upper_tb/data_in
add wave -noupdate -label NEW_DATA -radix hexadecimal /to_upper_tb/new_data
add wave -noupdate -divider TO_UPPER
add wave -noupdate -label DATA_OUT /to_upper_tb/U1/data_out
add wave -noupdate -label TRANSMIT /to_upper_tb/U1/transmit
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
