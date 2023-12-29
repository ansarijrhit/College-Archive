`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:30:38 08/12/2020 
// Design Name: 
// Module Name:    mux16b2 
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
module mux6b2(
    input [5:0] a,
    input [5:0] b,
    input s,
	 output [5:0] r
    );

assign r = (s == 0 ) ? a : b;

endmodule
