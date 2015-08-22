module demo(f, x1, x2, x3);
input x1, x2, x3;
output f;
and(g, x1, x2);
not(h, x2);
and(i, h, x3);
or(f, i, g);
endmodule
