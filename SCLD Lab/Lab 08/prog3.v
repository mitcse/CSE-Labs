module prog3 (w, y, z);
	input [7:0] w;
	output [2:0] y;
	output z;
	reg [2:0] y;
	reg z;
	always @(w)
	begin
		z = 1;
		casex(w)
			8'b1xxxxxxx: y = 7;
			8'b01xxxxxx: y = 6;
			8'b001xxxxx: y = 5;
			8'b0001xxxx: y = 4;
			8'b00001xxx: y = 3;
			8'b000001xx: y = 2;
			8'b0000001x: y = 1;
			8'b00000001: y = 0;
			default:
			begin
				z = 0;
				y = 3'bx;
			end
		endcase
	end
endmodule
