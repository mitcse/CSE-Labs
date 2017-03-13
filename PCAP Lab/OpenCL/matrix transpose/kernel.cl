__kernel void transpose (__global int *A, int M, int N, __global int *B) {
	int i = get_global_id(0);
	int j = get_global_id(1);
//	printf("B[%d] = A[%d] = %d\n", j * N + i, i * M + j, A[i * M + j]);
	B[j + N * i] = A[i + M * j];
}
