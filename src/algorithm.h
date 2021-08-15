/*=======================================================
//
//      Authors:    Kosorotova Valeria
//                  Pasechnikov Vyacheslav
//
//      15/8/2021
//
//=======================================================*/

#include <math.h>
#include <stdio.h>
#include <stdint.h>

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

extern double GK42[3];
extern double SK42_R[3];
extern double PZ_90_11[3];

//функции перевода из СК-42 ГК в ПЗ-90.11
extern void from_SK42_GK_to_PZ_90_11(double X_GK42, double Y_GK42, double H_GK42);
void from_42GK_to_42(double X, double Y, double H);
void from_SK42_R_to_PZ_90_11(double X, double Y, double Z);

//функции перевода из ПЗ-90.11 в СК-42 ГК
extern void from_PZ_90_11_to_SK42_GK(double B_PZ_90_11, double L_PZ_90_11, double H_PZ_90_11);
void from_PZ_90_11_R_to_SK42(double X, double Y, double Z);
void from_Rect_to_Geod(double X, double Y, double Z, int a, double E, double dopusk);
void from_42_to_42GK(double B, double L);

#endif