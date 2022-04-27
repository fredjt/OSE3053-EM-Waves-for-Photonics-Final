clear
clc
figure
data3 = importdata("data3.txt");
plot(data3(:, 1), data3(:, 2))
xline(0)
xline(100.000000)
title("Electric Field Amplitude at t=0")
ylabel("E (V/m)")
xlabel("z (nm)")