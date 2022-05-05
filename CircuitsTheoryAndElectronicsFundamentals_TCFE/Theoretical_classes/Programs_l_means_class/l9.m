close all 
clear all

t=0:1e-6:3e-3;
f = 1000

i = cos(2*pi*f*t);
v = -sin(2*pi*f*t);


plot(1000*t, i)
hold on
plot(1000*t, v)
xlabel ("t[ms]")
ylabel ("i[mA], v[V]")

print ("i_v.eps", "-depsc");


figure
plot(1000*t, i.*i/2)
hold on
plot(1000*t, v.*v/2)
xlabel ("t[ms]")
ylabel ("E[W]")
print ("e.eps", "-depsc");


figure 
s1 = -30
s2 = -10
A1 = 10
A2 = -2
t=0:1e-6:1;


od = A1*exp(s1*t) + A2*exp(s2*t);
cd = (A1+A2*t).*exp(s2*t);
plot(t, zeros(1,length(t)))
hold on;
plot(t, od);
plot(t,cd);





