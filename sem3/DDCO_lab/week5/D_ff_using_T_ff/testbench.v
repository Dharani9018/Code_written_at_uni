module TB_D_using_T;
    reg D, CLK, RST;
    wire Q;

    // Instantiate D FF (built from T FF)
    d_using_t uut (.D(D), .clk(CLK), .rst(RST), .Q(Q));

    // Clock: 10 time unit period
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;
    end

    // Dump VCD
    initial begin
        $dumpfile("d_using_t.vcd");
        $dumpvars(0, TB_D_using_T);
    end

    // Monitor
    initial begin
        $monitor("Time=%0t | RST=%b | D=%b | Q=%b", $time, RST, D, Q);
    end

    // Stimulus
    initial begin
        RST = 1; D = 0; #7;      // Apply reset
        RST = 0; D = 0; #10;     // Expect Q=0
        D = 1; #10;              // Expect Q=1
        D = 0; #10;              // Expect Q=0
        D = 1; #20;              // Expect Q=1
        D = 1; #10;              // Hold 1
        RST = 1; #5;             // Reset again
        RST = 0; D = 0; #10;     // Back to 0
        $finish;
    end
endmodule

