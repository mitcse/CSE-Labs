module prog3(w, t, f);
input [3:0] w;
input [1:0] t;
output f;
reg f;
always @(w or t or f)
	if (t == 0)
		f = w[0];
	else if (t == 1)
		f = w[1];
	else if(t == 2)
		f = w[2];
	else
		f = w[3];
endmodule

