// Verilog test fixture created from schematic C:\Users\hunte\Desktop\CSSE232\rhit-csse232-2021c-projects-2021c_violet\implementation\Memory\FullSystemSchm.sch - Thu May 20 23:24:49 2021

`timescale 1ns / 1ps

module FullSystemSchm_FullSystemSchm_sch_tb();

// Inputs
   reg CLK;
   reg Reset;
   reg [15:0] Input;

// Output
   wire [15:0] finalOutput;
	

// Bidirs
	integer ResetCount = 0;
	reg [15:0] inputOne = 5040;
	reg [15:0] inputTwo = 2310;
	reg [15:0] inputThree = 4095;
	parameter HALF_PERIOD = 6;
	initial begin
			CLK = 0;
			forever begin
				#(HALF_PERIOD);
				CLK = ~CLK;
				if (finalOutput != 0 && CLK == 1) begin
					if(ResetCount == 0) begin
					Reset = 1;
					#(2*HALF_PERIOD);
					Reset = 0;
					#(2*HALF_PERIOD);
					Input = inputTwo;
					ResetCount = ResetCount + 1;
					end
					else if(ResetCount == 1) begin
					Reset = 1;
					#(2*HALF_PERIOD);
					Reset = 0;
					#(2*HALF_PERIOD);
					Input = inputThree;
					ResetCount = ResetCount + 1;
					end
					else if(ResetCount == 2) begin
					
					end
					end
					end
				end
	
// Instantiate the UUT
   FullSystemSchm UUT (
		.CLK(CLK), 
		.Reset(Reset), 
		.Input(Input), 
		.finalOutput(finalOutput), 
		.Cycles(Cycles)
   );
// Initialize Inputs
      initial begin
		CLK = 0;
		Reset = 1;
		Input = inputOne;
		#(2*HALF_PERIOD);
		Reset = 0;
		ResetCount = 0;
	end
		
		
		
endmodule
