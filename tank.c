#include "common.h"
#include "tank.h"

static void Tank_Think(Object *self, Tank *tank);

void Tank_Init(Tank *self) {
	memset(self, 0, sizeof(Tank));

	/* Setup callback functions */
	self->obj.thinkFunc = (ObjectCallbackFunc*)Tank_Think;
	self->obj.funcData = self;

	/* Looking up */
	self->obj.upAngles[1] = 1;
}

/* Callback from the world to do any per-frame calculations for the tank */
static void Tank_Think(Object *self, Tank *tank) {
	int i;

	/* Move treads to speed */
	for (i = 0; i < 2; i++) {
		tank->treadPositions[i] += 10 * self->speed / self->maxSpeed;
	}
}

