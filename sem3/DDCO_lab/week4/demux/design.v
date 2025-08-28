module demux(input wire S,I, output wire y1,y2);
  assign y1 =  ((!S) & I);
  assign y2 = (S & I);
endmodule
