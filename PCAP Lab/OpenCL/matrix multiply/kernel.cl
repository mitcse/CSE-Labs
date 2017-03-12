__kernel void multiply (__global int *A, __global int *B, int n, int m, __global int *C) {
	size_t r = get_global_id(0);
	size_t c = get_global_id(1);
//	printf("(r, c) = (%d, %d)\n", r, c);
	int sum = 0, i;
	for (i = 0; i < n; ++i) {
//		printf("sum += (A[%d] = %d) * (B[%d] = %d)\n", r * n + i, A[r * n + i], m * i + c, B[m * i + c]);
		sum += (A[r * n + i] * B[m * i + c]);
	}
//	printf("C[%d] = %d\n", r * n + c, sum);
	C[r * m + c] = sum;
}
