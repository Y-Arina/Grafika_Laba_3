#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

//класс движущегося объекта
class MovingObject
{
	double A1[3] = { 0,0,0 }; double A2[3] = { 0,0,0 };
	double B1[3] = { 0,0,0 }; double B2[3] = { 0,0,0 };
	double C1[3] = { 0,0,0 }; double C2[3] = { 0,0,0 };
	double D1[3] = { 0,0,0 }; double D2[3] = { 0,0,0 };
	double E1[3] = { 0,0,0 }; double E2[3] = { 0,0,0 };
	double F1[3] = { 0,0,0 }; double F2[3] = { 0,0,0 };
	double G1[3] = { 0,0,0 }; double G2[3] = { 0,0,0 };
	double H1[3] = { 0,0,0 }; double H2[3] = { 0,0,0 };
	double O[3] = { 0,0,0 };

	double X_Space[3] = { 1,0,0 };

	double x_object[3];
	double y_object[3];
	double z_object[3];

public: MovingObject() {}
	  void FindingPoints(double point[3], double next_point[3]);
	  
private: void PrintObject(); 
	     void FindingX();
		 void FindingY();
	     void FindingZ();
	     void PrintFrontSide();
	     void PrintBackSide();
	     void PrintShapeSide();
	     void PrintAxesObject();
	     void FindingAnAngleWithAxes(double point[3], double next_point[3]);
};

//нахождение точек в зависимости от координаты центра фигуры
void MovingObject::FindingPoints(double point[3], double next_point[3])
{
	FindingX();
	FindingY();
	FindingZ();

	glPushMatrix();
	glTranslated(point[0], point[1], point[2]);
	FindingAnAngleWithAxes(point, next_point);
	PrintObject();
	glPopMatrix();
}

//нахождение координат по х
void MovingObject::FindingX()
{
	A1[0] = O[0] - 0.5;  A2[0] = O[0] + 0.5;
	B1[0] = O[0] - 0.5;  B2[0] = O[0] + 0.5;
	C1[0] = O[0] - 0.5;  C2[0] = O[0] + 0.5;
	D1[0] = O[0] - 0.5;  D2[0] = O[0] + 0.5;
	E1[0] = O[0] - 0.5;  E2[0] = O[0] + 0.5;
	F1[0] = O[0] - 0.5;  F2[0] = O[0] + 0.5;
	G1[0] = O[0] - 0.5;  G2[0] = O[0] + 0.5;
	H1[0] = O[0] - 0.5;  H2[0] = O[0] + 0.5;
}

//нахождение координат по у
void MovingObject::FindingY()
{
	C1[1] = O[1] + 3;  C2[1] = O[1] + 3;
	G1[1] = O[1] - 3;  G2[1] = O[1] - 3;

	B1[1] = O[1] + 0.5;  B2[1] = O[1] + 0.5;
	D1[1] = O[1] + 0.5;  D2[1] = O[1] + 0.5;

	H1[1] = O[1] - 0.5;  H2[1] = O[1] - 0.5;
	F1[1] = O[1] - 0.5;  F2[1] = O[1] - 0.5;

	A1[1] = O[1];  A2[1] = O[1];
	E1[1] = O[1];  E2[1] = O[1];
}

//нахождение уоординат по z
void MovingObject::FindingZ()
{
	A1[2] = O[2] + 3;  A2[2] = O[2] + 3;
	E1[2] = O[2] - 3;  E2[2] = O[2] - 3;

	B1[2] = O[2] + 0.5;  B2[2] = O[2] + 0.5;
	H1[2] = O[2] + 0.5;  H2[2] = O[2] + 0.5;

	D1[2] = O[2] - 0.5;  D2[2] = O[2] - 0.5;
	F1[2] = O[2] - 0.5;  F2[2] = O[2] - 0.5;

	G1[2] = O[2];  G2[2] = O[2];
	C1[2] = O[2];  C2[2] = O[2];
}

//рисование объекта
void MovingObject::PrintObject()
{
	PrintFrontSide();
	PrintBackSide();
	PrintShapeSide();
}

