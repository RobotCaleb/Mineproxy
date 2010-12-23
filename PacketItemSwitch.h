#pragma once


#include "Packet.h"
#include "protocol.h"

class Packet_ItemSwitch : public Packet
{
private:
	//int entityID;
	short blockID;
public:
	Packet_ItemSwitch() : blockID(0) {}

	bool ReadPacket(SOCKET s)
	{
		//entityID = ReadInt(s);
		blockID = ReadShort(s);;
		return true;
	}

	void WritePacket(SOCKET s)
	{
		//WriteInt(s,entityID);
		WriteShort(s,blockID);
	}

	void Print(FILE *fp)
	{
		//fprintf(fp, "ItemSwitch ( entityID = %d, blockID = %d )",
			//entityID, (int)blockID);
		fprintf(fp, "ItemSwitch ( blockID = %d )", (int)blockID);
	}
};

REGISTER_PACKET(ItemSwitch);
