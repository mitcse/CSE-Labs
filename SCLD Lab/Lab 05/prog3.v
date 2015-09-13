module prog3 (s, cout, x, y, m);
input [3:0] x, y;
input m;
output [3:0] s;
output cout;
wire [3:0] w;
wire [3:1] c;
assign w = y^m;
fulladd f1(x[0], w[0], m,	 s[0], c[1]);
fulladd f2(x[1], w[1], c[1], s[1], c[2]);
fulladd f3(x[2], w[2], c[2], s[2], c[3]);
fulladd f4(x[3], w[3], c[3], s[3], cout);
endmodule

module fulladd (j, k, l, ss, cc);
input j, k, l;
output ss, cc;
assign ss = j^k^l;
assign cc = j&k|k&l|l&j;
endmodule
