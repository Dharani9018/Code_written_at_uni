module TB;
  reg S,I;
  wire y1,y2;
  initial begin
    $dumpfile("demux_test.vcd");
    $dumpvars(0,TB);
  end;
  demux F(.S(S), .I(I), .y1(y1), .y2(y2));

  initial begin
    S = 1'b0;    I = 1'b0;
    #5 S = 1'b0;I = 1'b0;
    #5 S = 1'b0;I = 1'b1;
    #5 S = 1'b0;I = 1'b1;
    #5 S = 1'b1;I = 1'b0;
    #5 S = 1'b1;I = 1'b0;
    #5 S = 1'b1;I = 1'b1;
    #5 S=1'b1;I = 1'b1;  
  end
  initial begin
    $monitor($time, "S = %b, I = %b, y1 = %b, y2 = %b",S,I,y1,y2);
  end
endmodule
