import numpy as np
from numpy import *
import math
import matplotlib.pyplot as plt

#Valores teóricos

N_teo_A1B1=1
N_teo_A2B1=1
N_teo_A3B1=1
N_teo_A1B2=2
N_teo_A2B2=3
N_teo_A3B2=4
N_teo_A1B3=3
N_teo_A2B3=4
N_teo_A3B3=5


v_teo_A1=0.85
Erro_v_teo_A1=0.01
v_teo_A2=0.91
Erro_v_teo_A2=0.01
v_teo_A3=0.97
Erro_v_teo_A3=0.01

N_teo_h1=[N_teo_A1B1, N_teo_A2B1, N_teo_A3B1, N_teo_A1B2, N_teo_A2B2, N_teo_A3B2, N_teo_A1B3, N_teo_A2B3, N_teo_A3B3]
v_teo_h1=[v_teo_A1, v_teo_A2, v_teo_A3, v_teo_A1, v_teo_A2, v_teo_A3, v_teo_A1, v_teo_A2, v_teo_A3]
Erro_v_teo_h1=[Erro_v_teo_A1, Erro_v_teo_A2, Erro_v_teo_A3, Erro_v_teo_A1, Erro_v_teo_A2, Erro_v_teo_A3, Erro_v_teo_A1, Erro_v_teo_A2, Erro_v_teo_A3]


#Valores visuais+cronómetro

N_vis_A1B1=1
N_vis_A2B1=2
N_vis_A3B1=1
N_vis_A1B2=4
N_vis_A2B2=6
N_vis_A3B2=7
N_vis_A1B3=6
N_vis_A2B3=4
N_vis_A3B3=4


v_crono_A1B1=0.7
Erro_v_crono_A1B1=0.1
v_crono_A2B1=0.9
Erro_v_crono_A2B1=0.2
v_crono_A3B1=0.9
Erro_v_crono_A3B1=0.2
v_crono_A1B2=0.9
Erro_v_crono_A1B2=0.2
v_crono_A2B2=1.1
Erro_v_crono_A2B2=0.2
v_crono_A3B2=0.9
Erro_v_crono_A3B2=0.2
v_crono_A1B3=0.8
Erro_v_crono_A1B3=0.1
v_crono_A2B3=0.9
Erro_v_crono_A2B3=0.2
v_crono_A3B3=1.1
Erro_v_crono_A3B3=0.2

N_vis_h1=[N_vis_A1B1, N_vis_A2B1, N_vis_A3B1, N_vis_A1B2, N_vis_A2B2, N_vis_A3B2, N_vis_A1B3, N_vis_A2B3, N_vis_A3B3]
v_crono_h1=[v_crono_A1B1, v_crono_A2B1, v_crono_A3B1, v_crono_A1B2, v_crono_A2B2, v_crono_A3B2, v_crono_A1B3, v_crono_A2B3, v_crono_A3B3]
Erro_v_crono_h1=[Erro_v_crono_A1B1, Erro_v_crono_A2B1, Erro_v_crono_A3B1, Erro_v_crono_A1B2, Erro_v_crono_A2B2, Erro_v_crono_A3B2, Erro_v_crono_A1B3, Erro_v_crono_A2B3, Erro_v_crono_A3B3]


#Valores software

#Ainda não temos a partir daqui
N_soft_A1B1=1
N_soft_A2B1=2
N_soft_A3B1=1
N_soft_A1B2=4
N_soft_A2B2=6
N_soft_A3B2=7
N_soft_A1B3=6
N_soft_A2B3=4
N_soft_A3B3=4

#Ainda não temos a partir daqui
v_soft_A1B1=0.7
Erro_v_soft_A1B1=0.1
v_soft_A2B1=0.9
Erro_v_soft_A2B1=0.2
v_soft_A3B1=0.9
Erro_v_soft_A3B1=0.2
v_soft_A1B2=0.9
Erro_v_soft_A1B2=0.2
v_soft_A2B2=1.1
Erro_v_soft_A2B2=0.2
v_soft_A3B2=0.9
Erro_v_soft_A3B2=0.2
v_soft_A1B3=0.8
Erro_v_soft_A1B3=0.1
v_soft_A2B3=0.9
Erro_v_soft_A2B3=0.2
v_soft_A3B3=1.1
Erro_v_soft_A3B3=0.2

