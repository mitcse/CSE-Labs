
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

// It's a M * N matrix
#define M 6
#define N 3

// Each element is computed on one thread

__global__ void add (int *A, int *B, int *C) {
    // Get the 1D Array index of the matrix
    int idx = blockDim.x * blockIdx.x + threadIdx.x;
    printf("idx = %d\n", idx);
    C[idx] = A[idx] + B[idx];
}

int main () {
    
    // Host copies of the variables
    int A[M * N], B[M * N], C[M * N];

    int i, j;
    for (i = 0; i < M * N; ++i) {
        A[i] = i + 1;
        B[i] = M * N - i - 1;
    }

    // Device copies of the variables
    int *d_a, *d_b, *d_c;

    int size = sizeof(int) * M * N;

    // Allocate memories to device copies of the objects
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    // Copy inputs to device
    cudaMemcpy(d_a, &A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &B, size, cudaMemcpyHostToDevice);

    // Launch kernel onto the device
    add<<<M, N>>>(d_a, d_b, d_c);

    // Copy the result back to the host
    cudaMemcpy(&C, d_c, size, cudaMemcpyDeviceToHost);

    // Outpoooot it
    printf("A:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", A[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("B:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", B[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("A + B:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", C[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

	getchar();

    return 0;
}