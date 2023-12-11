#include "pch.h"
#include "RenderComponent.h"

RenderComponent::RenderComponent(VertexData* verts) : vertices(verts)
{

}

void RenderComponent::Initialize()
{

}

void RenderComponent::Update()
{
	TransformComponent* t = GetOwner()->FindComponent<TransformComponent>();
	glm::mat4 mvp = t->GetMVP();

	shaderHandle->Use(mvp);
	shapeHandle->Draw();
	shaderHandle->Unuse();
}

void RenderComponent::Shutdown()
{

}