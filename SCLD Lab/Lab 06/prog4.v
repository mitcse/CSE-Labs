module prog4(w, t, f);
input [3:0] w;
input [1:0] t;
output f;
reg f;
always @(w or t)
f = t[1]?(t[0]?w[3]:w[2]):(t[0]?w[1]:w[0]);
endmodule


