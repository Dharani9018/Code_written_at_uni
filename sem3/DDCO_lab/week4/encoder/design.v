module Encode4to2 (input wire [0:3] a, output wire [1:0] b);
  assign b[0] = a[3] + a[2];
  assign b[1] = a[3] + a[1];
endmodule
