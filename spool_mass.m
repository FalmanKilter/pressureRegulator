function m_s = spool_mass(a)
% calculate spool mass given that the spool has three sections: two big
% cylinders diameter D_s = 3*a and height a, and between them a neck height
% a and diameter 1.5*a. The spool is made of steel with density rho =
% 7.8e3 kg/m3
%%
% calculate spool volume
V_s = 2*a*(pi*(3*a)^2)/4 + a*(pi*(1.5*a)^2)/4;

% calculate spool mass
rho = 7.8e3;
m_s = V_s*rho;
end
