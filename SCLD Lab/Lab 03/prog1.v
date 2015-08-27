module prog1 (f, a, b, c, d);
input a, b, c, d;
output f;
assign f = (b&d)|(~b&~d)|(~a&b);
endmodule
