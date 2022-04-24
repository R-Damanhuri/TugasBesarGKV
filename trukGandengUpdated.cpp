//Nama	: R. Damanhuri
//NIM	: 24060120130072
//Lab	: A2
//Waktu	: 21 Maret 2022

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float angle=0.0, deltaAngle = 0.0, ratio;
float x=-2.0f,y=1.75f,z=35.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
void Reshape(int w1, int h1){
// Fungsi reshape
	if(h1 == 0) h1 = 1;
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		x, y, z,
		x + lx,y + ly,z + lz,
		0.0f,1.0f,0.0f);
}
void orientMe(float ang){
// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}
void moveMeFlat(int i){
// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.05;
	z = z + i*(lz)*0.05;
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void cylinder(float alas,float atas,float tinggi)
{
	float i;
 	glPushMatrix();
 	glTranslatef(1.0,0.0,-alas/8);
 	glutSolidCone(alas,0,32,4);
 	for(i=0;i<=tinggi;i+=alas/24)
 	{
  		glTranslatef(0.0,0.0,alas/24);
  		glutSolidTorus(alas/4,alas-((i*(alas-atas))/tinggi),16,16);
 	}
 	glTranslatef(0.0,0.0,alas/4);
 	glutSolidCone(tinggi,0,20,1);
 	glColor3f(0.,0.,0.);
 	glPopMatrix();
}

void Jalanan() {
// Fungsi untuk membuat jalan
	double i;
	const float Z_MIN = -30, Z_MAX = 30;
	const float X_MIN = -2.5, X_MAX = -1.5;
	const float gap = 4; 
	//Rumput kiri
	glBegin(GL_POLYGON);
		glColor3f(0, 0.3, 0);
		glVertex3f(-39,0.8,-30);
		glVertex3f(-39,0.8,30);
		glVertex3f(-9,0.8,30);
		glVertex3f(-9,0.8,-30);
	glEnd();
	//Aspal kiri
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex3f(-9,0.8,-30);
		glVertex3f(-9,0.8,30);
		glVertex3f(-2.5,0.8,30);
		glVertex3f(-2.5,0.8,-30);
	glEnd();
	//Garis Tengah
	i = Z_MIN;
	while(i< Z_MAX){
			glBegin(GL_QUADS);
				glColor3f(1, 0.8, 1);
				glVertex3f(X_MIN,0.8,i);
				glVertex3f(X_MAX,0.8,i);
				i+=gap;
				glVertex3f(X_MAX,0.8,i);
				glVertex3f(X_MIN,0.8,i);
			glEnd();
			glBegin(GL_QUADS);
				glColor3f(0, 0, 0);
				glVertex3f(X_MIN,0.8,i);
				glVertex3f(X_MAX,0.8,i);
				i+=gap;
				glVertex3f(X_MAX,0.8,i);
				glVertex3f(X_MIN,0.8,i);
			glEnd();
	}
	//Aspal kanan
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		glVertex3f(-1.5,0.8,-30);
		glVertex3f(-1.5,0.8,30);
		glVertex3f(6,0.8,30);
		glVertex3f(6,0.8,-30);
	glEnd();
	//Rumput kanan
	glBegin(GL_POLYGON);
		glColor3f(0, 0.3, 0);
		glVertex3f(6,0.8,-30);
		glVertex3f(6,0.8,30);
		glVertex3f(36,0.8,30);
		glVertex3f(36,0.8,-30);
	glEnd();	
}

void Pos()
{
glPushMatrix();
glTranslatef(-4,0.8,25.7);

		// Lantai
		glPushMatrix();
			glColor3f(0.0, 0.0, 0);
			glTranslatef(-6.5,0,0);
			glScalef(3.5, 1, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// Tembok
		glPushMatrix();
			glColor3f(1,0.0,0);
			glTranslatef(-6.5,3.0,0);
			glScalef(3.5, 5, 4.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// Atap
		glPushMatrix();
			glColor3f(0,0.0,0);
			glTranslatef(-6.5,6.0,0);
			glScalef(7.5, 0.3, 7.5);
			glutSolidCube(1);
		glPopMatrix();
		
		//Jendela
		glPushMatrix();
			glColor3f(0,1,0);
			glTranslatef(-4.7,2.5,1.7);
			glScalef(0, 3, 1);
			glutSolidCube(1);
		glPopMatrix();
		
		//Pintu
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(-8.27,2,0);
			glScalef(0, 4, 1.5);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
}
void Palang()
{
	glPushMatrix();
	glTranslatef(-3,0.8,29);
		
		// Horizontal
		glPushMatrix();
			glColor3f(1,0.5,0);
			glTranslatef(0,2.5,0);
			glScalef(15, 0.5, 0.5);
			glutSolidCube(1);
		glPopMatrix();
		
		// Vertikal
		glPushMatrix();
			glColor3f(1,0.5,0);
			glTranslatef(-6.5,2,0);
			glScalef(0.5, 4, 0.5);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
		
		
		
		
}

void rumah()
{
glPushMatrix();

	glRotatef(90,0,1,0);
	glScalef(2.5,2.5,2.5);
	glTranslatef(-2,-0.50,-10);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//pintu
	glPushMatrix();
		glTranslatef(0.5,0,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.3f,0.1f,0.0f);
			glVertex3f(2.0f,1.650f,0.0f);
			glVertex3f(2.650f,1.650f,0.0f);
			glVertex3f(2.650f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,0.0f);
		glEnd();
	glPopMatrix();	
	
//tingkat2
glPushMatrix();
		
	glTranslatef(0,1.5,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//atap	
//atap depan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap kanan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();
				
//atap kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap belakang
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();	
glPopMatrix();		
	
glPopMatrix();
}

void rumah2()
{
glPushMatrix();

	glRotatef(90,0,1,0);
	glScalef(2.5,2.5,2.5);
	glTranslatef(-9,-0.10,-9.5);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//pintu
	glPushMatrix();
		glTranslatef(0.5,0,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.3f,0.1f,0.0f);
			glVertex3f(2.0f,1.650f,0.0f);
			glVertex3f(2.650f,1.650f,0.0f);
			glVertex3f(2.650f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,0.0f);
		glEnd();
	glPopMatrix();	
	
//tingkat2
glPushMatrix();
	glTranslatef(0,1.5,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//atap	
//atap depan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap kanan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();
				
//atap kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap belakang
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();	
glPopMatrix();		
	
glPopMatrix();
}

void rumah3()
{
glPushMatrix();

	glRotatef(90,0,1,0);
	glScalef(2.5,2.5,2.5);
	glTranslatef(5,-0.10,-10);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//pintu
	glPushMatrix();
		glTranslatef(0.5,0,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.3f,0.1f,0.0f);
			glVertex3f(2.0f,1.650f,0.0f);
			glVertex3f(2.650f,1.650f,0.0f);
			glVertex3f(2.650f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,0.0f);
		glEnd();
	glPopMatrix();	
	
//tingkat2
glPushMatrix();
	glTranslatef(0,1.5,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
glPopMatrix();

//tingkat3
glPushMatrix();
	glTranslatef(0,2.9,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//atap	
//atap depan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap kanan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();
				
//atap kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap belakang
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();	
glPopMatrix();
		
	
glPopMatrix();
}

void rumah4kanan()
{
glPushMatrix();

	glRotatef(-90,0,1,0);
	glScalef(2.8,2.5,2.5);
	glTranslatef(0,-0.10,-10);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskkanan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//pintu
	glPushMatrix();
		glTranslatef(0.5,0,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.3f,0.1f,0.0f);
			glVertex3f(2.0f,1.650f,0.0f);
			glVertex3f(2.650f,1.650f,0.0f);
			glVertex3f(2.650f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,0.0f);
		glEnd();
	glPopMatrix();	
	
//tingkat2
glPushMatrix();
	glTranslatef(0,1.5,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);		
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.40f);	
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.20f);	
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.20f);	
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//atap	
//atap depan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap kanan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();
				
//atap kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap belakang
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();	
glPopMatrix();		
	
glPopMatrix();
}


void rumah5kanan()
{
glPushMatrix();

	glRotatef(-90,0,1,0);
	glScalef(2.7,2.5,2.2);
	glTranslatef(-10,-0.10,-9.5);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//pintu
	glPushMatrix();
		glTranslatef(0.5,0,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.3f,0.1f,0.0f);
			glVertex3f(2.0f,1.650f,0.0f);
			glVertex3f(2.650f,1.650f,0.0f);
			glVertex3f(2.650f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,0.0f);
		glEnd();
	glPopMatrix();	
	
//tingkat2
glPushMatrix();
	glTranslatef(0,1.5,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
glPopMatrix();

//tingkat3
glPushMatrix();
	glTranslatef(0,2.9,0);
//depan
	glPushMatrix();
		glTranslatef(0,0,3);
		glBegin(GL_POLYGON);
			glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//belakang
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
	glColor3f(1.0f,1.0f,1.0f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(5.0f,0.50f,0.0f);
			glVertex3f(5.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.9f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();

//kanan
	glPushMatrix();
		glTranslatef(3,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.90f,0.9f,0.9f);
			glVertex3f(2.0f,0.50f,0.0f);
			glVertex3f(2.0f,0.50f,3.0f);
			glVertex3f(2.0f,2.0f,3.0f);
			glVertex3f(2.0f,2.0f,0.0f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atas
	glPushMatrix();
		glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasdepan
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//atasbelakang
	glPushMatrix();
		glTranslatef(0,0,-3.70);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
		glEnd();
	glPopMatrix();
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.70f);
			glVertex3f(5.35f,2.0f,-0.350f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(5.350f,2.250f,3.350f);
			glVertex3f(5.35f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();	
	
//ataskiri
	glPushMatrix();
		//glTranslatef(0,0.25,0);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.50f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(1.65f,2.0f,3.350f);
			glVertex3f(1.65f,2.250f,3.350f);
			glVertex3f(1.65f,2.250f,-0.350f);
		glEnd();
	glPopMatrix();
	
//jendela atas
	glPushMatrix();
		glTranslatef(0.45,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//jendela atas2
	glPushMatrix();
		glTranslatef(1.6,0.1,3.01);
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(2.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.50f,0.0f);
			glVertex3f(3.0f,1.0f,0.0f);
			glVertex3f(2.0f,1.0f,0.0f);
		glEnd();
	glPopMatrix();	
	
//atap	
//atap depan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap kanan
	glPushMatrix();
		glTranslatef(0,0,0);
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(5.350f,2.0f,3.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();
				
//atap kiri
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.4f,0.4f,0.4f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(1.65f,2.0f,3.350f);
		glEnd();
	glPopMatrix();
	
//atap belakang
	glPushMatrix();
		glBegin(GL_POLYGON);
			glColor3f(0.6f,0.6f,0.6f);
			glVertex3f(1.65f,2.0f,-0.350f);
			glVertex3f(3.5f,3.0f,1.5f);
			glVertex3f(5.35f,2.0f,-0.350f);
		glEnd();
	glPopMatrix();	
glPopMatrix();
	
glPopMatrix();
}


void Truk(){
	//kerangka tengah
	//depan
		glPushMatrix();
		glColor3f(0,0,0.5);
		glTranslatef(0,0,21.5);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,1.5f,0.0f);
			glVertex3f(0.0f,1.5f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(-4.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
	//belakang
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(0, 1, 0, 0);
		glTranslatef(0,0,1.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,1.5f,10.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,1.5f,10.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,2.0f,10.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,2.0f,10.0f);
		glEnd();
		glPopMatrix();
	// kiri
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(-90, 0, 1, 0);
		glTranslatef(17.5,0,4);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(4.0f,1.5f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(-6.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
	// kanan
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(90, 0, 1, 0);
		glTranslatef(-15.5,0,0);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(4.0f,1.5f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(-6.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
	
		//Penghubung//
		glPushMatrix();
		glTranslatef(0,0,10.75);
		//depan//
		glPushMatrix();
			glColor3f(0,0.5,0);
			glBegin(GL_QUADS);
				glVertex3f(-2.0f,1.5f,0.0f);
				glVertex3f(-1.0f,1.5f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(-2.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
		//belakang
		glPushMatrix();
			glColor3f(0,0.5,0);
			glRotated(0, 1, 0, 0);
			glTranslatef(0,0,1);
			glBegin(GL_QUADS);
				glVertex3f(-2.0f,1.5f,0.0f);
				glVertex3f(-1.0f,1.5f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(-2.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
		//kanan//
		glPushMatrix();
			glColor3f(0,0.5,0);
			glRotated(-90, 0, 1, 0);
			glTranslatef(2,0,2);
			glBegin(GL_QUADS);
				glVertex3f(-2.0f,1.5f,0.0f);
				glVertex3f(-1.0f,1.5f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(-2.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
//		//kiri//
		glPushMatrix();
			glColor3f(0,0.5,0);
			glRotated(90, 0, 1, 0);
			glTranslatef(1,0,-1);
			glBegin(GL_QUADS);
				glVertex3f(-2.0f,1.5f,0.0f);
				glVertex3f(-1.0f,1.5f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(-2.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
		//atas//
		glPushMatrix();
			glColor3f(0,0.5,0);
			glRotated(90, 1, 0, 0);
			glRotated(90, 0, 0, 1);
			glTranslatef(1,0,-2);
			glBegin(GL_QUADS);
				glVertex3f(0.0f,1.0f,0.0f);
				glVertex3f(-1.0f,1.0f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(0.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
		//bawah//
		glPushMatrix();
			glColor3f(0,0.5,0);
			glRotated(90, 1, 0, 0);
			glRotated(90, 0, 0, 1);
			glTranslatef(1,0,-1.5);
			glBegin(GL_QUADS);
				glVertex3f(0.0f,1.0f,0.0f);
				glVertex3f(-1.0f,1.0f,0.0f);
				glVertex3f(-1.0f,2.0f,0.0f);
				glVertex3f(0.0f,2.0f,0.0f);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	
	//kerangka belakang
	//depan
		glPushMatrix();
		glColor3f(0,0,0.5);
		glTranslatef(0,0,3);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,1.5f,0.0f);
			glVertex3f(0.0f,1.5f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(-4.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
	//belakang
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(0, 1, 0, 0);
		glTranslatef(0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,1.5f,10.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,1.5f,10.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,2.0f,10.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,2.0f,10.0f);
		glEnd();
		glPopMatrix();
	// kiri
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(-90, 0, 1, 0);
		glTranslatef(9,0,4);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(2.0f,1.5f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
			glVertex3f(-6.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
	// kanan
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(90, 0, 1, 0);
		glTranslatef(-5,0,0);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(2.0f,1.5f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
			glVertex3f(-6.0f,2.0f,0.0f);
		glEnd();
		glPopMatrix();
		
	//body depan	
	//depan
		glPushMatrix();
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.5);
		glTranslatef(0,-1.74,24.74);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,1.5f,0.0f);
			glVertex3f(0.0f,1.5f,0.0f);
			glVertex3f(0.0f,4.5f,0.0f);
			glVertex3f(-4.0f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
	// atas
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,20,-4.5);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,1.5f,0.0f);
			glVertex3f(0.0f,1.5f,0.0f);
			glVertex3f(0.0f,4.5f,0.0f);
			glVertex3f(-4.0f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
	// bawah
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,20,-1.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,1.5f,0.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,1.5f,0.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,4.7f,0.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,4.7f,0.0f);
		glEnd();
		glPopMatrix();
	// kiri
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(-90, 0, 1, 0);
		glTranslatef(27.5,0,4);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(-2.8f,1.5f,0.0f);
			glVertex3f(-3.0f,4.5f,0.0f);
			glVertex3f(-6.0f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
	// kanan
		glPushMatrix();
		glColor3f(0,0,0.5);
		glRotated(90, 0, 1, 0);
		glTranslatef(-18.7,0,0);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,1.5f,0.0f);
			glVertex3f(-2.8f,1.5f,0.0f);
			glVertex3f(-2.8f,4.5f,0.0f);
			glVertex3f(-5.8f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
	//pintu kiri
		glPushMatrix();
		glColor3f(0,0,0.4);
		glRotated(-90, 0, 1, 0);
		glTranslatef(27.2,-0.2,4.001);
		glBegin(GL_QUADS);
			glVertex3f(-5.0f,1.75f,0.0f);
			glVertex3f(-2.6f,1.75f,0.0f);
			glVertex3f(-2.8f,4.5f,0.0f);
			glVertex3f(-5.0f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.4,0.4,0.4);
		glRotated(-90, 0, 1, 0);
		glTranslatef(28.3,0,4.002);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,3.0f,0.0f);
			glVertex3f(-3.9f,3.0f,0.0f);
			glVertex3f(-4.0f,4.2f,0.0f);
			glVertex3f(-6.0f,4.2f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0,0,0);
		glRotated(-90, 0, 1, 0);
		glTranslatef(27.4,-0.2,4.002);
		glBegin(GL_QUADS);
			glVertex3f(-5.0f,3.0f,0.0f);
			glVertex3f(-4.7f,3.0f,0.0f);
			glVertex3f(-4.7f,3.1f,0.0f);
			glVertex3f(-5.0f,3.1f,0.0f);
		glEnd();
		glPopMatrix();
		
	//pintu kanan	
		glPushMatrix();
		glColor3f(0,0,0.4);
		glRotated(90, 0, 1, 0);
		glTranslatef(-19.4,-0.2,0.001);
		glBegin(GL_QUADS);
			glVertex3f(-5.2f,1.75f,0.0f);
			glVertex3f(-2.7f,1.75f,0.0f);
			glVertex3f(-2.7f,4.5f,0.0f);
			glVertex3f(-5.0f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0.4,0.4,0.4);
		glRotated(90, 0, 1, 0);
		glTranslatef(-18.4,0,0.002);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,3.0f,0.0f);
			glVertex3f(-3.9f,3.0f,0.0f);
			glVertex3f(-3.9f,4.2f,0.0f);
			glVertex3f(-5.9f,4.2f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glColor3f(0,0,0);
		glRotated(90, 0, 1, 0);
		glTranslatef(-17.7,-0.2,0.002);
		glBegin(GL_QUADS);
			glVertex3f(-5.0f,3.0f,0.0f);
			glVertex3f(-4.7f,3.0f,0.0f);
			glVertex3f(-4.7f,3.1f,0.0f);
			glVertex3f(-5.0f,3.1f,0.0f);
		glEnd();
		glPopMatrix();
		
	//jendela
		glPushMatrix();
		glRotated(-4, 1, 0, 0);
		glColor3f(0.4,0.4,0.4);
		glTranslatef(-0.05,-2,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-3.9f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,4.5f,0.0f);
			glVertex3f(-3.9f,4.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.4);
		glTranslatef(0,-2,24.741);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,2.9f,0.0f);
			glVertex3f(0.0f,2.9f,0.0f);
			glVertex3f(0.0f,4.6f,0.0f);
			glVertex3f(-4.0f,4.6f,0.0f);
		glEnd();
		glPopMatrix();
		
	//lampu
		glPushMatrix();
		glRotated(-4, 1, 0, 0);
		glColor3f(0.55,0.55,0.55);
		glTranslatef(-0.05,-2.5,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glRotated(-4, 1, 0, 0);
		glColor3f(0.55,0.55,0.55);
		glTranslatef(-3.45,-2.5,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
	//spion	kiri
		glPushMatrix();  //depan
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.4);
		glTranslatef(-4.3,-1,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();  //belakang
		glRotated(-4, 1, 0, 0);
		glColor3f(0.6,0.6,0.6);
		glTranslatef(-4.3,-1,24.741);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();  // tangkai
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.4);
		glTranslatef(-4,-1.3,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-0.8f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.95f,0.0f);
			glVertex3f(-0.8f,2.95f,0.0f);
		glEnd();
		glPopMatrix();
	//spion kanan	
		glPushMatrix();   //depan
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.4);
		glTranslatef(0.8,-1,24.742);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();   //belakang
		glRotated(-4, 1, 0, 0);
		glColor3f(0.6,0.6,0.6);
		glTranslatef(0.8,-1,24.741);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.5f,0.0f);
			glVertex3f(-0.5f,2.5f,0.0f);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();   //tangkai
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0.4);
		glTranslatef(0.6,-1.3,24.741);
		glBegin(GL_QUADS);
			glVertex3f(-0.8f,3.0f,0.0f);
			glVertex3f(0.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.95f,0.0f);
			glVertex3f(-0.8f,2.95f,0.0f);
		glEnd();
		glPopMatrix();
		
	//pembersih jendela
		glPushMatrix();   
		glRotated(-4, 1, 0, 0);
		glColor3f(0,0,0);
		glTranslatef(-1,-1.2,24.743);
		glBegin(GL_QUADS);
			glVertex3f(-2.0f,3.0f,0.0f);
			glVertex3f(0.0f,2.2f,0.0f);
			glVertex3f(0.0f,2.15f,0.0f);
			glVertex3f(-2.0f,2.95f,0.0f);
		glEnd();
		glPopMatrix();
		
		
	//body tengah	
	//depan
		glPushMatrix();
		glColor3f(0.5,0,0);
		glTranslatef(0,0,21.5);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(0.0f,5.5f,0.0f);
			glVertex3f(-4.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
	// atas
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,9.5,-5.5);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(0.0f,12.0f,0.0f);
			glVertex3f(-4.0f,12.0f,0.0f);
		glEnd();
		glPopMatrix();
	//belakang
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(0, 1, 0, 0);
		glTranslatef(0,0,1.5);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,2.0f,10.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,2.0f,10.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,5.5f,10.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,5.5f,10.0f);
		glEnd();
		glPopMatrix();
	// bawah
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,9.5,-2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,2.0f,0.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,2.0f,0.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,12.0f,0.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,12.0f,0.0f);
		glEnd();
		glPopMatrix();
	// kiri
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(-90, 0, 1, 0);
		glTranslatef(17.5,0,4);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(4.0f,5.5f,0.0f);
			glVertex3f(-6.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
	// kanan
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 0, 1, 0);
		glTranslatef(-15.5,0,0);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,2.0f,0.0f);
			glVertex3f(4.0f,2.0f,0.0f);
			glVertex3f(4.0f,5.5f,0.0f);
			glVertex3f(-6.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
	
	//body belakang
	//depan
		glPushMatrix();
		glColor3f(0.5,0,0);
		glTranslatef(0,0,3);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(0.0f,5.5f,0.0f);
			glVertex3f(-4.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
	// atas
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,1,-5.5);
		glBegin(GL_QUADS);
			glVertex3f(-4.0f,2.0f,0.0f);
			glVertex3f(0.0f,2.0f,0.0f);
			glVertex3f(0.0f,10.0f,0.0f);
			glVertex3f(-4.0f,10.0f,0.0f);
		glEnd();
		glPopMatrix();
	//belakang
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(0, 1, 0, 0);
		glTranslatef(0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,2.0f,10.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,2.0f,10.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,5.5f,10.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,5.5f,10.0f);
		glEnd();
		glPopMatrix();
	// bawah
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 1, 0, 0);
		glTranslatef(0,1,-2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); // kiri bawah
			glVertex3f(-4.0f,2.0f,0.0f);
			glTexCoord2f(1.0f,0.0f); // kanan bawah
			glVertex3f(0.0f,2.0f,0.0f);
			glTexCoord2f(1.0f,1.0f); // kanan atas
			glVertex3f(0.0f,10.0f,0.0f);
			glTexCoord2f(0.0f,1.0f); // kanan bawah
			glVertex3f(-4.0f,10.0f,0.0f);
		glEnd();
		glPopMatrix();
	// kiri
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(-90, 0, 1, 0);
		glTranslatef(9,0,4);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
			glVertex3f(2.0f,5.5f,0.0f);
			glVertex3f(-6.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
	// kanan
		glPushMatrix();
		glColor3f(0.5,0,0);
		glRotated(90, 0, 1, 0);
		glTranslatef(-5,0,0);
		glBegin(GL_QUADS);
			glVertex3f(-6.0f,2.0f,0.0f);
			glVertex3f(2.0f,2.0f,0.0f);
			glVertex3f(2.0f,5.5f,0.0f);
			glVertex3f(-6.0f,5.5f,0.0f);
		glEnd();
		glPopMatrix();
		
}

void Roda(){
	//truk depan
	glPushMatrix();//roda kiri depan
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(22,1.5,0.0);
	cylinder(0.5, 0.5,0.5);
	glColor3f(0.5,0.5,0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();	 

	glPushMatrix();//roda kanan depan
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(22,1.5,3.6);
	cylinder(0.5, 0.5,0.5);
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glRotated(180, 0, 1, 0);
	glTranslatef(-2,0,-0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//roda kiri belakang
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(13.5,1.5,0.0);
	cylinder(0.5, 0.5,0.5);
	glColor3f(0.5,0.5,0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();	 

	glPushMatrix();//roda kanan belakang
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(13.5,1.5,3.6);
	cylinder(0.5, 0.5,0.5);
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glRotated(180, 0, 1, 0);
	glTranslatef(-2,0,-0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();
	glPopMatrix();
	
	//truk belakang
	glPushMatrix();//roda kiri belakang
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(3.5,1.5,0.0);
	cylinder(0.5, 0.5,0.5);
	glColor3f(0.5,0.5,0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();	 
	
	glPushMatrix();//roda kiri depan
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(8.5,1.5,0.0);
	cylinder(0.5, 0.5,0.5);
	cylinder(0.5, 0.5,0.5);
	glColor3f(0.5,0.5,0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();
	
	glPushMatrix();//roda kanan depan
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(8.5,1.5,3.6);
	cylinder(0.5, 0.5,0.5);
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glRotated(180, 0, 1, 0);
	glTranslatef(-2,0,-0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//roda kanan belakang
	glColor3f(0.0,0.0,0.0);
	glRotated(-90, 0, 1, 0);
	glTranslatef(3.5,1.5,3.6);
	cylinder(0.5, 0.5,0.5);
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	glRotated(180, 0, 1, 0);
	glTranslatef(-2,0,-0.5);
	cylinder(0.25, 0.25,0.25);
	glPopMatrix();	
	glPopMatrix();
}

void Awan(){
	//Awan 1
	glPushMatrix();
		glTranslatef(-20, 20, 5);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3ub(153, 223, 255);
		glutSolidSphere(3, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-20, 20, 2);
		glutSolidSphere(2, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-20, 20, 8);
		glutSolidSphere(2, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-20, 20, 0);
		glutSolidSphere(1, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-20, 20, 10);
		glutSolidSphere(1, 50, 50);
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Kalau move dan angle tidak nol, gerakkan kamera...
	if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}

	//Gambar environtment
	Jalanan();
	Awan();
	//Langit();
	rumah();
	rumah2();
	rumah3();
	rumah4kanan();
	rumah5kanan();
	Pos();
	Palang();
	
	// Gambar objek di sini...
	Truk();
	Roda();
	glutSwapBuffers();
	glFlush();
}
void pressKey(int key, int x, int y) {
// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
	switch (key) {
		case GLUT_KEY_LEFT : 
			deltaAngle = -0.005f;
		break;
		case GLUT_KEY_RIGHT : 
			deltaAngle = 0.005f;
		break;
		case GLUT_KEY_UP : 
			deltaMove = 3;
		break;
		case GLUT_KEY_DOWN : 
			deltaMove = -3;
		break;
	}
}

void releaseKey(int key, int x, int y) {
// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
	switch (key) {
		case GLUT_KEY_LEFT :
			if (deltaAngle < 0.0f)
				deltaAngle = 0.0f;
			break;
		case GLUT_KEY_RIGHT : 
			if (deltaAngle > 0.0f)
				deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP : 
			if (deltaMove > 0)
				deltaMove = 0;
			break;
		case GLUT_KEY_DOWN : 
			if (deltaMove < 0)
				deltaMove = 0;
			break;
	}
}
// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting(){
// Fungsi mengaktifkan pencahayaan
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void){
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("3D Truk Gandeng");
	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutDisplayFunc(display);
	glutIdleFunc(display); // Fungsi display-nya dipanggil terus-menerus
	
	glutReshapeFunc(Reshape);
	lighting();
	init();
	glutMainLoop();
	return(0);
}

