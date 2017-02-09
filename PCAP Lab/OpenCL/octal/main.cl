__kernel void octal_conv (__global int *A, __global int *B) {

	int i = get_global_id(0);

	int dec = A[i];
	int oct = 0, r, p = 1;
	while (dec != 0) {
		r = dec % 8;
		oct = oct + p * r;
		dec /= 8;
		p *= 10;
	}
	B[i] = oct;

}