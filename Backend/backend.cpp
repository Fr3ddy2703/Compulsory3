#include "pch.h"
#include "backend.h"

#include "../Input/input.h"
#include "../Shaders/shader.h"

float Backend::DeltaTime = 0.f;
Camera Backend::camera = Camera();

void Backend::Initialize()
{
	window = window::initWindow();
	camera.initCamera();


	
	Run();
}

void Backend::Create()
{
	/* Player */
	Cube.CreateCube(Color::Pink);

	/* object in game */
	HollowByte.CreateCube(Color::Black);
	HollowByte.position = glm::vec3(10.f, Barycentric(&HollowByte, terrain), 18.f);

	/* Terrain */
	terrain.createTerrain(20,Color::Lavender);

	Meshes.emplace_back(&Cube);
	Meshes.emplace_back(&HollowByte);
	Meshes.emplace_back(&terrain);
}

void Backend::Run()
{
	Create();
	float FirstFrame = 0.0f;
	glm::vec3 color(Color::Teal);
	
	while (!glfwWindowShouldClose(window))
	{
		Aplayer.GetPosition().y = Barycentric(&Cube, terrain);
		const auto CurrentFrame = static_cast<float>(glfwGetTime());
		DeltaTime = CurrentFrame - FirstFrame;
		FirstFrame = CurrentFrame;

		glClearColor(color.x, color.y, color.z, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(Shader::ShaderProgram);

		KeyBoardInput::processInput(window, &Aplayer);
		camera.update(Cube);
		Update(DeltaTime);

		glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjection(window::width, window::height)));
		glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));
		glUniform3fv(glGetUniformLocation(Shader::ShaderProgram, "viewPos"), 1, glm::value_ptr(camera.cameraPos));
		std::cout << Aplayer.GetPosition().y << std::endl;
		for (auto mesh : Meshes)
		{
			mesh->Draw();
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
}

void Backend::Update(float deltaTime)
{

}

Backend::~Backend()
{
}
