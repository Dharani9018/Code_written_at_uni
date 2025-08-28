module Ripple(input wire [3:0] a,input wire [3:0] b, input wire cin,output wire [3:0]sum,output wire cout);
  wire [2:0] c;
  fulladd U0(a[0],b[0],cin,sum[0],c[0]);
  fulladd U1(a[1],b[1],c[0],sum[1],c[1]);
  fulladd U2(a[2],b[2],c[1],sum[2],c[2]);
  fulladd U3(a[3],b[3],c[2],sum[3],cout);
endmodule


