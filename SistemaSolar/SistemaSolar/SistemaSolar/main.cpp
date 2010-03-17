#include <GL/glut.h>

#include <math.h>

float PI = 3.14159265f;

float height = 2.0f;
float x = 0.0f;
float z = 0.0f;
float y = 0.0f;
int mouseButton = 0;

float camX = 1000.0f, camY = 0.0f, camZ = 500;
float camlookX = 900.0f, camlookY = 0.0f, camlookZ = 0.0f;
float alpha = 0, beta = 0, r = 1000;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set the correct perspective
	gluPerspective(45,ratio,10,100000);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void planetas(){
	//sol
	glColor3f(1,1,0);
	glutSolidSphere(696,32,32);
	//mercurio
	glTranslatef(1000,0,0);
	glColor3f(0.5,0.5,0.5);
	glutSolidSphere(1.2195,32,32);
	//venus
	glTranslatef(10,0,0);
	glColor3f(0.6,0.5,0.1);
	glutSolidSphere(3.0259,32,32);
	//terra
	glTranslatef(10,0,0);
	glColor3f(0,0,1);
	glutSolidSphere(3.1855,32,32);
	//planeta marte
	glTranslatef(30,0,0);
	glColor3f(0,0,1);
	glutSolidSphere((6.780/2),32,32);
	//planeta jupiter
	glTranslatef(150,0,0);
	glColor3f(0,0,1);
	glutSolidSphere((139.822/2),32,32);
	//planeta saturno
	glTranslatef(300,0,0);
	glColor3f(0,0,1);
	glutSolidSphere((116.464/2),32,32);
	//planeta urano
	glTranslatef(120,0,0);
	glColor3f(0,0,1);
	glutSolidSphere((50.724/2),32,32);
	//planeta spock
	glTranslatef(80,0,0);
	glColor3f(0,0,1);
	glutSolidSphere((49.244/2),32,32);

}
void renderScene(void) {

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(camX,camY,camZ, 
			camlookX,camlookY,camlookZ,
			  0.0f,1.0f,0.0f);	
	
	glPushMatrix();
	planetas();
	glPopMatrix();

	// End of frame
	glutSwapBuffers();

}

void processKeys(unsigned char tecla, int x, int y){
	switch(tecla){
		case 27 : exit(0);
	}
	glutPostRedisplay();
}
void processSpecialKeys(int key, int xx, int yy) 
{
	switch(key) {
		case GLUT_KEY_UP: 
			if(beta < (89*PI/180)){
				beta+=0.03;
				camZ = r * cos(beta) * cos(alpha);
				camX = r * cos(beta) * sin(alpha);
				camY = r * sin(beta);
			}
			break;
		case GLUT_KEY_DOWN:
			if(beta > -(89*PI/180)){
				beta-=0.03;
				camZ = r * cos(beta) * cos(alpha);
				camX = r * cos(beta) * sin(alpha);
				camY = r * sin(beta);
			}
			break;
		case GLUT_KEY_LEFT:
			alpha-=0.03;
			camZ = r * cos(beta) * cos(alpha);
			camX = r * cos(beta) * sin(alpha);
			break;
		case GLUT_KEY_RIGHT:
			alpha+=0.03;
			camZ = r * cos(beta) * cos(alpha);
			camX = r * cos(beta) * sin(alpha);
			break;
	}
	glutPostRedisplay();
}

void fmouse(int button, int state, int xx, int yy) 
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			mouseButton=0;
			x=xx; y=yy;
			break;
		case GLUT_MIDDLE_BUTTON:
			mouseButton=1;
			y=yy;
			break;
		case GLUT_RIGHT_BUTTON:
			mouseButton=2;
			x=xx; y=yy;
			break;
	}	
}

//TODO: prender o rato ao ecra e nao o mexer.
void fmotion(int xx, int yy)
{
	switch(mouseButton){
		case 0:
			if(beta < (89*PI/180) && beta > -(89*PI/180)){
				alpha+=((x-xx)/100);
				beta-=((y-yy)/100);
				camZ = r * cos(beta) * cos(alpha);
				camX = r * cos(beta) * sin(alpha);
				camY = r * sin(beta);
				
			}else{
				if(beta < 0) beta = -(89*PI/180);
				else beta = (89*PI/180);
			};
			break;
		case 1:
			r+=(y-yy)/10;
			camZ = r * cos(beta) * cos(alpha);
			camX = r * cos(beta) * sin(alpha);
			camY = r * sin(beta);
			break;
		case 2: 
			camlookX += ((x-xx))/10;
			camlookZ += ((y-yy))/10;
			break;
	}
	x=xx;y=yy;
	glutPostRedisplay();
}

void menu(int id_op){}

void gerarMenu(){
	glutCreateMenu(menu);
	glutAddMenuEntry("'Sup?",1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("SistemaSolar@CG@DI-UM");
		
// registo de funções 
	glutDisplayFunc(renderScene);
	//glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMotionFunc(fmotion);
	glutMouseFunc(fmouse);

	gerarMenu();

// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// entrar no ciclo do GLUT 
	glutMainLoop();
}

