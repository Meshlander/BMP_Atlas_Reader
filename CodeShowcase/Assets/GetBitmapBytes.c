
#include<stdio.h>


int BlueData[64];
int GreenData[64];
int RedData[64];

void ReadBMP()
{
	//struct BitMap source_info;
	FILE *BMPFile;
	FILE *BMPHeader;
	FILE *BMPPixelInfo;

   	BMPHeader=fopen("BMPHeader.bin","wb");
	BMPPixelInfo=fopen("BMPPixelInfo.bin","wb");

	if(!(BMPFile=fopen("Test.bmp","rb")))
 	{
    	printf(" cannot open file");
    	exit(-1);
 	}

	char BMPFileBuff[1024];
	char BMPHeaderBuff[54];
	unsigned char PixelInfoBuff[1024];
	int BuffIndex = 0;

	int ch;
	while ((BMPFileBuff[BuffIndex] = getc(BMPFile)) != EOF)
	BuffIndex++;
    	//putc(ch, stdout);

	for(int i=0;i<54;i++)
	BMPHeaderBuff[i] = BMPFileBuff[i];
	
	BMPHeaderBuff[0] = BMPFileBuff[18];

	int BMPWidth = (int)BMPFileBuff[18];//28
	int BMPHeight = (int)BMPFileBuff[22];
	int WxHxSize = BMPWidth * BMPHeight * 3;//*6? ffffff added

	for(int i=54; i< 1024; i++)
	PixelInfoBuff[i - 54] = (unsigned char)BMPFileBuff[i];

	for
	(
		int i = WxHxSize; 
		i < 1024; 
		i++
	) PixelInfoBuff[i] = 0;

	/*****************************************************/

	int BlueCounter = 0;
	int GreenCounter = 0;
	int RedCounter = 0;

	for(int n = 0; n < BMPWidth * BMPHeight * 3; n += 3)
	{
		BlueData[BlueCounter] = 
		(int)(PixelInfoBuff[n]);
		BlueCounter++;
		GreenData[GreenCounter] = 
		(int)(PixelInfoBuff[n+1]);
		GreenCounter++;
		RedData[RedCounter] = 
		(int)(PixelInfoBuff[n+2]);
		RedCounter++;
	}

	

	/*****************************************************/

	for(int i=0; i<54; i++)//54
    	fprintf(BMPHeader,"%d",BMPHeaderBuff[i]);

	for(int i=0;i< BlueCounter;i++)//WxHxSize
	fprintf(BMPPixelInfo,"%d",GreenData[i]);
    	//fprintf(BMPPixelInfo,"%x",PixelInfoBuff[i]);

}

int main() 
{
	ReadBMP();
}