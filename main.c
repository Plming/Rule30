#include <stdio.h>
#include <stdbool.h>
#define CELL_SIZE 110

typedef struct _Cell
{
	bool current;
	bool next;
} Cell;

Cell cell[CELL_SIZE] = { 0, };

void render();
void process();
void update();

int main()
{
	cell[CELL_SIZE / 2].current = true;
	for (int i = 0; i < 100; i++)
	{
		render();
		process();
		update();
	}
	return 0;
}

void render()
{
	int i;
	for (i = 0; i < CELL_SIZE; i++)
	{
		if (cell[i].current)
		{
			printf("бс");
		}
		else
		{
			printf("  ");
		}
	}
	printf("\n");
}

void process()
{
	int i;
	cell[0].next = false;
	cell[CELL_SIZE - 1].next = false;
	for (i = 1; i < CELL_SIZE-1; i++)
	{
		cell[i].next = cell[i - 1].current ^ (cell[i].current || cell[i + 1].current);
	}
}

void update()
{
	int i;
	for (i = 0; i < CELL_SIZE; i++)
	{
		cell[i].current = cell[i].next;
	}
}