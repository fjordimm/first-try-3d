
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

void printMatVisualization(bool** mat, int height, int width);
void drawLine(bool** mat, int height, int width, int x1, int y1, int x2, int y2);
void drawLine3d(bool** mat, int height, int width, double x1, double y1, double z1, double x2, double y2, double z2);

int main(void)
{
	const int height = 150;
	const int width = 300;

	bool** mat = (bool**) malloc(height * sizeof(bool*));
	for (int h = 0; h < height; h++)
	{
		mat[h] = (bool*) malloc(width * sizeof(bool));
	}

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			mat[h][w] = false;

			// Testing; a diagonal line
			/*
			if (h < w)
			{
				mat[h][w] = true;
			}
			*/
		}
	}

	drawLine3d(mat, height, width, 50, 50, 300, 50, 100, 300);
	drawLine3d(mat, height, width, 50, 100, 300, 100, 100, 300);
	drawLine3d(mat, height, width, 100, 100, 300, 100, 50, 300);
	drawLine3d(mat, height, width, 100, 50, 300, 50, 50, 300);

	drawLine3d(mat, height, width, 50, 50, 300, 50, 50, 350);
	drawLine3d(mat, height, width, 50, 100, 300, 50, 100, 350);
	drawLine3d(mat, height, width, 100, 50, 300, 100, 50, 350);
	drawLine3d(mat, height, width, 100, 100, 300, 100, 100, 350);

	drawLine3d(mat, height, width, 50, 50, 350, 50, 100, 350);
	drawLine3d(mat, height, width, 50, 100, 350, 100, 100, 350);
	drawLine3d(mat, height, width, 100, 100, 350, 100, 50, 350);
	drawLine3d(mat, height, width, 100, 50, 350, 50, 50, 350);

	printMatVisualization(mat, height, width);
}

void drawLine3d(bool** mat, int height, int width, double x1, double y1, double z1, double x2, double y2, double z2)
{
	z1 /= width;
	z2 /= width;

	int x1p = (int)(x1 / z1);
	int y1p = (int)(y1 / z1);
	
	int x2p = (int)(x2 / z2);
	int y2p = (int)(y2 / z2);

	drawLine(mat, height, width, x1p, height - y1p, x2p, height - y2p);
}

void drawLine(bool** mat, int height, int width, int x1, int y1, int x2, int y2)
{
	int intervals = std::max(height, width);
	
	for (int i = 0; i < intervals; i++)
	{
		int x = x1 + ((x2 - x1) * i) / intervals;
		int y = y1 + ((y2 - y1) * i) / intervals;

		if (x > 0 && x < width && y > 0 && y < height)
		{ mat[y][x] = true; }
	}
}

void printMatVisualization(bool** mat, int height, int width)
{
	const double widthRescaleFactor = 0.47;
	const double scaleFactor = 3.69420;

	const double hScaleFactor = scaleFactor;
	const double wScaleFactor = scaleFactor * widthRescaleFactor;

	const int adjHeight = (int)(height / hScaleFactor);
	const int adjWidth = (int)(width / wScaleFactor);
	
	char** vmat = (char**) malloc(adjHeight * sizeof(char*));
	for (int i = 0; i < adjHeight; i++)
	{
		vmat[i] = (char*) malloc((adjWidth + 1) * sizeof(char));
	}

	for (int ha = 0; ha < adjHeight; ha++)
	{
		for (int wa = 0; wa < adjWidth; wa++)
		{
			int h = (int)(ha * hScaleFactor);
			int w = (int)(wa * wScaleFactor);

			int filledCntr = 0;
			for (int i = 0; i < (int)ceil(hScaleFactor); i++)
			{
				for (int j = 0; j < (int)ceil(wScaleFactor); j++)
				{
					int hp = (int)(ha * hScaleFactor) + i;
					int wp = (int)(wa * wScaleFactor) + j;

					if (mat[hp][wp])
					{ filledCntr++; }
				}
			}

			if (filledCntr == 0)
			{ vmat[ha][wa] = ' '; }
			else if (filledCntr <= 1)
			{ vmat[ha][wa] = '*'; }
			else if (filledCntr <= (int)scaleFactor)
			{ vmat[ha][wa] = 'x'; }
			else
			{ vmat[ha][wa] = '#'; }
		}

		vmat[ha][adjWidth] = '\0';
	}

	for (int ha = 0; ha < adjHeight; ha++)
	{
		printf("%s\n", vmat[ha]);
	}
}
