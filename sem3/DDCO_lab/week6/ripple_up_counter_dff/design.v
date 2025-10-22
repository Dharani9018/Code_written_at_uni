module dff (
  input wire clk,
  input wire rst, // async reset, active-high
  input wire d,
  output reg q
);
  always @(posedge clk or posedge rst) begin
    if (rst) 
      q <= 1'b0;
    else 
      q <= d;
  end
endmodule

module ripple_up_counter_2bit (
  input wire clk,
  input wire rst,
  output wire [1:0] q
);
  wire q0, q1;

  // LSB toggles on every clock
  dff ff0 (.clk(clk), .rst(rst), .d(~q0), .q(q0));

  // MSB toggles when Q0 goes from 1 → 0 (falling edge of Q0)
  dff ff1 (.clk(~q0), .rst(rst), .d(~q1), .q(q1));

  assign q = {q1, q0};
endmodule

