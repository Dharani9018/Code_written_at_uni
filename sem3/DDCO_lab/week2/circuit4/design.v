module simple_circuit  (A, B, O, F);
output F;
input A, B, O;  
wire w1;
and G1 (w1,A,B);
or G2 (F,w1,O);
endmodule

