`timescale 1ns/1ps
`define TESTVECS 10

module tb;  
  reg [3:0] i0, i1;
  reg cin;  
  wire [3:0] o; 
  wire cout; 
  reg [8:0] test_vecs [0:(`TESTVECS-1)];  
  integer i;

  Ripple u0(i0, i1, cin, o, cout);

  initial begin 
    $dumpfile("rca_test.vcd"); 
    $dumpvars(0,tb);  

    // preload test vectors
    test_vecs[0] = 9'b000000000;   
    test_vecs[1] = 9'b000000001; 
    test_vecs[2] = 9'b000100010;  
    test_vecs[3] = 9'b000100011;    
    test_vecs[4] = 9'b001000100;  
    test_vecs[5] = 9'b001000101;  
    test_vecs[6] = 9'b101010110; 
    test_vecs[7] = 9'b101010111;
    test_vecs[8] = 9'b111011110;
    test_vecs[9] = 9'b111011111;

    // apply all test vectors
    for(i=0; i<`TESTVECS; i=i+1) begin
      {i0, i1, cin} = test_vecs[i];
      #10; // wait 10ns so outputs can settle
      $display("Time=%t | i0=%b i1=%b cin=%b -> sum=%b cout=%b", 
               $time, i0, i1, cin, o, cout);
    end

    #10 $finish;
  end
endmodule

