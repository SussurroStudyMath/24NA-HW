data = readmatrix("ProblemB.txt");
x = data(1,:);
y = data(2,:);
figure('visible','off');
fig = plot(x,y);
hold on;
for i = 1:4
    y_interpolation = data(2+i,:);
    plot(x,y_interpolation);
    hold on;
end
xlim([-5,5]);
ylim([-2.5,2.5]);
xlabel("x");
ylabel("y");
title("Newton interpolation with equal x steps");
legend('exact function','interpolation, n = 2','interpolation, n = 4', 'interpolation, n = 6', 'interpolation, n = 8');
saveas(fig, 'ProblemB.jpg');