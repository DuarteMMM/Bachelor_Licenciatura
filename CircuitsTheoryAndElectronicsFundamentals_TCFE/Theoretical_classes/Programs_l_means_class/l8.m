clear all 
close all

w=0:100:1e6-1; %s


%%%%%RC
R = 1e3
C=10e-9

T = 1 ./(1 + j*w*R*C);

plot (w, abs(T));
xlabel ("w[rad/s]");
ylabel ("Amplitude");
print ("rc_abs_T.png", "-dpng");

figure
plot (w, 180/pi*angle(T));
xlabel ("w[rad/s]");
ylabel ("Phase (degrees)");
print ("rc_phase_T.png", "-dpng");



%%%%%%%RL
L=10e-3

T = j*w*L ./(R + j*w*L);

figure
plot (w, abs(T));
xlabel ("w[rad/s]");
ylabel ("Amplitude");
print ("rl_abs_T.png", "-dpng");

figure
plot (w, 180/pi*angle(T));
xlabel ("w[rad/s]");
ylabel ("Phase (degrees)");
print ("rl_phase_T.png", "-dpng");


%%%%% now in dBs

w=0:100:1e7-1; %s
T = j*w*L ./(R + j*w*L);

figure
plot (log10(w/2/pi), 20*log10(abs(T)));
xlabel ("log10(w) [rad/s]");
ylabel ("|T| dB");
print ("rl_abs_Tlog.png", "-dpng");

figure
plot (log10(w/2/pi), 180/pi*angle(T));
xlabel ("log10(w) [rad/s]");
ylabel ("Phase (degrees)");
print ("rl_phase_Tlog.png", "-dpng");


%%%%%%Octave Bode plots
numer = [L, 0]
denom=[L, R]
sys = tf(numer,denom);
w = logspace(1, 6, 200); % 200 pt w vector from 1krad/s (10^3) to 1Mrad/s (10^6)
figure
bode(sys, w);
print ("rl_bode.png", "-dpng");

