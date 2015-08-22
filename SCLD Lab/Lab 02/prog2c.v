module prog2c (x1, x2, x3, f1, f2);
input x1, x2, x3;
output f1, f2;

// f1 for "NOR ONLY"
// f2 for "NAND ONLY"

nor (x11, x1);
nor (x31, x3);
nor (a1, x2, x1);
nor (b1, x31, x11);
nor (f1, a1, b1);

nand (x12, x1);
nand (x32, x3);
nand (a2, x2, x12);
nand (b2, x1, x32);
nand (f2, a2, b2);

endmodule
