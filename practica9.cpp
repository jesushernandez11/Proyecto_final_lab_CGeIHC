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
float movPiglet;
float movPigletOffset;
float rotPiglet;
float rotPigletOffset;
float movTigger;
float movTiggerOffset;
float rotTigger;
float rotTiggerOffset;
float movFrancesco;
float movFrancescoOffset;
float rotFrancesco;
float rotFrancescoOffset;
float movTree;
float movTreeOffset;
float rotTree;
float rotTreeOffset;
float movTiroAlBlanco;
float movTiroAlBlancoOffset;
float rotTiroAlBlanco;
float rotTiroAlBlancoOffset;
float movSlinky;
float movSlinkyOffset;
float rotSlinky;
float rotSlinkyOffset;
float movPinocchio;
float movPinocchioOffset;
float rotPinnochio;
float rotPinnochioOffset;
float movMickey;
float movMickeyOffset;
float rotMickey;
float rotMickeyOffset;
float movWinnie;
float movWinnieOffset;
float rotWinnie;
float rotWinnieOffset;
float movPrincesaAtta;
float movPrincesaAttaOffset;
float rotPrincesaAtta;
float rotPrincesaAttaOffset;
float movWalle;
float movWalleOffset;
float rotWalle;
float rotWalleOffset;
float movRalph;
float movRalphOffset;
float rotRalph;
float rotRalphOffset;
float movTinkerbell;
float movTinkerbellOffset;
float rotTinkerbell;
float rotTinkerbellOffset;
float movRedCat;
float movRedCatOffset;
float rotRedCat;
float rotRedCatOffset;
float movMegara;
float movMegaraOffset;
float rotMegara;
float rotMegaraOffset;
float movMushu;
float movMushuOffset;
float rotMushu;
float rotMushuOffset;
float movMrFlash;
float movMrFlashOffset;
float rotMrFlash;
float rotMrFlashOffset;
float movSimba;
float movSimbaOffset;
float rotSimba;
float rotSimbaOffset;
float movPocahontas;
float movPocahontasOffset;
float rotPocahontas;
float rotPocahontasOffset;
float movSully;
float movSullyOffset;
float rotSully;
float rotSullyOffset;
float movPepita;
float movPepitaOffset;
float rotPepita;
float rotPepitaOffset;
float movCilindro;
float movCilindroOffset;
float rotCilindro;
float rotCilindroOffset;
float movFantasia;
float movFantasiaOffset;
float rotFantasia;
float rotFantasiaOffset;
float movPelota;
float movPelotaOffset;
float rotPelota;
float rotPelotaOffset;
float movDado;
float rotDado;
float movDirZ;
float movDirY;
float movDirX;
float movDirZOffset;
const float GRAVITY = 0.0981f;
const float BOUNCE_DAMPING = 0.5f;
const glm::vec3 START_POSITION(0.0f, 5.0f, 0.0f);
const float FLOOR_Y = 0.0f;

bool anima;
bool avanza;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;


Camera camera_follow=Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);
Camera* camera_selected = &camera_follow;
Camera cameraXY = Camera(glm::vec3(0.0f, 50.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, -90.0f, 5.0f, 0.3f);
Camera cameraFixed = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), 0.0f, -45.0f, 5.0f, 0.3f);//Definir posicion correcta

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
Model Piglet_M;
Model Tigger_M;
Model HangmanTree_M;
Model TiroAlBlanco_M;
Model Slinky_M;
Model Francesco_M;
Model Pinocchio_M;
Model Mickey_M;
Model Winnie_M;
Model PrincesaAtta_M;
Model Walle_M;
Model Ralph_M;
Model Tinkerbell_M;
Model RedCat_M;
Model Megara_M;
Model Mushu_M;
Model MrFlash_M;
Model Simba_M;
Model Pocahontas_M;
Model Sully_M;
Model Pepita_M;
Model Cilindro_M;
Model Fantasia_M;
Model Pelota_M;
Model Die4_M;
Model Die8_M;


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

//Funcion para la animacion de los personajes
//Utilizamos el operador & para pasar por referencia cada movimiento, rotacion y casilla del personaje
//Y deltaTime para el control de la animacion
void animaPersonaje( float& movPersonaje, float& rotPersonaje, float movPersonajeOffset, float rotPersonajeOffset, bool& casilla, GLfloat deltaTime) {
	if (casilla) {
		if (movPersonaje <= 6.0f) {
			movPersonaje += movPersonajeOffset * deltaTime;
			rotPersonaje += rotPersonajeOffset * deltaTime;
		}
		else {
			casilla = !casilla;
		}
	}
	else {
		if (movPersonaje >= -4.0f) {
			movPersonaje -= movPersonajeOffset * deltaTime;
			rotPersonaje -= rotPersonajeOffset * deltaTime;
		}
		else {
			casilla = false;
		}
	}
}

