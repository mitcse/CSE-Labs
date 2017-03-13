__kernel void operate (__global int *A, int M, int N) {
	int i = get_global_id(0);
	int j = get_global_id(1);
	int k;
	int x = A[i * M + j];
	int p = x;
	for (k = 1; k <= i; ++k) {
		p *= x;
	}
	A[i * M + j] = p;
}
