#pragma once
#include <string>
#include <vector>

class Component;
class Shader;

class GameObject
{
private:
	std::string name;
	std::string tag;
	std::vector<Component*> components;
	GameObject* parent;

public:
	GameObject(std::string n = "");
	~GameObject();

	void SetName(std::string n);
	std::string GetName() const;
	void SetTag(std::string t);
	std::string GetTag() const;

	void SetParent(GameObject* go);
	GameObject* GetParent();
	void RemoveParent();

	void AddComponent(Component* component);
	std::vector<Component*>* GetComponents();

	template<class T>
	T* FindComponent()
	{
		std::vector<Component*>::iterator current = components.begin();
		while (current != components.end())
		{
			T* component = dynamic_cast<T*>((*current));
			if (component != 0)
			{
				return(component);
			}
			current = current + 1;
		}
		return(NULL);
	}
};
