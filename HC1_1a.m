clear
clc
figure
data1 = importdata("data1.txt");
plot(data1(:, 1), data1(:, 2))
ylim([0, 1])
title("Transmission vs. Wavenumber")
ylabel("Transmission")
xlabel("k_0 (\mum^{-1})")