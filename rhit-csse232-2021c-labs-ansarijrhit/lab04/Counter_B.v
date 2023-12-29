`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:39:31 08/12/2020 
// Design Name: 
// Module Name:    counter_by_two 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module counter_B(
    input direction,
	 input reset,
    input CLK,
    output [5:0] dout
    );
	 
wire [5:0] adder_out;
wire [5:0] mux_out;

adder counter_adder (
    .a(dout), 
    .b(mux_out),
	 .r(adder_out)
    );
	 
mux6b2 counter_mux (
    .a(6'b000001), 
    .b(6'b111110), 
    .s(direction), 
    .r(mux_out)
    );

registerA counter_register (
    .din(adder_out),
	 .reset(reset),
    .dout(dout), 
    .CLK(CLK)
    );


endmodule
