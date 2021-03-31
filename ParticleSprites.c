/* ======================================================
SFile: ParticleSprites.c
SDate: 2021.02.12.
SRevision: S
SCreator: Gergely Zara
SNotice: S
======================================================*/

#include<stdio.h>

#define BUFFSIZE 256000
//#define SIZE 4096

//uint8 BlueData[4096];
//uint8 GreenData[4096];
//uint8 RedData[4096];

//maybe you cna put in the particle draw pipeline after everything
//is projected to camera

void ReadBMPAtlas(int Index)
{
	//struct BitMap source_info;
	FILE *BMPFile;

	if(!(BMPFile=fopen("Assets/TestAtlas.bmp","rb")))
 	{
    		//printf(" can not open file");
    		exit(-1);
 	}

	char BMPFileBuff[BUFFSIZE];
	unsigned char PixelInfoBuff[BUFFSIZE];
	int BuffIndex = 0;

	int ch;
	while ((BMPFileBuff[BuffIndex] = getc(BMPFile)) != EOF)
	BuffIndex++;

	fclose(BMPFile);

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! what if the image is larger than 255?

	uint32_t BMPWidth = *(uint32_t*)(BMPFileBuff + 18);
	uint32_t BMPHeight = *(uint32_t*)(BMPFileBuff + 22);

	//int BMPWidth = (int)BMPFileBuff[18];//28
	//int BMPHeight = (int)BMPFileBuff[22];

	int WxHxSize = BMPWidth * BMPHeight * 3;//*6? ffffff added

	for(int i=54; i< BUFFSIZE; i++)
	PixelInfoBuff[i - 54] = (unsigned char)BMPFileBuff[i];

	/*for
	(
		int i = WxHxSize; 
		i < BUFFSIZE; 
		i++
	) PixelInfoBuff[i] = 0;*/

	/*****************************************************/

	int BlueCounter = 0;
	int GreenCounter = 0;
	int RedCounter = 0;

	/*for(int n = 0; n < BMPWidth * BMPHeight * 3; n += 3)
	{
		//Sprites[Index].B[BlueCounter] = 
		//*(uint32_t*)(PixelInfoBuff + n);
		//BlueCounter++;
		//Sprites[Index].G[GreenCounter] = 
		//*(uint32_t*)(PixelInfoBuff + n + 1);
		//GreenCounter++;
		//Sprites[Index].R[RedCounter] = 
		//*(uint32_t*)(PixelInfoBuff + n + 2);
		//RedCounter++;

		Sprites[Index].B[BlueCounter] = 
		(int)(PixelInfoBuff[n]);
		BlueCounter++;
		Sprites[Index].G[GreenCounter] = 
		(int)(PixelInfoBuff[n+1]);
		GreenCounter++;
		Sprites[Index].R[RedCounter] = 
		(int)(PixelInfoBuff[n+2]);
		RedCounter++;
	}*/

	//Here reading happens on the atlas in 64x64 chunks, a 256x256 atlas size
	//is presupposed
	 - - - - - - - -
	|   |   |   |   |
	 - - - - - - - -
	|   |   |   |   |
	 - - - - - - - -
	|   |   |   |   |
	 - - - - - - - -
	| 0 |   |   |   |
	 - - - - - - - -

	for(int n = 0; n < 256; n += 64)
	{
		for(int m = 0; m < 256; m += 64)
		{
			for(int y = n * 3; y < n * 3 + BMPHeight * 3 / 4; y += 3 )
			{
				for(int x = m * 3; x < m * 3 + BMPWidth * 3 / 4; x += 3 )
				{
					Sprites[Index].B[BlueCounter] = 
					*(uint32_t*)(PixelInfoBuff + x + y * BMPWidth );
					BlueCounter++;
					Sprites[Index].G[GreenCounter] = 
					*(uint32_t*)(PixelInfoBuff + x + y * BMPWidth + 1);
					GreenCounter++;
					Sprites[Index].R[RedCounter] = 
					*(uint32_t*)(PixelInfoBuff + x + y * BMPWidth + 2);
					RedCounter++;

			    }
		    }
	    }
    }

}

void ReadBMP()
{
	ReadBMPAtlas(0);
}
