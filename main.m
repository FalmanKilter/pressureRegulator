clc
clear
close all
%%
% the pressure regulator must keep reduced pressure P_red around 10 MPa
%
% parameter initialization for the pressure regulator:
%   m_s - spool mass[kg]
%   k - spring stiffness [N/m]
%   D_s - spool diameter [m]
%   D_p - pipe diameter [m]
%   a - orifice 1 side length [m]

% for static calculation of reduced pressure:
%   P_in - inlet pressure [Pa] (variable)
%   P_out - outlet pressure [Pa] (constant)

%%

a = 1e-2;
D_s = 3*a;                              % spool diameter

F_init = 1e6*(pi*D_s^2)/4;              % initial force on the spool

k = 5*F_init/a;                         % spring stiffness

m_s = spool_mass(a);                    % spool mass

D_p = 4e-3;                             % pipe diameter (GOST - 11881 - 76)
D_w = sqrt(4*a^2/pi);                   % equivalent diameter of the window

A_o1 = 0;                               % valve open
A_o2 = pi*1e-3^2/4;                     % outlet orifice area  (constant diameter 1 mm)

beta_o1 = sqrt(4*A_o1/pi)/D_w;          % valve to pipe diameter ratio
beta_o2 = 1e-3/D_p;                     % outlet throttle to pipe diameter ratio

gamma_1 = A_o1*(1-beta_o2^4);
gamma_2 = A_o2*(1-beta_o1^4);

%% static calculation
P_in = 0.1e6;                           % inlet pressure
P_out = 0.1e6;                          % ambient pressure

P_red = (gamma_1*P_in + gamma_2*P_out)/(gamma_1 + gamma_2);

%% dynamic calculation
t_sim = [0 20];                        % simulation start and stop time

i_c = [0 0];                           % initial conditions for x(1) and x(2)

param_set = [A_o2, beta_o2, P_out, D_s, ...
    a, D_p, F_init, k, m_s, D_w];      % parameters vector for ode

[t, y] = ode45(@(t, x) eom(t, x, param_set), t_sim, i_c);

%%
% given y - state vector of the spool, calculate evolution of P_red

P_red = reduced_pressure(t, y, param_set);

P_in = 0.9e5*t + 1e5;                   % ramp input 0.1 MPa .. 1 MPa in 10 s

P_des = 0*t + 1e6;                      % desired reduced pressure value 1 Mpa

%% plot system dynamics simulation results
figure
subplot(2,1,1)
% plot spool position dynamics
plot(t,y(:,1),'k-','LineWidth',2);
legend('spool position','Location','best')
set(gca,'Fontsize',14)
subplot(2,1,2)
% plot pressure values evolution for P_red and P_in
plot(t,P_in,'k--','LineWidth',2)
hold on
plot(t,P_red,'r-','LineWidth',2)
plot(t,P_des,'LineWidth',2,'Color','#a8a8a8')
legend('inlet pressure','reduced pressure','desired reduced pressure','Location','best');
set(gca,'Fontsize',14);

