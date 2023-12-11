#include "pch.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent()
{

}

void TransformComponent::Initialize()
{

}

void TransformComponent::Update()
{
	if (GetOwner()->GetParent() != NULL)
	{
		SetPosition(LocalPosition + GetOwner()->GetParent()->FindComponent<TransformComponent>()->GetPosition());
	}
}

void TransformComponent::Shutdown()
{

}