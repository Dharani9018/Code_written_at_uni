module dec2to4 (input wire [1:0] a, input wire en, output wire [3:0] y);
  assign y[0] =(!a[0])&(!a[1]);
  assign y[1] = (!a[0])&(a[1]);
  assign y[2] = a[0]&(!a[1]);
  assign y[3] = a[0]&a[1];
endmodule

