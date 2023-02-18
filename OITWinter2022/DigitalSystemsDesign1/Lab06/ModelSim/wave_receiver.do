onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /receiver_tb/clk
add wave -noupdate -label DATA_IN -radix hexadecimal /receiver_tb/data_in
add wave -noupdate -divider RECEIVER
add wave -noupdate -label DATA_OUT /receiver_tb/U1/data_out
add wave -noupdate -label COUNT /receiver_tb/U1/count
add wave -noupdate -label STATE /receiver_tb/U1/state
add wave -noupdate -label CLKCOUNT /receiver_tb/U1/clkCount
add wave -noupdate -label TEMP /receiver_tb/U1/temp
add wave -noupdate -label PARITY /receiver_tb/U1/parity
add wave -noupdate -label VALID /receiver_tb/U1/valid
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
