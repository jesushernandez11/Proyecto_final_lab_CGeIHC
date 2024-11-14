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
#include <cstdlib>
#include <ctime>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include<irrKlang.h>

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
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> disd8(1, 8);
std::uniform_int_distribution<> disd4(1, 4);
const float toRadians = 3.14159265f / 180.0f;
using namespace irrklang;

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
float rotPumpkinOffset;
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
float rotPinocchio;
float rotPinocchioOffset;
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
float movDadoOffset;
float rotDadoXd8;
float rotDadoYd8;
float rotDadoZd8;
float rotDadoXd4;
float rotDadoYd4;
float rotDadoZd4;
float rotDadoOffset;
float movDirZ;
float movDirY;
float movDirX;
float movDirZOffset;
float orejaT;
float orejaTOffset;
float rotPiernaDerecha;
float rotPiernaDerechaOffset;
float rotPiernaIzquierda;
float rotPiernaIzquierdaOffset;
bool cicloNoche;
bool avanzaDumbo;
float movDumboX;
float movDumboZ;
float rotDumbo;
float limite=0;
float limiteXN=0.0f;
float limiteZN = 0.0f;
float movDumboXOffset;
float movDumboZOffset;
float rotPataDerechaDumbo;
float rotDumboOffset;

glm::vec3 rotacionesDado4[4]{
	glm::vec3(30.0f,0.0f,-90.0f),//Punta con numeros 1 hacia arriba
	glm::vec3(-120.0f,0.0f,0.0f),//Punta con numeros 2 hacia arriba
	glm::vec3(30.0f,0.0f,90.0f),//Punta con numeros 3 hacia arriba
	glm::vec3(0.0f,0.0f,0.0f)//Punta con numeros 4 hacia arriba
};
glm::vec3 rotacionesDado8[8]{
	glm::vec3(-35.0f,0.0f,35.0f), //Cara 1 hacia arriba
	glm::vec3(-45.0f, -45.0f, 180.0f), // Cara 2 hacia arriba
	glm::vec3(-35.0f, 0.0f, -35.0f), // Cara 3 hacia arriba
	glm::vec3(-45.0f, 45.0f, 180.0f),// Cara 4 hacia arriba
	glm::vec3(35.0f, 0.0f, -35.0f),// Cara 5 hacia arriba
	glm::vec3(45.0f, -45.0f, 180.0f),// Cara 6 hacia arriba
	glm::vec3(35.0f, 0.0f, 35.0f),// Cara 7 hacia arriba
	glm::vec3(45.0f, 45.0f, 180.0f) // Cara 8 hacia arriba
};
enum DireccionMovimiento {
	DERECHA,
	ARRIBA,
	IZQUIERDA,
	ABAJO
};

Sphere sp=Sphere(1.0f,20,20);
const float GRAVITY = 0.0981f;
const float BOUNCE_DAMPING = 0.5f;
const glm::vec3 START_POSITION(0.0f, 5.0f, 0.0f);
const float FLOOR_Y = 0.0f;

bool anima;
bool avanza;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;


Camera camera_follow=Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, -30.0f, 0.3f, 0.5f);
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
Model Dumbo_Cuerpo_M;
Model Oreja_izq_M;
Model Oreja_der_M;
Model Pata_izq_M;
Model Pata_der_M;
Model Lumiere_M;
Model PixarLamp_M;
Model Soul_M;
Model LampPP_M;
Model Mate_M;
Model Rueda_tras_izq_M;
Model Rueda_tras_der_M;
Model Rueda_del_izq_M;
Model Rueda_del_der_M;
Model Gancho_Mate_M;
Model MikeWasawski_M;
Model CastilloCenicienta_M;
Model MGM_Disney;
Model OwlHouse_M;
Model Hooty_OwlHouse_M;

//Declaracion para sonido
ISoundEngine* engine = createIrrKlangDevice();


Skybox skybox;
Skybox night;

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
			casilla = true;
		}
	}
}

