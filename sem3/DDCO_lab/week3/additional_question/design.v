
  /*  Design a digital system that adds two decimal digits represented in BCD format and outputs the result in BCD. Explain the need for correction in the result and implement it in Verilog.

What should be verified in simulation?
*/
// BCD Adder
module bcd_adder(
    input  [3:0] a, b,   // two BCD digits (0–9)
    input        cin,    // carry in
    output [3:0] sum,    // BCD ones digit
    output [3:0] tens,   // BCD tens digit
    output       cout    // carry out
);

    wire [4:0] binary_sum;     // can go up to 19
    wire [4:0] corrected_sum;

    // Step 1: Normal binary addition
    assign binary_sum = a + b + cin;

    // Step 2: Apply correction if needed
    assign corrected_sum = (binary_sum > 9) ? (binary_sum + 5'd6) : binary_sum;

    // Step 3: Extract BCD digits
    assign sum  = corrected_sum[3:0]; // ones place
    assign tens = corrected_sum[4];   // tens place (only 0 or 1 possible)
    assign cout = corrected_sum[4];   // same as tens

endmodule

  
  
