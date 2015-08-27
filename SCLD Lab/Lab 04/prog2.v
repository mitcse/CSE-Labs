module prog2 (a, b, d, f);
input a, b, d;
output f;
nand (d1, d);
nand (b1, b);
nand (ab, a, b1);
nand (f, d1, ab);
endmodule
