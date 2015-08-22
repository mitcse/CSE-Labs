module prog2a(a, b, c, y1, y2);
input a, b, c;
output y1, y2;
not (a1, a);
not (b1, b);
not (c1, c);
and (z1, a, b, c);
and (z2, a, b, c1);
and (z3, a, b1, c);
and (z4, a1, b, c);
or (y1, z1, z2, z3, z4);

nand (a2, a, a);
nand (b2, b, b);
nand (c2, c, c);
nand (n1, a, b, c);
nand (n2, a, b, c2);
nand (n3, a, b2, c);
nand (n4, a2, b, c);
nand (y2, n1, n2, n3, n4);

endmodule
