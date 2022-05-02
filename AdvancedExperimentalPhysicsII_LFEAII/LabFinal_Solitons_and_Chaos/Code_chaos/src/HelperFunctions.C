#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include <algorithm>

#include "HelperFunctions.h"
#include "Debug.h"

std::vector<MClass> makeUniformMDist(const long double M_Min, const long double M_Max, const int M_Div, const long double x0, const int N, const long double xprecision) {
        const long double M_sep = (M_Max - M_Min)/(long double) (M_Div-1);

        std::vector<MClass> MVec;
        for(int i=0; i<M_Div; ++i) {
                MVec.push_back(MClass(M_Min + i*M_sep, x0, N, xprecision));
                if(MVec.back().getb() == 0) break;
        }

        return MVec;
}

std::vector<MClass> makeBissectionMDist(const long double M_Min, const long double M_Max, const int maxb, const long double x0, const int N, const long double xprecision) {
        std::vector<MClass> MVec;

        long double M_Left  = M_Min;
        long double M_Right = M_Max;

        int b_Objective = 2;

        MVec.push_back(MClass(M_Left, x0, N, xprecision));
        MVec.back().print();
        MVec.push_back(MClass(M_Right, x0, N, xprecision));
        MVec.back().print();

        while(MVec.back().getb() != maxb) {
                if(MVec.back().getb() == b_Objective) {
                        //printf("= | b_Objective = %d, M_Left = %Lf | M_Right = %Lf | M_Next = %Lf\n", b_Objective, M_Left, M_Right, M_Right + (M_Max - M_Right)/2);
                        M_Left  = M_Right;
                        M_Right = M_Right + (M_Max - M_Right)/2;

                        b_Objective = 2*b_Objective;
                } else if (MVec.back().getb() > b_Objective || MVec.back().getb() == 0 || MVec.back().getb()%2 != 0) {
                        //printf("> | b_Objective = %d, M_Left = %Lf | M_Right = %Lf | M_Next = %Lf\n", b_Objective, M_Left, M_Right, M_Left + (M_Right - M_Left)/2);
                        M_Right = M_Left + (M_Right - M_Left)/2;
                } else if (MVec.back().getb() < b_Objective) {
                        //printf("< | b_Objective = %d, M_Left = %Lf | M_Right = %Lf | M_Next = %Lf\n", b_Objective, M_Left, M_Right, M_Right + (M_Max - M_Right)/2);
                        M_Right = M_Right + (M_Max - M_Right)/2;
                }

                MVec.push_back(MClass(M_Right, x0, N, xprecision));
                MVec.back().print();
        }

        std::sort(MVec.begin(), MVec.end());

        return MVec;
}

std::vector<std::array<long double, 2>> getTransitions(const std::vector<MClass> InputVec) {
        const int M_N = InputVec.size() - 1;

        std::vector<std::array<long double, 2>> Transitions;
        for(int i=0; i<M_N; ++i) if(InputVec[i+1].getb() == 2*InputVec[i].getb() && InputVec[i].getb()!=0 && InputVec[i+1].getb()!=0) {
                Transitions.push_back({InputVec[i].getM(), InputVec[i+1].getM()});
        }

        return Transitions;
}

long double makeBissection(const long double M_Min, const long double M_Max, const long double Mprecision, const long double x0, const int N, const long double xprecision) {
        const long double M_Mid = (M_Max + M_Min)/2;

        if(fabs(M_Max - M_Min) < Mprecision)
                return M_Mid;

        const MClass Min2Max[3] = { MClass(M_Min, x0, N, xprecision), MClass(M_Mid, x0, N, xprecision), MClass(M_Max, x0, N, xprecision) };

        if(Min2Max[0].getb() == Min2Max[1].getb())
                return makeBissection(M_Mid, M_Max, Mprecision, x0, N, xprecision);

        if(Min2Max[1].getb() == Min2Max[2].getb())
                return makeBissection(M_Min, M_Mid, Mprecision, x0, N, xprecision);

        printf(RED "Error: " YEL "b[Mid] is neither b[Min] nor b[Max]" RESET "\
                        \n\tMin | %Lf | %d\
                        \n\tMid | %Lf | %d\
                        \n\tMax | %Lf | %d\n",
                        Min2Max[0].getM(), Min2Max[0].getb(), Min2Max[1].getM(), Min2Max[1].getb(), Min2Max[2].getM(), Min2Max[2].getb());

        return NAN;
}

std::vector<long double> getFeigenbaum(const std::vector<long double> Transitions) {
        const int T_N = Transitions.size() - 2;

        std::vector<long double> Feigenbaum;
        for (int i=0; i<T_N; i++)
                Feigenbaum.push_back((Transitions[i+1]-Transitions[i])/(Transitions[i+2]-Transitions[i+1]));

        return Feigenbaum;
}
