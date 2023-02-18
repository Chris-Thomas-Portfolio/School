module ALU(
	input clk,
	input reset,
	input go,
	input [2:0] opcode,
	input [3:0] data,	
	output wait_led, cout, led_idle, led_ready, led_done,
	output [4:0] result
);

wire [3:0] data_out;
wire state_change;


go				U1(clk, reset, go, data, data_out, wait_led, state_change);
fsm_alu		U2(opcode, data, data_out, clk, reset, state_change, result, cout, led_idle, led_ready, led_done);

endmodule