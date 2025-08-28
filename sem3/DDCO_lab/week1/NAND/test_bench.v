module nand_test; 
	reg a, b;  wire y;
	nand_gate nand(y,a,b);  /*Instantiates the NAND gate (connects its ports to y, a, and b).*/
	initial
	begin
		#0 a=0;b=0;
		#5 a=0;b=1;    /*procedural block*/
		#10 a=1;b=0;
		#15 a=1;b=1;
	end

	initial  
	begin
		$monitor($time, "a=%b, b=%b, y=%b", a ,b ,y);
	end

	initial
	begin
		$dumpfile ("nand_test.vcd");
		$dumpvars (0, nand_test);
	end

endmodule



