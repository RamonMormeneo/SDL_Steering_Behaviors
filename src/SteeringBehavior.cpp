#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicSeek(Agent *agent, Agent *target, float dtime)
{
	return KinematicSeek(agent, target->position, dtime);
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = agent->position - target;
	steering.Normalize();
	return steering * agent->max_velocity;
}

Vector2D SteeringBehavior::KinematicFlee(Agent *agent, Agent *target, float dtime)
{
	return KinematicFlee(agent, target->position, dtime);
}

/* Add here your own Steering Behavior functions definitions */
///////////////////////////////////////////////////////////////////////////////////////////SEEK
Vector2D SteeringBehavior::Seek(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	steering *= agent->max_velocity;

	Vector2D steeringForce = (steering - agent->velocity);
	steeringForce /= agent->max_velocity;

	return steeringForce * agent->max_force;

}

Vector2D SteeringBehavior::Seek(Agent *agent, Agent *target, float dtime)
{
	return Seek(agent, target->position, dtime);
}

///////////////////////////////////////////////////////////////////////////////////////////FLEE
Vector2D SteeringBehavior::Flee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering =  agent->position - target;
	steering.Normalize();
	steering *= agent->max_velocity;

	Vector2D steeringForce = (steering - agent->velocity);
	steeringForce /= agent->max_velocity;

	return steeringForce * agent->max_force;
}

Vector2D SteeringBehavior::Flee(Agent *agent, Agent *target, float dtime)
{
	return Flee(agent, target->position, dtime);
}

///////////////////////////////////////////////////////////////////////////////////////////ARRIVE
Vector2D SteeringBehavior::Arrive(Agent * agent, Vector2D target, float dtime,float factorSlow)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	float newmaxvel = agent->max_velocity * factorSlow;
	steering *= newmaxvel;

	Vector2D steeringForce = (steering - agent->velocity);
	steeringForce /= agent->max_velocity;

	return steeringForce * agent->max_force;
}

Vector2D SteeringBehavior::Arrive(Agent * agent, Agent * target, float dtime, float factorSlow)
{
	return Arrive(agent, target->position, dtime, factorSlow);
}
