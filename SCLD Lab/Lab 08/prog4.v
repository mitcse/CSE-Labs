module prog4 (w, en, y);
	input [3:0] w;
	input en;
	output [15:0] y;
	wire [1:0] m;
	assign m[0] = ~w[3] & en;
	assign m[1] = w[3] & en;
	dec3_8 d1 (w[2:0], y[7:0], m[0]);
	dec3_8 d2 (w[2:0], y[15:8], m[1]);
endmodule

module dec3_8 (w, y, en);
	input [2:0] w;
	input en;
	output [7:0] y;
	reg [7:0] y;
	integer k;
	always @(w or en)
	begin
		for (k = 0; k < 8; k = k + 1)
		begin
			if (w == k && en)
				y[k] = 1;
			else
				y[k] = 0;
		end
	end 
endmodule
