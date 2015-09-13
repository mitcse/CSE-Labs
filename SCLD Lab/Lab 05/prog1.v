module prog1 (x, y, s, c);
input x, y;
output s, c;
assign s = x^y;
assign c = x&y;
endmodule
