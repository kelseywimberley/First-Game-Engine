#include "pch.h"
#include "Transform.h"

Transform::Transform(glm::vec3 p, glm::vec3 r, glm::vec3 s) : Position(p), Rotation(r), Scale(s), mvp(glm::mat4())
{

}
