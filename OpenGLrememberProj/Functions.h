#pragma once

//���������� ��� ������ ������ ������ � ����� ������� ��� �� ����������
void TheFirstHermiteCurve()
{
	double P1[3] = { -5,-5,0 };
	double P2[3] = { 7,24,17 };
	double P3[3] = { 30,21,7 };
	double P4[3] = { 20,-10,-7 };

	HermiteCurves(P1, P2, P3, P4);
	//����� �-�� ��� �������� ������� �� ������
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 1);
}

//���������� ��� ������ ������ ������ � ����� ������� ��� �� ����������
void TheSecondHermiteCurve()
{
	double P1[3] = { 5,5,0 };
	double P2[3] = { -7,-24,-17 };
	double P3[3] = { -30,-21,7 };
	double P4[3] = { -20,10,-7 };

	HermiteCurves(P1, P2, P3, P4);
	//����� �-�� ��� �������� ������� �� ������
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 1);
}

//��������� ��� ������ ������ ����� � ����� ������� ��� �� ����������
void TheFirstBezierCurve()
{
	//��������� ����� ��� ������ ������ (����� �������� ����� � ������� ������ ����)
	double P1[3] = { 5,5,0 };
	double P2[3] = { -7,-24,-17 };
	double P3[3] = { -20,10,-7 };
	double P4[3] = { -30,-21,7 };

	BezierCurves(P1, P2, P3, P4, 1);
	//����� �-�� ��� �������� ������� �� ������
	AnimationObjectMovingAlongCurve(P1, P2, P3, P4, 2);
}

//���������� ��� ������ ������ ����� � ����� ������� ��� �� ����������
void TheSecondBezierCurve()
{
	//���������� ����� ��� ������ ������ ����� (����� �������� ����� � ������ ������ ����)
	double p0[3] = { 0,0,0 };
	double p1[3] = { 10,15,15 };
	double p2[3] = { 25,35,25 };
	double p3[3] = { 30,10,5 };

	BezierCurves(p0, p1, p2, p3, 2);
	//����� �-�� ��� �������� ������� �� ������
	AnimationObjectMovingAlongCurve(p0, p1, p2, p3, 2);
}