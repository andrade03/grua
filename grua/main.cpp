#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

static int girox = 0;
static int giroy = 0;
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;


GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
GLfloat scale2=1.0f;
void init(void)
{
	GLfloat light_position[] = { -1.0, 1.0, 5.0, 0.0 };
// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT, GL_FILL);

}
//funcion que controla los matariales 
void color(float a1, float a2, float a3, float d1, float d2, float d3, float s1, float s2, float s3, float a4)
	{
		GLfloat mat_ambient[] = { a1, a2, a3, a4 };
		GLfloat mat_diffuse[] = { d1, d2, d3, a4 };
		GLfloat mat_specular[] = { s1, s2, s3, a4 };
		GLfloat shine[] = {a4};

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);

	}
void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-500, 500, -500, 500, -500, 500);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}


void display(void)
{
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
	 //glShadeModel(GL_SMOOTH);
    glClearColor(0,1,0,0.0);
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
    
// Rotacion de 30 grados en torno al eje x
    glRotated(30.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);


	//BASE
	glPushMatrix();
    glTranslatef(17.5,-220.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
    glColor3f(1.0,1.0,0.0);
    glScalef(0.9, 0.8, 0.9);
    glutSolidCube (120.0);
    glPopMatrix();
    //BASE FIN
     
    //MASTIL
	glPushMatrix();
    glTranslatef(17.5,20.0,30.0);
    color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
    glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 3.0, 0.5);
    glutSolidCube (120.0);
    glPopMatrix();     
	//MASTIL FIN

	//LATERAL 1
	glPushMatrix();
    glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
	glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(18.0,240.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
    glColor3f(1.0,1.0,0.0);
    glScalef(0.7, 0.7, 0.5);
    glutSolidCube (120.0);
    glPopMatrix();
    //LATERAL 1 FIN 
     
	//LATERAL 2
	glPushMatrix();
    glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
	glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(240.0,240.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
    glColor3f(1.0,1.0,0.0);
    glScalef(3.0, 0.7, 0.5);
    glutSolidCube (120.0);
    glPopMatrix();     
	//LATERAL 2 FIN
	
	//MASTIL PEQUEÑO
	glPushMatrix();
    glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
	glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,140.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
    glColor3f(1.0,1.0,0.0);
    glScalef(0.5, 1.0, 0.5);
    glutSolidCube (120.0);
    glPopMatrix();  
	//MASTIL PEQUEÑO FIN


	//POLEA
	glPushMatrix();
    glRotated ((GLdouble) girox, 1.0, 0.0, 0.0);
	glRotated ((GLdouble) giroy, 0.0, 1.0, 0.0);
    glTranslatef(390.0,10.0,30.0);
    color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
    glColor3f(1.0,1.0,0.0);
    glScalef(0.2, scale2, 0.2);
    glutSolidCube (120.0);
    glPopMatrix();
	//POLEA FIN


	//PRIMER CUBO BAJO LA POLEA
	if(scale2>=3.5 && (((GLdouble) giroy))==0.0)
	{
		glPushMatrix();
		glTranslatef(390.0,-220.0,30.0);
		color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.55, 0.55, 0.55);
		glutSolidCube (120.0);
		glPopMatrix();  
     }
	else
	{
		glPushMatrix();
		glTranslatef(390.0,-220.0,30.0);
		color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.35, 0.35, 0.35);
		glutSolidCube (120.0);
		glPopMatrix();  
     }
	//PRIMER CUBO BAJO LA POLEA FIN


	//CUBO GRADOS POSITIVOS

	if(scale2>=2.3 && (((GLdouble) giroy))==15.0)
	{
		glPushMatrix();
		glTranslatef(390.0,-160.0,-60.0);
		color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.55, 0.55, 0.55);
		glutSolidCube (120.0);
		glPopMatrix();  
     
	}
	else
	{
		glPushMatrix();
		glTranslatef(390.0,-160.0,-60.0);
		color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.35, 0.35, 0.35);
		glutSolidCube (120.0);
		glPopMatrix();  
    }
	//CUBO GRADOS POSITIVOS FIN


	//SEGUNDO NEGATIVOS
	if(scale2>=2.3 && (((GLdouble) giroy))==85.0)
	{
		glPushMatrix();
		glTranslatef(80.0,-160.0,-380.0);
		color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.7, 0.7, 0.7);
		glutSolidCube (120.0);
		glPopMatrix();  
     
	}
	else
	{
		glPushMatrix();
		glTranslatef(80.0,-160.0,-380.0);
		color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube (120.0);
		glPopMatrix();  
     }
	//SEGUNDO NEGATIVOS FIN
     
     
     //NEGATIVOS PRIMERO
	if(scale2>=2.8 && (((GLdouble) giroy))==-55.0)
	{
		glPushMatrix();
		glTranslatef(180.0,-220.0,320.0);
		color(0.05f, 0.0, 0.0f,0.5f, 0.5f, 0.4f,0.7f, 0.04f, 0.04f,0.078125f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.7, 0.7, 0.7);
		glutSolidCube (120.0);
		glPopMatrix();  
	}
	else
	{
		glPushMatrix();
		glTranslatef(180.0,-220.0,320.0);
		color(0.329412f, 0.223529f, 0.027451f,0.780392f, 0.568627f, 0.113725f,0.992157f, 0.941176f, 0.807843f,1.0f);
		glColor3f(1.0,1.0,0.0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube (120.0);
		glPopMatrix();  
     }
     //NEGATIVOS PRIMERO FIN

	glFlush();
}

void specialKeys( int key, int x, int y )
{
    //  Flecha derecha: aumentar rotación 5 grados
    if (key == GLUT_KEY_RIGHT)
    {
		if(giroy>=85)
		{
			giroy=90;
		}
		else
		{
			giroy = (giroy + 5) % 90;
		}
	}
   //  Flecha izquierda: rotación en eje Y negativo 5 grados
    else if (key == GLUT_KEY_LEFT)
    {
        if(giroy<=-85)
        {
			giroy=-90;
		}
		else
		{        
        giroy = (giroy - 5)  % 180;
		}
	}
    else if (key == GLUT_KEY_UP)
    {
		if(scale2<=1.0)
		{
			scale2=1.0;
		}
		else
		{
		    scale2 -= 0.1;
		}
	}
    else if (key == GLUT_KEY_DOWN)
    {
		if(scale2>=4.0)
		{
			scale2=4.0;
		}
		else
		{
		scale2 += 0.1;
		}
	} 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
	// Inicializo OpenGL
    glutInit(&argc, argv);
	// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
	// Definimos una ventana de medidas 800 x 600 como ventana
	// de visualizacion en pixels	
    glutInitWindowSize (1000, 800);
	// Posicionamos la ventana en la esquina superior izquierda de
	// la pantalla.
    glutInitWindowPosition (10, 0);
	// Creamos literalmente la ventana y le adjudicamos el nombre que se
	// observara en su barra de titulo.
    glutCreateWindow ("Grua Mecanica");
	// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
