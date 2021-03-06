/* Copyright (c) 2020, Dyssol Development Team. All rights reserved. This file is part of Dyssol. See LICENSE file for license information. */

#pragma once

#include "BaseUnit.h"

class CDynamicUnit : public CBaseUnit
{
public:
	CDynamicUnit();
	~CDynamicUnit();

	/** Calculates unit on specified time interval (for dynamic units).
	 *	\param _dStartTime Start of the time interval
	 *	\param _dEndTime End of the time interval*/
	virtual void Simulate(double _dStartTime, double _dEndTime) = 0;
};
