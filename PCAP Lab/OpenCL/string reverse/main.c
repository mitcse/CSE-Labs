/**
 *
 *	String reverse
 *
 *	".11/9 DID HSUB" -> "BUSH DID 9/11."
 *
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

	size_t global_work_size;			// global domain size for our calculation
	size_t local_work_size;				// local domain size for our calculation

	cl_platform_id platform_id;			// compute platform id
	cl_device_id device_id;				// compute device id
	cl_context context;					// compute context
	cl_command_queue command_queue;		// compute command queue
	cl_program program;					// compute program
	cl_kernel kernel;					// compute kernel
	
	cl_mem mem_input;					// device memory used for the input array
	
	int i = 0;
	
	// Ain't no body got time to take input :p
	char *inpooot = ".11/9 DID HSUB\0";
	unsigned int len = strlen(inpooot);
	char *outpoot = (char *)malloc(len * sizeof(char));
	
	
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
	
	mem_input = clCreateBuffer(context,  CL_MEM_READ_WRITE,  sizeof(char) * len, NULL, NULL);
	
	if (!mem_input) {
		printf("Error: Failed to allocate device memory!\n");
		exit(1);
	}
	
	
	
	// 6. Write the memory contents to the device memory
	
	err = clEnqueueWriteBuffer(command_queue, mem_input, CL_TRUE, 0, sizeof(char) * len, inpooot, 0, NULL, NULL);
	
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
	
	kernel = clCreateKernel(program, "reverse", &err);
	
	if (!kernel || err != CL_SUCCESS) {
		printf("Error: Failed to create compute kernel!\n");
		exit(1);
	}
	
	
	
	// 10. Set the arguments to our compute kernel
	
	err  = 0;
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_input);
	err |= clSetKernelArg(kernel, 1, sizeof(int), &len);
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to set kernel arguments! %d\n", err);
		exit(1);
	}

	
	
	// 11. Execute the kernel on device
	
	global_work_size = len / 2;
	local_work_size = 1;
	
	printf("Global work size = %li, Local work size = %li\n", global_work_size, local_work_size);
	
	err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_work_size, &local_work_size, 0, NULL, NULL);
	
	if (err) {
		printf("Error: Failed to execute kernel!\n");
		return EXIT_FAILURE;
	}

 	clFinish(command_queue); // Wait for the command commands to get serviced before reading back results

	
	
	// 12. Read the memory buffer from the device memory and copy to local memory
	
	err = clEnqueueReadBuffer(command_queue, mem_input, CL_TRUE, 0, sizeof(char) * len, outpoot, 0, NULL, NULL );
	
	if (err != CL_SUCCESS) {
		printf("Error: Failed to read output array! %d\n", err);
		exit(1);
	}
	
	printf("%s\t|\t%s\n", inpooot, outpoot);
	
	
	
	// 13. Clean shit up
	
	clReleaseMemObject(mem_input);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);

	return 0;
	
}

