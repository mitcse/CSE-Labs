module prog1(x1, y1, z1, l1, r1, x2, y2, z2, l2, r2, a, l3, r3);
input x1, y1, z1, x2, y2, z2, a;
output l1, r1, l2, r2, l3, r3;

assign l1 = x1&(y1|z1);
assign r1 = x1&y1 | x1&z1;

assign l2 = x2|(y2&z2);
assign r2 = (x2&y2)|(x2&z2);

assign l3 = ~(~a);
assign r3 = a;

endmodule
