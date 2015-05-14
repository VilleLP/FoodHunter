#include "Collisioncheck.h"


//class Collisioncheck : public b2ContactListener
//{

void Collisioncheck::handleContact(Enemy1* f1, Food1* e1)
	{
		//bool temp = f1->m_imIt;
		//f1->m_imIt = e1->m_imIt;
		//e1->m_imIt = temp;
	}
	
	void Collisioncheck::BeginContact(b2Contact* contact)
	{
		//void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		//if (bodyAUserData)
			//static_cast<Enemy1*>(bodyAUserData)->startContact();
		//void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		//if (bodyBUserData)
		//	static_cast<Food1*>(bodyBUserData)->startContact();
		void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyAUserData && bodyBUserData)
			{
			handleContact(static_cast<Enemy1*>(bodyAUserData),
							static_cast<Food1*>(bodyBUserData));
			}
			
	}
	/*
	void Collisioncheck::EndContact(b2Contact* contact)
	{
		void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
			if (bodyAUserData)
				static_cast<Enemy1*>(bodyAUserData)->endContact();
			void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
			if (bodyBUserData)
				static_cast<Food1*>(bodyBUserData)->endContact();

	}
	*/
//};


/*
Collisioncheck::Collisioncheck()
{
	m_imIt = false;
}


Collisioncheck::~Collisioncheck()
{
}

void Collisioncheck::render()
{
	if (m_imIt)
	{
	// poista
	}
	else
	//piirrä
}

void handelContact(Food1* f11, Enemy1* e11)
{
	bool temp = f11->m_imIt;
	f11 m_imIt = e11 - m_imIt;
	e11->m_imIt = temp;
}

void Collisioncheck::cCheck(b2Contact* contact)
{
	void* bodyFoodData = contact->GetFixtureA()->GetBody->Getuserdata();
	void* bodyEnemyData = contact->GetFixtureB()->GetBody->Getuserdata();
	if (bodyFoodData && bodyEnemyData)
	 handleContact(static_cast<Food1*>(bodyFoodData),
		static_cast<Enemy1*>(bodyEnemyData));
}
*/

//http://www.iforce2d.net/b2dtut/collision-callbacks