#pragma once

#include <glm/gtx/string_cast.hpp>

class Transform
{
public:
	Transform(glm::vec3 p = glm::vec3(), glm::vec3 r = glm::vec3(), glm::vec3 s = glm::vec3(1, 1, 1));

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	glm::mat4 mvp;
};
