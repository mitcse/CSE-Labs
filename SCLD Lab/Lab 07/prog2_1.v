module prog2_1 (inp, out);
	input [3:0] inp; // A, B, C, D;
	output out;
	wire [3:0] w1, w2;
	wire [1:0] o1;
	assign w1[0] = 0, w1[1] = 1, w1[2] = inp[2], w1[3] = ~inp[2];
	assign w2[0] = 0, w2[1] = ~inp[2], w2[2] = 0, w2[3] = ~inp[2];
	mux4_1 m1 (w1, inp[1:0], o1[0]);
	mux4_1 m2 (w2, inp[1:0], o1[1]);
	mux2_1 m3 (o1, inp[3], out);
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

module mux2_1 (w, t, f);
input [1:0] w;
input t;
output f;
assign f = (t==1)?w[1]:w[0];
endmodule
