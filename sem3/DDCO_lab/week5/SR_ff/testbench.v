module TB_SR; 
    reg S, R, CLK, RST;
    wire Q;

    // Instantiate SR flip-flop
    sr_ff uut (.S(S), .R(R), .clk(CLK), .rst(RST), .Q(Q));

    // Clock generation: 10 time unit period
    initial begin
        CLK = 1'b0;
        forever #5 CLK = ~CLK;
    end

    // Waveform dump
    initial begin
        $dumpfile("sr_ff.vcd");
        $dumpvars(0, TB_SR);
    end

    // Monitor
    initial begin
        $monitor("Time=%0t | RST=%b | S=%b | R=%b | Q=%b", $time, RST, S, R, Q);
    end

    // Stimulus
    initial begin
        RST = 1'b1; S = 0; R = 0; #7;   // Reset asserted
        RST = 1'b0; #8;                 // Release reset

        S = 1; R = 0; #20;              // Set
        S = 0; R = 1; #20;              // Reset
        S = 0; R = 0; #20;              // Hold
        S = 1; R = 1; #20;              // Invalid state (Q=x)

        RST = 1; #10;                   // Async reset again
        RST = 0; #10;

        $finish;
    end

endmodule

