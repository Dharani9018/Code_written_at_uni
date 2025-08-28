module not_test;
	reg a;  wire y;
	not_gate meow(y,a);  
	initial
	begin
		#0 a=0;
		#10 a=1;
	end

	initial  
	begin
		$monitor($time, "a=%b, y=%b", a,y);
	end

	initial
	begin
		$dumpfile ("not_test.vcd");
		$dumpvars (0, not_test);
	end

endmodule



