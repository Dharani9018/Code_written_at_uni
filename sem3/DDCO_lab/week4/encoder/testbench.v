module TB;
  reg [0:3] A;
  wire [1:0] B;

  initial begin
    $dumpfile("Enc_test.vcd");
    $dumpvars(0,TB);
  end

  Encode4to2 new(.a(A),.b(B));
  initial begin
    $monitor("Time=%0t | A=%b | B=%b",$time,A,B);
  end

  initial begin
    A = 4'b1000; #5;
    A = 4'b0100; #5;
    A = 4'b0010; #5;
    A = 4'b0001; #5;
  end

endmodule


  

