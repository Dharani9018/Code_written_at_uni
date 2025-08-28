/*Smart Light with Occupancy + Ambient

Inputs: L (ambient light low), P (person present), O (override ON)

Output: X (light ON)

Spec: X = 1 if (L=1 AND P=1) OR O=1.

Constraint: Implement using only NAND gates.
*/
module nand_gate (A,B,C);
  input A,B;
  output C;
  assign C = !(A&B);
endmodule

module nand_implement(L,P,O,X);
  input L,P,O;
  output X;
  wire w1,w2;
  nand_gate F1(L,P,w1);
  nand_gate F2(O,O,w2);
  nand_gate F3(w1,w2,X);
endmodule



