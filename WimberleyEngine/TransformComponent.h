#pragma once

#include "Component.h"

class Transform;

class TransformComponent : public Component
{
public:
	TransformComponent();
	void Initialize();
	void Update();
	void Shutdown();

	void SetTransform(Transform* transform) { transformHandle = transform; }
	glm::mat4 GetMVP() { return(transformHandle->mvp); }
	void SetMVP(glm::mat4 mvpVal) { transformHandle->mvp = mvpVal; }

	glm::vec3 GetPosition() const { return(transformHandle->Position); }
	glm::vec3 GetRotation() const { return(transformHandle->Rotation); }
	glm::vec3 GetScale() const { return(transformHandle->Scale); }

	void SetPosition(glm::vec3 pos) { transformHandle->Position = pos; }
	void SetRotation(glm::vec3 pos) { transformHandle->Rotation = pos; }
	void SetScale(glm::vec3 pos) { transformHandle->Scale = pos; }

	glm::vec3 LocalPosition;
	glm::vec3 LocalRotation;
	glm::vec3 LocalScale;

private:
	Transform* transformHandle;
};
