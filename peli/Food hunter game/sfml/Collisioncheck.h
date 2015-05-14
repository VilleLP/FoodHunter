#ifndef COLLISIONCHECK_H
#define COLLISIONCHECK_H

#include <Box2D/Box2D.h>
#include "Enemy1.h"
#include "Food1.h"


class Collisioncheck : public b2ContactListener
{
public:
	Collisioncheck();
	~Collisioncheck();
	
	virtual void BeginContact(b2Contact* contact);

	virtual void EndContact(b2Contact* contact);

	void handleContact(Enemy1* e1, Food1* f1);


private:
	
	bool m_imIt;
};
#endif
