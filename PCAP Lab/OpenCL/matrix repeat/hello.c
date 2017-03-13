/**
 *	OpenCL Demo
 *
 *	Write an OpenCL kernel code that replaces the principal diagonal elements with zero. 
 *	Elements above the principal diagonal by their factorial and elements below the principal diagonal by their sum of digits.
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
//
#define DATA_SIZE (64)

////////////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv) {
	
    int err;                            // error code returned from api calls
      
	int inpooot[DATA_SIZE] = {0};              // original data set given to device
	int outpoot[DATA_SIZE] = {0};          // results returned from device

    size_t global[2];                      // global domain size for our calculation
    size_t local[2];                       // local domain size for our calculation

    cl_device_id device_id;             // compute device id 
    cl_context context;                 // compute context
    cl_command_queue commands;          // compute command queue
    cl_program program;                 // compute program
    cl_kernel kernel;                   // compute kernel
    
    cl_mem mem_obj_inp, mem_obj_out;                     // memory object
    
    // Fill our data set with random float values
    //
	printf("Inpooot:\n");
    int i = 0, j = 0;
    unsigned int count = 2;
	unsigned int scount = count * count;
	for (i = 0; i < count; i++) {
		for (j = 0; j < count; ++j) {
			inpooot[i * count + j] = rand() % 6 + i;
			printf("\t%d", inpooot[i * count + j]);
		}
		printf("\n");
	}
	printf("\n");
	
    // Connect to a compute device
    //
    int gpu = 0;
    err = clGetDeviceIDs(NULL, gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
  
    // Create a compute context 
    //
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context) {
        printf("Error: Failed to create a compute context!\n");
        return EXIT_FAILURE;
    }

    // Create a command commands
    //
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands) {
        printf("Error: Failed to create a command commands!\n");
        return EXIT_FAILURE;
    }

    // Create the compute program from the source buffer
    //
	
	FILE *kernel_code_file = fopen("kernel.cl", "r");
	if (kernel_code_file == NULL) {
		printf("Kernel loading failed.");
		exit(1);
	}
	
	char *source_str = (char *)malloc(1024 * sizeof(char));
	size_t source_size = fread(source_str, 1, 1024, kernel_code_file);
	source_str[source_size] = '\0'; // VERY IMPORTANT, cause random C stuff.
	
	fclose(kernel_code_file);
	
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, NULL, &err);
    if (!program) {
        printf("Error: Failed to create compute program!\n");
        return EXIT_FAILURE;
    }

    // Build the program executable
    //
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }

    // Create the compute kernel in the program we wish to run
    //
    kernel = clCreateKernel(program, "operate", &err);
    if (!kernel || err != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        exit(1);
    }

    // Create the input and output arrays in device memory for our calculation
    //
    mem_obj_inp = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * scount, NULL, NULL);
	mem_obj_out = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * scount * scount, NULL, NULL);
    if (!mem_obj_inp || !mem_obj_out) {
        printf("Error: Failed to allocate device memory!\n");
        exit(1);
    }    
    
    // Write our data set into the input array in device memory 
    //
    err = clEnqueueWriteBuffer(commands, mem_obj_inp, CL_TRUE, 0, sizeof(int) * scount, inpooot, 0, NULL, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to write to source array!\n");
        exit(1);
    }

    // Set the arguments to our compute kernel
    //
    err  = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_obj_inp);
    err |= clSetKernelArg(kernel, 1, sizeof(unsigned int), &count);
	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mem_obj_out);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        exit(1);
    }

    // Get the maximum work group size for executing the kernel on the device
    //
    err = clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to retrieve kernel work group info! %d\n", err);
        exit(1);
    }

    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device
    //
	
	global[0] = count;
	global[1] = count;
	
	local[0] = 1;
	local[1] = 1;
	
    err = clEnqueueNDRangeKernel(commands, kernel, 2, NULL, global, local, 0, NULL, NULL);
    if (err) {
        printf("Error: Failed to execute kernel!\n");
//		perror("--");
        return EXIT_FAILURE;
    }
	
	printf("Global work size = %li, Local work size = %li\n", global[0], local[0]);

    // Wait for the command commands to get serviced before reading back results
    //
    clFinish(commands);

    // Read back the results from the device to verify the output
    //
    err = clEnqueueReadBuffer(commands, mem_obj_out, CL_TRUE, 0, sizeof(int) * scount * scount, outpoot, 0, NULL, NULL );
    if (err != CL_SUCCESS) {
        printf("Error: Failed to read output array! %d\n", err);
        exit(1);
    }
	
	printf("Outpoot:\n");
	for (i = 0; i < scount; i++) {
		for (j = 0; j < scount; ++j) {
			printf("\t%d", outpoot[i * scount + j]);
		}
		printf("\n");
	}
	printf("\n");
	
    // Shutdown and cleanup
    //
    clReleaseMemObject(mem_obj_inp);
	clReleaseMemObject(mem_obj_out);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);

    return 0;
}

