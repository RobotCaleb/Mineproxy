#pragma once


#include "Packet.h"
#include "protocol.h"

class Packet_Health : public Packet
{
private:
	char health;
public:
	Packet_Health() : health(0) {}
	~Packet_Health()
	{
	}
	bool ReadPacket(SOCKET s)
	{
		health = ReadShort(s);
		return true;
	}

	void WritePacket(SOCKET s)
	{
		WriteShort(s, health);
	}

	void Print(FILE *fp)
	{
		fprintf(fp, "Health( Health = %d )", (int)health);
	}
};

REGISTER_PACKET(Health);
