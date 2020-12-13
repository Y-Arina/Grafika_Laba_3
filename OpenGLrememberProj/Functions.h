#pragma once

//координаты для первой кривой Эрмита и вызов функций для ее построения
void TheFirstHermiteCurve()
{
	double P1[3] = { -5,-5,0 };
	double P2[3] = { 7,24,17 };
	double P3[3] = { 30,21,7 };
	double P4[3] = { 20,-10,-7 };

	HermiteCurves(P1, P2, P3, P4);
	//вызов ф-ии для движения объекта по кривой
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 1);
}

//координаты для второй кривой Эрмита и вызов функций для ее построения
void TheSecondHermiteCurve()
{
	double P1[3] = { 5,5,0 };
	double P2[3] = { -7,-24,-17 };
	double P3[3] = { -30,-21,7 };
	double P4[3] = { -20,10,-7 };

	HermiteCurves(P1, P2, P3, P4);
	//вызов ф-ии для движения объекта по кривой
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 1);
}

//кординаты для первой кривой Безие и вызов функций для ее построения
void TheFirstBezierCurve()
{
	//кординаты точек для первой кривой (когда конечная точка в верхнем правом углу)
	double P1[3] = { 5,5,0 };
	double P2[3] = { -7,-24,-17 };
	double P3[3] = { -20,10,-7 };
	double P4[3] = { -30,-21,7 };

	BezierCurves(P1, P2, P3, P4, 1);
	//вызов ф-ии для движения объекта по кривой
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 2);
}

//координаты для второй кривой Безие и вызов функций для ее построения
void TheSecondBezierCurve()
{
	//координаты точек для второй кривой Безье (когда конечная точка в нижнем правом углу)
	double p0[3] = { 0,0,0 };
	double p1[3] = { 10,15,15 };
	double p2[3] = { 25,35,25 };
	double p3[3] = { 30,10,5 };

	BezierCurves(p0, p1, p2, p3, 2);
	//вызов ф-ии для движения объекта по кривой
	AnimationObjectMovingAlongCurve(p0, p1, p2, p3, 2);
}