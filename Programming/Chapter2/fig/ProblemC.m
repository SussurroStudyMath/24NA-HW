data = readmatrix("ProblemC.txt");
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
xlim([-1,1]);
ylim([-1,2]);
xlabel("x");
ylabel("y");
title("Newton interpolation with Chebyshev polynomials");
legend('exact function','interpolation, n = 5','interpolation, n = 10', 'interpolation, n = 15', 'interpolation, n = 20');
saveas(fig, 'ProblemC.jpg');