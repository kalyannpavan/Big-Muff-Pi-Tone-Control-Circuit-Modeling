% BigMuff Tone Stage

clear; clc; close all;

% sampling frequency and time
Fs = 48000;
Ts = 1/Fs;

% Components
C9 = 4e-9;          % 4nF Capacitor
CR9 = Ts/(2*C9);    %Capacitor Resistance
CX9 = 0;            %Capacitor State

C8 = 10e-9;         % 10nF Capacitor
CR8 = Ts/(2*C8);    %Capacitor Resistance
CX8 = 0;            %Capacitor State

R8 = 39e3;            % Resistor (39kOhms)
R5 = 22e3;            % Resistor (22kOhms)

Tone = 100e3;      % 100K resistor
ToneAlpha = .5;     % position of the pot
ToneA = (1-ToneAlpha) * Tone;
ToneB = ToneAlpha * Tone;

%Filter Coefficients
a = ((1/CR8) + (1/ToneB) + (1/R8));
b = ((1/R5) + (1/ToneA) + (1/CR9));

% initialize input and output
Vin = [1; zeros(2047,1)];
N = length(Vin);
Vout = zeros(N,1);

for n = 1:N
  %use Va and Vb for State Update equations
  Va = ((Vin(n)/R8) + (Vout(n)/ToneB) + CX8) / a;
  Vb = (((Vout(n)/ToneA) - CX9) + (Vin(n)/CR9)) / b;

  Vout(n) = ((ToneA / a) * (Vin(n) / R8 + CX8) + (ToneB / b) * (-CX9 + Vin(n) / CR9)) / (ToneA + ToneB - (ToneA / (a * ToneB)) - (ToneB / (b * ToneA)));


  %capacitor state update
  CX8 = (2/CR8) * Va - CX8;
  CX9 = (2/CR9) * (Vin(n) - Vb) - CX9;



end

% Perform FFT
Vout_fft = fft(Vout);

% Compute the magnitude of the frequency response
Vout_magnitude = abs(Vout_fft(1:N/2+1)); % Only keep the positive frequencies

% Compute the frequency axis
frequencies = (0:N/2) * (Fs / N);

% Plot the magnitude of the frequency response on a logarithmic scale
figure;
semilogx(frequencies, 20*log10(Vout_magnitude));
title('Frequency Response of Filter');
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
grid on;

% Customize x-axis ticks for better readability
xticks = [20, 50, 100, 200, 500, 1e3, 2e3, 5e3, 10e3, 20e3];
set(gca, 'XTick', xticks);
set(gca, 'XTickLabel', {'20', '50', '100', '200', '500', '1k', '2k', '5k', '10k', '20k'});

% Set y-axis limits
ylim([-30 30]);

grid on;
