module prog2b (x, y, z, f1, f2);
input x, y, z;
output f1, f2;

// f1 for "NAND ONLY"
// f2 for "NOR ONLY"

nand (y1, y, y);
nand (z1, z, z);
nand (xz1, x, z1);
nand (f1, y1, xz1);

nor (z2, z);
nor (xy2, x, y);
nor (yz2, y, z2);
nor (f2, xy2, yz2);

endmodule
