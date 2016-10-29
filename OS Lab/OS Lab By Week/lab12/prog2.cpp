#include <iostream>

using namespace std;

bool isexist(string arr[], int size, string file_name)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == file_name)
			return true;
	}
	return false;
}

void display(string arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] != "")
			cout<<arr[i]<<endl;
	}
	cout<<endl;
}

void delete_file(string arr[], int size, string file_name)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == file_name)
			{
				arr[i] = "";
				return;
			}
	}
}
int main()
{
	string dir;
	string arr[100];
	int counter = 0;
	
	cout<<"Enter the name of the directory: ";
	cin>>dir;
	
	while(true)
	{
		int x;
		bool flag = false;
		string file_name;
		cout<<"1.Create file\t2.Delete file\t3.Search file\t4.Display file\t5.Exit\n-";
		cin>>x;
		
		switch(x)
		{
			case 1:
					cout<<"Enter the file name: ";
					cin>>file_name;
					
					if(isexist(arr, counter, file_name))
						cout<<"Duplicate file name.\n";
					else
						arr[counter++] = file_name;
					break;
			case 2:
					cout<<"Enter the file name: ";
					cin>>file_name;
					
					if(isexist(arr, counter, file_name))
						delete_file(arr, counter, file_name);
					else
						cout<<"File missing.\n";					
					break;
			case 3:
					cout<<"Enter the file name: ";
					cin>>file_name;
			
					if(isexist(arr, counter, file_name))
						cout<<"File found.\n";
					else
						cout<<"File missing.\n";						
					break;
			case 4:
					display(arr, counter);
					break;
			default:
					flag = true;
					break;										
		}
		if(flag)
			break;
	}
	return 0;
}
