__kernel void transpose (__global int *A, int M, int N, __global int *B) {
	int row = get_global_id(0);
	int col = get_global_id(1);
	int rsum = 0, csum = 0;
	int i;
	for (i = 0; i < N; ++i) {
//		printf("rsum += A[%d] (%d)\n", i + M * row, A[i + M * row]);
		rsum += A[i + M * row];
	}
	for (i = 0; i < M; ++i) {
//		printf("csum += A[%d] (%d)\n", i * N + col, A[i * N + col]);
		csum += A[i * N + col];
	}
//	printf("(row, col) = (%d, %d) = %d | rsum = %d, csum = %d\n", row, col, row * M + col, rsum, csum);
	B[row * M + col] = rsum + csum;
}
