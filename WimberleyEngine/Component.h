#pragma once
class GameObject;
class Event;

class Component
{
private:
	friend class GameObject;
	GameObject* owner;

public:
	Component();
	virtual ~Component();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;

	GameObject* GetOwner() { return owner; }
};
