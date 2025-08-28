module fulladd_tb;
  reg a,b,c;
  wire s,cout;
  fulladd A1(.a(a), .b(b), .c(c), .sum(s), .cout(cout));

  initial begin
    $dumpfile("fulladd_test.vcd");
    $dumpvars(0,fulladd_tb);
  end

   initial begin
    a = 1'b0; b = 1'b0; c = 1'b0; #5;
    a = 1'b0; b = 1'b0; c = 1'b1; #5;
    a = 1'b0; b = 1'b1; c = 1'b0; #5;
    a = 1'b0; b = 1'b1; c = 1'b1; #5;
    a = 1'b1; b = 1'b0; c = 1'b0; #5;
    a = 1'b1; b = 1'b0; c = 1'b1; #5;
    a = 1'b1; b = 1'b1; c = 1'b0; #5;
    a = 1'b1; b = 1'b1; c = 1'b1; #5;
  end 



  initial begin
    $monitor($time, "a=%b, b=%b, c=%b, sum=%b, carry=%b", a, b, c, s, cout);
  end

endmodule


