module prog2b(x1, x2, x3, f);
input x1, x2, x3;
output f;
// assign f = (x1^x2)^x3;
assign f = (x1|x2|x3)&(~x1|~x2|x3)&(~x1|x2|~x3)&(x1|~x2|~x3);
endmodule
