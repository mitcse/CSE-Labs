module prog5(w, t, f);
input [7:0] w;
input [2:0] t;
output f;
reg f;
always @(w or t)
	if(t == 0)
		f = w[0];
	else if (t == 1)
		f = w[1];
	else if (t == 2)
		f = w[2];
	else if (t == 3)
		f = w[3];
	else if (t == 4)
		f = w[4];
	else if (t == 5)
		f = w[5];
	else if (t == 6)
		f = w[6];
	else
		f = w[7];
endmodule

