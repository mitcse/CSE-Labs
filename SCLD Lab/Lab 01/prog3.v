module prog3(x1, x2, x3, x4, f1, f2);
input x1, x2, x3, x4;
output f1, f2;
assign f1 = (x1&x3)|(x2&x3)|(x3&x4)|(x1&x2)|(x1&x4);
assign f2 = (x1|x3)&(x1|x2|x4)&(x2|x3|x4);
endmodule
