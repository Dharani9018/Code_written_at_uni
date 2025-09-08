`timescale 1ns/1ps
module tb_jk_ff;   
 reg j, k, clk;   
 wire q;   
 // Instantiate JK flip-flop 
 jk_ff    jk1 (.j(j),.k(k),.clk(clk),.q(q));  
  // Generate clock
 initial begin   
  clk = 0;      
 forever #5 clk = ~clk;   // Clock period = 10 ns   
 end
 // Test sequence    
 initial begin        // Monitor outputs   
  $monitor("Time=%0t | J=%b K=%b | Q=%b", $time, j, k, q);      
   // Initialize        j = 0; k = 0;       
  // Apply inputs on different clock edges      
  #10 j = 0; k = 0;   // Hold  
  #10 j = 0; k = 1;   // Reset  
  #10 j = 1; k = 0;   // Set       
  #10 j = 1; k = 1;   // Toggle   
  #10 j = 1; k = 1;   // Toggle again       
  #10 j = 0; k = 1;   // Reset        
  #10 j = 1; k = 0;   // Set      
  #20 $finish;    
  end

  initial begin  
    $dumpfile("tb_jk_ff.vcd");   
    $dumpvars(0, tb_jk_ff);  
  end

endmodule


