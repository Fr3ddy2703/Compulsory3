#pragma once
#include "../Collision/Collision.h"

class Player;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 Color;
	glm::vec3 normal = glm::vec3(0.f);
	Vertex(glm::vec3 position, glm::vec3 rgb) : position(position), Color(rgb)
	{
	}
};

struct Triangle
{
	Triangle(unsigned int indice1, unsigned int indice2, unsigned int indice3): index1(indice1), index2(indice2), index3(indice3){}
	unsigned int index1, index2, index3;
};

class Mesh
{
public:
	std::vector<Vertex> mVertices;
	std::vector<Triangle> mIndices;
	glm::vec3 position = glm::vec3(0);

	void Draw();
	void CreateCube(glm::vec3 color);
	void createTerrain(float size, glm::vec3 color);
	void BindBuffer();

	

private:
	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;

};

class Player{
	int index = 0;
	glm::vec3 Position;
	glm::vec3 Scale;
	glm::vec3 Rotation;

public:
	Player(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
		: Position(position), Scale(scale), Rotation(rotation)
	{}

	Player* OverlappedCube = nullptr;

	std::shared_ptr<Collision> Collider;
	glm::vec3& GetPosition() { return Position; }
	glm::vec3& GetScale() { return Scale; }
	glm::vec3& GetRotation() { return Rotation; }
	int& GetIndex() { return index; }
	void AddCollider(glm::vec3 scale,ECollisionType collisionType, glm::vec3 offset = glm::vec3(0.f));
	virtual ~Player();
};

float CalcMath(float x, float z);

float Barycentric(Mesh* player, Mesh terrain);