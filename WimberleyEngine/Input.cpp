#include "pch.h"
#include "Input.h"

bool Input::IsKeyPressed(int key, WindowHandler* window)
{
	return glfwGetKey(window->GetCurrentContext(), key) == GLFW_PRESS;
}
