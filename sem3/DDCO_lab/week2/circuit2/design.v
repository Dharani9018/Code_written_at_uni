module simple_circuit  (A, B, C, D);
output D;  
input A, B, C;  
wire w1;
and G1 (w1,C,B); // Optional  gate instance name
or G3 ( D, w1 ,A);
endmodule

