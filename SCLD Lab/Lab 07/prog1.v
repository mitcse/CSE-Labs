module prog1 (b, g);
	input [3:0] b;
	output [3:0] g;
	wire [7:0] w0, w1, w2;
	assign w2 = 8'b00111100;
	assign w1 = 8'b01100110;
	/*
	integer i; 
	for (i= 0; i< 8; i= i+ 1)
	  begin
	    w0[i] = (i%2==0)?b[0]:~b[0];
	  end
	*/	
	assign w0[0]=b[0], w0[1]=~b[0], w0[2]=b[0], w0[3]=~b[0], w0[4]=b[0], w0[5]=~b[0], w0[6]=b[0], w0[7]=~b[0];
	mux8_1 m0 (w0, b[3:1], g[0]);
	mux8_1 m1 (w1, b[3:1], g[1]);
	mux8_1 m2 (w2, b[3:1], g[2]);
	assign g[3] = b[3];
endmodule

module mux8_1 (w, t, f);
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

