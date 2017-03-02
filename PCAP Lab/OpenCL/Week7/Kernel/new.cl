__kernel void rowOp (__global int *A,int width) {
	int row = get_global_id(0);
	int col = get_global_id(1);
	int i,j;
	
	int val = A[col+width*row];
	for (j=0;j<row;j++)
		A[col+width*row] = val*A[col+width*row];

}

__kernel void q2Op(__global int *A,int height, int width) {
	int row = get_global_id(0);
	int col = get_global_id(1);
	if (row == 0 || row == height-1 || col == 0 || col == width-1) {
	}
	else {
	int val = A[col+ row*width];
	int temp = 0;
	int i = 1;
	while (val>0) {
		temp = temp + (val%2)*i;
		i *= 10;
		val=val/2;
	}
	int temp2 = 0,val2;
	i=1;
	while (temp>0) {
		val2 = temp%10;
		if (val2 == 0)
			temp2 = temp2 + i*1;
		else
			temp2 = temp2;
		temp = temp/10;
		i*=10;
	}
	
	A[col+ row*width] = temp2;
}
	
}

__kernel void q3Op(__global int *A,__global int *B,int height, int width) {
	int row = get_global_id(0);
	int col = get_global_id(1);

	B[row+ col*height] = A[col+ row*width];
}

__kernel void q4Op(__global int *A,__global int *B,int height, int width) {
	int row = get_global_id(0);
	int col = get_global_id(1);

	int sum = 0;
	int i,j;
	for (i=0;i<height;i++) {
		sum+=A[col+width*i];
	}
	for (i=0;i<width;i++) {
		sum+=A[i+width*row];
	}
	B[col + width*row] = sum;
}

