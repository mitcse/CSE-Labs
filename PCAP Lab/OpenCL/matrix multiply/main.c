/**
 *	Parallel matrix multiplication in OpenCL
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <OpenCL/opencl.h>


////////////////////////////////////////////////////////////////////////////////

// Use a static data size for simplicity
#define DATA_SIZE (1024)

////////////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv) {
	
	int err;                            // error code returned from api calls

	cl_platform_id platform_id;			// compute platform id
	cl_device_id device_id;				// compute device id
	cl_context context;					// compute context
	cl_command_queue command_queue;		// compute command queue
	cl_program program;					// compute program
	cl_kernel kernel;					// compute kernel
	
	cl_mem mem_a;						// device memory used for the input array
	cl_mem mem_b;						// device memory used for the input array
	cl_mem mem_c;						// device memory used for the input array
	
	int ma, na, mb, nb;					// dimensions of matrix A and B
	
	int i = 0;
	
	ma = 3;
	na = 3;
	
	mb = 3;
	nb = 3;
	
	// Ain't no body got time to take input :p
//	int *a = (int *)calloc(ma * na, sizeof(int));
//	int *b = (int *)calloc(mb * nb, sizeof(int));
	
	int A[9] = {1, -3, 4, 2, 0, 7, -5, -6, 9};
	int B[9] = {0, 1, -6, -8, 2, 0, -3, 1, 1};
	
	int *C = (int *)calloc(ma * nb, sizeof(int));
	
	// 1. Load the kernel code for the glory of the Sontaran Empire
	
	FILE *kernel_code_file = fopen("kernel.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}
	
	char *source_str = (char *)malloc(DATA_SIZE);
	size_t source_size = fread(source_str, 1, DATA_SIZE, kernel_code_file);
	source_str[source_size] = '\0'; // VERY IMPORTANT, cause random C stuff.
	
	fclose(kernel_code_file);
	
	
	
	// 2. Get platform and device information (Connect to a compute device)
	
	err = clGetPlatformIDs(1, &platform_id, NULL);
	err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to create a device group!\n");
		return EXIT_FAILURE;
	}
	
	
	
	// 3. Create an OpenCL context
	
	context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	
	if (!context) {
		printf("Error: Failed to create a compute context!\n");
		return EXIT_FAILURE;
	}

	
	
	// 4. Create a command queue
	
	command_queue = clCreateCommandQueue(context, device_id, 0, &err);
	
	if (!command_queue) {
		printf("Error: Failed to create a command commands!\n");
		return EXIT_FAILURE;
	}
	
	
	
	// 5. Create memory buffers on the device for the kernel args
	
	mem_a = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * ma * na, NULL, NULL);
	mem_b = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(int) * mb * nb, NULL, NULL);
	mem_c = clCreateBuffer(context,  CL_MEM_WRITE_ONLY,  sizeof(int) * na * mb, NULL, NULL);
	
	if (!mem_a || !mem_b || !mem_c) {
		printf("Error: Failed to allocate device memory!\n");
		exit(1);
	}
	
	
	
	// 6. Write the memory contents to the device memory
	
	err  = 0;
	err  = clEnqueueWriteBuffer(command_queue, mem_a, CL_TRUE, 0, sizeof(int) * ma * na, A, 0, NULL, NULL);
	err |= clEnqueueWriteBuffer(command_queue, mem_b, CL_TRUE, 0, sizeof(int) * mb * nb, B, 0, NULL, NULL);
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to write to source array!\n");
		exit(1);
	}
	
	
	
	// 7. Create a program from kernel source
	
	program = clCreateProgramWithSource(context, 1, (const char **)&source_str, NULL, &err);
	
	if (!program) {
		printf("Error: Failed to create compute program!\n");
		return EXIT_FAILURE;
	}
	
	

	// 8. Build the kernel program executable
	
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	
	if (err != CL_SUCCESS) {
		size_t len;
		char buffer[2048];
		printf("Error: Failed to build program executable!\n");
		clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
		printf("%s\n", buffer);
		exit(1);
	}

	
	
	// 9. Create the OpenCL kernel object in the program we wish to run
	
	kernel = clCreateKernel(program, "multiply", &err);
	
	if (!kernel || err != CL_SUCCESS) {
		printf("Error: Failed to create compute kernel!\n");
		exit(1);
	}
	
	
	
	// 10. Set the arguments to our compute kernel
	
	err  = 0;
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_a);
	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &mem_b);
	err |= clSetKernelArg(kernel, 2, sizeof(int), &na);
	err |= clSetKernelArg(kernel, 3, sizeof(int), &mb);
	err |= clSetKernelArg(kernel, 4, sizeof(cl_mem), &mem_c);
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to set kernel arguments! %d\n", err);
		exit(1);
	}

	
	
	// 11. Execute the kernel on device
	
	size_t global_work_size[2] = {na, mb}; // That many work items should be there
	size_t local_work_size[2] = {1, 1};
	
	err = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_work_size, local_work_size, 0, NULL, NULL);
	
	if (err) {
		printf("Error: Failed to execute kernel!\n");
		return EXIT_FAILURE;
	}

 	clFinish(command_queue); // Wait for the command commands to get serviced before reading back results

	
	
	// 12. Read the memory buffer from the device memory and copy to local memory
	
	err = clEnqueueReadBuffer(command_queue, mem_c, CL_TRUE, 0, sizeof(int) * na * mb, C, 0, NULL, NULL );
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to read output array! %d\n", err);
		exit(1);
	}
	
	
	printf("\nA:\n");
	for (i = 0; i < ma * na; ++i) {
		printf("\t%d", A[i]);
		if (i % ma == ma - 1)
			printf("\n");
	}
	
	printf("\nB:\n");
	for (i = 0; i < mb * nb; ++i) {
		printf("\t%d", B[i]);
		if (i % mb == mb - 1)
			printf("\n");
	}
	
	printf("\nA x B:\n");
	for (i = 0; i < na * mb; ++i) {
		printf("\t%d", C[i]);
		if (i % na == na - 1)
			printf("\n");
	}
	printf("\n\n");
	
	
	// 13. Clean shit up
	
	clReleaseMemObject(mem_a);
	clReleaseMemObject(mem_b);
	clReleaseMemObject(mem_c);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	return 0;
	
}

