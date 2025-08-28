/*NAND_gate*/
module nand_gate(y,a,b);
input a,b;
output y;
assign y= !(a & b);
endmodule







