clc;
close all;
clear all;

% Signal generation
x=0:0.3:4*pi;                             % siganal taken upto 4pi
sig1=8*sin(x);                           % generate 1st sinusoidal signal
l=length(sig1);
sig2=8*triang(l);                        % Generate 2nd traingular Sigal

% Display of Both Signal
subplot(2,2,1);  
plot(sig1);
grid on

subplot(2,2,2);
plot(sig2);
grid on

% Display of Both Sampled Signal
subplot(2,2,3);
stem(sig1);

subplot(2,2,4);
stem(sig2);

l1=length(sig1);
l2=length(sig2);
 for i=1:l1
  sig(1,i)=sig1(i); % Making Both row vector to a matrix
  sig(2,i)=sig2(i);
 end  

% TDM of both quantize signal
tdmsig=reshape(sig,1,2*l1);               
% Display of TDM Signal
figure
stem(tdmsig);

% Demultiplexing of TDM Signal
 demux=reshape(tdmsig,2,l1);
 for i=1:l1
  sig3(i)=demux(1,i);                    % Converting The matrix into row vectors
  sig4(i)=demux(2,i);
 end  
 
 % display of demultiplexed signal
 figure
 subplot(2,1,1)
 plot(sig3);
 
 subplot(2,1,2)
 plot(sig4);
 