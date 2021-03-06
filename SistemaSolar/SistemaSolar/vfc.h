void criaVector(float v1,float v2,float v3,double res[3]);
void calculaAltLarg(int fov,float ratio,int nearDist,int farDist);
double innerProduct(double * vec1, double *vec2);
void prodVect(double vec1[3],double vec2[3],double* res);
void normaliza(double *vec);
void somaVectores(double* vec1,double *vec2,double *res);
void subVectores(double* vec1,double *vec2,double *res);
void multVecValor(double* vec1,double valor,double *res);
void geraPlano(double *v1,double* v2,double*v3,int indice);
void setPlanes(double *p, double *l, double *u);
double distancia(double* p,int indice);
int sphereInFrustum(double *point, double radius);
