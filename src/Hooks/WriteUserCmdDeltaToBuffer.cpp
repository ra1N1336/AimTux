//
// Created by [Aimtux-Fuzion --- LWSS] on 4/18/17.
//
// CONFIDENTIAL -- Property of Fuzion inc.
//


#include "hooks.h"


CUserCmd* GetUserCmd(int sequence_number)
{
	return ((CUserCmd*)&input->m_pCommands[sequence_number % 150]);
}

bool Hooks::WriteUserCmdDeltaToBuffer(void *thisptr, int slot, void *buf, int from, int to, bool isnewcommand) {

	cvar->ConsoleDPrintf("Hook");
	int* pBackupCommands = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(buf) - 0x30);
	int* pNewCommands = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(buf) - 0x2C);

	int cl_cmdbackup = 0;
	*pBackupCommands = cl_cmdbackup;

	static bool firstcmd = false;
	if (from == -1) { firstcmd = true; }


	if( to > GetLocalClient(-1)->lastoutgoingcommand - cl_cmdbackup ){
		if( firstcmd ){ from = -1; }
		firstcmd = false;

		CUserCmd nullCmd;
		CUserCmd* cmdFrom;
		CUserCmd* cmdTo;

		if( from == -1 ){
			cmdFrom = &nullCmd;
		} else {
			cmdFrom = GetUserCmd(to);
		}

		if( to == -1 ){
			cmdTo = &nullCmd;
		} else {
			cmdTo = GetUserCmd(to);
		}

		clientModeVMT->GetOriginalMethod< WriteUserCmdDeltaToBufferFn >(23)(thisptr, slot, buf, from, to, isnewcommand);


	}

	return true;

}