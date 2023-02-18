onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider MUX_CASE 
add wave -noupdate -label ONES /mux_case_tb/U1/ones
add wave -noupdate -label TENS /mux_case_tb/U1/tens
add wave -noupdate -label HUNDREDS /mux_case_tb/U1/hundreds
add wave -noupdate -label THOUSANDS /mux_case_tb/U1/thousands
add wave -noupdate -label SEL /mux_case_tb/U1/sel
add wave -noupdate -label CLK /mux_case_tb/U1/clk
add wave -noupdate -label MOUT /mux_case_tb/U1/mout
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
