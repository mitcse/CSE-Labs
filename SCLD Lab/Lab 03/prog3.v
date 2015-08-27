module prog3(f, a, b, c, d);
input a, b, c, d;
output f;
assign f = (b|d)&(~a|b)&(a|~c|~d)&(~a|c|~d);
endmodule
