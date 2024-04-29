#pragma once

typedef enum
{
	eIOBoardSharedMem,
	eIOBoardContec,
	eIOBoardErr
}EzvIOBoardType;

const char g_strIOBoardType[eIOBoardErr + 1][255] =
{
	"IOBoardSharedMem",
	"IOBoardContec",
	"IOBoardErr",
};

#define DIOInputNum 64
#define DIOOutputNum 64


typedef struct
{
	BOOL bInput[DIOInputNum];
	BOOL bOutput[DIOOutputNum];
}TzvIOShared;

