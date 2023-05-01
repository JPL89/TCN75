// @File		TCN75.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		Brazil
// @Date		04/05/23
//
//
// Copyright (C) 2023  JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef TCN75_H_
#define TCN75_H_

// SLAVE, MASTER ADDRESS
#define TCN75_SLA_W				0x90
#define TCN75_SLA_R				0x91

// ADDRESS MAP
#define TCN75_REG_TEMP			0x00
#define TCN75_REG_CONFIG		0x01
#define TCN75_REG_THYST			0x02
#define TCN75_REG_TSET			0x03
#define TCN75_SHUTDOWN_ENABLE	0x01
#define TCN75_SHUTDOWN_DISABLE	0x00
#define TCN75_COMP_MODE			0x02
#define TCN75_INT_MODE			0x00
#define TCN75_POLARITY_HIGH		0x04
#define TCN75_POLARITY_LOW		0x00

void TCN75_Write(unsigned char reg, unsigned char data)
{
	Wire_Start();
	Wire_Write(0x90);
	Wire_Write(reg);
	Wire_Write(data);
	Wire_Stop();
}

unsigned char TCN75_Read(unsigned char reg)
{
	unsigned char data = 0;
	
	Wire_Start();
	Wire_Write(TCN75_SLA_W);
	Wire_Write(reg);
	Wire_Start();
	Wire_Write(TCN75_SLA_R);
	data = Wire_Ack();
	Wire_Stop();
	
	return data;
}

#endif
