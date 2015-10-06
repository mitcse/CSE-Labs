module prog1 (w, y, en);
	input [2:0] w;
	input en;
	output [7:0] y;
	reg [7:0] y;
	always @(w or en)
	begin
		if(en == 0)
			y = 8'b11111111;
		else
			case({en, w})
				15: y = 8'b11111110;
				14: y = 8'b11111101;
				13: y = 8'b11111011;
				12: y = 8'b11110111;
				11: y = 8'b11101111;
				10: y = 8'b11011111;
				 9: y = 8'b10111111;
				 8: y = 8'b01111111;
			default: y = 8'b11111111;
			endcase
	end 
endmodule
