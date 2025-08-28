module halfadd(a, b,sum, cout);
  input a, b;
  output sum, cout;
  xor S(sum,a,b);    
  and C(cout,a,b);  
endmodule

