x = 0:360;
l = 89;
h = 49;
D = 55;
beta1 = 11.5*2*pi/360;
y = f(x*2*pi/360, l, h, D, beta1);
figure('visible','off');
fig = plot(x,y);
xlabel('\alpha');
ylabel('f(\alpha)');
saveas(fig, 'ProblemF.jpg');




function y = f(alpha, l, h, D, beta1)
    A = l*sin(beta1);
    B = l*cos(beta1);
    C = (h + 0.5*D)*sin(beta1) - 0.5*D*tan(beta1);
    E = (h + 0.5*D)*cos(beta1) - 0.5*D;
    y = A.*sin(alpha).*cos(alpha) + B.*sin(alpha).*sin(alpha) - C.*cos(alpha) - E.*sin(alpha);
end