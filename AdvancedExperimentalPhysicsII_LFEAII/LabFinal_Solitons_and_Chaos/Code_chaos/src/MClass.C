/* MClass */
#include <stdio.h>

#include "Debug.h"
#include "MClass.h"

MClass::MClass(const long double M, const long double x0, const int N, const long double xprecision) :
        N(N), M(M), b(calc_b(x0, xprecision))
{}

MClass::~MClass() {}

void MClass::print() const {
        printf(MAG "MClass: " CYN "M = %Lf" RESET " | " CYN "b = %d\n" RESET, M, b);
}

long double MClass::getM() const{
        return M;
}

int MClass::getb() const{
        return b;
}

int MClass::getN() const {
        return N;
}

bool MClass::operator<(const MClass &OtherObject) const {
        return getM() < OtherObject.getM();
}

// overload the operator> (if required)
bool MClass::operator>(const MClass &OtherObject) const {
        return getM() > OtherObject.getM();
}

int MClass::calc_b(const long double x0, const long double xprecision) const {
        long double* x = calc_x(x0);

        int tempb = 0;
        for(int j=2; j<=N; ++j)
                if(fabs(x[N-1] - x[N-j]) <= xprecision) {
                        tempb = j - 1;
                        break;
               }

        // Safty checks
        if(fabs(x[N-1] - x[N-2*tempb-1]) > xprecision) {
                printf(RED "Error: " YEL "x[N-2b-1] != x[N-1] : M=%Lf : b=%d"
                                RESET "\n\tx[N-1]    = %Lf\n\tx[N-2b-1] = %Lf\n",
                                M, tempb, x[N-1], x[N-2*tempb-1]);
                tempb = 0;
        } else if(fabs(x[N-2] - x[N-tempb-2]) > xprecision) {
                printf(RED "Error: " YEL "x[N-b-2] != x[N-2] : M=%Lf : b=%d"
                                RESET "\n\tx[N-2]   = %Lf\n\tx[N-b-2] = %Lf\n",
                                M, tempb, x[N-2], x[N-tempb-2]);
                tempb = 0;
        }

        delete(x);

        return tempb;
}

long double* MClass::calc_x(const long double x0) const {
        long double* x = new long double[N];
        x[0] = x0;

        for(int j=1; j<N; ++j)
                x[j] = extFunction(x[j-1], M);

        return x;
}
