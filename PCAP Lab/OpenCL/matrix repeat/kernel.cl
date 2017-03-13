__kernel void operate (__global int *A, int count, __global int *B) {
	int i = get_global_id(0);
	int j = get_global_id(1);
	int x = A[i * count + j];
	int ind = i * count + j;
	int k;
	for (k = 0; k < count * count; ++k) {
		B[ind * count * count + k] = x;
	}
}
