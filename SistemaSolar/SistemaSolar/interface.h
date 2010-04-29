#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <GL/glut.h>

extern float height;
extern float x;
extern float z;
extern float y;
extern int mouseBtn;
extern int mouseMod;

extern float camX;
extern float camY;
extern float camZ;
extern float camlookX;
extern float camlookY;
extern float camlookZ;
extern float alpha;
extern float beta;
extern float r;

extern bool axes;
extern bool fullscreen;
extern bool luz;

extern int MouseBtnState;
extern int window;
extern int winX;
extern int winY;
extern int infotab;

extern int fontTitle;
extern int fontText;

extern GLfloat lamb[];
extern GLfloat ldiff[];
extern GLfloat lpos[];
extern GLfloat specular[];

extern char s[100];


void processKeys(unsigned char tecla, int x, int y);
void processSpecialKeys(int key, int xx, int yy);
void fmouse(int button, int state, int xx, int yy);
void fmotion(int xx, int yy);
void menu(int id_op);
void gerarMenu();