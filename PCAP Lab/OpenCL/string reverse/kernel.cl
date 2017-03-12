__kernel void reverse (__global char *S, int len) {
	size_t i = get_global_id(0);
	char t = S[len - 1 - i];
	S[len - 1 - i] = S[i];
	S[i] = t;
}