void animaDados(float deltaTime, float& rotDadoXd8, float& rotDadoYd8, float& rotDadoZd8, float& rotDadoXd4,
	float& rotDadoYd4, float& rotDadoZd4, int &caraSeld8, int &caraSeld4, int &suma, float &movDado) {
		rotDadoXd8 = 0.0f;
		rotDadoYd8 = 0.0f;
		rotDadoZd8 = 0.0f;
		rotDadoXd4 = 0.0f;
		rotDadoYd4 = 0.0f;
		rotDadoZd4 = 0.0f;
		if (movDado >= -1.0f)
			movDado -= movDadoOffset * deltaTime;
		
		caraSeld8 = disd8(gen);
		caraSeld4 = disd4(gen);
		printf("Numero de cara dado d8: %i\n", caraSeld8);
		printf("Numero de cara dado d4: %i\n", caraSeld4);
		if (suma <= 40) {
			suma += caraSeld4 + caraSeld8; //Para seleccionar la casilla
		}
		else {
			suma = 0;
		}
		printf("Numero de suma: %i\n", suma);

		rotDadoXd8 = rotacionesDado8[caraSeld8 - 1].x;
		rotDadoYd8 = rotacionesDado8[caraSeld8 - 1].y;
		rotDadoZd8 = rotacionesDado8[caraSeld8 - 1].z;

		rotDadoXd4 = rotacionesDado4[caraSeld4 - 1].x;
		rotDadoYd4 = rotacionesDado4[caraSeld4 - 1].y;
		rotDadoZd4 = rotacionesDado4[caraSeld4 - 1].z;
		
		mainWindow.setTiraDados(false);
		avanzaDumbo = true;
	
	
}
///////////////////////////////KEYFRAMES/////////////////////


bool animacion = false;


//variables para keyframes
float reproduciranimacion, habilitaranimacion, guardoFrame, reinicioFrame, ciclo, ciclo2, contador = 0;
//NEW// Keyframes
float posXmate = 20.0, posYmate = 1.0, posZmate = -55.0;
float	movMate_x = 0.0f, movMate_z = 0.0f;
float giroMate = 0;
float rotLlantaMate = 0.0f;
float rotGanchoMate = 0.0f;

#define MAX_FRAMES 100
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float movMate_x;		//Variable para PosicionX
	float movMate_z;		//Variable para PosicionY
	float movMate_xInc;		//Variable para IncrementoX
	float movMate_zInc;		//Variable para IncrementoY
	float giroMate;
	float giroMateInc;
	float rotLlantaMate;
	float rotLlantaMateInc;
	float rot;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;
std::ofstream file;

std::string archivo = "animacion.txt";
glm::vec3 posMate;

void saveFrame(void) //tecla L
{


	printf("frameindex %d\n", FrameIndex);
	file.open(archivo, std::fstream::app); //Para añadir al último del archivo
	file << "KeyFrame[" << FrameIndex << "].movMate_x=" << movMate_x << std::endl;
	file << "KeyFrame[" << FrameIndex << "].movMate_z=" << movMate_z << std::endl;
	file << "KeyFrame[" << FrameIndex << "].giroMate=" << giroMate << std::endl;

	KeyFrame[FrameIndex].movMate_x = movMate_x;
	KeyFrame[FrameIndex].movMate_z = movMate_z;
	KeyFrame[FrameIndex].giroMate = giroMate;//completar
	//no volatil, agregar una forma de escribir a un archivo para guardar los frames
	FrameIndex++;
	file.close();

}
void loadFrame(void) {//tecla k
	std::ifstream arch(archivo);
	float movMateX, movMateZ, rotMate;
	while (arch >> movMateX >> movMateZ >> rotMate) {
		KeyFrame[FrameIndex].movMate_x = movMateX;
		KeyFrame[FrameIndex].movMate_z = movMateZ;
		KeyFrame[FrameIndex].giroMate = rotMate;
	}
	std::cout << "KeyFrame[" << FrameIndex << "].movMate_x = " << movMateX<<std::endl;
	std::cout << "KeyFrame[" << FrameIndex << "].movMate_z = " << movMateX<<std::endl;
	std::cout << "KeyFrame[" << FrameIndex << "].giroMate = " << movMateX<<std::endl;
	FrameIndex++;
	arch.close();
}

void resetElements(void) //Tecla 0
{

	movMate_x = KeyFrame[0].movMate_x;
	movMate_z = KeyFrame[0].movMate_z;
	giroMate = KeyFrame[0].giroMate;
}

void interpolation(void)
{
	KeyFrame[playIndex].movMate_xInc = (KeyFrame[playIndex + 1].movMate_x - KeyFrame[playIndex].movMate_x) / i_max_steps;
	KeyFrame[playIndex].movMate_zInc = (KeyFrame[playIndex + 1].movMate_z - KeyFrame[playIndex].movMate_z) / i_max_steps;
	KeyFrame[playIndex].giroMateInc = (KeyFrame[playIndex + 1].giroMate - KeyFrame[playIndex].giroMate) / i_max_steps;

}


