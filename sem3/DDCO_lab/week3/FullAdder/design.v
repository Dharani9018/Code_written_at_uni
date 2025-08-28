module fulladd(a,b,c,sum,cout);
  input a,b,c;
  output sum,cout;
  wire [4:0]w;
  xor S1(w[0],a,b);
  xor S2(sum,w[0],c);
  and C1(w[1],a,c);
  and C2(w[2],a,b);
  and C3(w[3],b,c);
  or C4(w[4],w[1],w[2]);
  or C5(cout,w[3],w[4]);
endmodule
