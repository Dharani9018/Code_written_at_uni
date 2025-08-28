module test_bench;
  wire X;
  reg L,P,O;

  nand_implement F(L,P,O,X);

  initial begin
    L = 1'b0; P = 1'b0; O = 1'b0; #20;
    L = 1'b0; P = 1'b0; O = 1'b1; #20;
    L = 1'b0; P = 1'b1; O = 1'b0; #20;
    L = 1'b0; P = 1'b1; O = 1'b1; #20;
    L = 1'b1; P = 1'b0; O = 1'b0; #20;
    L = 1'b1; P = 1'b0; O = 1'b1; #20;
    L = 1'b1; P = 1'b1; O = 1'b0; #20;
    L = 1'b1; P = 1'b1; O = 1'b1; #20;
  end

  initial begin
    $monitor($time, "L=%b, P=%b, O=%b, X=%b",L,P,O,X);
  end

  initial begin
    $dumpfile("dumpfile.vcd");
    $dumpvars(1,test_bench);
  end

endmodule
    
