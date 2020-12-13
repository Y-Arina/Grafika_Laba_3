#pragma once
#include "MovingObjects.h"

double t_max = 0;
double t_min = 1;
double delta_time = 0;
bool Checkingt_max = true;

//движение объекта от начала до конца пкривой
void MoveAnObjectToTheEnd(double t_max,double P1[3], double P2[3],double P3[3],double P4[3], int k)
{
	double X[3];
	double X_next[3];
	MovingObject Star;

	if (k == 1)
	{
		double R1[3];
		double R4[3];

		TangentVectorHermite(P1, P2, P3, P4, R1, R4);

		PointHermiteCurves(P1, P4, R1, R4, t_max, X);
		PointHermiteCurves(P1, P4, R1, R4, t_max + 0.01, X_next);
		Star.FindingPoints(X, X_next);
	}
	if (k == 2)
	{
		PointBezierCurve(P1, P2, P3, P4, t_max, X);
		PointBezierCurve(P1, P2, P3, P4, t_max + 0.01, X_next);
		Star.FindingPoints(X, X_next);
	}
}

//движение объекта от конца к началу кривой
void MoveAnObjectToTheBedinning(double t_min, double P1[3], double P2[3], double P3[3], double P4[3], int k)
{
	double X[3];
	double X_next[3];
	MovingObject Star;
	
	if (k == 1)
	{
		double R1[3];
		double R4[3];

		TangentVectorHermite(P1, P2, P3, P4, R1, R4);

		PointHermiteCurves(P1, P4, R1, R4, t_min, X);
		PointHermiteCurves(P1, P4, R1, R4, t_min - 0.01, X_next);
		Star.FindingPoints(X, X_next);
	}
	if (k == 2)
	{
		PointBezierCurve(P1, P2, P3, P4, t_min, X);
		PointBezierCurve(P1, P2, P3, P4, t_min - 0.01, X_next);
		Star.FindingPoints(X, X_next);
	}
}

//нахождение delta_time (разницы между прорисовками, кадрами)
double SearchDeltaTime() {
	static auto EndRender = std::chrono::steady_clock::now();
	auto CurTime = std::chrono::steady_clock::now();
	auto DeltaTime = CurTime - EndRender;
	double Delta = 1.0 * std::chrono::duration_cast<std::chrono::microseconds>(DeltaTime).count() / 1000000;
	EndRender = CurTime;
	return Delta;
}

//функция вызывающая ф-ии для осуществления движения по кривым
void AnimationObjectMovingAlongCurve(double P1[3], double P2[3], double P3[3], double P4[3], int k)
{
	delta_time = SearchDeltaTime();

	if (t_max >= 1)
	{
		t_max = 0;
		Checkingt_max = false;
	}

	if (t_min <= 0)
	{
		t_min = 1;
		Checkingt_max = true;
	}

	if (Checkingt_max == true)
	{
		t_max += delta_time / 10;
		MoveAnObjectToTheEnd(t_max, P1, P2, P3, P4, k);
	}
	else
	{
		t_min -= delta_time / 10;
		MoveAnObjectToTheBedinning(t_min, P1, P2, P3, P4, k);
	}
}