/*Air Purifier Mode Selector

Inputs: D1 (PM2.5 high), D2 (VOC high), S (sleep mode), O (override max)

Outputs: F1 (low), F2 (high)

Spec: If O=1 → F2=1 only. Else if D1 OR D2 → F2=1, else if S=1 → F1=1, otherwise OFF.

Constraint: Realize with a 2:1 MUX + minimal glue logic.
We want to design a logic circuit that controls an air purifier’s fan speed (low/high) depending on environmental conditions.

Inputs

D1 → PM2.5 high (dust detected)

D2 → VOC high (bad gases detected)

S → Sleep mode active

O → Override Max (force purifier to max)

Outputs

F1 → Low speed

F2 → High speed
*/

module or_gate(A,B,C);
  input A,B;
  output C;
  assign C = A | B;
endmodule

module air_conditioner(D1,D2,S,O,F1,F2);
  input D1,D2,S,O;
  output reg F1,F2;
  or_gate G1(D1,D2,F2);

  always @(*) begin
      if (O == 1) begin //outputs F1,F2 need to be declared as reg if you drive them in an always block.
        F2 = 1;
      end
  end

    always @(*) begin
      if (S == 1) begin
        F1 = 1;
      end
  end
endmodule





