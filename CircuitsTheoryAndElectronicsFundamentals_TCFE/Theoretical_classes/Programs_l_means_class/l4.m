%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This script was used to produce the plots in lecture 4
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all 
close all

% time vector
t = 0: 1e-6: 10e-3;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%RC series

w = 1e3*2*pi
phi = pi/6
Vi = 1

vi = Vi * cos (w * t - phi);

plot (t*1e3, vi)

xlabel("t [ms]")
ylabel("vi [V]")
legend("vi")

print ("cos_v.eps", "-depsc");

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%RC Example
V=5
R1=1e3
R2=2e3
R3=3e3
C=1e-6

tn=-3e-3:1e-6:-1e-6;
tp=0:1e-6:20e-3;
t=[tn,tp];

N = length(t)
%3000 negative  points

%
%t < 0
%
vC(1:length(tn)+length(tp)) = V;
v1(1:length(tn)+length(tp)) = R2/(R1+R2)*V;

%
% t = infinite
%
R23p = 1/(1/R2+1/R3)
vC_inf = (1-R23p/(R1+R23p))*V


%
%t >= 0
%
vC_0 = 5

R = 1 / (1/R1+1/R2+1/R3)
tau = R*C;
vC(length(tn)+1:length(tn)+length(tp))= vC_inf+(vC_0-vC_inf)*exp(-tp/tau);


%compute v2 from vC
v2 = V-vC;
%the two nodes merge at t=0
v1(length(tn)+1:length(tn)+length(tp)) = v2(length(tn)+1:length(tn)+length(tp)) ;

figure
plot(t*1e3,v1)
xlabel("t[ms]")
ylabel("v1[V]")
print ("v1.eps", "-depsc");

figure 
plot(t*1e3,v2)
xlabel("t[ms]")
ylabel("v2[V]")
print ("v2.eps", "-depsc");

%
% frequency response
%

w=0:10000;

G = 1 ./ sqrt(1+w.^2*R^2*C^2);
P = atan(w*R*C);

figure 
plot(w/1e3, G)
xlabel("radian frequency [krad/s]")
ylabel("Gain")
print ("g.eps", "-depsc");

figure 
plot(w/1e3, P/pi)
xlabel("radian frequency [krad/s]")
ylabel("Relative phase (phi_s - phi_1)")
print ("p.eps", "-depsc");
