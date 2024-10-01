#pragma once

#include "Laser.h"

class EnemyLaser : public Laser
{
public:
	EnemyLaser();

	virtual void moveLaser() override;

	virtual bool checkLaserOut() override;

private:
};
