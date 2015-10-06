module prog3 (i, f1, f2);
	input [2:0] i; // A, B, C
	output f1, f2;
	wire [3:0] w1, w2;
	assign w1[0] = 1, w1[1] = 1, w1[2] = ~i[2], w1[3] = i[2];
	assign w2[0] = 1, w2[1] = ~i[2], w2[2] = 0, w2[3] = i[2];
	mux4_1 m1 (w1, i[1:0], f1);
	mux4_1 m2 (w2, i[1:0], f2);
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
