/* MClass */

#ifndef MCLASS_H
#define MCLASS_H 1

#include<math.h>

#define FunctionA 1
#define FunctionB 0
#if FunctionA
#define extFunction(x, M) M*x*(1-x) // x in [-1,1] | M in [0,1]
#define M_MIN 2.8
#define M_MAX 3.6
#define X0 0.1
#elif FunctionB
#define extFunction(x, M) exp(-7*pow(x, 2)) + M; // M in [-1,0]
#define M_MIN -1.0
#define M_MAX 0.0
#define X0 0.0
#else
#define extFunction(x, M) 2.*M*pow(x, 2) + 1. - 2.*M; // x in [-1,1] | M in [0,1]
#define M_MIN 0.74
#define M_MAX 0.90
#define X0 0.1
#endif

typedef class MClass {
        private:
                int N;

                long double M;
                int b;

        public:
                MClass(const long double M, const long double x0, const int N, const long double xprecision);
                ~MClass();

                void print() const;

                long double getM() const;
                int getb() const;

                int getN() const;

                bool operator<(const MClass &OtherObject) const;
                bool operator>(const MClass &OtherObject) const;

        private:
                int calc_b(const long double x0, const long double xprecision) const;
                long double* calc_x(const long double x0) const;
} MClass;

#endif
