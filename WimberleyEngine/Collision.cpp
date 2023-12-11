#include "pch.h"
#include "Collision.h"

bool Collision::AABBCollision(GameObject g1, GameObject g2)
{
    bool collisionX = g1.FindComponent<TransformComponent>()->GetPosition().x + 0.2 >= g2.FindComponent<TransformComponent>()->GetPosition().x &&
        g2.FindComponent<TransformComponent>()->GetPosition().x + 0.2 >= g1.FindComponent<TransformComponent>()->GetPosition().x;

    bool collisionY = g1.FindComponent<TransformComponent>()->GetPosition().y + 0.2 >= g2.FindComponent<TransformComponent>()->GetPosition().y &&
        g2.FindComponent<TransformComponent>()->GetPosition().y + 0.2 >= g1.FindComponent<TransformComponent>()->GetPosition().y;

    return(collisionX && collisionY);
}

bool Collision::WallCollision(GameObject g, Transform t)
{
    bool collisionLeft = g.FindComponent<TransformComponent>()->GetPosition().x - g.FindComponent<TransformComponent>()->GetScale().x <= t.Position.x;
    bool collisionRight = g.FindComponent<TransformComponent>()->GetPosition().x + g.FindComponent<TransformComponent>()->GetScale().x >= t.Position.x;
    return(collisionLeft && collisionRight);
}
