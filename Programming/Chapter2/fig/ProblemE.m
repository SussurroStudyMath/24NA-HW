data = readmatrix("ProblemE.txt");
x = data(1,:);
figure('visible','off');
for i = 1:2
    y_interpolation = data(1+i,:);
    fig = plot(x,y_interpolation);
    hold on;
end
% xlim([-1,1]);
% ylim([-1,2]);
xlabel("Day");
ylabel("Average Weight");
% title("Newton interpolation with Chebyshev polynomials");
legend('Sp1','Sp2');
saveas(fig, 'ProblemE.jpg');