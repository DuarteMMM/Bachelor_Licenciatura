%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
This script was used to produce the plots in lecture 3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all 
close all

% time vector
t = 0: 1e-6: 20e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%RC series

V = 1
R = 1e3 
C = 1e-6

%voltage
v1 = (1-exp(-t./(R*C)))*V;

plot (t*1e3, v1)
hold 
plot (t*1e3, V-v1)

xlabel("t [ms]")
ylabel("v1 [V]")
legend("v1", "vR")

print ("sRCsol_v.eps", "-depsc");

%current
figure

iC = V/R*exp(-t./(R*C));
plot (t*1e3, iC*1e3)

xlabel("t [ms]")
ylabel("i [mA]")
legend("iC", "iR")

print ("sRCsol_i.eps", "-depsc");

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%RL parallel
%

I = 1e-3
R=1
L=1e-3

%current
iL = (1-exp(-t*R/L))*I;
iR = I-iL;

figure
plot (t*1e3, iL*1e3)
hold 
plot (t*1e3, iR*1e3)

xlabel("t [ms]")
ylabel("i [mA]")
legend("iL", "iR")

print ("pRLsol_i.eps", "-depsc");


%voltage
vL = R*I*exp(-t*R/L);

figure
plot (t*1e3, vL*1e3)

xlabel("t [ms]")
ylabel("v [mV]")

print ("pRLsol_v.eps", "-depsc");

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%RC parallel

I = 1e-3
R=1e3
C=1e-6

%current
iR = (1-exp(-t/R/C))*I;
iC = I-iR;

figure
plot (t*1e3, iR*1e3)
hold 
plot (t*1e3, iC*1e3)

xlabel("t [ms]")
ylabel("i [mA]")
legend("iR", "iC")

print ("pRCsol_i.eps", "-depsc");

%voltage
v1 = R*I*(1-exp(-t/R/C));


figure
plot (t*1e3, v1)

xlabel("t [ms]")
ylabel("v [V]")

print ("pRCsol_v.eps", "-depsc");



