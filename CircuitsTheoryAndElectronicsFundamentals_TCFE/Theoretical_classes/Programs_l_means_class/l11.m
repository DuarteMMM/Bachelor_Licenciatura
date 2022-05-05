close all 
clear all

I_S = 1e-9
V_T=25e-3

v = linspace(-1, 1, 30);
i = I_S*(exp(v/V_T/2) - 1);

plot(v, i)
title("Diode Current-Voltage Characteristic")
xlabel ("v[V]")
ylabel ("i[A]")
print ("iv.eps", "-depsc");

figure
v = linspace(-1, .1, 30);
i = I_S*(exp(v/V_T/2) - 1);

plot(v, i)
title("Diode Current-Voltage Characteristic (detail for v<0)")
xlabel ("v[V]")
ylabel ("i[A]")
print ("iv_detail.eps", "-depsc");


function f = f(vD,vS,R)
Is = 1e-9;
VT=25e-3;
f = vD+R*Is * (exp(vD/VT/2)-1) - vS;
endfunction

function fd = fd(vD,R)
Is = 1e-9;
VT=25e-3;
fd = 1 + R*Is/2/VT * (exp(vD/VT/2)-1);
endfunction

function vD_root = solve_vD (vS, R)
  delta = 1e-6;
  x_next = 0.65;

  do 
    x=x_next;
    x_next = x  - f(x, vS, R)/fd(x, R);
  until (abs(x_next-x) < delta)

  vD_root = x_next;
endfunction


R=1000;
f=1000;
w=2*pi*f;
t=0:1e-6: 5e-3;
vS=2*cos(w*t);
vO = zeros(1,length(t));

for i=1:length(t)
  vD = solve_vD  (vS(i), R);
  vO(i) = vS(i)-vD;
endfor



figure

plot(t*1000, vO)
title("Output voltage v_o(t)")
xlabel ("t[ms]")
ylabel ("v_o[V]")
print ("vo.eps", "-depsc");









