module prog2(x1, x2, x3, f);
input x1, x2, x3;
output f;
not(x11, x1);
not(x21, x2);
not(x31, x3);
or(y1, x1, x2, x3);
or(y2, x11, x21, x3);
or(y3, x11, x2, x31);
or(y4, x1, x21, x31);
and(f, y1, y2, y3, y4);
endmodule