void animaDados(float& movDado, float& rotDado, GLfloat deltaTime) {
	if (movDado <= FLOOR_Y) {
		movDado -= GRAVITY * deltaTime;
	}
	else {
		movDado = 0.0f;
	}
	/*movDado *= BOUNCE_DAMPING * deltaTime;*/

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
	Piglet_M = Model();
	Piglet_M.LoadModel("Models/piglet.obj");
	Tigger_M = Model();
	Tigger_M.LoadModel("Models/tigger.obj");
	HangmanTree_M = Model();
	HangmanTree_M.LoadModel("Models/hangman_tree.obj");
	Francesco_M = Model();
	Francesco_M.LoadModel("Models/francesco_bernoulli.obj");
	TiroAlBlanco_M = Model();
	TiroAlBlanco_M.LoadModel("Models/tiro_al_blanco.obj");
	Slinky_M = Model();
	Slinky_M.LoadModel("Models/slinky.obj");
	Pinocchio_M = Model();
	Pinocchio_M.LoadModel("Models/pinocchio.obj");
	Mickey_M = Model();
	Mickey_M.LoadModel("Models/mickey_mouse.obj");
	Winnie_M = Model();
	Winnie_M.LoadModel("Models/winnie_pooh.obj");
	PrincesaAtta_M = Model();
	PrincesaAtta_M.LoadModel("Models/princesa_bichos.obj");
	Walle_M = Model();
	Walle_M.LoadModel("Models/walle.obj");
	Ralph_M = Model();
	Ralph_M.LoadModel("Models/ralph.obj");
	Tinkerbell_M = Model();
	Tinkerbell_M.LoadModel("Models/tinkerbell.obj");
	RedCat_M = Model();
	RedCat_M.LoadModel("Models/red_cat.obj");
	Megara_M = Model();
	Megara_M.LoadModel("Models/megara.obj");
	Mushu_M = Model();
	Mushu_M.LoadModel("Models/mushu.obj");
	MrFlash_M = Model();
	MrFlash_M.LoadModel("Models/Flash.obj");
	Simba_M = Model();
	Simba_M.LoadModel("Models/simba.obj");
	Pocahontas_M = Model();
	Pocahontas_M.LoadModel("Models/pocahontas.obj");
	Sully_M = Model();
	Sully_M.LoadModel("Models/sully.obj");
	Pepita_M = Model();
	Pepita_M.LoadModel("Models/pepita.obj");
	Cilindro_M = Model();
	Cilindro_M.LoadModel("Models/cilindro_MI.obj");
	Fantasia_M = Model();
	Fantasia_M.LoadModel("Models/fantasia.obj");
	Pelota_M = Model();
	Pelota_M.LoadModel("Models/pixar_ball.obj");
	Die4_M = Model();
	Die4_M.LoadModel("Models/dado_d4.obj");
	Die8_M = Model();
	Die8_M.LoadModel("Models/dado_d8.obj");

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
		0.0f, 1.0f, -1.0f);
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
	movPiglet = 0.0f;
	movPigletOffset = 0.05f;
	rotPiglet = 0.0f;
	rotPigletOffset = 10.0f;
	movDirX = 0.0;
	movDirY = -1.0f;
	movDirZ = 1.0f;
	movDirZOffset = 0.001f;
	avanza = true;
	anima = true;
	bool direc = true;
	movDado = 0.0f;
	
	glfwSetTime(0);
	////Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		mainWindow.getCambiaCamara() ? camera_selected = &camera_follow : camera_selected = &cameraXY;

		animaPersonaje(movPiglet, rotPiglet, movPigletOffset, rotPigletOffset, anima, deltaTime);
		
		//printf("get Time %f\n", glfwGetTime());
		//if(casillaPumpkin.isSelected())
		//Dentro de este if va todo eso
		
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

		//printf("Before condition: movDirZ=%.2f\n", movDirZ);
		
		if (direc) {
			if (movDirZ >= -1.0f) {
				movDirY = -1.0f;
				movDirZ -= movDirZOffset * deltaTime;
				printf("Inside condition (after update): movDirZ=%.2f\n", movDirZ);
				mainLight.setDir(glm::vec3(0.0f, movDirY, movDirZ));
			}
			else {
				direc = !direc;
			}
		}
		else {
			if (movDirZ < 1.0f) {
				movDirY = 1.0f;
				movDirZ += movDirZOffset * deltaTime;
				printf("Inside  second condition (after update): movDirZ=%.2f\n", movDirZ);
				mainLight.setDir(glm::vec3(0.0f, movDirY, movDirZ));
			}
			else {
				direc = !direc;
			}
		}
		



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

		//dados
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f,5.0f+movDado,0.0f));
		animaDados(movDado, rotDado, deltaTime);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Die4_M.RenderModel();
		
		//Tablero
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -8.5f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tablero_M.RenderModel();

		

		//Piglet
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(20.0f, -4.0f+movPiglet, 35.0f));
		model = glm::rotate(model, glm::radians(rotPiglet), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Piglet_M.RenderModel();

		//Tigger
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(12.0f, -4.0f+movTigger, 35.0f));
		model = glm::rotate(model, glm::radians(rotTigger), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tigger_M.RenderModel();

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
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-8.5f,-4.0f+movTree, 35.0f));
		model = glm::rotate(model, glm::radians(rotTree), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		HangmanTree_M.RenderModel();

		//Tiro al blanco
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-15.5f, -4.0f+movTiroAlBlanco, 35.0f));
		model = glm::rotate(model, glm::radians(rotTiroAlBlanco), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		TiroAlBlanco_M.RenderModel();

		//Chicharos toy story
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-22.5f, -3.0f+movChicharos, 35.0f));
		model = glm::rotate(model, glm::radians(rotChicharos), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Chicharos_M.RenderModel();

		//Slinky
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-29.5f, -4.0f+movSlinky, 35.0f));
		model = glm::rotate(model, glm::radians(rotSlinky), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Slinky_M.RenderModel();

		//Francesco
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-36.5f, -4.0f+movFrancesco, 35.0f));
		model = glm::rotate(model, glm::radians(rotFrancesco), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Francesco_M.RenderModel();

		//Pinocchio
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-43.5, -4.0f+movPinocchio, 35.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPinnochio), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pinocchio_M.RenderModel();

		//Mickey Mouse
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movMickey, 29.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotMickey), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mickey_M.RenderModel();

		//Winnie Pooh
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movWinnie, 22.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotWinnie), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Winnie_M.RenderModel();
		

		//Jam
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movJam, 15.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotJam), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Jam_M.RenderModel();

		//Princesa Atta
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movPrincesaAtta, 8.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPrincesaAtta), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PrincesaAtta_M.RenderModel();

		//Walle
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movWalle, 1.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotWalle), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Walle_M.RenderModel();

		//Nemo
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f + movNemo, -4.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotNemo), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Nemo_M.RenderModel();

		//Ralph
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movRalph, -11.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotRalph), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Ralph_M.RenderModel();

		//Tinkerbell
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, -4.0f+movTinkerbell, -18.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotTinkerbell), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tinkerbell_M.RenderModel();
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
		model = glm::translate(model, glm::vec3(-36.0f, -4.0f + movBingBong, -30.0f));
		model = glm::rotate(model, -270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotBingBong), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bing_Bong_M.RenderModel();

		//Red Cat
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-29.0f, -4.0f+movRedCat, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotRedCat), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		RedCat_M.RenderModel();

		//Megara
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-22.0f, -4.0f+movMegara, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotMegara), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Megara_M.RenderModel();

		//Mushu
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-15.0f, -4.0f+movMushu, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotMushu), glm::vec3(0.0, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mushu_M.RenderModel();

		//Mr. Flash
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-8.0f, -4.0f+movMrFlash, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotMrFlash), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MrFlash_M.RenderModel();

		//Simba
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.0f, -4.0f+movSimba, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotSimba), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Simba_M.RenderModel();

		//Pocahontas
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(6.0f, -4.0f+movPocahontas, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPocahontas), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pocahontas_M.RenderModel();

		//Sully
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(13.0f, -4.0f+movSully, -30.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotSully), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Sully_M.RenderModel();


		//Camioneta pizza planeta
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(18.0f, -4.0f+movCamioneta, -30.0f));
		model = glm::rotate(model, -270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotCamioneta), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CamionetaPP_M.RenderModel();

		//Pepita
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movPepita, -32.0f));
		model = glm::rotate(model, -225 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPepita), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pepita_M.RenderModel();

		//Cilindro Monsters Inc
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movCilindro, -26.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotCilindro), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Cilindro_M.RenderModel();


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

		//Fantasia Disney
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movFantasia, -5.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotFantasia), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Fantasia_M.RenderModel();

		//Nave BLN
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movNave, -0.5f));
		model = glm::rotate(model, glm::radians(rotNave), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Nave_M.RenderModel();

		//Pelota pixar
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(24.0f, -4.0f+movPelota, 10.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPelota), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pelota_M.RenderModel();

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
