#pragma once
#define CAMERA_H
#include "../Collision/Collision.h"


class Mesh;
class Player;

class Camera
{
public:

    glm::vec3 cameraFront = glm::vec3 (0.0f, 0.0f,-1.0f);
    glm::vec3 cameraUp = glm::vec3 (0.0f, 1.0f, 0.0f);
    glm::vec3 PlayerPos = glm::vec3(0.375f, 1.15f, -0.375f);
    glm::vec3 cameraPos = glm::vec3(PlayerPos.x, PlayerPos.y, PlayerPos.z) + cameraFront * -3.f;
    float cameraSpeed = 5.f;


    int viewLoc;
    int projectionLoc;
    bool CameraLock = false;
    
    void initCamera();

    glm::mat4 view;
    glm::mat4 projection;
    
    glm::mat4 getView();
    glm::mat4 getProjection(float width, float height);
    void setPlayerPos(glm::vec3 position);
    glm::vec3 OrbitCamera(glm::vec3 direction);
    Mesh* aPlayer;
    void update(Mesh& player);

};


