x = 0:0.01:1;
y = zeros(size(x,2),1);
for i = 1:size(x,2)
    y(i) = f(x(i));
end
z = zeros(size(x,2),1);
for i = 1:size(x,2)
    z(i) = exp(x(i))/x(i);
end
figure('visible','off');
fig = plot(x,y);
xlabel("x");
ylabel("cond_f(x)");
saveas(fig, 'ProblemIX-c1.jpg');
fig = plot(x,z);
xlabel("x");
ylabel("estimated upper bound of cond_A(x)");
saveas(fig, 'ProblemIX-c2.jpg');


function y = f(x)
    if x == 0
        y = 1;
    else
        y = x/(exp(x)-1);
    end
end