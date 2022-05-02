#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H 1

#include<vector>
#include<array>

#include "MClass.h"

std::vector<MClass> makeUniformMDist(const long double M_Min, const long double M_Max, const int M_Div, const long double x0, const int N, const long double xprecision);
std::vector<MClass> makeBissectionMDist(const long double M_Min, const long double M_Max, const int maxb, const long double x0, const int N, const long double xprecision);

std::vector<std::array<long double, 2>> getTransitions(const std::vector<MClass> InputVec);

long double makeBissection(const long double M_Min, const long double M_Max, const long double Mprecision, const long double x0, const int N, const long double xprecision);

std::vector<long double> getFeigenbaum(const std::vector<long double> Transitions);

#endif
