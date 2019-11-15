//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//************** Alumno : Ramirez Elias Brian Armando *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include <MMSystem.h>
#include <Windows.h>

int w = 500, h = 500;

int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture piso1;
CTexture pared1;
CTexture pared2;
CTexture pared3;
CTexture techo;
CTexture alfombra;
CTexture madera;
CTexture madera3;
CTexture madera4;
CTexture madera5;
CTexture madera6;
CTexture madera7;
CTexture puerta;

CTexture colcha1;
CTexture colcha2;
CTexture verde;
CTexture rojo;
CTexture amarillo;
CTexture rosa;
CTexture spiderman;
CTexture superman;
CTexture america;
CTexture cajon;
CTexture cortina;
CTexture mueble1;
CTexture mueble2;
CTexture mueble3;


CTexture tree;

CFiguras sky;
CFiguras f_antena;

//Figuras de 3D Studio
CModel silla;
CModel libros;
CModel lamp1;
CModel lamp2;
CModel planta;
CModel tom;
CModel nave;
CModel carro;
CModel libro2;
CModel libro3;
CModel pillow1;
CModel pillow2;



void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

//NEW// Keyframes
float arriba = 0;
float grados = 0.0;
float lado = 0.0;

#define MAX_FRAMES 30 // Cuantos cuadros capturamos por segundo
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame  // Debemos declarar la variable y otra que es su incremento
{
	//Variables para GUARDAR Key Frames
	float arriba;
	float grados;
	float lado;
	float arribaInc;
	float gradosInc;
	float ladoInc;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 20;			//introducir datos
bool play = false;  //Play en falso
int playIndex = 0;

int frame = 0, time, timebase = 0;
char s[30];

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable (GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();


	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	piso1.LoadTGA("madera/piso2.tga");
	piso1.BuildGLTexture();
	piso1.ReleaseImage();

	pared1.LoadTGA("pared/pared1.tga");
	pared1.BuildGLTexture();
	pared1.ReleaseImage();

	pared2.LoadTGA("pared/pared4.tga");
	pared2.BuildGLTexture();
	pared2.ReleaseImage();

	pared3.LoadTGA("pared/pared3.tga");
	pared3.BuildGLTexture();
	pared3.ReleaseImage();

	techo.LoadTGA("pared/techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	alfombra.LoadTGA("madera/alfombra.tga");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	madera.LoadTGA("madera/madera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	madera3.LoadTGA("madera/madera3.tga");
	madera3.BuildGLTexture();
	madera3.ReleaseImage();

	madera4.LoadTGA("madera/madera4.tga");
	madera4.BuildGLTexture();
	madera4.ReleaseImage();

	madera5.LoadTGA("madera/madera5.tga");
	madera5.BuildGLTexture();
	madera5.ReleaseImage();

	madera6.LoadTGA("madera/madera6.tga");
	madera6.BuildGLTexture();
	madera6.ReleaseImage();

	madera7.LoadTGA("madera/madera7.tga");
	madera7.BuildGLTexture();
	madera7.ReleaseImage();

	colcha1.LoadTGA("madera/colcha1.tga");
	colcha1.BuildGLTexture();
	colcha1.ReleaseImage();

	colcha2.LoadTGA("madera/colcha2.tga");
	colcha2.BuildGLTexture();
	colcha2.ReleaseImage();

	cajon.LoadTGA("madera/cajon.tga");
	cajon.BuildGLTexture();
	cajon.ReleaseImage();

	mueble1.LoadTGA("madera/mueble1.tga");
	mueble1.BuildGLTexture();
	mueble1.ReleaseImage();

	mueble2.LoadTGA("madera/mueble2.tga");
	mueble2.BuildGLTexture();
	mueble2.ReleaseImage();

	mueble3.LoadTGA("madera/mueble3.tga");
	mueble3.BuildGLTexture();
	mueble3.ReleaseImage();

	puerta.LoadTGA("madera/puerta.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	rojo.LoadTGA("textura/rojo.tga");
	rojo.BuildGLTexture();
	rojo.ReleaseImage();

	rosa.LoadTGA("textura/rosa.tga");
	rosa.BuildGLTexture();
	rosa.ReleaseImage();

	verde.LoadTGA("textura/verde.tga");
	verde.BuildGLTexture();
	verde.ReleaseImage();

	amarillo.LoadTGA("textura/amarillo.tga");
	amarillo.BuildGLTexture();
	amarillo.ReleaseImage();

	superman.LoadTGA("textura/superman.tga");
	superman.BuildGLTexture();
	superman.ReleaseImage();

	spiderman.LoadTGA("textura/spiderman.tga");
	spiderman.BuildGLTexture();
	spiderman.ReleaseImage();

	america.LoadTGA("textura/america.tga");
	america.BuildGLTexture();
	america.ReleaseImage();

	cortina.LoadTGA("textura/cortina.tga");
	cortina.BuildGLTexture();
	cortina.ReleaseImage();

	//Modelos de las sillas
	silla._3dsLoad("3ds/silla.3DS");
	libros._3dsLoad("3ds/libros.3DS");
	lamp1._3dsLoad("3ds/lamp1.3DS");
	lamp2._3dsLoad("3ds/lamp2.3DS");
	planta._3dsLoad("3ds/planta.3DS");
	tom._3dsLoad("3ds/tom.3DS");
	nave._3dsLoad("3ds/nave.3DS");
	carro._3dsLoad("3ds/carro.3DS");
	libro2._3dsLoad("3ds/libro2.3DS");
	libro3._3dsLoad("3ds/libro3.3DS");
	pillow1._3dsLoad("3ds/pillow1.3DS");
	pillow2._3dsLoad("3ds/pillow3.3DS");

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);
	KeyFrame[0].arriba = 0.0001;
	KeyFrame[0].grados = 0.0001;
	KeyFrame[0].lado = 0.0001;


	KeyFrame[1].arriba = .2;
	KeyFrame[1].grados = 15;
	KeyFrame[1].lado = 0.4;

	KeyFrame[2].arriba = .4;
	KeyFrame[2].grados = 30;
	KeyFrame[2].lado = .8;

	KeyFrame[3].arriba = .6;
	KeyFrame[3].grados = 45;
	KeyFrame[3].lado = 1.2;

	KeyFrame[4].arriba = .8;
	KeyFrame[4].grados = 45;
	KeyFrame[4].lado = 1.6;

	KeyFrame[5].arriba = 1;
	KeyFrame[5].grados = 30;
	KeyFrame[5].lado = 2;

	KeyFrame[6].arriba = 1.2;
	KeyFrame[6].grados = 15;
	KeyFrame[6].lado = 2.4;

	KeyFrame[7].arriba = 1.4;
	KeyFrame[7].grados = 0;
	KeyFrame[7].lado = 3.2;

	KeyFrame[8].arriba = 1.6;
	KeyFrame[8].grados = -15;
	KeyFrame[8].lado = 3.4;

	KeyFrame[9].arriba = 1.8;
	KeyFrame[9].grados = 0;
	KeyFrame[9].lado = 3.6;

	KeyFrame[10].arriba = 2.0;
	KeyFrame[10].grados = 15;
	KeyFrame[10].lado = 4.0;

	KeyFrame[11].arriba = 2.2;
	KeyFrame[11].grados = 30;
	KeyFrame[11].lado = 4.4;

	KeyFrame[12].arriba = 2.4;
	KeyFrame[12].grados = 45;
	KeyFrame[12].lado = 4.8;

	KeyFrame[13].arriba = 2.6;
	KeyFrame[13].grados = 30;
	KeyFrame[13].lado = 5;

	KeyFrame[14].arriba = 2.8;
	KeyFrame[14].grados = 15;
	KeyFrame[14].lado = 5;

	KeyFrame[15].arriba = 3.2;
	KeyFrame[15].grados = 0;
	KeyFrame[15].lado = 5;

	KeyFrame[16].arriba = 3.4;
	KeyFrame[16].grados = 15;
	KeyFrame[16].lado = 5;

	KeyFrame[17].arriba = 3.6;
	KeyFrame[17].grados = 0;
	KeyFrame[17].lado = 5;
	KeyFrame[18].arriba = 3.8;
	KeyFrame[18].grados = 30;
	KeyFrame[18].lado = 5;

	KeyFrame[19].arriba = 4;
	KeyFrame[19].grados = 0;
	KeyFrame[19].lado = 5;

	KeyFrame[20].arriba = 4.2;
	KeyFrame[20].grados = 0;
	KeyFrame[20].lado = 5;

	KeyFrame[21].arriba = 4.4;
	KeyFrame[21].grados = 0;
	KeyFrame[21].lado = 5;

	KeyFrame[22].arriba = 4.6;
	KeyFrame[22].grados = 45;
	KeyFrame[22].lado = 5;

	KeyFrame[23].arriba = 4.4;
	KeyFrame[23].grados = 0;
	KeyFrame[23].lado = 5;

	KeyFrame[24].arriba = 4.8;
	KeyFrame[24].grados = 0;
	KeyFrame[24].lado = 5;

	KeyFrame[25].arriba = 5;
	KeyFrame[25].grados = 0;
	KeyFrame[25].lado = 5;
	
}

void antena(void) {

	glPushMatrix();
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 5);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.5, 2.5);
	glRotatef(90, 1, 0, 0);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0, 2.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0, 2.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	//tapa
	glPushMatrix();
	glTranslatef(lado, 2.5, 2.5);
	glRotatef(90, 1, 0, 0);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	//antena
	//base 
	glPushMatrix();
	glTranslatef(0, arriba, 0);


	glPushMatrix();
	glTranslatef(0, -2.2, 2.5);
	glRotatef(90, 1, 0, 0);
	glScalef(5, 5, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	//panel solar
	glPushMatrix();
	glTranslatef(0, -1.7, 1);
	glRotatef(45, 1, 0, 0);
	glScalef(2, 2, .1);
	f_antena.prisma2(0, 0);
	glPopMatrix();

	//poste antena

	glPushMatrix();
	glTranslatef(0, -1, 3);
	glScalef(.1, 2, .1);
	f_antena.prisma2(0, 0);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(.4, 0, 3);
	glRotatef(90, 0, 0, 1);
	glRotatef(grados, 1, 0, 0);
	f_antena.cono(.5, 1.5, 200, 0);
	glPopMatrix();
	glPopMatrix();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

		glEnable(GL_ALPHA_TEST); //INDICA QUE USAREMOS EL CANAL ALPHA
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);

				//Cascarón de la habitacion
				glPushMatrix();
				glTranslatef(0,-59,0);
				sky.cascaron(10, 15, 15, piso1.GLindex, techo.GLindex, pared1.GLindex, pared2.GLindex, pared3.GLindex);
				glPopMatrix();

				//Alfombra circulo
				glPushMatrix();
				glTranslatef(4, -63.9, -3.5);
				sky.cilindro(3, 0.05, 45, alfombra.GLindex );
				glPopMatrix();

				//Mesa y sillas --------------------------------------------------------------
				glPushMatrix();
				glTranslatef(4, -62, -3.5);
				sky.cilindro(1.5, 0.1, 45, madera4.GLindex);	//mesa
					glPushMatrix();
					glTranslatef(0, -0.5, 0);
					sky.cilindro(1, 0.5, 45, madera4.GLindex);
					glPopMatrix();
						glPushMatrix();
						glTranslatef(-1, -1.8, 0);
						sky.cilindro(0.1, 1.8, 45, madera4.GLindex);	//Patas de la mesa
						glPopMatrix();
							glPushMatrix();
							glTranslatef(1, -1.8, 0);
							sky.cilindro(0.1, 1.8, 45, madera4.GLindex);
							glPopMatrix();
								glPushMatrix();
								glTranslatef(0, -1.8, -1);
								sky.cilindro(0.1, 1.8, 45, madera4.GLindex);
								glPopMatrix();
									glPushMatrix();
									glTranslatef(0, -1.8, 1);
									sky.cilindro(0.1, 1.8, 45, madera4.GLindex);
									glPopMatrix();
				glPopMatrix();

				//Sillas  -------------------------------------------------------------------------------------
				glPushMatrix();
				glTranslatef(5.5, -62.7, -2);  //Asiento
				sky.cilindro(0.5, 0.3, 45, rojo.GLindex);
				glPushMatrix();
				glTranslatef(-0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);	//Patas 
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, -0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, 0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.05, -62.7, -2);  //Asiento
				sky.cilindro(0.5, 0.3, 45, amarillo.GLindex);
				glPushMatrix();
				glTranslatef(-0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);	//Patas 
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, -0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, 0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(5.5, -62.7, -5);  //Asiento
				sky.cilindro(0.5, 0.3, 45, verde.GLindex);
				glPushMatrix();
				glTranslatef(-0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);	//Patas 
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, -0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, 0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2, -62.7, -5);  //Asiento
				sky.cilindro(0.5, 0.3, 45, rosa.GLindex);
				glPushMatrix();
				glTranslatef(-0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);	//Patas 
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0.4, -1.2, 0);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, -0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0, -1.2, 0.4);
				sky.cilindro(0.05, 1.3, 45, madera3.GLindex);
				glPopMatrix();
				glPopMatrix();

				//Litera -------------------------------------------------------------------
				glPushMatrix();
				glTranslatef(-5.5, -63, -4.3); //Base inferior
				sky.prisma(0.5, 3,6, madera.GLindex);

				glPushMatrix();
				glTranslatef(0, 0.5, 0); //Colchón inferior
				sky.prisma(0.7, 2.8, 5.8, colcha2.GLindex);
				glPopMatrix();

					glPushMatrix();
					glTranslatef(1.5, 2.51, 2.9);	//Patas
					sky.prisma(7, 0.25, 0.25, madera.GLindex);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1.5, 2.51, 2.9);
					sky.prisma(7, 0.25, 0.25, madera.GLindex);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(1.5, 2.51,-2.9);
					sky.prisma(7, 0.25, 0.25, madera.GLindex);
					glPopMatrix();
					glPushMatrix();
					glTranslatef(-1.5, 2.51, -2.9);
					sky.prisma(7, 0.25, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 4, 0); //Base superior
					sky.prisma(0.5, 3, 6, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 4.5, 0); //Colchón superior
					sky.prisma(0.7, 2.8, 5.8, colcha1.GLindex);
					glPopMatrix();

					//Escaleras
					glPushMatrix();
					glTranslatef(0, 1, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 1.7, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 2.4, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 3.1, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 3.8, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 4.5, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, 5.2, 2.9);
					sky.prisma(0.3, 2.8, 0.25, madera.GLindex);
					glPopMatrix();
				glPopMatrix();

				//Cuadros   -----------------------------------------------------
				glPushMatrix(); //Base
				glTranslatef(7.4,-58,-5.5);
				sky.prisma(4, 0, 2, superman.GLindex);
					glPushMatrix(); //1 marcos
					glTranslatef(-0.05, 0, -0.9);
					sky.prisma(4, 0.15, 0.25, madera4.GLindex);
					glPopMatrix();
					glPushMatrix(); //2 marcos
					glTranslatef(-0.05, 0, 0.9);
					sky.prisma(4, 0.15, 0.25, madera4.GLindex);
					glPopMatrix();
					glPushMatrix(); //3 marcos
					glTranslatef(-0.05, 1.88, 0.0);
					sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
					glPopMatrix();
					glPushMatrix(); //4 marcos
					glTranslatef(-0.05, -1.88, 0.0);
					sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
					glPopMatrix();
				glPopMatrix();

				//Cuadro2
				glPushMatrix(); //Base
				glTranslatef(7.4, -58, -3);
				sky.prisma(4, 0, 2, spiderman.GLindex);
				glPushMatrix(); //1 marcos
				glTranslatef(-0.05, 0, -0.9);
				sky.prisma(4, 0.15, 0.25, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //2 marcos
				glTranslatef(-0.05, 0, 0.9);
				sky.prisma(4, 0.15, 0.25, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //3 marcos
				glTranslatef(-0.05, 1.88, 0.0);
				sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //4 marcos
				glTranslatef(-0.05, -1.88, 0.0);
				sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
				glPopMatrix();
				glPopMatrix();
				//Cuadro3
				glPushMatrix(); //Base
				glTranslatef(7.4, -58, -0.5);
				sky.prisma(4, 0, 2, america.GLindex);
				glPushMatrix(); //1 marcos
				glTranslatef(-0.05, 0, -0.9);
				sky.prisma(4, 0.15, 0.25, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //2 marcos
				glTranslatef(-0.05, 0, 0.9);
				sky.prisma(4, 0.15, 0.25, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //3 marcos
				glTranslatef(-0.05, 1.88, 0.0);
				sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
				glPopMatrix();
				glPushMatrix(); //4 marcos
				glTranslatef(-0.05, -1.88, 0.0);
				sky.prisma(0.25, 0.15, 1.55, madera4.GLindex);
				glPopMatrix();
				glPopMatrix();

				//Estante
				glPushMatrix();
				glPushMatrix();
					glTranslatef(4.8,-51.4,1.8);
					antena();
					glPopMatrix();
					glTranslatef(7, -58, 1.8);
					sky.prisma(5,1,0.2, madera.GLindex);
						glPushMatrix();

						glTranslatef(0, 0, 2.0);
						sky.prisma(5, 1, 0.2, madera.GLindex);
						glPopMatrix();

						glPushMatrix();
						glTranslatef(0, 2.45, 1);
						sky.prisma(0.1, 1, 1.8, madera.GLindex);
							glPushMatrix();
							glTranslatef(0, -2.5, 0);
							sky.prisma(0.1, 1, 1.8, madera.GLindex);
							glPopMatrix();
							glPushMatrix();
							glTranslatef(0, -4.9, 0);
							sky.prisma(0.1, 1, 1.8, madera.GLindex);
							glPopMatrix();
						glPopMatrix();
				glPopMatrix();

				//Mueble con cajones  -------------------------------------------------------------
				glPushMatrix();
				glTranslatef(-3, -62, -7);
				sky.prisma(0.1, 1.5, 0.9, madera7.GLindex);
					glPushMatrix();
					glTranslatef(0, -1, -0.4);
					sky.prisma(1.9, 1.4, 0.1, madera7.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(0, -1, 0.35);
					sky.prisma(1.9, 1.4, 0.1, cajon.GLindex);  //Cajon
					glPopMatrix();

					glPushMatrix();
					glTranslatef(-0.6, -1, 0.0);
					sky.prisma(1.9, 0.1, 0.7, madera7.GLindex);
					glPopMatrix();


					glPushMatrix();
					glTranslatef(0.6, -1, 0.0);
					sky.prisma(1.9, 0.1, 0.7, madera7.GLindex);
					glPopMatrix();
				glPopMatrix();

				//Cortina
				glPushMatrix();
				glTranslatef(-0.4, -59, -7.45);
				sky.prisma(10, 5,0, cortina.GLindex);
				glPopMatrix();  

				glPushMatrix();
				glTranslatef(4, -59, -7.45);
				sky.prisma(10, 5, 0, cortina.GLindex);
				glPopMatrix();

				//Muebles y escritorio
				glPushMatrix(); //Muebles laterales
				glTranslatef(-1, -59.08, 6.5);
				sky.cascaron(9.8, 1.5, 1.5, madera6.GLindex, madera6.GLindex, madera6.GLindex, madera6.GLindex, mueble2.GLindex);

					glPushMatrix();
					glTranslatef(-5.7, 0, 0);
					sky.cascaron(9.8, 1.5, 1.5, madera6.GLindex, madera6.GLindex, madera6.GLindex, madera6.GLindex, mueble1.GLindex);
					glPopMatrix();
				glPopMatrix();

				//Escritorio
				glPushMatrix(); //Mueble escritorio
				glTranslatef(-5.2, -62.45, 6.5);
				sky.cascaron(3, 1.5, 1.5, madera6.GLindex, madera6.GLindex, madera6.GLindex, madera6.GLindex, mueble3.GLindex);
					glPushMatrix(); //escritorio
					glTranslatef(1.35, 1.75, 0);
					sky.prisma(0.5, 4.22, 1.5, madera6.GLindex);
					glPopMatrix();
				glPopMatrix();

				glPushMatrix(); //estante
				glTranslatef(-3.86, -56, 6.85);
				sky.prisma(0.25, 4.25, 1, madera6.GLindex);
				glPopMatrix();

				glPushMatrix(); //estante2
				glTranslatef(-3.86, -58, 6.85);
				sky.prisma(0.25, 4.25, 1, madera6.GLindex);
				glPopMatrix();

				glPushMatrix(); //puerta
				glTranslatef(4.65, -59.8, 7.5);
				sky.prisma(8.3, 1.75, 0, puerta.GLindex);
				glPopMatrix();

//-----------------------------------------------------

//Modelos 3DS
				glPushMatrix();
				glScalef(0.1, 0.1, 0.1);
				glRotatef(270,0, 1, 0);
				glTranslatef(8, -639.0, 43);
				silla.GLrender(NULL, _SHADED, 1.0);  //Silla
				glPopMatrix();

				glPushMatrix();
				glScalef(0.05, 0.05, 0.05);
				glRotatef(180, 0, 1, 0);
				glTranslatef(98, -1157.0, -136);
				libros.GLrender(NULL, _SHADED, 1.0);  //Libros
				glPopMatrix();

				glPushMatrix();
				glScalef(0.002, 0.002, 0.002);
				glRotatef(120, 0, 1, 0);
				glTranslatef(-2000, -30200.0, -3300);
				lamp1.GLrender(NULL, _SHADED, 1.0);  //Lampara de escritorio
				glPopMatrix();

				glPushMatrix();
				glScalef(0.001, 0.001, 0.001);
				//glRotatef(0, 0, 1, 0);
				glTranslatef(-4000, -61900.0, -6500);
				lamp2.GLrender(NULL, _SHADED, 1.0);  //Lampara de buró
				glPopMatrix();
				
				glPushMatrix();
				glScalef(0.008, 0.008, 0.008);
				glRotatef(90, 0, 1, 0);
				glTranslatef(-370, -7210.0, 870);
				planta.GLrender(NULL, _SHADED, 1.0);  //planta
				glPopMatrix();

				glPushMatrix();
				glScalef(0.03, 0.03, 0.03);
				glRotatef(270, 0, 1, 0);
				glTranslatef(72.5, -2014.0, -223);
				tom.GLrender(NULL, _SHADED, 1.0);  //tom
				glPopMatrix();

				glPushMatrix();
				glScalef(0.03, 0.03, 0.03);
				glRotatef(150, 0, 1, 0);
				glTranslatef(-30, -1855.0, -230);
				nave.GLrender(NULL, _SHADED, 1.0);  //nave
				glPopMatrix();

				glPushMatrix();
				glRotatef(150, 0, 1, 0);
				glTranslatef(0.65, -55.8, -8);
				carro.GLrender(NULL, _SHADED, 1.0);  //carro
				glPopMatrix();

				glPushMatrix();
				glScalef(0.048, 0.048, 0.048);
				//glRotatef(0, 0, 1, 0);
				glTranslatef(-54.5, -1258.5, 135);
				libro2.GLrender(NULL, _SHADED, 1.0);  //libro2
				glPopMatrix();

				glPushMatrix();
				glScalef(0.008, 0.008, 0.008);
				glRotatef(90, 0, 1, 0);
				glTranslatef(-372.5, -7555.0, 870);
				libro3.GLrender(NULL, _SHADED, 1.0);  //libro3
				glPopMatrix();

				glPushMatrix();
				glScalef(2.5, 2.5, 2.5);
				glTranslatef(-2.5, -23.25,-2.4);
				pillow1.GLrender(NULL, _SHADED, 1.0);  //Almohada superior
				glPopMatrix();


				glPushMatrix();
				glScalef(0.0027, 0.0027, 0.0027);
				//glRotatef(0, 0, 1, 0);
				glTranslatef(-2050, -23050.0, -2400);
				pillow2.GLrender(NULL, _SHADED, 1.0);  //Lampara de buró


				
				glPopMatrix();

			glPopMatrix();


		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation

								  //Interpolaciones incremento.
								  //el incremento es la distancia entre dos cuadros, el 2 - 1 y se divide entre el 90(i_max_steps)   Se hace la interpolacion


				KeyFrame[playIndex].arribaInc = (KeyFrame[playIndex + 1].arriba - KeyFrame[playIndex].arriba) / i_max_steps;
				KeyFrame[playIndex].gradosInc = (KeyFrame[playIndex + 1].grados - KeyFrame[playIndex].grados) / i_max_steps;
				KeyFrame[playIndex].ladoInc = (KeyFrame[playIndex + 1].lado - KeyFrame[playIndex].lado) / i_max_steps;


			}
		}
		else
		{	//Draw information


			arriba += KeyFrame[playIndex].arribaInc;
			grados += KeyFrame[playIndex].gradosInc;
			lado += KeyFrame[playIndex].ladoInc;



			i_curr_steps++;
		}

	}

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	glutPostRedisplay();
}


void cumbion() {

	PlaySound(TEXT("music/cumbion.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':
		case 'R':
			if (play == false && (FrameIndex > 1))
			{

				grados = KeyFrame[0].grados;
				arriba = KeyFrame[0].arriba;
				lado = KeyFrame[0].lado;

				//First Interpolation


				KeyFrame[playIndex].arribaInc = (KeyFrame[playIndex + 1].arriba - KeyFrame[playIndex].arriba) / i_max_steps;
				KeyFrame[playIndex].gradosInc = (KeyFrame[playIndex + 1].grados - KeyFrame[playIndex].grados) / i_max_steps;
				KeyFrame[playIndex].ladoInc = (KeyFrame[playIndex + 1].lado - KeyFrame[playIndex].lado) / i_max_steps;


				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;
			


		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (800, 600);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("MI PROYECTO-CUARTO"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  cumbion();

  glutMainLoop        ( );          // 

  return 0;
}
