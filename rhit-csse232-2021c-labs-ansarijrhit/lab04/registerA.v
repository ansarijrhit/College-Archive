`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:40:09 08/12/2020 
// Design Name: 
// Module Name:    register 
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
module registerA(
    input [5:0] din,
	 input reset,
    output reg [5:0] dout,
    input CLK
    );

always @ (posedge(CLK))
begin
	if (reset != 1) begin 
		dout = din;
	end else begin
		dout = 0;
	end
end

endmodule
