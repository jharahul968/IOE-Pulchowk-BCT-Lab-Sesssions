clc;
clear all;
close all;
n=8;
x=randi([0,1],1,n);   %random bit generator
bp=.000001;          % bit period
%disp(' Binary information at Trans mitter :');
disp(x);

N = length(x);
Tb = bp % 0.0001;   %Data rate = 1MHz i.e., bit period (second)

% ************* Represent input information as digital signal *************
nb = 100;   % Digital signal per bit
digit = []; 
for n = 1:1:N
    if x(n) == 1;
       sig = ones(1,nb);
    else x(n) == 0;
        sig = zeros(1,nb);
    end
     digit = [digit sig];
end
t1 = Tb/nb:Tb/nb:nb*N*(Tb/nb);   % Time period

%figure('Name','ASK Modulation','NumberTitle','off');
subplot(3,1,1);
plot(t1,digit,'LineWidth',2.5);
grid on;
axis([0 Tb*N -0.5 1.5]);
xlabel('Time(Sec)');
ylabel('Amplitude(Volts)');
title('Digital Input Signal');

% **************************** ASK Modulation *****************************
Ac1 = 12;     % Carrier amplitude for binary input '1'
Ac2 = 0;      % Carrier amplitude for binary input '0'
br = 1/Tb;    % Bit rate
Fc = br*10;   % Carrier frequency 
t2 = Tb/nb:Tb/nb:Tb;   % Signal time             
mod = [];
for (i = 1:1:N)
    if (x(i) == 1)
        y = Ac1*cos(2*pi*Fc*t2);   % Modulation signal with carrier signal 1
    else
        y = Ac2*cos(2*pi*Fc*t2);   % Modulation signal with carrier signal 2
    end
    mod = [mod y];
end
t3 = Tb/nb:Tb/nb:Tb*N;   % Time period
subplot(3,1,2);
plot(t3,mod);
xlabel('Time(Sec)');
ylabel('Amplitude(Volts)');
title('ASK Modulated Signal');
% ********************* Transmitted signal x ******************************
