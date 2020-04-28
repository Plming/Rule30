#include <stdio.h>
#define SIZE 100	//size of cells

//Array for Cells
int arr[SIZE] = { 0 };
int temp[SIZE];

//Define functions
void setup();
void print();
void process();
void transfer();

int main()
{
	char buffer;
	int gen = 1;
	setup();
	while (1)
	{
		print();	//print arr
		process();	//temp =arr
		transfer();	//temp-> arr
		printf("%6d", gen);
		buffer = getchar();
		gen++;
	}
	return 0;
}

void setup()
{
	arr[SIZE / 2] = 1;
}

void print()
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] == 1)	//alive
		{
			printf("O");
		}
		else if (arr[i] == 0)	//dead
		{
			printf("X");
		}
	}
}

void process()
{
	int n;
	for (n = 0; n < SIZE; n++)
	{
		if (arr[n] == 0)
		{
			temp[n] = (arr[n - 1] ^ arr[n + 1]);
		}
		else if (arr[n] == 1)
		{
			if (arr[n - 1] + arr[n + 1] == 0)
			{
				temp[n] = 1;
			}
			else if (arr[n - 1] == 0 && arr[n + 1] == 1)
			{
				temp[n] = 1;
			}
			else
			{
				temp[n] = 0;
			}
		}
	}
}

void transfer()
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		arr[i] = temp[i];
	}
}