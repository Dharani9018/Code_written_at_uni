`timescale 1ns/1ps

module tb_vending_machine;

    reg clk;
    reg reset;
    reg [1:0] coin;
    wire dispense;

    // Debug wires for state monitoring
    wire [1:0] present_state_dbg;
    wire [1:0] next_state_dbg;

    // Instantiate DUT (make sure your DUT has these debug outputs!)
    vending_machine_mealy uut (
        .clk(clk),
        .reset(reset),
        .coin(coin),
        .dispense(dispense),
        .present_state_dbg(present_state_dbg), // debug state
        .next_state_dbg(next_state_dbg)        // debug next state
    );

    // Clock generation (10 ns period)
    initial clk = 0;
    always #5 clk = ~clk;

    // Reset sequence
    initial begin
        reset = 1;
        #12 reset = 0;   // release reset after some time
    end

    // Stimulus
    initial begin
        $dumpfile("vending_machine_tb.vcd");
        $dumpvars(0, tb_vending_machine);

        // Start with no coin
        coin = 2'b00;

        // Test case 1: 5 + 10 = 15 → should dispense
        #20 coin = 2'b01;  // insert 5
        #20 coin = 2'b10;  // insert 10
        #20 coin = 2'b00;

        // Test case 2: 10 + 5 = 15 → should dispense
        #20 coin = 2'b10;  // insert 10
        #20 coin = 2'b01;  // insert 5
        #20 coin = 2'b00;

        // Test case 3: 10 + 10 = 20 → should dispense and carry 5
        #20 coin = 2'b10;  // insert 10
        #20 coin = 2'b10;  // insert 10
        #20 coin = 2'b00;

        // Test case 4: 5 + 5 + 5 = 15 → should dispense
        #20 coin = 2'b01;  // insert 5
        #20 coin = 2'b01;  // insert 5
        #20 coin = 2'b01;  // insert 5
        #20 coin = 2'b00;

        // Idle for some time
        #50 coin = 2'b00;

        $finish;
    end

    // Simple state monitor
    initial begin
        $monitor("T=%0t | Reset=%b | Coin=%b | State=%b -> Next=%b | Dispense=%b",
                 $time, reset, coin, present_state_dbg, next_state_dbg, dispense);
    end

endmodule

