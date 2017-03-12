__kernel void multiply (__global char *S, int len, __global char *RS) {
	size_t i = get_global_id(0);
	char x = S[i];
	__constant char *vowels = "AEIOUaeiou";
	int vowel = 0;
	for (int j = 0; j < 10; ++j) {
		vowel |= (x == vowels[j]);
	}
	if (vowel) {
		RS[i] = x & ~('a' - 'A');
	} else {
		RS[i] = x + ((x >= 'A' && x <= 'Z') ? 32 : 0);
	}
}