plt.plot(N_teo_A1B1, v_teo_A1, c='b', marker='o', markersize=8)
plt.plot(N_vis_A1B1, v_crono_A1B1, c='b', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A1B1, v_soft_A1B1, c='b', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A2B1, v_teo_A2, c='r', marker='o', markersize=8)
plt.plot(N_vis_A2B1, v_crono_A2B1, c='r', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A2B1, v_soft_A2B1, c='r', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A3B1, v_teo_A3, c='g', marker='o', markersize=8)
plt.plot(N_vis_A3B1, v_crono_A3B1, c='g', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A3B1, v_soft_A3B1, c='g', marker='+', markersize=15, mew=2)

plt.plot(N_teo_A1B2, v_teo_A1, c='c', marker='o', markersize=8)
plt.plot(N_vis_A1B2, v_crono_A1B2, c='c', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A1B2, v_soft_A1B2, c='c', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A2B2, v_teo_A2, c='m', marker='o', markersize=8)
plt.plot(N_vis_A2B2, v_crono_A2B2, c='m', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A2B2, v_soft_A2B2, c='m', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A3B2, v_teo_A3, c='y', marker='o', markersize=8)
plt.plot(N_vis_A3B2, v_crono_A3B2, c='y', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A3B2, v_soft_A3B2, c='y', marker='+', markersize=15, mew=2)

plt.plot(N_teo_A1B3, v_teo_A1, c='dimgray', marker='o', markersize=8)
plt.plot(N_vis_A1B3, v_crono_A1B3, c='dimgray', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A1B3, v_soft_A1B3, c='dimgray', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A2B3, v_teo_A2, c='orange', marker='o', markersize=8)
plt.plot(N_vis_A2B3, v_crono_A2B3, c='orange', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A2B3, v_soft_A2B3, c='orange', marker='+', markersize=15, mew=2)
plt.plot(N_teo_A3B3, v_teo_A3, c='deeppink', marker='o', markersize=8)
plt.plot(N_vis_A3B3, v_crono_A3B3, c='deeppink', marker='x', markersize=15, mew=2)
plt.plot(N_soft_A3B3, v_soft_A3B3, c='deeppink', marker='+', markersize=15, mew=2)

label_teo_x=-1
label_teo_y=-1
plt.scatter(label_teo_x, label_teo_y, c='k', marker='o', label='Teóricos')
plt.scatter(label_teo_x, label_teo_y, c='k', marker='x', label='Visual + Cronómetro')
plt.scatter(label_teo_x, label_teo_y, c='k', marker='+', label=r'$\it{Software}$')
plt.scatter(label_teo_x, label_teo_y, c='b', marker='s', label='A=2cm, B=10cm (U=2)')
plt.scatter(label_teo_x, label_teo_y, c='r', marker='s', label='A=4cm, B=10cm (U=3)')
plt.scatter(label_teo_x, label_teo_y, c='g', marker='s', label='A=6cm, B=10cm (U=5)')
plt.scatter(label_teo_x, label_teo_y, c='c', marker='s', label='A=2cm, B=40cm (U=26)')
plt.scatter(label_teo_x, label_teo_y, c='m', marker='s', label='A=4cm, B=40cm (U=52)')
plt.scatter(label_teo_x, label_teo_y, c='y', marker='s', label='A=6cm, B=40cm (U=78)')
plt.scatter(label_teo_x, label_teo_y, c='dimgray', marker='s', label='A=2cm, B=50cm (U=41)')
plt.scatter(label_teo_x, label_teo_y, c='orange', marker='s', label='A=4cm, B=50cm (U=81)')
plt.scatter(label_teo_x, label_teo_y, c='deeppink', marker='s', label='A=6cm, B=50cm (U=122)')
plt.xlim(0, 10)
plt.ylim(0.5, 1.2)

plt.xlabel(r'$N$', fontsize=13, loc='right')
plt.ylabel(r'$v\;(m/s)$', fontsize=13, rotation='horizontal', loc='top')
plt.xticks(np.arange(0, 10, 2))
plt.yticks(np.arange(0.5, 1.2, 0.05))
plt.title(r'$h=6\;cm$', fontsize=20)
plt.legend(loc='best', shadow=False, fontsize='large')
plt.grid()
plt.show()