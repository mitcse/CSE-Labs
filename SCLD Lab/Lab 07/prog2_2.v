module prog2_2 (i, o);
	input [2:0] i; // A, B, C
	output o;
	wire [3:0] w;
	assign w[0] = ~i[2], w[1] = 0, w[2] = 1, w[3] = ~i[2];
	mux4_1 m1 (w, i[1:0], o);
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
