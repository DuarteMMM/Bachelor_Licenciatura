pkg load symbolic

%NMOS inverter
kn= vpa(111e-6)
vtn= vpa(1.4)
vdd= vpa(5) 
R=vpa(50e3)

syms vo

solve ((vdd-vo)/R == kn*vo^2, vo)

vi = ans + vtn

clear all

syms kn vi_vtn vdd R vo

solve ( kn*(2*(vi_vtn)*vo - vo^2) == (vdd-vo)/R, vo) 

%CMOS inverter
clear all
syms kn vtn kp vtp vi vo vdd vi_vtn vi_vtp
solve (kn*(vi-vtn)^2 == kp*(2*(vdd-vi - vtp)*(vdd-vo) - (vdd-vo)^2), vo)
solve (kn*(vi_vtn)^2 == kp*(2*(vdd-vi_vtp)*(vdd-vo) - (vdd-vo)^2), vo)

clear all
kn= vpa(111e-6)
kp= vpa(55e-6)
vtn= vpa(1.4)
vtp= vpa(1.2)
vdd= vpa(5) 
syms vi
solve (kn*(vi-vtn)^2 == kp*(vdd-vi-vtp)^2,vi)

clear all
kn= vpa(111e-6)
kp= vpa(55e-6)
vtn= vpa(1.4)
vtp= vpa(1.2)
vdd= vpa(5) 
syms vi vo

solve (kn*(vi-vtn)^2 == kp*(vdd-vi-vtp)^2,vi)
vi = ans(2)
solve (kn*(2*(vi - vtn)*vo - vo^2) == kp*(vdd-vi-vtp)^2,vo)

clear all
kn= vpa(111e-6)
kp= vpa(55e-6)
vtn= vpa(1.4)
vtp= vpa(1.2)
vdd= vpa(5) 
syms vi vo

solve (kn*(vi-vtn)^2 == kp*(vdd-vi-vtp)^2,vi)
vi = ans(2)
solve (kp*(2*(vdd-vi - vtp)*(vdd-vo) - (vdd-vo)^2) == kn*(vi-vtn)^2,vo)


