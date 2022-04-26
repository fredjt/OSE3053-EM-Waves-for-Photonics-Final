clear
clc
figure
data2 = importdata("data2.txt");
plot(data2(:, 1), data2(:, 2))
xline(0)
xline(100.000000)
title("Electric Field Amplitude at t=0")
ylabel("E (V/m)")
xlabel("z (nm)")