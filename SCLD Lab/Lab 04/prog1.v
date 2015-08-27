module prog1 (a, b, c, d, f);
input a, b, c, d;
output f;
nor (b1, b);
nor (d1, d);
nor (a1, a);
nor (k, b1, d);
nor (l, a1, d1);
nor (f, k, l);
endmodule
