#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
//MAX source size of the kernel string
#define MAX_SOURCE_SIZE (0x100000)

int main(void)
{
	//Create the two input vectors
	time_t start,end;
	start = clock();
	int i, n;
	int LIST_SIZE=100,m;
	printf("Enter M and N : \n");
	scanf("%d %d",&m,&n);
	int *A = (int *) malloc(sizeof(int)*m*n);

	
	for (i=0;i<m*n;i++)
		scanf("%d",&A[i]);	
		//printf("Enter how many elements\n");
	//scanf("%d",&LIST_SIZE);

	
	//initialize the input vectors
	int *B = (int *) malloc(sizeof(int)*m*n);
	//char *B = (char *) malloc(sizeof(char)*LIST_SIZE);
	//initialize the input vectors
	
	//Load the kernel source code into arrau source_str
	FILE *fp;
	char *source_str;
	size_t source_size;
	fp=fopen("new.cl","r");

	if(!fp)
	{
		fprintf(stderr, "Failed to load kernel\n" );
		getchar();
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str,1,MAX_SOURCE_SIZE,fp);
	
	fclose(fp);

	//Get platform and device information
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;

	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1,&platform_id,&ret_num_platforms);
	ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_GPU,1,&device_id, &ret_num_devices);

	//Create an OpenCL context
	cl_context context = clCreateContext(NULL,1,&device_id,NULL,NULL,&ret);

	//Create an command queue
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE,&ret);

	//Create memory buffers on the device for each vector A, B, C
	
	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, m*n*sizeof(int), NULL, &ret);

	cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, m*n*sizeof(int), NULL, &ret);

	//cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE*sizeof(int), NULL, &ret);

	//Copy the lists A and B to their respective memory buffers
	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj,CL_TRUE, 0, m*n*sizeof(int), A, 0, NULL, NULL);

	ret = clEnqueueWriteBuffer(command_queue, b_mem_obj,CL_TRUE, 0, m*n*sizeof(int), B, 0, NULL, NULL);

	//Create a program from the kernel source
	cl_program program = clCreateProgramWithSource(context,1,(const char **)&source_str,(const size_t *)&source_size, &ret);

	if (ret != CL_SUCCESS) {
	  printf("clCreateProgramWithSource!"); exit(0);
	}

	//Build the program
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	if (ret != CL_SUCCESS) {
	  printf("clBuildProgram!"); exit(0);
	}
	
	//Create the OpenCL kernel object
	cl_kernel kernel = clCreateKernel(program, "q4Op",&ret);

	if (ret != CL_SUCCESS) {
	  printf("clCreateKernel!"); exit(0);
	}

	//Set the arguments of the kernel
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);

	if (ret != CL_SUCCESS) {
	  printf("sdsd to set kernel arguments!"); exit(0);
	}
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
	//ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
		ret = clSetKernelArg(kernel, 2, sizeof(int), (void *)&m);


	ret = clSetKernelArg(kernel, 3, sizeof(int), (void *)&n);

	if (ret != CL_SUCCESS) {
	  printf("to set kernel arguments!"); exit(0);
	}
	
	//ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
	
	//ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&c_mem_obj);

	//Execute the OpenCL kernel on the array
	size_t global_item_size[2] = {m,n};
	size_t local_item_size[2] = {1,1};

	//Execute the kernel on the device
	cl_event event;

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, &event);

	time_t stime = clock();
	ret = clFinish(command_queue);
	cl_ulong time_start,time_end;
	double total_time;
	clGetEventProfilingInfo(event,CL_PROFILING_COMMAND_START,sizeof(time_start),&time_start,NULL);
	clGetEventProfilingInfo(event,CL_PROFILING_COMMAND_END,sizeof(time_end),&time_end,NULL);
	//Read the memory buffer C on the device to the local variable C
	//int *C = (int *)malloc(sizeof(int)*LIST_SIZE);
	total_time = double(time_end - time_start);
	ret = clEnqueueReadBuffer(command_queue, b_mem_obj, CL_TRUE, 0, m*n*sizeof(int), B, 0, NULL, NULL);

	//display the result to the screen
	for (i=0;i<m*n;i++)
		printf("%d ",B[i]);

	//Clean Up
	ret = clFlush(command_queue);

	ret = clReleaseKernel(kernel);

	ret = clReleaseProgram(program);

	ret = clReleaseMemObject(a_mem_obj);

	//ret = clReleaseMemObject(b_mem_obj);
	
	//ret = clReleaseMemObject(c_mem_obj);

	ret = clReleaseCommandQueue(command_queue);

	ret = clReleaseContext(context);
	end = clock();
	printf("Time taken for Kernel : %0.3f msec \n\n  Whole Program Time : %0.3f sec\n",total_time/1000000,(end-start)/(double)CLOCKS_PER_SEC);

	free(A);
	free(B);
	getch();
	return 0;

}