void animate(void)
{
	//Movimiento del objeto con barra espaciadora
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //fin de animación entre frames?
		{
			playIndex++;
			printf("playindex : %d\n", playIndex);
			if (playIndex > FrameIndex - 2)	//Fin de toda la animación con último frame?
			{
				printf("Frame index= %d\n", FrameIndex);
				printf("termino la animacion\n");
				playIndex = 0;
				play = false;
			}
			else //Interpolación del próximo cuadro
			{

				i_curr_steps = 0; //Resetea contador
				//Interpolar
				interpolation();
			}
		}
		else
		{
			//Dibujar Animación
			movMate_x += KeyFrame[playIndex].movMate_xInc;
			movMate_z += KeyFrame[playIndex].movMate_zInc;
			giroMate += KeyFrame[playIndex].giroMateInc;
			i_curr_steps++;

		}

	}
}
void inputKeyframes(bool* keys)
{
	if (keys[GLFW_KEY_SPACE])
	{
		if (reproduciranimacion < 1)
		{
			if (play == false && (FrameIndex > 1))
			{
				resetElements();
				//First Interpolation				
				interpolation();
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
				reproduciranimacion++;
				printf("\n presiona 0 para habilitar reproducir de nuevo la animación'\n");
				habilitaranimacion = 0;

			}
			else
			{
				play = false;

			}
		}
	}
	if (keys[GLFW_KEY_0])
	{
		if (habilitaranimacion < 1 && reproduciranimacion>0)
		{
			printf("Ya puedes reproducir de nuevo la animación con la tecla de barra espaciadora'\n");
			reproduciranimacion = 0;
			habilitaranimacion++;

		}
	}

	/*if (keys[GLFW_KEY_M])
	{
		if (guardoFrame < 1)
		{
			saveFrame();
			printf("movMate_x es: %f\n", movMate_x);
			printf("movMate_z es: %f\n", movMate_z);
			printf("giroMate  es: %f\n", giroMate);
			printf("presiona P para habilitar guardar otro frame'\n");
			guardoFrame++;
			reinicioFrame = 0;
		}
	}*/
	if (keys[GLFW_KEY_K]) {
		if (guardoFrame < 1) {
			loadFrame();
			printf("Presiona la tecla espacio para reproducir la animacion\n");
			guardoFrame++;
		}
	}
	if (keys[GLFW_KEY_P])
	{
		if (reinicioFrame < 1)
		{
			guardoFrame = 0;
			reinicioFrame++;
			printf("Ya puedes guardar otro frame presionando la tecla L'\n");
		}
	}


	if (keys[GLFW_KEY_1])
	{
		if (ciclo < 1)
		{
			//printf("movMate_x es: %f\n", movMate_x);
			movMate_x -= 5.0f;
			printf("\n movMate_x es: %f\n", movMate_x);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 2 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_2])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;
			printf("\n Ya puedes modificar tu variable presionando la tecla 1\n");
		}
	}

	if (keys[GLFW_KEY_3])
	{
		if (ciclo < 1)
		{
			//printf("movMate_x es: %f\n", movMate_x);
			movMate_x += 5.0f;
			printf("\n movMate_x es: %f\n", movMate_x);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 4 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_4])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;
			printf("\n Ya puedes modificar tu variable presionando la tecla 3\n");
		}
	}

	if (keys[GLFW_KEY_5])
	{
		if (ciclo < 1)
		{
			//printf("movMate_x es: %f\n", movMate_x);
			movMate_z -= 5.0f;
			printf("\n movMate_z es: %f\n", movMate_z);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 6 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_6])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;
			printf("\n Ya puedes modificar tu variable presionando la tecla 5\n");
		}
	}

	if (keys[GLFW_KEY_7])
	{
		if (ciclo < 1)
		{
			//printf("movMate_x es: %f\n", movMate_x);
			movMate_z += 5.0f;
			printf("\n movMate_z es: %f\n", movMate_z);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla 8 para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_8])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;
			printf("\n Ya puedes modificar tu variable presionando la tecla 7\n");
		}
	}


	if (keys[GLFW_KEY_9])
	{
		if (ciclo < 1)
		{
			//printf("movMate_x es: %f\n", movMate_x);
			giroMate += 90.0f;
			printf("\n girAvion es: %f\n", giroMate);
			ciclo++;
			ciclo2 = 0;
			printf("\n Presiona la tecla Q para poder habilitar la variable\n");
		}

	}
	if (keys[GLFW_KEY_Q])
	{
		if (ciclo2 < 1)
		{
			ciclo = 0;
			ciclo2++;
			printf("\n Ya puedes modificar tu variable presionando la tecla 9\n");
		}
	}

}

///////////////* FIN KEYFRAMES*////////////////////////////
void reproducirSonidoEspacial(glm::vec3 posicionJugador, glm::vec3 posicionSonido, float rangoDeteccion) {
	// Calcula la distancia entre el jugador y la posición del sonido
	float distancia = glm::distance(posicionJugador, posicionSonido);

	if (distancia <= rangoDeteccion) {
		// Reproduce el sonido espacial si el jugador está dentro del rango
		engine->play3D("audio/mike_wazowski.ogg", vec3df(posicionSonido.x, posicionSonido.y, posicionSonido.z));
	}
}