//рисование лицевой стороны
void MovingObject::PrintFrontSide()
{
	glColor3f(2.0f, 0.5f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3dv(A1);
	glVertex3dv(B1);
	glVertex3dv(H1);

	glVertex3dv(B1);
	glVertex3dv(C1);
	glVertex3dv(D1);

	glVertex3dv(D1);
	glVertex3dv(E1);
	glVertex3dv(F1);

	glVertex3dv(F1);
	glVertex3dv(G1);
	glVertex3dv(H1);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3dv(H1);
	glVertex3dv(B1);
	glVertex3dv(D1);
	glVertex3dv(F1);
	glEnd();
}

//рисование боковой стороны
void MovingObject::PrintBackSide()
{
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex3dv(A2);
	glVertex3dv(B2);
	glVertex3dv(H2);

	glVertex3dv(B2);
	glVertex3dv(C2);
	glVertex3dv(D2);

	glVertex3dv(D2);
	glVertex3dv(E2);
	glVertex3dv(F2);

	glVertex3dv(F2);
	glVertex3dv(G2);
	glVertex3dv(H2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3dv(H2);
	glVertex3dv(B2);
	glVertex3dv(D2);
	glVertex3dv(F2);
	glEnd();

}

//рисование боковых сторон фигуры
void MovingObject::PrintShapeSide()
{
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3dv(A1);
	glVertex3dv(A2);
	glVertex3dv(B2);
	glVertex3dv(B1);

	glVertex3dv(B1);
	glVertex3dv(B2);
	glVertex3dv(C2);
	glVertex3dv(C1);

	glVertex3dv(C1);
	glVertex3dv(C2);
	glVertex3dv(D2);
	glVertex3dv(D1);

	glVertex3dv(D1);
	glVertex3dv(D2);
	glVertex3dv(E2);
	glVertex3dv(E1);

	glVertex3dv(E1);
	glVertex3dv(E2);
	glVertex3dv(F2);
	glVertex3dv(F1);

	glVertex3dv(F1);
	glVertex3dv(F2);
	glVertex3dv(G2);
	glVertex3dv(G1);

	glVertex3dv(G1);
	glVertex3dv(G2);
	glVertex3dv(H2);
	glVertex3dv(H1);

	glVertex3dv(H1);
	glVertex3dv(H2);
	glVertex3dv(A2);
	glVertex3dv(A1);
	glEnd();
}

//рисование осей фигуры
void MovingObject::PrintAxesObject()
{
	double X_Object[3] = { O[0] + 1,O[1],O[2] };
	double Y_Object[3] = { C1[0] + 0.5,C1[1] + 1,C1[2] };
	double Z_Object[3] = { A1[0] + 0.5, A1[1],A1[2] + 1 };

	glBegin(GL_LINES);
	glColor4f(1, 0, 0, 0);
	glVertex3dv(O);
	glVertex3dv(X_Object);

	glColor3f(0, 1, 0);
	glVertex3d(C1[0] + 0.5, C1[1], C1[2]);
	glVertex3dv(Y_Object);

	glColor3f(0, 0, 1);
	glVertex3d(A1[0] + 0.5, A1[1], A1[2]);
	glVertex3dv(Z_Object);
	glEnd();
}

//нахождение углов и поворот
void MovingObject::FindingAnAngleWithAxes(double point[3], double next_point[3])
{
	double Vec[3] = { 0,0,0 };
	FindingAVectorByPoints(point, next_point, Vec);
	NormalizationOfTheVector(Vec, FIndingTheLenghtOfAVector(Vec));
	x_object[0] = Vec[0]; x_object[1] = Vec[1]; x_object[2] = 0;

	NormalizationOfTheVector(x_object, FIndingTheLenghtOfAVector(x_object));

	double cos = ScalarProductOfTwoVectors(X_Space, x_object);
	double VecProduct[3] = { 0,0,0 };
	VectorProductOfTwoVectors(X_Space, x_object, VecProduct);

	double sin = VecProduct[2] / abs(VecProduct[2]);
	double alpha = acos(cos) * 180.0 / M_PI * sin;
	double betta = acos(Vec[2]) * 180.0 / M_PI - 90;

	glRotated(alpha, 0, 0, 1);
	glRotated(betta, 0, 1, 0);
}

