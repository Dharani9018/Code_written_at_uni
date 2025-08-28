module simple_circuit  (A, B, C, D);
output D; 
input A, B, C;
wire w1,w2,w3;
and G1 (w1,C,B);
or G2 (w2,A,w1);
and G3 (w3,A,B);
or G4 (D,w3,w2);
endmodule

