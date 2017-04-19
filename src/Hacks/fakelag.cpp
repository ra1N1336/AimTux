#include "fakelag.h"

bool Settings::FakeLag::enabled = false;
int Settings::FakeLag::value = 9;
bool Settings::FakeLag::adaptive = false;
bool Settings::FakeLag::drPepper = false; // yolo

static int ticks = 0;
int ticksMax = 16;

void FakeLag::CreateMove(CUserCmd* cmd)
{
	if( Settings::FakeLag::enabled ){
		//cvar->ConsoleDPrintf("cmdNum: %d\n", cmd->command_number);
		//cvar->ConsoleDPrintf("lastCmd: %d\n", GetLocalClient(-1)->lastoutgoingcommand);
		//cvar->ConsoleDPrintf("outSeq: %d\n", GetLocalClient(-1)->outSequencenr);



		//cvar->ConsoleDPrintf("lastCmd: %d - ", *(int*)(addr+0x4CA8));
		//cvar->ConsoleDPrintf("lastCmd2: %d, addr: %#08x\n", GetLocalClient(-1)->lastoutgoingcommand, &GetLocalClient(-1)->lastoutgoingcommand);
		//cvar->ConsoleDPrintf("outSeq: %d - ", *(int*)(addr+0x42CC));
		cvar->ConsoleDPrintf("NetChanneladdr: %#08x  -- PtrAddr: %#08x\n", GetLocalClient(-1)->m_NetChannel, &GetLocalClient(-1)->m_NetChannel);
		cvar->ConsoleDPrintf("NetChanneladdr->outSeq: %d addr: %#08x\n", GetLocalClient(-1)->m_NetChannel->m_nOutSequenceNr, &GetLocalClient(-1)->m_NetChannel->m_nOutSequenceNr);
	}
	if( Settings::FakeLag::drPepper && inputSystem->IsButtonDown(Settings::Airstuck::key)){
		//cvar->ConsoleDPrintf("outSeq: %d", GetLocalClient(-1)->outSequencenr);
		GetLocalClient(-1)->m_NetChannel->m_nOutSequenceNr += ( 3 * 150 );
		return;
	}
	if (!Settings::FakeLag::enabled)
		return;

	C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());
	if (!localplayer || !localplayer->GetAlive())
		return;

	if (localplayer->GetFlags() & FL_ONGROUND && Settings::FakeLag::adaptive)
		return;

	if (cmd->buttons & IN_ATTACK)
	{
		CreateMove::sendPacket = true;
		return;
	}

	if (ticks >= ticksMax)
	{
		CreateMove::sendPacket = true;
		ticks = 0;
	}
	else
	{
		if (Settings::FakeLag::adaptive)
		{
			int packetsToChoke;
			if (localplayer->GetVelocity().Length() > 0.f)
			{
				packetsToChoke = (int)((64.f / globalVars->interval_per_tick) / localplayer->GetVelocity().Length()) + 1;
				if (packetsToChoke >= 15)
					packetsToChoke = 14;
				if (packetsToChoke < Settings::FakeLag::value)
					packetsToChoke = Settings::FakeLag::value;
			}
			else
				packetsToChoke = 0;

			CreateMove::sendPacket = ticks < 16 - packetsToChoke;
		}
		else
			CreateMove::sendPacket = ticks < 16 - Settings::FakeLag::value;
	}

	ticks++;
}
