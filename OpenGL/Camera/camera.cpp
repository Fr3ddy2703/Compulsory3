#include "pch.h"
#include "camera.h"

#include "../Mesh/Mesh.h"
#include "../Shaders/shader.h"

void Camera::initCamera()
{
    viewLoc = glGetUniformLocation(Shader::ShaderProgram, "view");
    projectionLoc = glGetUniformLocation(Shader::ShaderProgram, "projection");
}

glm::mat4 Camera::getView()
{
    glm::mat4 view = glm::mat4(1.f);
    view = glm::lookAt(cameraPos, PlayerPos, cameraUp);
    return view;
}

glm::mat4 Camera::getProjection(float width, float height)
{
    glm::mat4 proj = glm::mat4(1.f);
    proj = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    return proj;
}

void Camera::setPlayerPos(glm::vec3 position)
{
    PlayerPos = glm::vec3(position.x + 0.375f, position.y + 0.65f, position.z - 0.375f);
    if(aPlayer)
    {
	    aPlayer->position = position;
    }

}

glm::vec3 Camera::OrbitCamera(glm::vec3 direction)
{
    cameraPos = PlayerPos;
    cameraFront = glm::normalize(direction);
    cameraPos = glm::vec3(PlayerPos.x,PlayerPos.y,PlayerPos.z) + cameraFront * -3.f;
    return cameraPos;
}

void Camera::update(Mesh& player)
{
    aPlayer = &player;
    cameraPos = player.position - cameraFront * 5.f;
}
