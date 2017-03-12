__kernel void multiply (__global char *S, int n, int len, __global char *RS) {
	size_t id = get_global_id(0);
	int i;
	for (i = id; i < len * n; i += len) {
		RS[i] = S[id];
	}
}
