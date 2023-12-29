`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:38:24 08/12/2020 
// Design Name: 
// Module Name:    register_no_reset 
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
module registerB(
    input [5:0] din,
	 input reset,
    output reg [5:0] dout,
    input CLK
    );

initial begin
	dout = 0;
end

always @ (posedge(CLK))
begin
	if (reset != 1) begin 
		dout = din;
	end
end
endmodule
