#pragma once
#include "../Camera/camera.h"
#include "../Mesh/Mesh.h"

class ElementBuffer;
class VertexBuffer;
struct GLFWwindow;

class Backend
{
public:
	GLFWwindow *window;
	static Camera camera;
	static float DeltaTime;
	Mesh Cube;
	Mesh HollowByte;
	Mesh terrain;
	Player Aplayer = Player(glm::vec3(0.f,0.f,0.f), glm::vec3 (1.f), glm::vec3(0.f));

	Backend(){};

	virtual void Initialize();
	virtual void Create();
	virtual void Run();
	virtual void Update(float deltaTime);

	virtual  ~Backend();

private:
	std::vector<Mesh*> Meshes; 

};

