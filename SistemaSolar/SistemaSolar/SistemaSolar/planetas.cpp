#include "planetas.h"

//velocidades de rota��o em dias
GLfloat rotSol = 0;
GLfloat rotMercurio = 0;
GLfloat rotVenus = 0;
GLfloat rotTerra = 0;
GLfloat rotLua = 0;
GLfloat rotMarte = 0;
GLfloat rotJupiter = 0;
GLfloat rotSaturno = 0;
GLfloat rotUrano = 0;
GLfloat rotNeptuno = 0;

float scale = 10;
bool orbitas = true;
float distFactor = 1.0;
float time = 0;
float timeFactor = 0.0001;

GLuint cintura;


void rotacao(GLfloat rotacao,float tilt)
{
	glRotatef(tilt,0.0,0.0,1.0);
	glRotated(rotacao,0.0,1.0,0.0);
	
	glutPostRedisplay();
}

void draw_orbita(float raio, float angleX,float angleY, float angleZ){
	glPushMatrix();
	
	glRotatef(angleZ,0.0,0.0,1.0);
	glRotatef(angleX,1.0,0.0,0.0);
	glRotatef(angleY,0.0,1.0,0.0);

	float xx=0;
	float yy=0;
	glBegin(GL_LINES);
	for (int i = 0; i < 180; i++)
	{
		xx = raio * cos((float)i);
		yy = raio * sin((float)i);
		glVertex3f(xx,yy,0);
		xx = raio * cos(i + 0.1);
		yy = raio * sin(i + 0.1);
		glVertex3f(xx,yy,0);
	}
	glEnd();

	glPopMatrix();	
}

void desenharAnel(float raio1, float raio2){
	glColor3f(1,0,0);
	glutSolidTorus(raio1,raio2,360,150);
}

void desenharSol()
{
	glPushMatrix();
	glColor3f(1,1,0);//amarelo
	rotSol += velRSol;
	rotacao(rotSol,0.0);
	glutWireSphere(scale*raioSol*(1/scale),32,32);
	glPopMatrix();
}

void desenharMercurio()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltMercurio,0.0,0.0,1.0);
	glTranslatef(1000*cos(0.0)*sin(time*0.2),1000*sin(0.0),1000*cos(0.0)*cos(time*0.2));
=======
	glTranslatef(distFactor*distSolMercurio*sin(velMercurio*time), 0, distFactor*distSolMercurio*cos(velMercurio*time));
>>>>>>> .r46
	glColor3f(0.5,0.5,0.5);//cinza
	rotMercurio += velRMercurio;
	rotacao(rotMercurio,axisTiltMercurio);
	glutWireSphere(scale*raioMercurio,32,32);
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(1000,90,0.0,orbitalTiltMercurio);
=======
	if(orbitas)draw_orbita(distFactor*distSolMercurio,90,0.0,0.0);
>>>>>>> .r46
}

void desenharVenus()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltVenus,0.0,0.0,1.0);
	glTranslatef(1100*cos(0.0)*sin(time*0.6),1100*sin(0.0),1100*cos(0.0)*cos(time*0.6));
=======
	glTranslatef(distFactor*distSolVenus*sin(velVenus*time), 0, distFactor*distSolVenus*cos(velVenus*time));
>>>>>>> .r46
	glColor3f(0.6,0.5,0.1);//castanho
	rotVenus += velRVenus;
	rotacao(rotVenus,axisTiltVenus);
	glutWireSphere(scale*raioVenus,32,32);
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(1100,90,0.0,orbitalTiltVenus);
=======
	if(orbitas)draw_orbita(distFactor*distSolVenus,90,0.0,0.0);
>>>>>>> .r46
}

void desenharLua()
{
	if(orbitas)draw_orbita(distFactor*distTerraLua,90,0.0,0.0);
	//a distancia entre a terra e lua aqui � afectada pelo 'scale'
	glTranslatef(distFactor*scale*distTerraLua*sin(velLua*time), 0, distFactor*scale*distTerraLua*10*sin(velLua*time));
	glColor3f(1,1,1);//branco
	rotLua += velRLua;
	rotacao(rotLua,0.0);
	glutWireSphere(scale*raioLua,32,32);
	
}

void desenharTerra()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltTerra,0.0,0.0,1.0);
	glTranslatef(1200*cos(0.0)*sin(time),1200*sin(0.0),1200*cos(0.0)*cos(time));
=======
	glTranslatef(distFactor*distSolTerra*sin(velTerra*time), 0, distFactor*distSolTerra*cos(velTerra*time));
>>>>>>> .r46
	glColor3f(0,0,1);//azul
	rotTerra += velRTerra;
	rotacao(rotTerra,axisTiltTerra);
	glutWireSphere(scale*raioTerra,32,32);
	desenharLua();
	glPopMatrix();
	glColor3f(0,0,1);//azul
<<<<<<< .mine
	draw_Orbita(1200,90,0.0,orbitalTiltTerra);
=======
	if(orbitas)draw_orbita(distFactor*distSolTerra,90,0.0,0.0);
>>>>>>> .r46
}

void desenharMarte()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltMarte,0.0,0.0,1.0);
	glTranslatef(1300*cos(0.0)*sin(time),1300*sin(0.0),1300*cos(0.0)*cos(time));
