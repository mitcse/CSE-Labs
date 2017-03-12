__kernel void reverse (__global char *S, int len, __global int *indices) {
	size_t id = get_global_id(0);
	int si = indices[id] + 1;
	int ei = indices[id + 1];
	printf("Indices[%d] = %d, %d\n", id, si, ei);
	int i;
	for (i = si; i < (ei + si) / 2; ++i) {
		char t = S[ei + si - 1 - i];
		S[ei + si - 1 - i] = S[i];
		S[i] = t;
	}
}
