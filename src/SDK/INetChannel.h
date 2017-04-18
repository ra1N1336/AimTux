//
// Created by [Aimtux-Fuzion --- LWSS] on 4/18/17.
//
// CONFIDENTIAL -- Property of Fuzion inc.
//

#pragma once

class INetChannel {
public:
	int vtable; //0x0000
	int __buy;
	int ____aim;
	int ______tux;
	int ________fuzion;
	/*
	Netmsgbinder *msgbinder1; //0x0004
	Netmsgbinder *msgbinder2; //0x0008
	Netmsgbinder *msgbinder3; //0x000C
	Netmsgbinder *msgbinder4; //0x0010
	 */
	unsigned char m_bProcessingMessages; //0x0014
	unsigned char m_bShouldDelete; //0x0015
	char pad_0x0016[0x2]; //0x0016
	int m_nOutSequenceNr; //0x0018
	int m_nInSequenceNr; //0x001C
	int m_nOutSequenceNrAck; //0x0020
	int m_nOutReliableState; //0x0024
	int m_nInReliableState; //0x0028
	int m_nChokedPackets; //0x002C
	/*
	bf_write m_StreamReliable; //0x0030
	CUtlMemory m_ReliableDataBuffer; //0x0048
	bf_write m_StreamUnreliable; //0x0054
	CUtlMemory m_UnreliableDataBuffer; //0x006C
	bf_write m_StreamVoice; //0x0078
	CUtlMemory m_VoiceDataBuffer; //0x0090
	__int32 m_Socket; //0x009C
	__int32 m_StreamSocket; //0x00A0
	__int32 m_MaxReliablePayloadSize; //0x00A4
	char pad_0x00A8[0x4]; //0x00A8
	netadr_t remote_address; //0x00AC
	float last_received; //0x00B8
	char pad_0x00BC[0x4]; //0x00BC
	float connect_time; //0x00C0
	char pad_0x00C4[0x4]; //0x00C4
	__int32 m_Rate; //0x00C8
	float m_fClearTime; //0x00CC
	char pad_0x00D0[0x8]; //0x00D0
	CUtlVector m_WaitingList[0]; //0x00D8
	CUtlVector m_WaitingList[1]; //0x00EC
	char pad_0x0100[0x4120]; //0x0100
	__int32 m_PacketDrop; //0x4220
	char m_Name[32]; //0x4224
	__int32 m_ChallengeNr; //0x4244
	float m_Timeout; //0x4248
	INetChannelHandler* m_MessageHandler; //0x424C
	CUtlVector m_NetMessages; //0x4250
	__int32 m_pDemoRecorder; //0x4264
	__int32 m_nQueuedPackets; //0x4268
	float m_flInterpolationAmount; //0x426C
	float m_flRemoteFrameTime; //0x4270
	float m_flRemoteFrameTimeStdDeviation; //0x4274
	float m_nMaxRoutablePayloadSize; //0x4278
	__int32 m_nSplitPacketSequence; //0x427C
	char pad_0x4280[0x14]; //0x4280
	 */
};