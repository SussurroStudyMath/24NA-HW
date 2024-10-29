data = readmatrix("ProblemF.txt");
figure('visible','off');
for i = 0:2
    x_col = 2*i + 1;
    y_col = 2*i + 2;
    x = data(:,x_col);
    y = data(:,y_col);
    fig = plot(x,y);
    hold on;
end
legend('m = 10','m = 40', 'm = 160');
xlabel("x");
ylabel("y");
saveas(fig, 'ProblemF.jpg');