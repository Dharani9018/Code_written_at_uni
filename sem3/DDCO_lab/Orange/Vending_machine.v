module vending_machine_mealy (
    input clk,
    input reset,
    input [1:0] coin,
    output reg dispense,
    output [1:0] present_state_dbg,  // <-- added
    output [1:0] next_state_dbg      // <-- added
);

    // State encoding
    parameter S0  = 2'b00;
    parameter S5  = 2'b01;
    parameter S10 = 2'b10;
    parameter S15 = 2'b11;

    reg [1:0] present_state, next_state;

    // Debug assignments
    assign present_state_dbg = present_state;
    assign next_state_dbg    = next_state;

    // State register
    always @(posedge clk or posedge reset) begin
        if (reset)
            present_state <= S0;
        else
            present_state <= next_state;
    end

    // Next state logic + output (Mealy)
    always @(*) begin
        dispense = 0;
        case (present_state)
            S0: begin
                if (coin == 2'b01) next_state = S5;
                else if (coin == 2'b10) next_state = S10;
                else next_state = S0;
            end
            S5: begin
                if (coin == 2'b01) next_state = S10;
                else if (coin == 2'b10) begin
                    next_state = S15;
                    dispense = 1;
                end else next_state = S5;
            end
            S10: begin
                if (coin == 2'b01) begin
                    next_state = S15;
                    dispense = 1;
                end else if (coin == 2'b10) begin
                    next_state = S15;
                    dispense = 1;
                end else next_state = S10;
            end
            S15: begin
                next_state = S0;
                dispense = 0;
            end
            default: next_state = S0;
        endcase
    end
endmodule

