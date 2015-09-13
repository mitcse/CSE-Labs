module prog2 (x, y, s, cout, cin);
input [3:0] x, y;
input cin;
output [3:0] s;
output cout;
wire [3:1] c;
fulladd stage0 (x[0], y[0], cin, s[0], c[1]);
fulladd stage1 (x[1], y[1], c[1], s[1], c[2]);
fulladd stage2 (x[2], y[2], c[2], s[2], c[3]);
fulladd stage3 (x[3], y[3], c[3], s[3], cout);
endmodule

module fulladd (x, y, cin, s, c);
input x, y, cin;
output s, c;
assign s = x^y^cin;
assign c = x&y|y&cin|cin&x;
endmodule
