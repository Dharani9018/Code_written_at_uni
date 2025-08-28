module tb_simple_circuit;
  wire F;
  reg A, B, O;

  simple_circuit M1(A, B, O, F);

  initial begin
    A = 1'b0; B = 1'b0; O = 1'b0; #20;
    A = 1'b0; B = 1'b0; O = 1'b1; #20;
    A = 1'b0; B = 1'b1; O = 1'b0; #20;
    A = 1'b0; B = 1'b1; O = 1'b1; #20;
    A = 1'b1; B = 1'b0; O = 1'b0; #20;
    A = 1'b1; B = 1'b0; O = 1'b1; #20;
    A = 1'b1; B = 1'b1; O = 1'b0; #20;
    A = 1'b1; B = 1'b1; O = 1'b1; #20;
  end

  initial begin
    $monitor($time, " A=%b, B=%b, O=%b, F=%b ", A, B, O, F);
  end

  initial begin
    $dumpfile("tb_simple_circuit.vcd");
    $dumpvars(1, tb_simple_circuit); 
  end
endmodule




