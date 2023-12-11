#pragma once

#include "Component.h"
#include "VertexStruct.h"

class Shader;
class Shape;

class RenderComponent : public Component
{
public:
	RenderComponent(VertexData* verts);

	void Initialize();
	void Update();
	void Shutdown();

	void SetShader(Shader* shader) { shaderHandle = shader; }
	void SetShape(Shape* shape) { shapeHandle = shape; }

	VertexData* vertices;

private:
	Shader* shaderHandle;
	Shape* shapeHandle;
};
