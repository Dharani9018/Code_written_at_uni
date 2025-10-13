module jk_ff (input wire j, input wire k,input wire clk,  input wire rst,output reg q );
 always @(posedge clk or posedge rst) 
 begin       
  if (rst)     q <= 1'b0;                // Reset to 0       
  else begin
   case ({j, k})             
    2'b00: q <= q;        // No change       
    2'b01: q <= 1'b0;     // Reset       
    2'b10: q <= 1'b1;     // Set            
    2'b11: q <= ~q;       // Toggle          
   endcase
  end
 end 
endmodule

module updown_counter_2bit ( input wire clk, input wire rst, input wire up_down,output wire[1:0] q);  // 1: up, 0: down,
 wire j0, j1, k0, k1;
 assign j0 = 1'b1;
 assign k0 = 1'b1;
 assign j1 = up_down ? q[0] : ~q[0];
 assign k1 = j1;
 
// Flip-flops instantiation
 jk_ff uut(j0,k0,clk,rst,q[0]);
 jk_ff uut2(j1,k1,clk,rst,q[1]);
endmodule

