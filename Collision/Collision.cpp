#include "pch.h"
#include "Collision.h"
#include "../Backend/backend.h"

std::vector<std::shared_ptr<Collision>> Collision::AllCollision;

Collision::Collision(glm::vec3 position, glm::vec3 scale, glm::vec3 offset, ECollisionType collision_type, Cube* realCube) : scale(scale), offset(offset), collisionType(collision_type)
{
    min = position;
    max = position + scale;
    max.z = position.z - scale.z;
 
    cube = realCube;
    AllCollision.push_back(std::make_shared<Collision>(*this));
}

void Collision::UpdatePosition(glm::vec3 position)
{
    min = position;
    max = position + scale;
    max.z = position.z - scale.z;
}


void Collision::checkWorldCollision()
{
}

//void Collision::CheckPickupCollisions()
//{
//    for(auto& player : AllCollision)
//    {
//        if(player->cube)
//        {
//            if (player->cube->bIsPlayer)
//            {
//                for (auto& element : AllCollision)
//                {
//                }
//                break;
//            }
//        }
//
//    }
//}

bool Collision::checkCollision(Collision& other)
{
    if(other.min.x < max.x && other.max.x > min.x &&
        other.min.y < max.y && other.max.y > min.y &&
        max.z <= other.min.z && min.z >= other.max.z)
    {
        if(cube == nullptr && other.cube == nullptr)
            return false;

      /*  if(cube != nullptr)
        {
             if (cube->bIsPlayer)
             {
                 if(other.cube)
                    cube->OverlappedCube = other.cube;
             }
        }*/
        else
        {
            if (HasOverlapped == false)
            {
                    HasOverlapped = true;
                    timer = 0.f;
                    Backend::camera.cameraFront = glm::vec3(-1.f, -0.2f, -1.f);
                    OriginalCameraPosition = Backend::camera.cameraPos;
            }
                else
                {
                    HasOverlapped = true;
                    timer = 0.f;
                    Backend::camera.cameraFront = glm::vec3(0.f,0.f, -1.f);
                }
            }
        }
       //if (other.cube != nullptr)
       //{
       //    if (other.cube->bIsPlayer)
       //    {
       //        if(cube)
       //         other.cube->OverlappedCube = cube;
       //    }
       //}
         return true;
    }