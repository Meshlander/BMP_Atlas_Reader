/* ======================================================
SFile: ParticleSprites.h
SDate: 2021.02.12.
SRevision: S
SCreator: Gergely Zara
SNotice: S
======================================================*/

#define SPRITE_COUNT 100
#define SPRITE_PITCH 512
#define SPRITE_MAX_SIZE 262144 //16384 //160k

/*
struct Sprite
{
	int StartingIndex;
	int ParticleCount;

} Sprites[SPRITE_COUNT];
*/

struct Sprite//Atlas
{
	unsigned char B[SPRITE_MAX_SIZE];//color map
	unsigned char G[SPRITE_MAX_SIZE];
	unsigned char R[SPRITE_MAX_SIZE];

	unsigned char X[SPRITE_MAX_SIZE];//normal map
	unsigned char Y[SPRITE_MAX_SIZE];
	unsigned char Z[SPRITE_MAX_SIZE];

	uint16 AnimCut;// = 4096;
	uint8 Timer;
	uint8 AnimIndex;
	
} Sprites[SPRITE_COUNT];