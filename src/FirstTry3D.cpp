
#include <iostream>
#include <cstdio>
#include <cstdlib>

void printMatVisualization(bool** mat, int height, int width, char spaceSymbol, char filledSymbol);

int main(void)
{
	const int height = 150;
	const int width = 450;

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
			if (h == w)
			{
				mat[h][w] = true;
			}
		}
	}

	printMatVisualization(mat, height, width, '.', '#');
}

void printMatVisualization(bool** mat, int height, int width, char spaceSymbol, char filledSymbol)
{
	const double widthRescaleFactor = 0.6;
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

			int yesCount = 0;
			for (int i = 0; i < (int)hScaleFactor; i++)
			{
				for (int j = 0; j < (int)wScaleFactor; j++)
				{
					int hp = (int)(ha * hScaleFactor) + i;
					int wp = (int)(wa * wScaleFactor) + j;

					if (mat[hp][wp])
					{ yesCount++; }
				}
			}

			if (yesCount > 0)
			{ vmat[ha][wa] = filledSymbol; }
			else
			{ vmat[ha][wa] = spaceSymbol; }
		}

		vmat[ha][adjWidth] = '\0';
	}

	for (int ha = 0; ha < adjHeight; ha++)
	{
		printf("%s\n", vmat[ha]);
	}
}
