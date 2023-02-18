onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label HEX -radix hexadecimal /display_tb/hex
add wave -noupdate -divider Output
add wave -noupdate -label DISPLAY -radix hexadecimal /display_tb/display
add wave -noupdate -divider DISPLAY Module
add wave -noupdate -label HEX /display_tb/U1/hex
add wave -noupdate -label DISPLAY /display_tb/U1/display
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
