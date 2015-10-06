module prog4 (b, g);
	input [3:0] b;
	output [3:0] g;
	wire [3:0] w0, w1, w2;
	wire [1:0] m;
	assign m[1] = b[3], m[0] = b[2];
	assign w2[0] = 0, w2[1] = b[1]|b[0], w2[2] = 1, w2[3] = 1;
	assign w1[0] = 0, w1[1] = b[1]|(~b[0]), w1[2] = 1, w1[3] = 1;
	assign w0[0] = b[1], w0[1] = ~(b[1])&b[0], w0[2] = 1, w0[3] = 1;
	mux4_1 m0 (w2, m, g[3]);
	mux4_1 m1 (w1, m, g[2]);
	mux4_1 m2 (w0, m, g[1]);
	assign g[0] = b[0];
endmodule

module mux4_1 (w, t, f);
input [3:0] w;
input [1:0] t;
output f;
reg f;
always @(w or t)
	if(t == 0)
		f = w[0];
	else if (t == 1)
		f = w[1];
	else if (t == 2)
		f = w[2];
	else
		f = w[3];
endmodule
