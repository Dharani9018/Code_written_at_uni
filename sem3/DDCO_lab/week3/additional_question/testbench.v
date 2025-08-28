`timescale 1ns/1ps

module tb_bcd_adder;
    reg  [3:0] a, b;
    reg        cin;
    wire [3:0] sum, tens;
    wire       cout;

    // Instantiate DUT
    bcd_adder uut (
        .a(a), .b(b), .cin(cin),
        .sum(sum), .tens(tens), .cout(cout)
    );

    integer i, j, k;

    initial begin
        $dumpfile("bcd_adder_tb.vcd");   // for waveform view
        $dumpvars(0, tb_bcd_adder);

        // Loop through all valid inputs
        for (i = 0; i <= 9; i = i + 1) begin
            for (j = 0; j <= 9; j = j + 1) begin
                for (k = 0; k <= 1; k = k + 1) begin
                    a   = i;
                    b   = j;
                    cin = k;
                    #5; // wait for result

                    $display("a=%d b=%d cin=%d => tens=%d sum=%d cout=%d",
                             a, b, cin, tens, sum, cout);
                end
            end
        end

        $finish;
    end
endmodule

