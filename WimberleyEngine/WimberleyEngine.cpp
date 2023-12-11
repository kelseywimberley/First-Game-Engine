#include "pch.h"
#include "VertexStruct.h"
#include <glm/gtx/string_cast.hpp>

Input* inputManager = NULL;
Collision* collisionManager = NULL;

int main()
{
    WindowHandler window = WindowHandler::getInstance();
    window.Props.Title = "My First Game Engine";
    window.Init();

    // Player
    VertexData vertices[6];
    vertices[0] = { -0.1f, -0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    vertices[1] = { 0.1f, -0.1f, -0.5f,   0.5f, 0.5f, 0.0f };
    vertices[2] = { -0.1f,  0.1f, -0.5f,   0.0f, 1.0f, 0.0f };
    vertices[3] = { 0.1f,  0.1f, -0.5f,   0.0f, 0.0f, 1.0f };
    vertices[4] = { -0.1f,  0.1f, -0.5f,   0.0f, 1.0f, 0.0f };
    vertices[5] = { 0.1f, -0.1f, -0.5f,   0.5f, 0.5f, 0.0f };

    GameObject player;

    RenderComponent rplayer(vertices);
    player.AddComponent(&rplayer);
    Shape shapeplayer(vertices, sizeof(vertices));
    Shader shaderplayer(vertices, sizeof(vertices));
    player.FindComponent<RenderComponent>()->SetShader(&shaderplayer);
    player.FindComponent<RenderComponent>()->SetShape(&shapeplayer);

    TransformComponent tplayer;
    player.AddComponent(&tplayer);
    Transform transformplayer(glm::vec3(0, -0.75, 0), glm::vec3(), glm::vec3(1, 1, 1));
    player.FindComponent<TransformComponent>()->SetTransform(&transformplayer);

    glm::vec3 playerPos = player.FindComponent<TransformComponent>()->GetPosition();

    // Laser
    VertexData vertices2[6];
    vertices2[0] = { -0.02f,-0.05f, -0.75f, 1.0f, 1.0f, 0.0f };
    vertices2[1] = { 0.02f, -0.05f, -0.75f, 1.0f, 1.0f, 0.0f };
    vertices2[2] = { -0.02f, 0.05f, -0.75f, 1.0f, 1.0f, 0.0f };
    vertices2[3] = { 0.02f,  0.05f, -0.75f, 1.0f, 1.0f, 0.0f };
    vertices2[4] = { -0.02f, 0.05f, -0.75f, 1.0f, 1.0f, 0.0f };
    vertices2[5] = { 0.02f, -0.05f, -0.75f, 1.0f, 1.0f, 0.0f };

    GameObject laser;

    RenderComponent rlaser(vertices2);
    laser.AddComponent(&rlaser);
    Shape shapelaser(vertices2, sizeof(vertices2));
    Shader shaderlaser(vertices2, sizeof(vertices2));
    laser.FindComponent<RenderComponent>()->SetShader(&shaderlaser);
    laser.FindComponent<RenderComponent>()->SetShape(&shapelaser);

    TransformComponent tlaser;
    laser.AddComponent(&tlaser);
    Transform transformlaser(glm::vec3(0, -0.75, 0), glm::vec3(), glm::vec3(1, 1, 1));
    laser.FindComponent<TransformComponent>()->SetTransform(&transformlaser);
    laser.SetParent(&player);
    tlaser.LocalPosition = glm::vec3();

    glm::vec3 laserPos = laser.FindComponent<TransformComponent>()->GetPosition();
    bool fired = false;

    // Enemies
    VertexData verts[6];
    verts[0] = { -0.1f, -0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    verts[1] = { 0.1f, -0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    verts[2] = { -0.1f,  0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    verts[3] = { 0.1f,  0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    verts[4] = { -0.1f,  0.1f, -0.5f,   1.0f, 0.0f, 0.0f };
    verts[5] = { 0.1f, -0.1f, -0.5f,   1.0f, 0.0f, 0.0f };

    // Enemy 1
    GameObject enemy1;
    enemy1.SetTag("Enemy");

    RenderComponent renemy1(verts);
    enemy1.AddComponent(&renemy1);
    Shape shapeenemy1(verts, sizeof(verts));
    Shader shaderenemy1(verts, sizeof(verts));
    enemy1.FindComponent<RenderComponent>()->SetShader(&shaderenemy1);
    enemy1.FindComponent<RenderComponent>()->SetShape(&shapeenemy1);

    TransformComponent tenemy1;
    enemy1.AddComponent(&tenemy1);
    glm::vec3 enemy1Pos = glm::vec3(-0.5, 0, 0);
    Transform transformenemy1(enemy1Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy1.FindComponent<TransformComponent>()->SetTransform(&transformenemy1);

    // Enemy 2
    GameObject enemy2;
    enemy2.SetTag("Enemy");

    RenderComponent renemy2(verts);
    enemy2.AddComponent(&renemy2);
    Shape shapeenemy2(verts, sizeof(verts));
    Shader shaderenemy2(verts, sizeof(verts));
    enemy2.FindComponent<RenderComponent>()->SetShader(&shaderenemy2);
    enemy2.FindComponent<RenderComponent>()->SetShape(&shapeenemy2);

    TransformComponent tenemy2;
    enemy2.AddComponent(&tenemy2);
    glm::vec3 enemy2Pos = glm::vec3(-0.25, 0, 0);
    Transform transformenemy2(enemy2Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy2.FindComponent<TransformComponent>()->SetTransform(&transformenemy2);

    // Enemy 3
    GameObject enemy3;
    enemy3.SetTag("Enemy");

    RenderComponent renemy3(verts);
    enemy3.AddComponent(&renemy3);
    Shape shapeenemy3(verts, sizeof(verts));
    Shader shaderenemy3(verts, sizeof(verts));
    enemy3.FindComponent<RenderComponent>()->SetShader(&shaderenemy3);
    enemy3.FindComponent<RenderComponent>()->SetShape(&shapeenemy3);

    TransformComponent tenemy3;
    enemy3.AddComponent(&tenemy3);
    glm::vec3 enemy3Pos = glm::vec3(0, 0, 0);
    Transform transformenemy3(enemy3Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy3.FindComponent<TransformComponent>()->SetTransform(&transformenemy3);

    // Enemy 4
    GameObject enemy4;
    enemy4.SetTag("Enemy");

    RenderComponent renemy4(verts);
    enemy4.AddComponent(&renemy4);
    Shape shapeenemy4(verts, sizeof(verts));
    Shader shaderenemy4(verts, sizeof(verts));
    enemy4.FindComponent<RenderComponent>()->SetShader(&shaderenemy4);
    enemy4.FindComponent<RenderComponent>()->SetShape(&shapeenemy4);

    TransformComponent tenemy4;
    enemy4.AddComponent(&tenemy4);
    glm::vec3 enemy4Pos = glm::vec3(0.25, 0, 0);
    Transform transformenemy4(enemy4Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy4.FindComponent<TransformComponent>()->SetTransform(&transformenemy4);

    // Enemy 5
    GameObject enemy5;
    enemy5.SetTag("Enemy");

    RenderComponent renemy5(verts);
    enemy5.AddComponent(&renemy5);
    Shape shapeenemy5(verts, sizeof(verts));
    Shader shaderenemy5(verts, sizeof(verts));
    enemy5.FindComponent<RenderComponent>()->SetShader(&shaderenemy5);
    enemy5.FindComponent<RenderComponent>()->SetShape(&shapeenemy5);

    TransformComponent tenemy5;
    enemy5.AddComponent(&tenemy5);
    glm::vec3 enemy5Pos = glm::vec3(0.5, 0, 0);
    Transform transformenemy5(enemy5Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy5.FindComponent<TransformComponent>()->SetTransform(&transformenemy5);

    // Enemy 6
    GameObject enemy6;
    enemy6.SetTag("Enemy");

    RenderComponent renemy6(verts);
    enemy6.AddComponent(&renemy6);
    Shape shapeenemy6(verts, sizeof(verts));
    Shader shaderenemy6(verts, sizeof(verts));
    enemy6.FindComponent<RenderComponent>()->SetShader(&shaderenemy6);
    enemy6.FindComponent<RenderComponent>()->SetShape(&shapeenemy6);

    TransformComponent tenemy6;
    enemy6.AddComponent(&tenemy6);
    glm::vec3 enemy6Pos = glm::vec3(-0.5, 0.5, 0);
    Transform transformenemy6(enemy6Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy6.FindComponent<TransformComponent>()->SetTransform(&transformenemy6);

    // Enemy 7
    GameObject enemy7;
    enemy7.SetTag("Enemy");

    RenderComponent renemy7(verts);
    enemy7.AddComponent(&renemy7);
    Shape shapeenemy7(verts, sizeof(verts));
    Shader shaderenemy7(verts, sizeof(verts));
    enemy7.FindComponent<RenderComponent>()->SetShader(&shaderenemy7);
    enemy7.FindComponent<RenderComponent>()->SetShape(&shapeenemy7);

    TransformComponent tenemy7;
    enemy7.AddComponent(&tenemy7);
    glm::vec3 enemy7Pos = glm::vec3(-0.25, 0.5, 0);
    Transform transformenemy7(enemy7Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy7.FindComponent<TransformComponent>()->SetTransform(&transformenemy7);

    // Enemy 8
    GameObject enemy8;
    enemy8.SetTag("Enemy");

    RenderComponent renemy8(verts);
    enemy8.AddComponent(&renemy8);
    Shape shapeenemy8(verts, sizeof(verts));
    Shader shaderenemy8(verts, sizeof(verts));
    enemy8.FindComponent<RenderComponent>()->SetShader(&shaderenemy8);
    enemy8.FindComponent<RenderComponent>()->SetShape(&shapeenemy8);

    TransformComponent tenemy8;
    enemy8.AddComponent(&tenemy8);
    glm::vec3 enemy8Pos = glm::vec3(0, 0.5, 0);
    Transform transformenemy8(enemy8Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy8.FindComponent<TransformComponent>()->SetTransform(&transformenemy8);

    // Enemy 9
    GameObject enemy9;
    enemy9.SetTag("Enemy");

    RenderComponent renemy9(verts);
    enemy9.AddComponent(&renemy9);
    Shape shapeenemy9(verts, sizeof(verts));
    Shader shaderenemy9(verts, sizeof(verts));
    enemy9.FindComponent<RenderComponent>()->SetShader(&shaderenemy9);
    enemy9.FindComponent<RenderComponent>()->SetShape(&shapeenemy9);

    TransformComponent tenemy9;
    enemy9.AddComponent(&tenemy9);
    glm::vec3 enemy9Pos = glm::vec3(0.25, 0.5, 0);
    Transform transformenemy9(enemy9Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy9.FindComponent<TransformComponent>()->SetTransform(&transformenemy9);

    // Enemy 10
    GameObject enemy10;
    enemy10.SetTag("Enemy");

    RenderComponent renemy10(verts);
    enemy10.AddComponent(&renemy10);
    Shape shapeenemy10(verts, sizeof(verts));
    Shader shaderenemy10(verts, sizeof(verts));
    enemy10.FindComponent<RenderComponent>()->SetShader(&shaderenemy10);
    enemy10.FindComponent<RenderComponent>()->SetShape(&shapeenemy10);

    TransformComponent tenemy10;
    enemy10.AddComponent(&tenemy10);
    glm::vec3 enemy10Pos = glm::vec3(0.5, 0.5, 0);
    Transform transformenemy10(enemy10Pos, glm::vec3(), glm::vec3(1, 1, 1));
    enemy10.FindComponent<TransformComponent>()->SetTransform(&transformenemy10);


    // Enemy Lasers
    VertexData verts2[6];
    verts2[0] = { -0.02f,-0.05f, -0.75f, 0.5f, 0.5f, 0.5f };
    verts2[1] = { 0.02f, -0.05f, -0.75f, 0.5f, 0.5f, 0.5f };
    verts2[2] = { -0.02f, 0.05f, -0.75f, 0.5f, 0.5f, 0.5f };
    verts2[3] = { 0.02f,  0.05f, -0.75f, 0.5f, 0.5f, 0.5f };
    verts2[4] = { -0.02f, 0.05f, -0.75f, 0.5f, 0.5f, 0.5f };
    verts2[5] = { 0.02f, -0.05f, -0.75f, 0.5f, 0.5f, 0.5f };

    // Laser 1
    GameObject e1laser;

    RenderComponent re1laser(verts2);
    e1laser.AddComponent(&re1laser);
    Shape shapee1laser(verts2, sizeof(verts2));
    Shader shadere1laser(verts2, sizeof(verts2));
    e1laser.FindComponent<RenderComponent>()->SetShader(&shadere1laser);
    e1laser.FindComponent<RenderComponent>()->SetShape(&shapee1laser);

    TransformComponent te1laser;
    e1laser.AddComponent(&te1laser);
    Transform transforme1laser(glm::vec3(4, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    e1laser.FindComponent<TransformComponent>()->SetTransform(&transforme1laser);

    glm::vec3 e1laserPos = e1laser.FindComponent<TransformComponent>()->GetPosition();
    bool e1fired = false;

    // Laser 2
    GameObject e2laser;

    RenderComponent re2laser(verts2);
    e2laser.AddComponent(&re2laser);
    Shape shapee2laser(verts2, sizeof(verts2));
    Shader shadere2laser(verts2, sizeof(verts2));
    e2laser.FindComponent<RenderComponent>()->SetShader(&shadere2laser);
    e2laser.FindComponent<RenderComponent>()->SetShape(&shapee2laser);

    TransformComponent te2laser;
    e2laser.AddComponent(&te2laser);
    Transform transforme2laser(glm::vec3(4, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    e2laser.FindComponent<TransformComponent>()->SetTransform(&transforme2laser);

    glm::vec3 e2laserPos = e2laser.FindComponent<TransformComponent>()->GetPosition();
    bool e2fired = false;

    // Laser 3
    GameObject e3laser;

    RenderComponent re3laser(verts2);
    e3laser.AddComponent(&re3laser);
    Shape shapee3laser(verts2, sizeof(verts2));
    Shader shadere3laser(verts2, sizeof(verts2));
    e3laser.FindComponent<RenderComponent>()->SetShader(&shadere3laser);
    e3laser.FindComponent<RenderComponent>()->SetShape(&shapee3laser);

    TransformComponent te3laser;
    e3laser.AddComponent(&te3laser);
    Transform transforme3laser(glm::vec3(4, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    e3laser.FindComponent<TransformComponent>()->SetTransform(&transforme3laser);

    glm::vec3 e3laserPos = e3laser.FindComponent<TransformComponent>()->GetPosition();
    bool e3fired = false;

    // Laser 4
    GameObject e4laser;

    RenderComponent re4laser(verts);
    e4laser.AddComponent(&re4laser);
    Shape shapee4laser(verts2, sizeof(verts2));
    Shader shadere4laser(verts2, sizeof(verts2));
    e4laser.FindComponent<RenderComponent>()->SetShader(&shadere4laser);
    e4laser.FindComponent<RenderComponent>()->SetShape(&shapee4laser);

    TransformComponent te4laser;
    e4laser.AddComponent(&te4laser);
    Transform transforme4laser(glm::vec3(4, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    e4laser.FindComponent<TransformComponent>()->SetTransform(&transforme4laser);

    glm::vec3 e4laserPos = e4laser.FindComponent<TransformComponent>()->GetPosition();
    bool e4fired = false;

    // Laser 5
    GameObject e5laser;

    RenderComponent re5laser(verts);
    e5laser.AddComponent(&re5laser);
    Shape shapee5laser(verts2, sizeof(verts2));
    Shader shadere5laser(verts2, sizeof(verts2));
    e5laser.FindComponent<RenderComponent>()->SetShader(&shadere5laser);
    e5laser.FindComponent<RenderComponent>()->SetShape(&shapee5laser);

    TransformComponent te5laser;
    e5laser.AddComponent(&te5laser);
    Transform transforme5laser(glm::vec3(4, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    e5laser.FindComponent<TransformComponent>()->SetTransform(&transforme5laser);

    glm::vec3 e5laserPos = e5laser.FindComponent<TransformComponent>()->GetPosition();
    bool e5fired = false;

    // Invisible Walls
    Transform wallRight(glm::vec3(1.75, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));
    Transform wallLeft(glm::vec3(-1.75, 0, 0), glm::vec3(), glm::vec3(1, 1, 1));

    // Win
    VertexData vertsLetters[6];
    vertsLetters[0] = { -0.02f,-0.05f, -0.75f, 1.0f, 1.0f, 1.0f };
    vertsLetters[1] = { 0.02f, -0.05f, -0.75f, 1.0f, 1.0f, 1.0f };
    vertsLetters[2] = { -0.02f, 0.05f, -0.75f, 1.0f, 1.0f, 1.0f };
    vertsLetters[3] = { 0.02f,  0.05f, -0.75f, 1.0f, 1.0f, 1.0f };
    vertsLetters[4] = { -0.02f, 0.05f, -0.75f, 1.0f, 1.0f, 1.0f };
    vertsLetters[5] = { 0.02f, -0.05f, -0.75f, 1.0f, 1.0f, 1.0f };

    GameObject w1;

    RenderComponent rw1(vertsLetters);
    w1.AddComponent(&rw1);
    Shape shapew1(vertsLetters, sizeof(vertsLetters));
    Shader shaderw1(vertsLetters, sizeof(vertsLetters));
    w1.FindComponent<RenderComponent>()->SetShader(&shaderw1);
    w1.FindComponent<RenderComponent>()->SetShape(&shapew1);

    TransformComponent tw1;
    w1.AddComponent(&tw1);
    glm::vec3 w1Pos = glm::vec3(-0.25, 0.25, 0);
    Transform transformw1(w1Pos, glm::vec3(), glm::vec3(4, 6, 1));
    w1.FindComponent<TransformComponent>()->SetTransform(&transformw1);

    GameObject w2;

    RenderComponent rw2(vertsLetters);
    w2.AddComponent(&rw2);
    Shape shapew2(vertsLetters, sizeof(vertsLetters));
    Shader shaderw2(vertsLetters, sizeof(vertsLetters));
    w2.FindComponent<RenderComponent>()->SetShader(&shaderw2);
    w2.FindComponent<RenderComponent>()->SetShape(&shapew2);

    TransformComponent tw2;
    w2.AddComponent(&tw2);
    glm::vec3 w2Pos = glm::vec3(0.25, 0.25, 0);
    Transform transformw2(w2Pos, glm::vec3(), glm::vec3(4, 6, 1));
    w2.FindComponent<TransformComponent>()->SetTransform(&transformw2);

    GameObject w3;

    RenderComponent rw3(vertsLetters);
    w3.AddComponent(&rw3);
    Shape shapew3(vertsLetters, sizeof(vertsLetters));
    Shader shaderw3(vertsLetters, sizeof(vertsLetters));
    w3.FindComponent<RenderComponent>()->SetShader(&shaderw3);
    w3.FindComponent<RenderComponent>()->SetShape(&shapew3);

    TransformComponent tw3;
    w3.AddComponent(&tw3);
    glm::vec3 w3Pos = glm::vec3(0, 0.15, 0);
    Transform transformw3(w3Pos, glm::vec3(), glm::vec3(4, 4, 1));
    w3.FindComponent<TransformComponent>()->SetTransform(&transformw3);

    GameObject w4;

    RenderComponent rw4(vertsLetters);
    w4.AddComponent(&rw4);
    Shape shapew4(vertsLetters, sizeof(vertsLetters));
    Shader shaderw4(vertsLetters, sizeof(vertsLetters));
    w4.FindComponent<RenderComponent>()->SetShader(&shaderw4);
    w4.FindComponent<RenderComponent>()->SetShape(&shapew4);

    TransformComponent tw4;
    w4.AddComponent(&tw4);
    glm::vec3 w4Pos = glm::vec3(0, 0, 0);
    Transform transformw4(w4Pos, glm::vec3(), glm::vec3(9, 1, 1));
    w4.FindComponent<TransformComponent>()->SetTransform(&transformw4);

    GameObject l1;

    RenderComponent rl1(vertsLetters);
    l1.AddComponent(&rl1);
    Shape shapel1(vertsLetters, sizeof(vertsLetters));
    Shader shaderl1(vertsLetters, sizeof(vertsLetters));
    l1.FindComponent<RenderComponent>()->SetShader(&shaderl1);
    l1.FindComponent<RenderComponent>()->SetShape(&shapel1);

    TransformComponent tl1;
    l1.AddComponent(&tl1);
    glm::vec3 l1Pos = glm::vec3(-0.15, 0.25, 0);
    Transform transforml1(l1Pos, glm::vec3(), glm::vec3(4, 6, 1));
    l1.FindComponent<TransformComponent>()->SetTransform(&transforml1);

    GameObject l2;

    RenderComponent rl2(vertsLetters);
    l2.AddComponent(&rl2);
    Shape shapel2(vertsLetters, sizeof(vertsLetters));
    Shader shaderl2(vertsLetters, sizeof(vertsLetters));
    l2.FindComponent<RenderComponent>()->SetShader(&shaderl2);
    l2.FindComponent<RenderComponent>()->SetShape(&shapel2);

    TransformComponent tl2;
    l2.AddComponent(&tl2);
    glm::vec3 l2Pos = glm::vec3(0, 0, 0);
    Transform transforml2(l2Pos, glm::vec3(), glm::vec3(7, 1, 1));
    l2.FindComponent<TransformComponent>()->SetTransform(&transforml2);

    // Game Variables
    bool play = false;
    bool win = false;
    bool lose = false;
    float speed = 0.001f;
    int willShoot;

    float ratio;
    glm::mat4 model, projection, mvp;
    glm::mat4 translate, scale;

    // Main loop
    while (!window.ShouldClose())
    {
        window.Update();

        ratio = window.FrameBuffer.Width / (float)window.FrameBuffer.Height;
        projection = glm::ortho(-ratio, ratio, -ratio, ratio, -ratio, ratio);

        // Object 1 movement
        if (inputManager->IsKeyPressed(GLFW_KEY_A, &window) || inputManager->IsKeyPressed(GLFW_KEY_LEFT, &window))
        {
            play = true;
            if (win || lose)
            {
                player.FindComponent<TransformComponent>()->SetPosition(glm::vec3(0, -0.75, 0));
                enemy1.FindComponent<TransformComponent>()->SetPosition(enemy1Pos);
                enemy2.FindComponent<TransformComponent>()->SetPosition(enemy2Pos);
                enemy3.FindComponent<TransformComponent>()->SetPosition(enemy3Pos);
                enemy4.FindComponent<TransformComponent>()->SetPosition(enemy4Pos);
                enemy5.FindComponent<TransformComponent>()->SetPosition(enemy5Pos);
                enemy6.FindComponent<TransformComponent>()->SetPosition(enemy6Pos);
                enemy7.FindComponent<TransformComponent>()->SetPosition(enemy7Pos);
                enemy8.FindComponent<TransformComponent>()->SetPosition(enemy8Pos);
                enemy9.FindComponent<TransformComponent>()->SetPosition(enemy9Pos);
                enemy10.FindComponent<TransformComponent>()->SetPosition(enemy10Pos);
            }
            win = false;
            lose = false;

            if (collisionManager->WallCollision(player, wallLeft) == false)
            {
                playerPos += speed * glm::vec3(-1, 0, 0);
                player.FindComponent<TransformComponent>()->SetPosition(playerPos);
            }
        }
        if (inputManager->IsKeyPressed(GLFW_KEY_D, &window) || inputManager->IsKeyPressed(GLFW_KEY_RIGHT, &window))
        {
            play = true;
            if (win || lose)
            {
                player.FindComponent<TransformComponent>()->SetPosition(glm::vec3(0, -0.75, 0));
                enemy1.FindComponent<TransformComponent>()->SetPosition(enemy1Pos);
                enemy2.FindComponent<TransformComponent>()->SetPosition(enemy2Pos);
                enemy3.FindComponent<TransformComponent>()->SetPosition(enemy3Pos);
                enemy4.FindComponent<TransformComponent>()->SetPosition(enemy4Pos);
                enemy5.FindComponent<TransformComponent>()->SetPosition(enemy5Pos);
                enemy6.FindComponent<TransformComponent>()->SetPosition(enemy6Pos);
                enemy7.FindComponent<TransformComponent>()->SetPosition(enemy7Pos);
                enemy8.FindComponent<TransformComponent>()->SetPosition(enemy8Pos);
                enemy9.FindComponent<TransformComponent>()->SetPosition(enemy9Pos);
                enemy10.FindComponent<TransformComponent>()->SetPosition(enemy10Pos);
            }
            win = false;
            lose = false;

            if (collisionManager->WallCollision(player, wallRight) == false)
            {
                playerPos += speed * glm::vec3(1, 0, 0);
                player.FindComponent<TransformComponent>()->SetPosition(playerPos);
            }
        }
        if (inputManager->IsKeyPressed(GLFW_KEY_SPACE, &window) && fired == false)
        {
            play = true;
            if (win || lose)
            {
                player.FindComponent<TransformComponent>()->SetPosition(glm::vec3(0, -0.75, 0));
                enemy1.FindComponent<TransformComponent>()->SetPosition(enemy1Pos);
                enemy2.FindComponent<TransformComponent>()->SetPosition(enemy2Pos);
                enemy3.FindComponent<TransformComponent>()->SetPosition(enemy3Pos);
                enemy4.FindComponent<TransformComponent>()->SetPosition(enemy4Pos);
                enemy5.FindComponent<TransformComponent>()->SetPosition(enemy5Pos);
                enemy6.FindComponent<TransformComponent>()->SetPosition(enemy6Pos);
                enemy7.FindComponent<TransformComponent>()->SetPosition(enemy7Pos);
                enemy8.FindComponent<TransformComponent>()->SetPosition(enemy8Pos);
                enemy9.FindComponent<TransformComponent>()->SetPosition(enemy9Pos);
                enemy10.FindComponent<TransformComponent>()->SetPosition(enemy10Pos);
            }
            win = false;
            lose = false;

            laser.RemoveParent();
            laserPos = laser.FindComponent<TransformComponent>()->GetPosition();
            fired = true;
        }

        // Firing the Laser
        if (fired)
        {
            laserPos += speed * 3 * glm::vec3(0, 1, 0);
            laser.FindComponent<TransformComponent>()->SetPosition(laserPos);
            if (laser.FindComponent<TransformComponent>()->GetPosition().y > 2.5)
            {
                fired = false;
                laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
                laser.SetParent(&player);
            }
        }
        else
        {
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
        }

        // Checking Collision between Enemies and Player's Laser
        if (collisionManager->AABBCollision(laser, enemy1))
        {
            enemy1.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy2))
        {
            enemy2.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy3))
        {
            enemy3.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy4))
        {
            enemy4.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy5))
        {
            enemy5.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy6))
        {
            enemy6.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy7))
        {
            enemy7.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy8))
        {
            enemy8.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy9))
        {
            enemy9.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }
        if (collisionManager->AABBCollision(laser, enemy10))
        {
            enemy10.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            fired = false;
            laser.FindComponent<TransformComponent>()->SetPosition(playerPos);
            laser.SetParent(&player);
        }

        // Enemy Firing
        willShoot = (rand() % 5000) + 1;
        if (willShoot < 2 && play && (enemy6.FindComponent<TransformComponent>()->GetPosition().x < 3))
        {
            if (e1fired == false)
            {
                if (enemy1.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e1laserPos = enemy1.FindComponent<TransformComponent>()->GetPosition();
                }
                else if (enemy6.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e1laserPos = enemy6.FindComponent<TransformComponent>()->GetPosition();
                }
                e1fired = true;
            }
        }
        willShoot = (rand() % 5000) + 1;
        if (willShoot < 2 && play && (enemy7.FindComponent<TransformComponent>()->GetPosition().x < 3))
        {
            if (e2fired == false)
            {
                if (enemy2.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e2laserPos = enemy2.FindComponent<TransformComponent>()->GetPosition();
                }
                else if (enemy7.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e2laserPos = enemy7.FindComponent<TransformComponent>()->GetPosition();
                }
                e2fired = true;
            }
        }
        willShoot = (rand() % 5000) + 1;
        if (willShoot < 2 && play && (enemy8.FindComponent<TransformComponent>()->GetPosition().x < 3))
        {
            if (e3fired == false)
            {
                if (enemy3.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e3laserPos = enemy3.FindComponent<TransformComponent>()->GetPosition();
                }
                else if (enemy8.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e3laserPos = enemy8.FindComponent<TransformComponent>()->GetPosition();
                }
                e3fired = true;
            }
        }
        willShoot = (rand() % 5000) + 1;
        if (willShoot < 2 && play && (enemy9.FindComponent<TransformComponent>()->GetPosition().x < 3))
        {
            if (e4fired == false)
            {
                if (enemy4.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e4laserPos = enemy4.FindComponent<TransformComponent>()->GetPosition();
                }
                else if (enemy9.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e4laserPos = enemy9.FindComponent<TransformComponent>()->GetPosition();
                }
                e4fired = true;
            }
        }
        willShoot = (rand() % 5000) + 1;
        if (willShoot < 2 && play && (enemy10.FindComponent<TransformComponent>()->GetPosition().x < 3))
        {
            if (e5fired == false)
            {
                if (enemy5.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e5laserPos = enemy5.FindComponent<TransformComponent>()->GetPosition();
                }
                else if (enemy10.FindComponent<TransformComponent>()->GetPosition().x < 3)
                {
                    e5laserPos = enemy10.FindComponent<TransformComponent>()->GetPosition();
                }
                e5fired = true;
            }
        }

        if (e1fired)
        {
            e1laserPos -= speed * 3 * glm::vec3(0, 1, 0);
            e1laser.FindComponent<TransformComponent>()->SetPosition(e1laserPos);
            if (e1laser.FindComponent<TransformComponent>()->GetPosition().y < -2.5)
            {
                e1fired = false;
                e1laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            }
        }
        if (e2fired)
        {
            e2laserPos -= speed * 3 * glm::vec3(0, 1, 0);
            e2laser.FindComponent<TransformComponent>()->SetPosition(e2laserPos);
            if (e2laser.FindComponent<TransformComponent>()->GetPosition().y < -2.5)
            {
                e2fired = false;
                e2laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            }
        }
        if (e3fired)
        {
            e3laserPos -= speed * 3 * glm::vec3(0, 1, 0);
            e3laser.FindComponent<TransformComponent>()->SetPosition(e3laserPos);
            if (e3laser.FindComponent<TransformComponent>()->GetPosition().y < -2.5)
            {
                e3fired = false;
                e3laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            }
        }
        if (e4fired)
        {
            e4laserPos -= speed * 3 * glm::vec3(0, 1, 0);
            e4laser.FindComponent<TransformComponent>()->SetPosition(e4laserPos);
            if (e4laser.FindComponent<TransformComponent>()->GetPosition().y < -2.5)
            {
                e4fired = false;
                e4laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            }
        }
        if (e5fired)
        {
            e5laserPos -= speed * 3 * glm::vec3(0, 1, 0);
            e5laser.FindComponent<TransformComponent>()->SetPosition(e5laserPos);
            if (e5laser.FindComponent<TransformComponent>()->GetPosition().y < -2.5)
            {
                e5fired = false;
                e5laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            }
        }

        // Checking Collision between Player and Enemy Lasers
        bool hit = false;
        if (collisionManager->AABBCollision(player, e1laser))
        {
            e1fired = false;
            e1laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            hit = true;
        }
        if (collisionManager->AABBCollision(player, e2laser))
        {
            e2fired = false;
            e2laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            hit = true;
        }
        if (collisionManager->AABBCollision(player, e3laser))
        {
            e3fired = false;
            e3laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            hit = true;
        }
        if (collisionManager->AABBCollision(player, e4laser))
        {
            e4fired = false;
            e4laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            hit = true;
        }
        if (collisionManager->AABBCollision(player, e5laser))
        {
            e5fired = false;
            e5laser.FindComponent<TransformComponent>()->SetPosition(glm::vec3(4, 0, 0));
            hit = true;
        }

        // Lose Condition: Player is Hit
        if (hit)
        {
            player.FindComponent<TransformComponent>()->SetPosition(glm::vec3(0, -4, 0));
            laser.FindComponent<TransformComponent>()->SetPosition(player.FindComponent<TransformComponent>()->GetPosition());
            if (fired)
            {
                fired = false;
                laser.SetParent(&player);
            }
            lose = true;
            play = false;
        }

        // Win Condition: All Back Enemies Are Defeated
        if (enemy6.FindComponent<TransformComponent>()->GetPosition().x > 3 &&
            enemy7.FindComponent<TransformComponent>()->GetPosition().x > 3 &&
            enemy8.FindComponent<TransformComponent>()->GetPosition().x > 3 &&
            enemy9.FindComponent<TransformComponent>()->GetPosition().x > 3 &&
            enemy10.FindComponent<TransformComponent>()->GetPosition().x > 3)
        {
            win = true;
            play = false;
        }

        if (inputManager->IsKeyPressed(GLFW_KEY_ESCAPE, &window))
        {
            window.ShutDown();
            exit(EXIT_SUCCESS);
        }

        // Player
        model = glm::mat4(1.0);
        translate = glm::translate(glm::mat4(1.0f), player.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), player.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        player.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Laser
        translate = glm::translate(glm::mat4(1.0f), laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Enemies
        translate = glm::translate(glm::mat4(1.0f), enemy1.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy1.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy1.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy2.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy2.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy2.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy3.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy3.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy3.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy4.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy4.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy4.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy5.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy5.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy5.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy6.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy6.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy6.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy7.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy7.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy7.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy8.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy8.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy8.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy9.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy9.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy9.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), enemy10.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), enemy10.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        enemy10.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Enemy Lasers
        translate = glm::translate(glm::mat4(1.0f), e1laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), e1laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        e1laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), e2laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), e2laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        e2laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), e3laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), e3laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        e3laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), e4laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), e4laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        e4laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), e5laser.FindComponent<TransformComponent>()->GetPosition());
        scale = glm::scale(glm::mat4(1.0f), e5laser.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        e5laser.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Win
        translate = glm::translate(glm::mat4(1.0f), w1Pos);
        scale = glm::scale(glm::mat4(1.0f), w1.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        w1.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), w2Pos);
        scale = glm::scale(glm::mat4(1.0f), w2.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        w2.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), w3Pos);
        scale = glm::scale(glm::mat4(1.0f), w3.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        w3.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), w4Pos);
        scale = glm::scale(glm::mat4(1.0f), w4.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        w4.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Lose
        translate = glm::translate(glm::mat4(1.0f), l1Pos);
        scale = glm::scale(glm::mat4(1.0f), l1.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        l1.FindComponent<TransformComponent>()->SetMVP(mvp);

        translate = glm::translate(glm::mat4(1.0f), l2Pos);
        scale = glm::scale(glm::mat4(1.0f), l2.FindComponent<TransformComponent>()->GetScale());
        mvp = projection * model;
        mvp = translate * scale * mvp;
        l2.FindComponent<TransformComponent>()->SetMVP(mvp);

        // Laser
        for (int i = 0; i < laser.GetComponents()[0].size(); ++i)
        {
            laser.GetComponents()[0][i]->Update();
        }

        // Enemy Lasers
        for (int i = 0; i < e1laser.GetComponents()[0].size(); ++i)
        {
            e1laser.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < e2laser.GetComponents()[0].size(); ++i)
        {
            e2laser.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < e3laser.GetComponents()[0].size(); ++i)
        {
            e3laser.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < e4laser.GetComponents()[0].size(); ++i)
        {
            e4laser.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < e5laser.GetComponents()[0].size(); ++i)
        {
            e5laser.GetComponents()[0][i]->Update();
        }

        // Player
        for (int i = 0; i < player.GetComponents()[0].size(); ++i)
        {
            player.GetComponents()[0][i]->Update();
        }

        // Enemies
        for (int i = 0; i < enemy1.GetComponents()[0].size(); ++i)
        {
            enemy1.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy2.GetComponents()[0].size(); ++i)
        {
            enemy2.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy3.GetComponents()[0].size(); ++i)
        {
            enemy3.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy4.GetComponents()[0].size(); ++i)
        {
            enemy4.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy5.GetComponents()[0].size(); ++i)
        {
            enemy5.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy6.GetComponents()[0].size(); ++i)
        {
            enemy6.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy7.GetComponents()[0].size(); ++i)
        {
            enemy7.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy8.GetComponents()[0].size(); ++i)
        {
            enemy8.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy9.GetComponents()[0].size(); ++i)
        {
            enemy9.GetComponents()[0][i]->Update();
        }
        for (int i = 0; i < enemy10.GetComponents()[0].size(); ++i)
        {
            enemy10.GetComponents()[0][i]->Update();
        }

        // Win
        if (win)
        {
            for (int i = 0; i < w1.GetComponents()[0].size(); ++i)
            {
                w1.GetComponents()[0][i]->Update();
            }
            for (int i = 0; i < w2.GetComponents()[0].size(); ++i)
            {
                w2.GetComponents()[0][i]->Update();
            }
            for (int i = 0; i < w3.GetComponents()[0].size(); ++i)
            {
                w3.GetComponents()[0][i]->Update();
            }
            for (int i = 0; i < w4.GetComponents()[0].size(); ++i)
            {
                w4.GetComponents()[0][i]->Update();
            }
        }

        // Lose
        if (lose)
        {
            for (int i = 0; i < l1.GetComponents()[0].size(); ++i)
            {
                l1.GetComponents()[0][i]->Update();
            }
            for (int i = 0; i < l2.GetComponents()[0].size(); ++i)
            {
                l2.GetComponents()[0][i]->Update();
            }
        }

        window.SwapBuffers();
    }

    window.ShutDown();
    exit(EXIT_SUCCESS);
}
