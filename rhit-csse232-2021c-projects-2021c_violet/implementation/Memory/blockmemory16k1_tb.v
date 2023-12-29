`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:34:48 04/26/2021
// Design Name:   blockmemory16kx1
// Module Name:   C:/Users/ansarij/Documents/232Classwork/Xilinx/memory/blockmemory16k1_tb.v
// Project Name:  memory
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: blockmemory16kx1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module blockmemory16k1_tb;

	// Inputs
	reg clka;
	reg [0:0] wea;
	reg [9:0] addra;
	reg [15:0] dina;


	parameter HALF_PERIOD = 50;

	// Outputs
	wire [15:0] douta;
	
	initial begin
		 clka = 0;
		 forever begin
			  #(HALF_PERIOD);
			  clka = ~clka;
		 end
	end
	// Instantiate the Unit Under Test (UUT)
	blockmemory16kx1 uut (
		.clka(clka), 
		.wea(wea), 
		.addra(addra), 
		.dina(dina), 
		.douta(douta)
	);

	initial begin
	
		// Initialize Inputs
		//clka = 0;
		wea = 1;
		addra = 0;
		dina = 0;

		// Wait 100 ns for global reset to finish
		#100;
      
		addra = 0;
		dina = 57005; //DEAD
		//wea = 1;
		
		#100;
		$display("1 (should be %d): %d", dina, douta);
		//wea = 0;
		addra = 1; 
		dina = 48879; //BEEF
		#50;
		wea = 1;
		#50;
		$display("2 (should be %d): %d", dina, douta);
		wea = 0;
		#100;
		addra = 2;
		#100;
		$display("3: (should be 43981): %d", douta);
		// Add stimulus here

	end
      
endmodule