=======
	glTranslatef(distFactor*distSolMarte*sin(velMarte*time), 0, distFactor*distSolMarte*cos(velMarte*time));
>>>>>>> .r46
	glColor3f(1,0,0);//vermelho
	rotMarte += velRMarte;
	rotacao(rotMarte,axisTiltMarte);
	glutWireSphere(scale*raioMarte,32,32);
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(1300,90,0.0,orbitalTiltMarte);
=======
	if(orbitas)draw_orbita(distFactor*distSolMarte,90,0.0,0.0);
>>>>>>> .r46
}
void desenharJupiter()
{
	glPushMatrix();
	glRotatef(orbitalTiltJupiter,0.0,0.0,1.0);
	glTranslatef(distFactor*distSolJupiter*sin(velJupiter*time), 0, distFactor*distSolJupiter*cos(velJupiter*time));
	glColor3f(1,1,0);//amarelo
	rotJupiter += velRJupiter;
	rotacao(rotJupiter,axisTiltJupiter);
	glutWireSphere(scale*raioJupiter,32,32);
	glPopMatrix();
	if(orbitas)draw_orbita(distFactor*distSolJupiter,90,0.0,orbitalTiltJupiter);
}
void desenharSaturno()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltSaturno,0.0,0.0,1.0);
	glTranslatef(2300*cos(0.0)*sin(time),2300*sin(0.0),2300*cos(0.0)*cos(time));
=======
	glTranslatef(distFactor*distSolSaturno*sin(velSaturno*time), 0, distFactor*distSolSaturno*cos(velSaturno*time));
>>>>>>> .r46
	glColor3f(1,0,1);//rosa
	rotSaturno += velRSaturno;
	rotacao(rotSaturno,axisTiltSaturno);
	glutWireSphere(scale*raioSaturno,32,32);
	glPushMatrix();
	//glRotatef(90.0,1.0,0.0,0.0);
	//glScalef(1,1,0.1);
	//desenharAnel(43,150);
	for(float i=0;i<20;i+=2)
		draw_Orbita(raioSaturno+20+i,0.0,0.0,orbitalTiltSaturno);
	
	glPopMatrix();
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(2300,90,0.0,orbitalTiltSaturno);
=======
	if(orbitas)draw_orbita(distFactor*distSolSaturno,90,0.0,0.0);
>>>>>>> .r46
}
void desenharUrano()
{
	glPushMatrix();
<<<<<<< .mine
	glRotatef(orbitalTiltUrano,0.0,0.0,1.0);
	glTranslatef(2800*cos(0.0)*sin(time),2800*sin(0.0),2800*cos(0.0)*cos(time));
=======
	glTranslatef(distFactor*distSolUrano*sin(velUrano*time), 0, distFactor*distSolUrano*cos(velUrano*time));
>>>>>>> .r46
	glColor3f(0.8,0.1,0.4);//roxo
	rotUrano += velRUrano;
	rotacao(rotUrano,axisTiltUrano);
	glutWireSphere(scale*raioUrano,32,32);
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(2800,90,0.0,orbitalTiltUrano);
=======
	if(orbitas)draw_orbita(distFactor*distSolUrano,90,0.0,0.0);
>>>>>>> .r46
}

void desenharNeptuno()
{
	glPushMatrix();
	glColor3f(0.12,0.432,0.123);//verde
<<<<<<< .mine
	rotNeptuno+=1.23;
	glRotatef(orbitalTiltNeptuno,0.0,0.0,1.0);
	glTranslatef(3200*cos(0.0)*sin(time),3200*sin(0.0),3200*cos(0.0)*cos(time));
=======
	rotNeptuno += velRNeptuno;
	glTranslatef(distFactor*distSolNeptuno*sin(velNeptuno*time), 0, distFactor*distSolNeptuno*cos(velNeptuno*time));
>>>>>>> .r46
	rotacao(rotNeptuno,axisTiltNeptuno);
	glutWireSphere(scale*raioNeptuno,32,32);
	glPopMatrix();
<<<<<<< .mine
	draw_Orbita(3200,90,0.0,orbitalTiltNeptuno);
=======
	if(orbitas)draw_orbita(distFactor*distSolNeptuno,90,0.0,0.0);
>>>>>>> .r46
}

void desenharCintura(){
	int i=0;
	float dist, ang, x, z;
	
	cintura = glGenLists( 1 );
	glNewList( cintura, GL_COMPILE );
	
	srand(30);
	glColor3f(0.5,0.5,0.2);
	glBegin(GL_POINTS);
	//existem 700,000 a 1.7 milhoens... mas para simplificar...
	for(i=0; i<100000; i++){
		dist = rand();
		ang = rand() / 3.1415;
		x = cos(ang) * (dist + distSolMarte*1.2);
		z = sin(ang) * (dist + distSolMarte*1.2);
		if(sqrt(x*x+z*z) < distSolJupiter*0.8)
			glVertex3f(x, 0, z);
		else i--;
	}
	glEnd();

	glEndList();
}

void planetas(){
	time += timeFactor;
	desenharSol();
	desenharMercurio();
	desenharVenus();
	desenharTerra();
	desenharMarte();
	desenharJupiter();
	desenharSaturno();
	desenharUrano();
	desenharNeptuno();

	glCallList(cintura);

}
