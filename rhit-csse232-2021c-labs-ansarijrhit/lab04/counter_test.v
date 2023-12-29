`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
// Names: Jordan Ansari, Hunter Masur
//
// Create Date:   10:12:10 04/07/2021
// Design Name:   counter_A
// Module Name:   C:/Users/ansarij/Documents/232Classwork/Xilinx/counter/counter_test.v
// Project Name:  counter
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: counter_A
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module counter_test;

	// Inputs
	reg direction;
	reg reset;
	reg CLK;

	// Outputs
	wire signed [5:0] dout;

	parameter HALF_PERIOD = 50;

	integer cycle_counter = 0;
	integer counter = 0;
	integer failures = 0;

	initial begin
		 CLK = 0;
		 forever begin
			  #(HALF_PERIOD);
			  CLK = ~CLK;
		 end
	end

	// Instantiate the Unit Under Test (UUT)
	counter_E unit_under_test (
		.direction(direction), 
		.reset(reset), 
		.CLK(CLK), 
		.dout(dout)
	);

	initial begin
		// Initialize Inputs
		direction = 0;
		reset = 1;
		CLK = 0;

		// Wait 100 ns for global reset to finish
		#(50*HALF_PERIOD);
		reset = 0;
		
        
		// Add stimulus here
		
		//-----TEST 1-----
		//Testing counting up 
		$display("Testing counting up.");
		reset = 1;
		counter = 0;
		cycle_counter = 0;
		#(2*HALF_PERIOD);
		reset = 0;
		direction = 0; //we are testing counting up
		
		repeat (40) begin
			 #(2*HALF_PERIOD);
			 counter = counter + 1;
			 if (cycle_counter == 31)
					counter = -32;
			 cycle_counter = cycle_counter + 1;
			 //$display("%t Cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 if (dout != counter) begin
				 failures = failures + 1;
				 $display("%t (COUNT UP) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 end
		end
		
		//-----TEST 2-----
		//Testing counting down
		$display("Testing counting down.");
		reset = 1;
		counter = 0;
		cycle_counter = 0;
		#(2*HALF_PERIOD);
		reset = 0;
		direction = 1; //we are testing counting down
		
		repeat (40) begin
			 #(2*HALF_PERIOD);
			 counter = counter - 1;
			 if (cycle_counter == 32)
					counter = 31;
			 cycle_counter = cycle_counter + 1;
			 //$display("%t Cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 if (dout != counter) begin
				 failures = failures + 1;
				 $display("%t (COUNT DOWN) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 end
		end
		
		//-----TEST 3-----
		//Testing direction
		$display("Testing direction.");
		reset = 1;
		counter = 0;
		cycle_counter = 0;
		#(2*HALF_PERIOD);
		reset = 0;
		direction = 0; //the direction appears to be flipped in C
		
		repeat (20) begin
			 #(2*HALF_PERIOD);
			 counter = counter + 1;
			 cycle_counter = cycle_counter + 1;
			 //$display("%t Cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 if (dout != counter) begin
				 failures = failures + 1;
				 $display("%t (COUNT UP) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 end
		end
		direction = 1;
		//Begin counting down
		$display("Counting down now.");
		repeat (20) begin
			 #(2*HALF_PERIOD);
			 counter = counter - 1;
			 cycle_counter = cycle_counter + 1;
			 //$display("%t Cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 if (dout != counter) begin
				 failures = failures + 1;
				 $display("%t (COUNT DOWN) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			 end
		end
		#(2*HALF_PERIOD);
		direction = 0;
		
		//-----TEST 4-----
		//Testing clock
		$display("Testing clock.");
		reset = 1;
		counter = dout;
		cycle_counter = 0;
		#(2*HALF_PERIOD);
		reset = 0;
		direction = 0; //we want to count up here
		
		repeat (20) begin
			counter = counter + 1;
			if (dout != counter) begin
				failures = failures + 1;
				$display("%t (FALLING EDGE) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			end
			#(HALF_PERIOD);
			cycle_counter = cycle_counter + 1;
			//$display("%t Cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			if (dout != counter) begin
				failures = failures + 1;
				$display("%t (RISING EDGE) Error at cycle %d, output = %d, expecting = %d", $time, cycle_counter, dout, counter);
			end
			#(HALF_PERIOD);
		end
		
		
		//-----TEST 5-----
		//Testing reset
		$display("Testing reset.");
		if (dout == 0) begin
			repeat (5) begin
				#(2*HALF_PERIOD);
				counter = counter + 1;
				cycle_counter = cycle_counter+1;
			end
		end
		reset = 1;
		counter = 0;
		cycle_counter = 0;
		#(2*HALF_PERIOD);
		reset = 0;
		direction = 0;
		if (dout != 0) begin
			failures = failures + 1;
			$display("%t Error: dout did not reset", $time);
		end
		reset = 0;
				
		$display("TESTS COMPLETE. \n Failures = %d", failures);
	end
      
endmodule

