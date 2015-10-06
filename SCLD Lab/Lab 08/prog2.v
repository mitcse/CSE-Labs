module prog2 (w, y, z);
	input [7:0] w;
	output [2:0] y;
	output z;
	reg [2:0] y;
	reg z;
	integer k;
	always @(w)
	begin
		y = 3'bx;
		z = 0;
		for (k = 0; k < 8; k = k + 1)
			if (w[k])
			begin
				y = k;
				z = 1;
			end
	end
endmodule