int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	
	

	if (!engine)
		printf("No se pudo cargar el motor de sonido irrklang");

	
	sp.init();
	sp.load();

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/piso.jpg");
	pisoTexture.LoadTexture();
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
	Dumbo_Cuerpo_M = Model();
	Dumbo_Cuerpo_M.LoadModel("Models/dumbo.obj");
	Oreja_der_M = Model();
	Oreja_der_M.LoadModel("Models/oreja_der_dumbo.obj");
	Oreja_izq_M = Model();
	Oreja_izq_M.LoadModel("Models/oreja_izq_dumbo.obj");
	Pata_der_M = Model();
	Pata_der_M.LoadModel("Models/pata_der_dumbo.obj");
	Pata_izq_M = Model();
	Pata_izq_M.LoadModel("Models/pata_izq_dumbo.obj");
	PixarLamp_M = Model();
	PixarLamp_M.LoadModel("Models/pixar_lamp.obj");
	Soul_M = Model();
	Soul_M.LoadModel("Models/soul.obj");
	LampPP_M = Model();
	LampPP_M.LoadModel("Models/lamp_pp.obj");
	Lumiere_M = Model();
	Lumiere_M.LoadModel("Models/lumiere.obj");
	Mate_M = Model();
	Mate_M.LoadModel("Models/mate.obj");
	Rueda_tras_izq_M = Model();
	Rueda_tras_izq_M.LoadModel("Models/rueda_tras_izq_mate.obj");
	Rueda_tras_der_M = Model();
	Rueda_tras_der_M.LoadModel("Models/rueda_tras_der_mate.obj");
	Rueda_del_izq_M = Model();
	Rueda_del_izq_M.LoadModel("Models/rueda_del_izq_mate.obj");
	Rueda_del_der_M = Model();
	Rueda_del_der_M.LoadModel("Models/rueda_del_der_mate.obj");
	Gancho_Mate_M = Model();
	Gancho_Mate_M.LoadModel("Models/gancho_mate.obj");
	MikeWasawski_M = Model();
	MikeWasawski_M.LoadModel("Models/mike_wasawski.obj");
	CastilloCenicienta_M = Model();
	CastilloCenicienta_M.LoadModel("Models/castillo_cenicienta.obj");
	MGM_Disney = Model();
	MGM_Disney.LoadModel("Models/MGM_disney.obj");
	OwlHouse_M = Model();
	OwlHouse_M.LoadModel("Models/owl_house.obj");
	Hooty_OwlHouse_M = Model();
	Hooty_OwlHouse_M.LoadModel("Models/hooty_owl_house.obj");
	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/miramar_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/miramar_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/miramar_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/miramar_up.tga");
	skyboxFaces.push_back("Textures/Skybox/miramar_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/miramar_ft.tga");

	std::vector<std::string> skyBoxNight;
	skyBoxNight.push_back("Textures/Skybox/indigo_rt.jpg");
	skyBoxNight.push_back("Textures/Skybox/indigo_lf.jpg");
	skyBoxNight.push_back("Textures/Skybox/indigo_dn.jpg");
	skyBoxNight.push_back("Textures/Skybox/indigo_up.jpg");
	skyBoxNight.push_back("Textures/Skybox/indigo_bk.jpg");
	skyBoxNight.push_back("Textures/Skybox/indigo_ft.jpg");


	skybox = Skybox(skyboxFaces);
	night = Skybox(skyBoxNight);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, 1.0f, -1.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	pointLights[0] = PointLight(0.827f, 0.827f, 0.827f, 
		0.0f, 1.0f,
		-6.0f, 1.5f, 1.5f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;
	pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,
		0.0f, 1.0f,
		-54.5f, 2.5f, 33.75f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;
	pointLights[2] = PointLight(0.686, 0.933, 0.933,
		0.0f, 1.0f,
		-39.5f, 1.5f, -40.0f,
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
	/*spotLights[1] = SpotLight(0.0f, 1.0f, 0.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;*/
	
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
	rotPumpkinOffset = 10.0f;
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
	movTigger = 0.0f;
	movTiggerOffset = 0.05f;
	rotTigger = 0.0f;
	rotTiggerOffset = 10.0f;
	movTree = 0.0f;
	movTreeOffset = 0.05f;
	rotTree = 0.0f;
	rotTreeOffset = 10.0f;
	movTiroAlBlanco = 0.0f;
	movTiroAlBlancoOffset = 0.05f;
	rotTiroAlBlanco = 0.0f;
	rotTiroAlBlancoOffset = 10.0f;
	movSlinky = 0.0f;
	movSlinkyOffset = 0.05f;
	rotSlinky = 0.0f;
	rotSlinkyOffset = 10.0f;
	movFrancesco = 0.0f;
	movFrancescoOffset = 0.05f;
	rotFrancesco = 0.0f;
	rotFrancescoOffset = 10.0f;
	movPinocchio = 0.0f;
	movPinocchioOffset = 0.05f;
	rotPinocchio = 0.0f;
	rotPinocchioOffset = 10.0f;
	movMickey = 0.0f;
	movMickeyOffset = 0.05f;
	rotMickey = 0.0f;
	rotMickeyOffset = 10.0f;
	movWinnie = 0.0f;
	movWinnieOffset = 0.05f;
	rotWinnie = 0.0f;
	rotWinnieOffset = 10.0f;
	movPrincesaAtta = 0.0f;
	movPrincesaAttaOffset = 0.05f;
	rotPrincesaAtta = 0.0f;
	rotPrincesaAttaOffset = 10.0f;
	movWalle = 0.0f;
	movWalleOffset = 0.05f;
	rotWalle = 0.0f;
	rotWalleOffset = 10.0f;
	movRalph = 0.0f;
	movRalphOffset = 0.05f;
	rotRalph = 0.0f;
	rotRalphOffset = 10.0f;
	movTinkerbell = 0.0f;
	movTinkerbellOffset = 0.05f;
	rotTinkerbell = 0.0f;
	rotTinkerbellOffset = 10.0f;
	movBingBong = 0.0f;
	movBingBongOffset = 0.05f;
	rotBingBong = 0.0f;
	rotBingBongOffset = 10.0f;
	movRedCat = 0.0f;
	movRedCatOffset = 0.05f;
	rotRedCat = 0.0f;
	rotRedCatOffset = 10.0f;
	movMushu = 0.0f;
	movMushuOffset = 0.05f;
	rotMushu = 0.0f;
	rotMushuOffset = 10.0f;
	movMrFlash = 0.0f;
	movMrFlashOffset = 0.05f;
	rotMrFlash = 0.0f;
	rotMrFlashOffset = 10.0f;
	movSimba = 0.0f;
	movSimbaOffset = 0.05f;
	rotSimba = 0.0f;
	rotSimbaOffset = 10.0f;
	movPocahontas = 0.0f;
	movPocahontasOffset = 0.05f;
	rotPocahontas = 0.0f;
	rotPocahontasOffset = 10.0f;
	movSully = 0.0f;
	movSullyOffset = 0.05f;
	rotSully = 0.0f;
	rotSullyOffset = 10.0f;
	movPepita = 0.0f;
	movPepitaOffset = 0.05f;
	rotPepita = 0.0f;
	rotPepitaOffset = 10.0f;
	movCilindro = 0.0f;
	movCilindroOffset = 0.05f;
	rotCilindro = 0.0f;
	rotCilindroOffset = 10.0f;
	movMcQueen = 0.0f;
	movMcQueenOffset = 0.05;
	rotMcQueen = 0.0f;
	rotMcQueenOffset = 10.0f;
	movForky = 0.0f;
	movForkyOffset = 0.05f;
	rotForky = 0.0f;
	rotForkyOffset = 10.0f;
	movNave = 0.0f;
	movNaveOffset = 0.05f;
	rotNave = 0.0f;
	rotNaveOffset = 10.0f;
	movFantasia = 0.0f;
	movFantasiaOffset = 0.05f;
	rotFantasia = 0.0f;
	rotFantasiaOffset = 10.0f;
	movPelota = 0.0f;
	movPelotaOffset = 0.05f;
	rotPelota = 0.0f;
	rotPelotaOffset = 10.0f;
	movUpHouse = 0.0f;
	movUpHouseOffset = 0.05f;
	rotUpHouse = 0.0f;
	rotUpHouseOffset = 10.0f;
	movAnemona = 0.0f;
	movAnemonaOffset = 0.05f;
	rotAnemona = 0.0f;
	rotAnemonaOffset = 10.0f;
	movCasaMickey = 0.0f;
	movCamionetaOffset = 0.05f;
	rotCasaMickey = 0.0f;
	rotCasaMickeyOffset = 10.0f;


	movDirX = 0.0;
	movDirY = -1.0f;
	movDirZ = 1.0f;
	movDirZOffset = 0.001f;
	orejaT = 0.0f;
	orejaTOffset = 0.01f;
	rotPiernaDerecha = 0.0f;
	rotPiernaDerechaOffset = 0.1f;
	movDado = 5.0f;
	rotDadoXd8 = 0.0f;
	rotDadoYd8 = 0.0f;
	rotDadoZd8 = 0.0f;
	rotDadoXd4 = 0.0f;
	rotDadoYd4 = 0.0f;
	rotDadoZd4 = 0.0f;
	avanza = true;
	anima = true;
	avanzaDumbo = false;
	bool direc = true;
	cicloNoche = false;
	int caraSeld8=0;
	int caraSeld4 = 0;
	movDado = 0.0f;
	int suma = 0;
	movDumboX = 27.0f;
	movDumboXOffset = 0.2f;
	movDumboZ = 40.0f;
	movDumboZOffset = 0.5f;
	rotPataDerechaDumbo = 0.0f;
	rotDumboOffset = 10.0f;
	DireccionMovimiento direccionActual = IZQUIERDA;
	glfwSetTime(0);
	////Loop mientras no se cierra la ventana
	printf("\nTeclas para uso de Keyframes:\n1.-Presionar barra espaciadora para reproducir animacion.\n2.-Presionar 0 para volver a habilitar reproduccion de la animacion\n");
	printf("3.-Presiona L para guardar frame\n4.-Presiona P para habilitar guardar nuevo frame\n5.-Presiona 1 para mover en X\n6.-Presiona 2 para habilitar mover en X");
	engine->play2D("audio/dumbo_circus.mp3", true); //Soundtrack
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;
		mainWindow.getCambiaCamara() ? camera_selected = &camera_follow : camera_selected = &cameraXY;
		
		

		

		orejaT += orejaTOffset * deltaTime;
		rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
		
		
		

		//Recibir eventos del usuario
		glfwPollEvents();
		camera_selected->keyControl(mainWindow.getsKeys(), deltaTime, mainWindow.getCambiaCamara());
		camera_selected->mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		inputKeyframes(mainWindow.getsKeys());
		animate();

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		cicloNoche? night.DrawSkybox(camera_selected->calculateViewMatrix(), projection):
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
				cicloNoche = false;
				movDirZ -= movDirZOffset * deltaTime;
				//printf("Inside condition (after update): movDirZ=%.2f\n", movDirZ);
				mainLight.setDir(glm::vec3(0.0f, movDirY, movDirZ));
			}
			else {
				direc = !direc;
			}
		}
		else {
			if (movDirZ < 1.0f) {
				movDirY = 1.0f;
				cicloNoche = true;
				movDirZ += movDirZOffset * deltaTime;
				//printf("Inside  second condition (after update): movDirZ=%.2f\n", movDirZ);
				mainLight.setDir(glm::vec3(0.0f, movDirY, movDirZ));
			}
			else {
				direc = !direc;
			}
		}
		
		cicloNoche ? shaderList[0].SetPointLights(pointLights, pointLightCount) :
			shaderList[0].SetPointLights(pointLights, pointLightCount - 3);
		
		if (mainWindow.getTiraDados()) {
			animaDados(deltaTime, rotDadoXd8, rotDadoYd8, rotDadoZd8, rotDadoXd4, rotDadoYd4, rotDadoZd4, caraSeld8, caraSeld4, suma, movDado);
		}


		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::mat4 modelAuxMate(1.0f);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[2]->RenderMesh();

		
		
		
		
		if (avanzaDumbo) {
			switch (suma)
			{
			case 1:
				if (movDumboX > 20.0f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha) * deltaTime;
				}
				else {
					animaPersonaje(movPiglet, rotPiglet, movPigletOffset, rotPigletOffset, anima, deltaTime);
				}
				
				break;
			case 2:
				if (movDumboX > 12.0f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movTigger, rotTigger, movTiggerOffset, rotTiggerOffset, anima, deltaTime);
				}
				
				break;
			case 3:
				if (movDumboX > 5.0f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movPumpkin, rotPumpkin, movPumpkinOffset, rotPumpkinOffset, anima, deltaTime);
				}
				
				break;
			case 4:
				if (movDumboX > -2.0f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movSingingFlowers, rotSingingFlowers, movSingingFlowersOffset, rotSingingFlowersOffset, anima, deltaTime);
				}
				
				break;
			case 5:
				if (movDumboX > -9.0f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movTree, rotTree, movTreeOffset, rotTreeOffset, anima, deltaTime);
				}
				
				break;
			case 6:
				if (movDumboX > -15.5f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movTiroAlBlanco, rotTiroAlBlanco, movTiroAlBlancoOffset, rotTiroAlBlancoOffset, anima, deltaTime);
				}
				
				break;
			case 7:
				if (movDumboX > -22.5f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movChicharos, rotChicharos, movChicharosOffset, rotChicharosOffset, anima, deltaTime);
				}
				
				break;
			case 8:
				if (movDumboX > -29.5f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movSlinky, rotSlinky, movSlinkyOffset, rotSlinkyOffset, anima, deltaTime);
				}
				
				break;
			case 9:
				if (movDumboX > -36.5f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movFrancesco, rotFrancesco, movFrancescoOffset, rotFrancescoOffset, anima, deltaTime);
				}
				
				break;
			case 10:
				if (movDumboX > -43.5f) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPiernaDerecha += rotPiernaDerechaOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					animaPersonaje(movPinocchio, rotPinocchio, movPinocchioOffset, rotPinocchioOffset, anima, deltaTime);
				}
				
				break;
			case 11:
				
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > 29.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movMickey, rotMickey, movMickeyOffset, rotMickeyOffset, anima, deltaTime);
				}
				
				break;
			case 12:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > 22.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movWinnie, rotWinnie, movWinnieOffset, rotWinnieOffset, anima, deltaTime);
				}
				
				break;
			case 13:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > 15.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movJam, rotJam, movJamOffset, rotJamOffset, anima, deltaTime);
				}
				
				break;
			case 14:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > 8.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movPrincesaAtta, rotPrincesaAtta, movPrincesaAttaOffset, rotPrincesaAttaOffset, anima, deltaTime);
				}
				
				break;
			case 15:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > 1.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					
					
					animaPersonaje(movWalle, rotWalle, movWalleOffset, rotWalleOffset, anima, deltaTime);
				}
				
				break;
			case 16:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > -4.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movNemo, rotNemo, movNemoOffset, rotNemoOffset, anima, deltaTime);
				}
				
				break;
			case 17:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > -11.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movRalph, rotRalph, movRalphOffset, rotRalphOffset, anima, deltaTime);
				}
				
				break;
			case 18:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > -18.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movTinkerbell, rotTinkerbell, movTinkerbellOffset, rotTinkerbellOffset, anima, deltaTime);
				}
				
				break;
			case 19:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > -27.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movAlegria, rotAlegria, movAlegriaOffset, rotAlegriaOffset, anima, deltaTime);
				}
				
				break;
			case 20:
				if (movDumboX > -43.5) {
					movDumboX -= movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -90.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ > -32.0f) {
						movDumboZ -= movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movStich, rotStich, movStichOffset, rotStichOffset, anima, deltaTime);
					
					
				}
				
				break;
			case 21:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -36.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movBingBong, rotBingBong, movBingBongOffset, rotBingBongOffset, anima, deltaTime);
				}
				
				break;
			case 22:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -29.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movRedCat, rotRedCat, movRedCatOffset, rotRedCatOffset, anima, deltaTime);
				}
				
				break;
			case 23:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -22.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movMegara, rotMegara, movMegaraOffset, rotMegaraOffset, anima, deltaTime);
				}
				
				break;
			case 24:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -15.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movMushu, rotMushu, movMushuOffset, rotMushuOffset, anima, deltaTime);
				}
				
				break;
			case 25:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -8.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movMrFlash, rotMrFlash, movMrFlashOffset, rotMrFlashOffset, anima, deltaTime);
				}
				
				break;
			case 26:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < -1.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movSimba, rotSimba, movSimbaOffset, rotSimbaOffset, anima, deltaTime);
				}
				
				break;
			case 27:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < 6.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movPocahontas, rotPocahontas, movPocahontasOffset, rotPocahontasOffset, anima, deltaTime);

				}
				
				break;
			case 28:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < 13.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movSully, rotSully, movSullyOffset, rotSullyOffset, anima, deltaTime);
				}
				
				break;
			case 29:
				if (movDumboZ > -32.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < 18.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movCamioneta, rotCamioneta, movCamionetaOffset, rotCamionetaOffset, anima, deltaTime);
				}
				
				break;
			case 30:
				if (movDumboZ > 24.0f) {
					movDumboZ -= movDumboZOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -180.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboX < 26.0f) {
						movDumboX += movDumboXOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movPepita, rotPepita, movPepitaOffset, rotPepitaOffset, anima, deltaTime);
				}
				
				break;
			case 31:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -26.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movCilindro, rotCilindro, movCilindroOffset, rotCilindroOffset, anima, deltaTime);
				}
				
				
				break;
			case 32:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -20.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movMcQueen, rotMcQueen, movMcQueenOffset, rotMcQueenOffset, anima, deltaTime);
				}
				
				break;
			case 33:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -12.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movForky, rotForky, movForkyOffset, rotForkyOffset, anima, deltaTime);
				}
				
				break;
			case 34:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -5.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movFantasia, rotFantasia, movFantasiaOffset, rotFantasiaOffset, anima, deltaTime);
				}
				
				break;
			case 35:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -0.5f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movNave, rotNave, movNaveOffset, rotNaveOffset, anima, deltaTime);
				}
				
				break;
			case 36:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < -10.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movPelota, rotPelota, movPelotaOffset, rotPelotaOffset, anima, deltaTime);
				}
				
				break;
			case 37:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < 17.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movUpHouse, rotUpHouse, movUpHouseOffset, rotUpHouseOffset, anima, deltaTime);
				}
				
				break;
			case 38:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < 23.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movAnemona, rotAnemona, movAnemonaOffset, rotAnemonaOffset, anima, deltaTime);
				}
				
				break;
			case 39:
				
				if (movDumboX < 26.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -270.0)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < 29.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
					animaPersonaje(movCasaMickey, rotCasaMickey, movCasaMickeyOffset, rotCasaMickeyOffset, anima, deltaTime);
				}
				
				break;
			
			default:
				
				
				if (movDumboX < 27.0f) {
					movDumboX += movDumboXOffset * deltaTime;
					rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
				}
				else {
					if (rotDumbo > -360.0f)
						rotDumbo -= rotDumboOffset * deltaTime;
					if (movDumboZ < 35.0f) {
						movDumboZ += movDumboZOffset * deltaTime;
						rotPataDerechaDumbo = 0.5 * sin(rotPiernaDerecha);
					}
				}
				
				movDumboX = 27.0f;
				movDumboZ = 40.0f;
				rotDumbo = 0.0f;
				suma = 0;
				break;
				
			}
		}
		

		//dado 8 caras
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-8.0f,movDado,0.0f));
		model = glm::rotate(model, rotDadoXd8*toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, rotDadoYd8*toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotDadoZd8*toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Die8_M.RenderModel();
		
		//Dado 4 caras
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(8.0f, movDado, 0.0f));
		model = glm::rotate(model, rotDadoXd4 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, rotDadoYd4 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotDadoZd4 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Die4_M.RenderModel();
		//Tablero
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -8.5f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Tablero_M.RenderModel();

		model = glm::mat4(1.0f);
		posMate = glm::vec3(posXmate + movMate_x, posYmate, posZmate + movMate_z);
		model = glm::translate(model, posMate);
		model = glm::rotate(model, giroMate*toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		modelAuxMate = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mate_M.RenderModel();

		model = modelAuxMate;
		model = glm::rotate(model, rotLlantaMate * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Rueda_del_der_M.RenderModel();
	
		//Dumbo
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(movDumboX, 1.5f, movDumboZ));
		pointLights[0].setPosition(model[3]);
		printf("%i", (int)rotDumbo);
		
		model = glm::rotate(model, rotDumbo * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		modelaux = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dumbo_Cuerpo_M.RenderModel();

		//Oreja derecha dumbo
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.35f, 0.4f, -0.2f));
		model = glm::rotate(model, 0.5f*sin(orejaT), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::translate(model, glm::vec3(-0.2, -0.3, 0.3));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Oreja_der_M.RenderModel();

		//Oreja izquierda Dumbo
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.35f, 0.4f, 0.2f));
		model = glm::rotate(model, -0.5f*sin(orejaT), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::translate(model, glm::vec3(-0.3f, 0.25f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Oreja_izq_M.RenderModel();

		//Pata derecha Dumbo
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.1f, -0.4f, -0.3f));
		model = glm::rotate(model, rotPataDerechaDumbo, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.1f, -0.1f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pata_der_M.RenderModel();
		
		//Pata izquierda Dumbo
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.1f, -0.4f, 0.3f));
		model = glm::rotate(model, -rotPataDerechaDumbo, glm::vec3(0.0f, 0.0f, 1.0f));
		//model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		model = glm::translate(model, glm::vec3(-0.1f, -0.1f, -0.15f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pata_izq_M.RenderModel();
		/*color = glm::vec3(1.0f, 0.45265f, 0.24132);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_brillante.UseMaterial(uniformSpecularIntensity, uniformShininess);
		sp.render();*/

		
		
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
		model = glm::translate(model, glm::vec3(5.0f, -4.0f+movPumpkin, 35.0f));
		model = glm::rotate(model, glm::radians(rotPumpkin), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pumpkin_M.RenderModel();

		//Singing Flowers
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.0f, -4.0f + movSingingFlowers, 35.0f));
		model = glm::rotate(model, glm::radians(rotSingingFlowers), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		SingingFlowers_M.RenderModel();

		//Tree hangman
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-9.0f,-4.0f+movTree, 35.0f));
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
		model = glm::translate(model, glm::vec3(-43.5f, -4.0f+movPinocchio, 35.0f));
		model = glm::rotate(model, -45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotPinocchio), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Pinocchio_M.RenderModel();

		
		//Pixar Lamp
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-57.5f, 2.5f, 35.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		PixarLamp_M.RenderModel();

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

		//Soul
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-40.0f, 1.5f, -40.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Soul_M.RenderModel();

		

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

		//Castillo cenicienta
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(60.0f, 0.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		CastilloCenicienta_M.RenderModel();

		//MGM Estudios Disney
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-110.0f, 2.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		MGM_Disney.RenderModel();

		//Owl house (La casa del buho)
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 2.0f, -80.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		OwlHouse_M.RenderModel();

		//Hooty (La casa del buho)
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 2.0f, 80.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hooty_OwlHouse_M.RenderModel();
		glUseProgram(0);

		mainWindow.swapBuffers();
	}
	engine->drop();
	return 0;
}
