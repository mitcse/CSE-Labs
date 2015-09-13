module prog4 (a, b, s);
input [1:0] a, b;
output [3:0] s;
wire [3:0] i;
assign i[1] = a[0]&b[1];
assign i[2] = a[1]&b[0];
assign i[3] = a[1]&b[1];
assign s[0] = a[0]&b[0];
halfadd h1(i[1], i[2], s[1], i[0]);
halfadd h2(i[3], i[0], s[2], s[3]);
endmodule

module halfadd (x, y, ss, cc);
input x, y;
output ss, cc;
assign ss = x^y;
assign cc = x&y;
endmodule
