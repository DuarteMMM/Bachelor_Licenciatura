#include "HelperFunctions.h"
#include "Debug.h"


int main() {
  /* Primeiro, experimentar com um incremento mais geral e obter os Initial Sets e obtêm-se vários valores dos parâmetros M para diferentes períodos; mas vai-se diminuindo o incremento à medida que se passa um período, se não saltava-se o outro -> "Inital Set:" no terminal;
Tendo esta lista, vê-se o primeiro e último em que b=2 (período 2, logo dois pontos fixos no final), em que b=4, etc., e faz-se método da biseção com cada par até se ter o limite (M MINIMO) em que b=2 e não b=1, no primeiro caso; em que b=4 depois do b=2, etc.
Com os M obtidos (mínimos para haver a transição), calculam-se os deltas de Feigenbaum 
*/
  
        const long double M_Min      = M_MIN;
        const long double M_Max      = M_MAX;
        const long double Mprecision = 1e-8;

        const long double x0         = X0;
        const int         N          = 1e+7;
        const long double xprecision = 1e-7;

        printf("%d\n", MClass(3.5698913, x0, N, xprecision).getb());
        printf("%d\n", MClass(3.5698914, x0, N, xprecision).getb());

        const std::vector<MClass> InitialMSet  = makeBissectionMDist(M_Min, M_Max, 256, x0, N, xprecision);

        printf(MAG "Initial set:\n" RESET);
        for(MClass i : InitialMSet ) {
                printf("\t");
                i.print();
        }

        const std::vector<std::array<long double, 2>> IMSTransitions = getTransitions(InitialMSet);

        std::vector<long double> Transitions;
        for(std::array<long double, 2> i : IMSTransitions)
                Transitions.push_back(makeBissection(i[0], i[1], Mprecision, x0, N, xprecision));

        std::vector<long double> Feigenbaum = getFeigenbaum(Transitions);

        printf(MAG "Transition Limits:\n" RESET);
        for(long unsigned int i=0; i<Transitions.size(); i++)
                printf("\t" CYN "ML = %Lf" RESET " | " CYN "MR = %Lf" RESET " | " CYN "M = %.10Lf\n", IMSTransitions[i][0], IMSTransitions[i][1], Transitions[i]);

        printf(MAG "Feigenbaum Constant:\n" RESET);
        for(long double i : Feigenbaum)
                printf("\t" CYN "Value = %.9Lf | Error = %12.9Lf\n" RESET, i, i-4.669201609);


        return 0;
}
