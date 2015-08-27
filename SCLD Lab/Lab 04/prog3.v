module prog3(x1, x2, x3, x4, f, g, k);
input x1, x2, x3, x4;
output f, g, k;
assign k = (~x1&~x3&~x4)|(~x2&x3&~x4)|(x1&~x2&~x3&x4);
assign f = k|(~x1&x2&x3);
assign g = k|(x1&x2&x4);
endmodule
