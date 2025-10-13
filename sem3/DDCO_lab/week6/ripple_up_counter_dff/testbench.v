`timescale 1ns/1ps

module tb_ripple_up_counter_2bit;
  reg clk;
  reg rst;
  wire [1:0] q;

  // DUT instantiation
  ripple_up_counter_2bit dut (
    .clk(clk),
    .rst(rst),
    .q(q)
  );

  // Clock generator: 10ns period
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  // Stimulus
  initial begin
    // Dump waves (for GTKWave or any viewer)
    $dumpfile("ripple_up_counter_2bit.vcd");
    $dumpvars(0, tb_ripple_up_counter_2bit);

    // Apply reset
    rst = 1;
    #10;
    rst = 0;

    // Run for a few cycles
    #100;

    // Finish simulation
    $finish;
  end

  // Monitor outputs
  initial begin
    $monitor("Time=%0t | clk=%b rst=%b | q=%b",
              $time, clk, rst, q);
  end
endmodule

