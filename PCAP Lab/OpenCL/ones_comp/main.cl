__kernel void octal_conv (__global int *A, __global int *B) {

	int i = get_global_id(0);

	int bin = A[i];
	int ones = 0;
	int b;
	while (bin > 0) {
		b = bin % 10;
		ones = ones * 10 + (b == 0);
		bin /= 10;
	}
	B[i] = ones;

}