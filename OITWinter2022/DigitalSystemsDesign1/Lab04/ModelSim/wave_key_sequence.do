onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label KEY -radix hexadecimal /key_sequence_tb/key
add wave -noupdate -divider KEY_SEQUENCE_GEN Module
add wave -noupdate -label KEY /key_sequence_tb/U1/key
add wave -noupdate -label SEQUENCE -radix hexadecimal /key_sequence_tb/U1/sequence
add wave -noupdate -label KP /key_sequence_tb/U1/kp
add wave -noupdate -label STATE /key_sequence_tb/U1/state
add wave -noupdate -label KEY_PRESSED /key_sequence_tb/U1/key_pressed
add wave -noupdate -label TEMP -radix hexadecimal /key_sequence_tb/U1/temp
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
