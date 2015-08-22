module prog1(x1, x2, x3, x4, f, g, h);
input x1, x2, x3, x4;
output f, g, h;
and(a, x1, x3);
and(b, x2, x4);
not(e1, x3);
not(e2, x2);
or(c, x1, e1);
or(d, e2, x4);
or(g, a, b);
and(h, c, d);
or(f, g, h);
endmodule
