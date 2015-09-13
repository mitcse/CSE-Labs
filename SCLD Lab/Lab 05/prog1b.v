module prog1b (x, y, cin, s, c);
input x, y, cin;
output s, c;
assign s = x^y^cin;
assign c = x&y|y&cin|cin&x;
endmodule
