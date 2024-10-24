/*
Semestre 2024-1
Animación:
Sesión 1:
Simple o básica:Por banderas y condicionales (más de 1 transforomación geométrica se ve modificada
Sesión 2
Compleja: Por medio de funciones y algoritmos.
Adicional.- ,Textura Animada
*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"
const float toRadians = 3.14159265f / 180.0f;

//variables para animación
float movCoche;
float movOffset;
float rotllanta;
float rotllantaOffset;
float movLetrero;
float movLetreroOffset;
float rotLetrero;
float rotLetreroOffset;
float movPumpkin;
float movPumpkinOffset;
float rotPumpkin;
float rotPumpkinOfsset;
float movSingingFlowers;
float movSingingFlowersOffset;
float rotSingingFlowers;
float rotSingingFlowersOffset;
float movChicharos;
float movChicharosOffset;
float rotChicharos;
float rotChicharosOffset;
float movJam;
float movJamOffset;
float rotJam;
float rotJamOffset;
float movNemo;
float movNemoOffset;
float rotNemo;
float rotNemoOffset;
float movAlegria;
float movAlegriaOffset;
float rotAlegria;
float rotAlegriaOffset;
float movStich;
float movStichOffset;
float rotStich;
float rotStichOffset;
float movBingBong;
float movBingBongOffset;
float rotBingBong;
float rotBingBongOffset;
float movCamioneta;
float movCamionetaOffset;
float rotCamioneta;
float rotCamionetaOffset;
float movMcQueen;
float movMcQueenOffset;
float rotMcQueen;
float rotMcQueenOffset;
float movForky;
float movForkyOffset;
float rotForky;
float rotForkyOffset;
float movNave;
float movNaveOffset;
float rotNave;
float rotNaveOffset;
float movUpHouse;
float movUpHouseOffset;
float rotUpHouse;
float rotUpHouseOffset;
float movAnemona;
float movAnemonaOffset;
float rotAnemona;
float rotAnemonaOffset;
float movCasaMickey;
float movCasaMickeyOffset;
float rotCasaMickey;
float rotCasaMickeyOffset;
bool avanza;
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;


Camera camera_follow=Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);
Camera* camera_selected = &camera_follow;
Camera cameraXY = Camera(glm::vec3(0.0f, 50.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, -90.0f, 5.0f, 0.3f);

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture AgaveTexture;

Model Tablero_M;
Model Pumpkin_M;
Model SingingFlowers_M;
Model Chicharos_M;
Model Jam_M;
Model Nemo_M;
Model Alegria_M;
Model Stich_M;
Model Bing_Bong_M;
Model CamionetaPP_M;
Model RayoMcQueen_M;
Model Forky_M;
Model Nave_M;
Model UpHouse_M;
Model Anemona_M;
Model CasaMickey_M;

Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;


//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";


//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,


	};
	
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh *obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh *obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);

}


void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

void animaPersonaje(double time, float movPersonaje, float rotPersonaje, float movPersonajeOffset, float rotPersonajeOffset, GLfloat deltaTime) {
	if (time > 2 && time < 4) {
		if(movPersonaje<4.0f)
			movPersonaje += movPersonajeOffset * deltaTime;
	}
	if (time > 4 && time < 6) {
		if (rotPersonaje < 360.0f)
			rotPersonaje += rotPersonajeOffset * deltaTime;
	}
	if (time > 6 && time < 8) {
		if (movPersonaje > -4.0f)
			movPersonaje -= movPersonajeOffset * deltaTime;
	}
	if (time > 8) {
		glfwSetTime(0);
		rotPersonaje = 0.0f;
	}
}




int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	



	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/piso.tga");
	pisoTexture.LoadTextureA();
	AgaveTexture = Texture("Textures/Agave.tga");
	AgaveTexture.LoadTextureA();

	Tablero_M = Model();
	Tablero_M.LoadModel("Models/monopoly.obj");
	Pumpkin_M = Model();
	Pumpkin_M.LoadModel("Models/pumpkin_cinderella.obj");
	SingingFlowers_M = Model();
	SingingFlowers_M.LoadModel("Models/singing_flowers.obj");
	Chicharos_M = Model();
	Chicharos_M.LoadModel("Models/chicharos_toy_story.obj");
	Jam_M = Model();
	Jam_M.LoadModel("Models/jam.obj");
	Nemo_M = Model();
	Nemo_M.LoadModel("Models/nemo.obj");
	Alegria_M = Model();
	Alegria_M.LoadModel("Models/alegria.obj");
	Stich_M = Model();
	Stich_M.LoadModel("Models/stich.obj");
	Bing_Bong_M = Model();
	Bing_Bong_M.LoadModel("Models/bing-bong.obj");
	CamionetaPP_M = Model();
	CamionetaPP_M.LoadModel("Models/camiona_pizza_planeta.obj");
	RayoMcQueen_M = Model();
	RayoMcQueen_M.LoadModel("Models/mcQueen.obj");
	Forky_M = Model();
	Forky_M.LoadModel("Models/forky.obj");
	Nave_M = Model();
	Nave_M.LoadModel("Models/nave_bln.obj");
	UpHouse_M = Model();
	UpHouse_M.LoadModel("Models/up_house.obj");
	Anemona_M = Model();
	Anemona_M.LoadModel("Models/anemona.obj");
	CasaMickey_M = Model();
	CasaMickey_M.LoadModel("Models/casa_mickey_mouse.obj");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, -1.0f, 0.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f,
		-6.0f, 1.5f, 1.5f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	unsigned int spotLightCount = 0;
	//linterna
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLightCount++;

	//luz fija
	spotLights[1] = SpotLight(0.0f, 1.0f, 0.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;
	
	//se crean mas luces puntuales y spotlight 

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
	movCoche = 0.0f;
	movOffset = 0.3f;
	rotllanta = 0.0f;
	rotllantaOffset = 5.0f;
	movLetrero = 1.0f;
	movLetreroOffset = 0.05f;
	rotLetrero = 0.0f;
	rotLetreroOffset = 10.0f;
	movPumpkin = 0.0f;
	movPumpkinOffset = 0.05f;
	rotPumpkin = 0.0f;
	rotPumpkinOfsset = 10.0f;
	movSingingFlowers = 0.0f;
	movSingingFlowersOffset = 0.05;
	rotSingingFlowers = 0.0f;
	rotSingingFlowersOffset = 10.0f;
	movChicharos = 0.0f;
	movChicharosOffset = 0.05;
	rotChicharos = 0.0f;
	rotChicharosOffset = 10.0f;
	movJam = 0.0f;
	movJamOffset = 0.05f;
	rotJam = 0.0f;
	rotJamOffset = 10.0f;
	movNemo = 0.0f;
	movNemoOffset = 0.05f;
	rotNemo = 0.0f;
	rotNemoOffset = 10.0f;
	movAlegria = 0.0f;
	movAlegriaOffset = 0.05f;
	rotAlegria = 0.0f;
	rotAlegriaOffset = 10.0f;
	avanza = true;
	glfwSetTime(0);
	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		mainWindow.getCambiaCamara() ? camera_selected = &camera_follow : camera_selected = &cameraXY;
		
		//printf("get Time %f\n", glfwGetTime());
		//if(casillaPumpkin.isSelected())
		//Dentro de este if va todo eso
		//if (glfwGetTime() < 4 && glfwGetTime()>2) {
		//	if (movPumpkin < 4.0f) {
		//		movPumpkin += movPumpkinOffset * deltaTime;
		//	}
		//}
		//if (glfwGetTime() > 4 && glfwGetTime() < 6) {
		//	if (rotPumpkin < 360.0)
		//		rotPumpkin += rotPumpkinOfsset * deltaTime;
		//}
		//if (glfwGetTime() > 6 && glfwGetTime() < 8) {
		//	if (movPumpkin > -4.0f) {
		//		movPumpkin -= movPumpkinOffset * deltaTime;
		//	}
		//}
		//if (glfwGetTime() > 8) {
		//	glfwSetTime(0);
		//	rotPumpkin = 0.0f;
		//	//casillaPumpkin=false Para "liberar" el tiempo
		//}
		//if(casillaSingingFlowers.isSelected())
		//todo lo demas
		//if (glfwGetTime() < 4 && glfwGetTime() > 2) {
		//	if (movSingingFlowers < 4.0f) {
		//		movSingingFlowers += movSingingFlowersOffset * deltaTime;
		//	}
		//}
		//if (glfwGetTime() > 4 && glfwGetTime() < 6) {
		//	if (rotSingingFlowers < 360.0)
		//		rotSingingFlowers += rotSingingFlowersOffset * deltaTime;
		//}
		//if (glfwGetTime() > 6 && glfwGetTime() < 8) {
		//	if (movSingingFlowers > -4.0f) {
		//		movSingingFlowers -= movSingingFlowersOffset * deltaTime;
		//	}
		//}
		//if (glfwGetTime() > 8) {
		//	glfwSetTime(0);
		//	rotSingingFlowers = 0.0f;
		//	//casillaPumpkin=false Para "liberar" el tiempo
		//}

		
		
		//if (glfwGetTime() > 5) {

		//	if (avanza) {
		//		if (movCoche > -15.0f)
		//		{
		//			movCoche -= movOffset * deltaTime;
		//			rotllanta += rotllantaOffset * deltaTime;
		//			//printf("avanza%f \n ",movCoche);
		//		}
		//		else {
		//			avanza = !avanza;
		//		}
		//	}
		//	else {
		//		if (movCoche < 20.0f) {
		//			movCoche += movOffset * deltaTime;
		//			rotllanta -= rotllantaOffset * deltaTime;
		//		}
		//		else {
		//			avanza = !avanza;
		//		}
		//	}
		//}
		

		//Recibir eventos del usuario
		glfwPollEvents();
		camera_selected->keyControl(mainWindow.getsKeys(), deltaTime, mainWindow.getCambiaCamara());
		camera_selected->mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera_selected->calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();
		
		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera_selected->calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera_selected->getCameraPosition().x, camera_selected->getCameraPosition().y, camera_selected->getCameraPosition().z);

		// luz ligada a la cámara de tipo flash
		//sirve para que en tiempo de ejecución (dentro del while) se cambien propiedades de la luz
			glm::vec3 lowerLight = camera_selected->getCameraPosition();
		lowerLight.y -= 0.3f;
		spotLights[0].SetFlash(lowerLight, camera_selected->getCameraDirection());

		//información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		shaderList[0].SetSpotLights(spotLights, spotLightCount);



		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[2]->RenderMesh();
		
		//Tablero
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -8.5f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tablero_M.RenderModel();

		//Pumpkin Cinderella
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(5.0f, -3.0f+movPumpkin, 35.0f));
		model = glm::rotate(model, glm::radians(rotPumpkin), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pumpkin_M.RenderModel();

		//Singing Flowers
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.5f, -3.0f + movSingingFlowers, 35.0f));
		model = glm::rotate(model, glm::radians(rotSingingFlowers), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		SingingFlowers_M.RenderModel();

		//Tree hangman

		//Chicharos toy story
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-22.5f, -3.0f+movChicharos, 35.0f));
		model = glm::rotate(model, glm::radians(rotChicharos), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Chicharos_M.RenderModel();

		//Raton de dumbo

		//Jam
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movJam, 15.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotJam), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Jam_M.RenderModel();

		//Cuervo de dumbo

		//Nemo
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f + movNemo, -4.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotNemo), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Nemo_M.RenderModel();

		//Alegria
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f + movAlegria, -27.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotAlegria), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Alegria_M.RenderModel();

		//Stich
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-42.0f, -4.0f + movStich, -32.0f));
		model = glm::rotate(model, -135 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotStich), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Stich_M.RenderModel();

		//Bing bong
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-36.0f, -4.0f + movBingBong, -32.0f));
		model = glm::rotate(model, -270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotBingBong), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bing_Bong_M.RenderModel();

		//Circo de dumbo

		//Camioneta pizza planeta
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(18.0f, -4.0f+movCamioneta, -30.0f));
		model = glm::rotate(model, -270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotCamioneta), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CamionetaPP_M.RenderModel();

		//Rayo McQueen
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movMcQueen, -20.0f));
		model = glm::rotate(model, glm::radians(rotMcQueen), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		RayoMcQueen_M.RenderModel();

		//Forky
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movForky, -12.0f));
		model = glm::rotate(model, glm::radians(rotForky), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Forky_M.RenderModel();

		//Nave BLN
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movNave, -0.5f));
		model = glm::rotate(model, glm::radians(rotNave), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Nave_M.RenderModel();
		//Casa del señor Fredriksen
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movUpHouse, 17.0f));
		model = glm::rotate(model, glm::radians(rotUpHouse), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		UpHouse_M.RenderModel();

		//Anemona de nemo
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f + movAnemona, 23.0f));
		model = glm::rotate(model, glm::radians(rotAnemona), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.003f, 0.003f, 0.003f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Anemona_M.RenderModel();

		//Casa de Mickey Mouse
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movCasaMickey, 29.0f));
		model = glm::rotate(model, glm::radians(rotCasaMickey), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CasaMickey_M.RenderModel();
		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
