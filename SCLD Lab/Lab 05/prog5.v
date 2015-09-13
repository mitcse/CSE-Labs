module prog5 (a, b, cin, cx, r);
input [3:0] a, b;
input cin;
output [3:0] r;
output cx;
wire [3:0] t, u;
wire co, cxo;
fourbitadder f1(t, co, a, b, cin);
assign cx = co|(t[3]&t[2])|(t[3]&t[1]);
assign u[0] = 0;
assign u[1] = cx;
assign u[2] = cx;
assign u[3] = 0;
fourbitadder f2(r, cxo, t, u, 0);
endmodule

module fourbitadder(s, cout, x, y, m);
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
