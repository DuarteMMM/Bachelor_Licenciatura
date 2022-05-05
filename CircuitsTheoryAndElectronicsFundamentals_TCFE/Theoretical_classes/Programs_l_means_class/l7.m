
close all
clear all

pkg load symbolic

syms w

syms I
syms phi_i
syms i(t)

syms V
syms phi_v
syms v(t)

i(t) = I*cos(w*t-phi_i)
v(t) = V*cos(w*t-phi_v)

syms P(t) 

P(t) = v(t)*i(t)

%time axis: 0 to 10ms with 1us steps
t=0:1e-6:2e-3; %s
f = 1000
w=2*pi*f

V=1
phi_vn = 60 * pi/180


I=2
phi_in = 30 * pi/180

v = V*cos(w*t-phi_vn);
i = I*cos(w*t-phi_in);
P = v.*i;

plot (t*1000, v, "g");
hold on;
plot (t*1000, i, "b");
hold on;
plot (t*1000, P, "r");

xlabel ("t[ms]");
ylabel ("v(t) [V], i(t)[A],  P[W]");
legend("v(t)", "i(t)", "P(t)")
print ("p_active.png", "-dpng");

%%%%%%% maximum power transfer

Vs = 5
Rs = 10
R = 0:.1:100;

PR = (R./(Rs.+R).^2)*Vs^2;

figure
plot (R, PR, "g");

xlabel ("R[Ohms]");
ylabel ("PR[W]");
print ("max_power_transf.png", "-dpng");


%%%%%%%%% power factor as function of C
w = 2*pi*50
L = 100e-3
R = 10
C=0:1e-6:0.5e-3;

Z = 1./(1/(R + j*w*L) + j*w*C);

figure
plot(C*1e6, angle(Z) * 180/pi)
xlabel ("C[uF]");
ylabel ("Phi[ª]");
print ("phi.png", "-dpng");

figure
plot(C*1e6, cos(angle(Z)) )
xlabel ("C[uF]");
ylabel ("PF");
print ("pf.png", "-dpng");


%%%%%%%%% power transfer as a function of C
V = Z./(Rs+Z)*Vs;
I = Vs./(Rs+Z);

VR = R/(R+j*w*L)*V;
IR = (1/(R+j*w*L))./(j*w.*C+1/(R+j*w*L)).*I;
Pr = real(1/2*VR.*conj(IR));

%Below is as presented in class. The small difference between apparent power and active power on R due ro Rs
%Pa = Vs*abs(I)/2;

%Below is after correction: after compensation apparent power matches consumed power on R exactly after compensation.
Pa = abs(V).*abs(I)/2;

hold
plot(C*1e6, Pr, 'r' )
plot(C*1e6, Pa, 'g' )


xlabel ("C[uF]");
ylabel ("PF, PR, Pa");
legend("PF", "PR", "Pa")
print ("pow.png", "-dpng");

%%%%%%%%%%%%%%%%%Z locus

figure 
plot(real(Z), imag(Z))
xlabel ("Re{Z}");
ylabel ("Im{Z}");
title("Z as a function of C: inductive-->resistive-->capacitive-->0")







