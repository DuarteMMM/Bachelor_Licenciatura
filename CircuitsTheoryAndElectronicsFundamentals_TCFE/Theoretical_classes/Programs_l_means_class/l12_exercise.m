close all 
clear all

%%solve circuit with accurate model

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

function v_out = tr(t, vS, R)
 v_out = zeros(1,length(t));
 for i=1:length(t)
    vD = solve_vD  (vS(i), R);
    v_out(i) = vS(i)-vD;
  endfor
endfunction 

%plot exact solution for 3 values of A

R=1000;
f=1000;
w=2*pi*f;
t=linspace(0, 5e-3, 1000);
vO = zeros(1,length(t));
figure
title("Output voltage vo(t) for various input amplitudes")
xlabel ("t[ms]")
ylabel ("v_[V]")
hold
VS = 2;

A=20e-3;
vS=VS+A*cos(w*t);
vO = tr(t, vS, R);
plot(t*1000, vO)

A=200e-3;
vS=VS+A*cos(w*t);
vO = tr(t, vS, R);
plot(t*1000, vO, 'g')
vO_200 = vO;

A=1.5;
vS=VS+A*cos(w*t);
vO = tr(t, vS, R);
plot(t*1000, vO, 'r')
vO_1500 = vO;

legend("Vs=20mV", "Vs=200mV", "Vs=1.5V");
print ("vo_amps.eps", "-depsc");


%plot incremental solution for 3 values of A
VD = solve_vD(2, R);
VT = 25e-3;
Is = 1e-9;
r_d = 2*VT/Is/exp(VD/2/VT);
figure
title("Output voltage vo(t) for various input amplitudes")
xlabel ("t[ms]")
ylabel ("v_[V]")
hold

VO=VS-VD;


A=20e-3;
vs=A*cos(w*t);
vo = R/(R+r_d) * vs;
vO = VO+vo;
plot(t*1000, vO, 'g')

A=200e-3;
vs=A*cos(w*t);
vo = R/(R+r_d) * vs;
vO = VO+vo;
plot(t*1000, vO, 'b')
vO_incr200 = vO;

A=1.5;
vs=A*cos(w*t);
vo = R/(R+r_d) * vs;
vO = VO+vo;
plot(t*1000, vO, 'r')
vO_incr1500 = vO;

legend("Vs=20mV", "Vs=200mV", "Vs=1.5V");
print ("vo_amps_incr.eps", "-depsc");

%comparison
figure
plot(t*1000, vO_1500, 'b')
hold 
plot(t*1000, vO_incr1500, 'r')
legend("Exact solution", "Incremental solution");
title("Compare exact vs. incremental vs=1.5V");
print ("vo_comp1500.eps", "-depsc");

figure
plot(t*1000, vO_200, 'b')
hold 
plot(t*1000, vO_incr200, 'r')
legend("Exact solution", "Incremental solution");
title("Compare exact vs. incremental vs=200mV");
print ("vo_comp200.eps", "-depsc");

