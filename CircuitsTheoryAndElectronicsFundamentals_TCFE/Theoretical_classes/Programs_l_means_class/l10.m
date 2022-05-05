% RLC with input current source

close all 
clear all

R=10
C=1e-6
L=1e-3
R_L=2

f=0:10:1e6;
w=2*pi*f;

Z_L = j*w*L;
Z_C = 1./(j*w*C);

Z_LCp = 1./(1./Z_L + 1./Z_C);
Z_LClp = 1./(1./Z_L + 1./Z_C + 1/R_L);

Z_RCp = 1 ./ (1/R + 1./Z_C);
Z_RLp = 1 ./ (1/R + 1./Z_L);



%I_S: R + C||L
T = Z_LCp;

plot(log10(f), 20*log10(abs(T)))
title("Input current, L||C")
xlabel ("log10 f[Hz]")
ylabel ("Vo[V] dB")
print ("ISRsLCp_M.eps", "-depsc");

figure
plot(log10(f), angle(T)*180/pi)
title("Input current, L||C")
xlabel ("log10 f[Hz]")
ylabel ("Phase (degrees")
print ("ISRsLCp_P.eps", "-depsc");


%I_S: R + C||L||l
T = Z_LClp;

figure
plot(log10(f), 20*log10(abs(T)))
title("Input current, L||C||R_L")
xlabel ("log10 f[Hz]")
ylabel ("Vo[V] dB")
print ("ISRsLClp_M.eps", "-depsc");

figure
plot(log10(f), angle(T)*180/pi)
title("Input current, L||C||R_L")
xlabel ("log10 f[Hz]")
ylabel ("Phase (degrees")
print ("ISRsLClp_P.eps", "-depsc");


%V_S: R + C||L
T = Z_LCp ./ (R + Z_LCp);

figure
plot(log10(f), 20*log10(abs(T)))
title("Input voltage, R+L||C")
xlabel ("log10 f[Hz]")
ylabel ("Vo[V] dB")
print ("VSRsLCp_M.eps", "-depsc");

figure
plot(log10(f), angle(T)*180/pi)
title("Input voltage, R+L||C")
xlabel ("log10 f[Hz]")
ylabel ("Phase (degrees")
print ("VSRsLCp_P.eps", "-depsc");

%V_S: L + R||C
T = Z_RCp./(Z_L+Z_RCp);

figure
plot(log10(f), 20*log10(abs(T)))
title("Input voltage, L+R||C")
xlabel ("log10 f[Hz]")
ylabel ("Vo[V] dB")
print ("VSLsRCp_M.eps", "-depsc");

figure
plot(log10(f), angle(T)*180/pi)
title("Input voltage, L+R||C")
xlabel ("log10 f[Hz]")
ylabel ("Phase (degrees")
print ("VSLsRCp_P.eps", "-depsc");


%V_S: C + R||L
T = Z_RLp./(Z_C+Z_RLp);

figure
plot(log10(f), 20*log10(abs(T)))
title("Input voltage, C+R||L")
xlabel ("log10 f[Hz]")
ylabel ("Vo[V] dB")
print ("VSCsRLp_M.eps", "-depsc");

figure
plot(log10(f), angle(T)*180/pi)
title("Input voltage, L+R||C")
xlabel ("log10 f[Hz]")
ylabel ("Phase (degrees")
print ("VSCsRLp_P.eps", "-depsc");
