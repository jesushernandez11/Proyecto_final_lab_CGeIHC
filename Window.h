#pragma once
#include<stdio.h>
#include<glew.h>
#include<glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	GLfloat getXChange();
	GLfloat getYChange();
	GLfloat getmuevex() { return muevex; }
	GLfloat getmueve_heli() { return mueve_heli; }
	GLfloat getmuevecofre() { return muevecofre; }
	GLboolean getApagaLuz() { return apaga_luz; }
	GLboolean getcambiaLuces() { return cambiaLuces; }
	GLboolean getApagaVela() { return apaga_vela; }
	GLboolean getCambiaCamara() { return cambia_camara; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);}
	bool* getsKeys() { return keys; }
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	
	~Window();
private: 
	GLFWwindow *mainWindow;
	GLint width, height;
	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	void createCallbacks();
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	GLfloat muevex;
	GLfloat mueve_heli;
	GLfloat muevecofre;
	GLboolean apaga_luz;
	GLboolean cambiaLuces;
	GLboolean apaga_vela;
	GLboolean cambia_camara;
	bool mouseFirstMoved;
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);

};

