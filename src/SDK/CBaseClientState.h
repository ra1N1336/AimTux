#pragma once

#include "INetChannel.h"
class CBaseClientState
{
public:
	char _FuzionPAD[0x94];
	INetChannel* m_NetChannel; // 0x94

	char _pad0[0x164];
	int m_nDeltaTick; // 0x1FC
	bool m_bPaused;
	char _pad1[0x3];
	int m_nViewEntity;
	char _pad2[0x8];
	char m_szLevelName[260]; // 0x314
	char m_szLevelNameShort[40]; // 0x33C

	//int m_nMaxClients; // 0x0308 ? this padding shit sucks

	char _giantAssFuzionPad[0x3F90];
	int outSequencenr; // 0x42CC
	char _pad3[0x9DC];
	int lastoutgoingcommand; // 0x4CA8
	int chokedcommands; // 0x4CAC
};