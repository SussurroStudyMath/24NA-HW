x = -2:0.05:3;
y = zeros(size(x,2),1);
for i = 1:size(x,2)
    y(i) = Bi(x(i));
end
figure('visible','off');
fig = plot(x,y);
xlabel("x");
ylabel("B_i^2(x)");
saveas(fig, 'ProblemV-e.jpg');

function y = Bi(x)
    if x > -1 && x <= 0
        y = (x + 1)^2/2;
    elseif x > 0 && x <= 1
        y = (x+1)*(1-x)/2 + x*(2-x)/2;
    elseif x > 1 && x <= 2
        y = (2-x)^2/2;
    else
        y = 0;
    end
end