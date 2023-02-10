#include "shader.h"
#include "camera.h"
#include "model.h"
#include "GL/glew.h"
#include "glfw/GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include "PathUtil.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 800;

Camera camera(glm::vec3(0.0f, 5.0f, 10.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Simple Scene", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize glew" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	glEnable(GL_DEPTH_TEST);

	std::string currExePath = MdlCommonNS::PathUtil::GetExecutePath();
	std::string VSahderPath = currExePath + "\\vertex_shader.vs";
	std::string FSahderPath = currExePath + "\\fragment_shader.fs";
	//构造着色器
	Shader myShader(VSahderPath.data(), FSahderPath.data());

	//calculate transformation matrices for each model
	glm::mat4 model_batwing = glm::mat4(1.0f);
	model_batwing = glm::translate(model_batwing, glm::vec3(0.0f, 0.1f, 0.0f));
	model_batwing = glm::scale(model_batwing, glm::vec3(1.0f, 1.0f, 1.0f));

	glm::mat4 model_earth = glm::mat4(1.0f);
	model_earth = glm::translate(model_earth, glm::vec3(0.0f, 3.225f, 2.0f));
	model_earth = glm::scale(model_earth, glm::vec3(0.2f, 0.2f, 0.2f));

	glm::mat4 model_moon = glm::mat4(1.0f);
	model_moon = glm::translate(model_moon, glm::vec3(-2.0f, 3.1f, 0.0f));
	model_moon = glm::rotate(model_moon, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model_moon = glm::scale(model_moon, glm::vec3(0.02f, 0.02f, 0.02f));

	glm::mat4 model_sun = glm::mat4(1.0f);
	model_sun = glm::translate(model_sun, glm::vec3(1.0f, 3.2f, -2.5f));
	model_sun = glm::scale(model_sun, glm::vec3(0.02f, 0.02f, 0.02f));

	glm::mat4 model_torus = glm::mat4(1.0f);
	model_torus = glm::translate(model_torus, glm::vec3(18.0f, 0.0f, -18.0f));
	model_torus = glm::rotate(model_torus, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model_torus = glm::scale(model_torus, glm::vec3(3.5f, 3.5f, 3.5f));

	glm::mat4 model_wing = glm::mat4(1.0f);
	model_wing = glm::translate(model_wing, glm::vec3(1.0f, -0.2f, 0.0f));
	model_wing = glm::scale(model_wing, glm::vec3(1.0f, 1.0f, 1.0f));

	std::string mdoelBasePath = currExePath + "\\3DModels\\";
	
	// load models
	Model batwing((mdoelBasePath + "batwing.obj").c_str(), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f), model_batwing);
	Model earth((mdoelBasePath + "earth.obj").c_str(), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), model_earth);
	Model moon((mdoelBasePath + "moon.obj").c_str(), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), model_moon);
	Model sun((mdoelBasePath + "sun.obj").c_str(), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), model_sun);
	Model torus((mdoelBasePath + "torus.obj").c_str(), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), model_torus);
	Model wing((mdoelBasePath + "wing.obj").c_str(), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), model_wing);//



	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window);

		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		myShader.use();

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		myShader.setMat4("projection", projection);
		myShader.setMat4("view", view);

		// render the loaded models
		myShader.setMat4("model", batwing.transform);
		myShader.setVec4("color", batwing.color);
		//batwing.Draw();


		myShader.setMat4("model", earth.transform);
		myShader.setVec4("color", earth.color);
		earth.Draw();

		myShader.setMat4("model", moon.transform);
		myShader.setVec4("color", moon.color);
		//moon.Draw();

		myShader.setMat4("model", sun.transform);
		myShader.setVec4("color", sun.color);
		//sun.Draw();

		myShader.setMat4("model", torus.transform);
		myShader.setVec4("color", torus.color);
		//torus.Draw();

		myShader.setMat4("model", wing.transform);
		myShader.setVec4("color", wing.color);
		//wing.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		camera.ProcessKeyboard(YAW_CCLKW, deltaTime);	
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
		camera.ProcessKeyboard(YAW_CLKW, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}