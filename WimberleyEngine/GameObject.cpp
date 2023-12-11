#include "pch.h"
#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(std::string n) : name(n), tag(""), parent()
{

}

GameObject::~GameObject()
{

}

void GameObject::SetName(std::string n)
{
	this->name = n;
}

std::string GameObject::GetName() const
{
	return(name);
}

void GameObject::SetTag(std::string t)
{
	this->tag = t;
}

std::string GameObject::GetTag() const
{
	return(tag);
}

void GameObject::SetParent(GameObject* go)
{
	parent = go;
	TransformComponent* t = FindComponent<TransformComponent>();
	TransformComponent* t2 = go->FindComponent<TransformComponent>();
	if (t != NULL && t2 != NULL)
	{
		t->LocalPosition = t->GetPosition() - t2->GetPosition();
	}
}

GameObject* GameObject::GetParent()
{
	return(parent);
}

void GameObject::RemoveParent()
{
	parent = NULL;
	TransformComponent* t = FindComponent<TransformComponent>();
	if (t != NULL)
	{
		t->SetPosition(t->LocalPosition + t->GetPosition());
		t->LocalPosition = glm::vec3(0, 0, 0);
	}
}

void GameObject::AddComponent(Component* component)
{
	components.push_back(component);
	component->owner = this;
}

std::vector<Component*>* GameObject::GetComponents()
{
	return(&components);
}
