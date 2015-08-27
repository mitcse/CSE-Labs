module prog2(f, a, b, c, d);
input a, b, c, d;
output f;
assign f = (~b&~d)|(c&~d)|(a&b&~c&d);
endmodule
