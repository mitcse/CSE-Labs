module prog2(w, t, f);
input [15:0]w;
input [3:0]t;
output f;
wire [3:0]m;
mux41 m0(w[15:12], t[1:0], m[3]);
mux41 m1(w[11:8], t[1:0], m[2]);
mux41 m2(w[7:4], t[1:0], m[1]);
mux41 m3(w[3:0], t[1:0], m[0]);
mux41 m4(m[3:0], t[3:2], f);
endmodule

module mux41(w, t, f);
input [3:0]w;
input [1:0]t;
output f;
reg f;
always @(w or t)
f=t[1]?(t[0]?w[3]:w[2]):(t[0]?w[1]:w[0]);
endmodule
