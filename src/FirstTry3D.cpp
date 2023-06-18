
#include <iostream>
#include <cstdio>
#include <cstdlib>

void printMatVisualization(bool** mat, int height, int width);

int main(void)
{
	const int height = 280;
	const int width = 650;

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
			// /*
			if (h == w)
			{
				mat[h][w] = true;
			}
			// */
		}
	}

	printMatVisualization(mat, height, width);
}

void printMatVisualization(bool** mat, int height, int width)
{
	const double widthRescaleFactor = 0.47;
	const double scaleFactor = 6.9420;

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
			for (int i = 0; i < (int)hScaleFactor; i++)
			{
				for (int j = 0; j < (int)wScaleFactor; j++)
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
