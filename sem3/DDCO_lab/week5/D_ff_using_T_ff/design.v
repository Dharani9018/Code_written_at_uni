module d_using_t (
    input wire D,
    input wire clk,
    input wire rst,
    output wire Q
);
    wire T;
    wire Q_int;   // must be wire, since it's driven by t_ff

    // D to T conversion
    assign T = D ^ Q_int;

    // Internal T flip-flop instance
    t_ff U1 (.T(T), .clk(clk), .rst(rst), .Q(Q_int));

    assign Q = Q_int;   // drive output
endmodule

