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
D_s = 3*a;                      % spool diameter

F_init = 1e6*(pi*D_s^2)/4;      % initial force on the spool 

k = 5*F_init/a;                   % spring stiffness

m_s = spool_mass(a);            % spool mass

D_p = 4e-3;                     % pipe diameter (GOST - 11881 - 76)

A_o1 = 0;                     % valve open
A_o2 = pi*1e-3^2/4;             % outlet orifice area  (constant diameter 1 mm)

beta_o1 = sqrt(4*A_o1/pi)/D_p;  % valve to pipe diameter ratio
beta_o2 = 1e-3/D_p;             % outlet throttle to pipe diameter ratio

gamma_1 = A_o1*(1-beta_o2^4);
gamma_2 = A_o2*(1-beta_o1^4);

%% static calculation
P_in = 0.1e6;                     % inlet pressure
P_out = 0.1e6;                  % ambient pressure

P_red = (gamma_1*P_in + gamma_2*P_out)/(gamma_1 + gamma_2);

%% dynamic calculation
t_sim = [0 100];                 % simulation start and stop time

i_c = [0 0];                    % initial conditions for x(1) and x(2)

param_set = [A_o2, beta_o2, P_out, D_s, ...
                a, D_p, F_init, k, m_s];    % parameters vector for ode

[t, y] = ode45(@(t, x) eom(t, x, param_set), t_sim, i_c);


function dx = eom(t, x, param_set)
% equations of motion of the spool: the motion is defined by the spring
% stiffness K, the force of the fluid F_r in the reduced pressure volume,
% and the position of the spool, as when it moves it opens or closes the
% valve.
% If P_in is such that F_red is less than initial sping deformation force
% F_in that presses the spool against the shoulder, the force F_init is
% couteracted by the reaction force of the shoulder which is exactly F_init
% as the shoulder position of the spool is zero.
%%
% get parameters from param_set
A_o2 = param_set(1);
beta_o2 = param_set(2);
P_out = param_set(3);
D_s = param_set(4);
a = param_set(5);
D_p = param_set(6);
F_init = param_set(7);
k = param_set(8);
m_s = param_set(9);

% calculate current value of P_in as a function of time
%P_in = 0.1e6;                   % constant, ambient
%P_in = 0.15e6;                   % constant, 1.5*ambient
P_in = 0.9e5*t + 1e5;           % ramp input 0.1 MPa .. 1 MPa in 10 s
% calculate current values of the valve parameters

A_o1 = a*(a-x(1));              % current area of the valve

if A_o1<0, A_o1 = 0; 
end                             % valve closes if x(1)>a, so A_o1 is non-negative

beta_o1 = sqrt(4*A_o1/pi)/D_p;  % current area of the valve/pipe 

gamma_1 = A_o1*(1-beta_o2^4);
gamma_2 = A_o2*(1-beta_o1^4);
% calculate current reduced pressure 
P_red = (gamma_1*P_in + gamma_2*P_out)/(gamma_1 + gamma_2);
% and reduced pressure force on the spool, assuming it acts on the whole
% surface, i.e. shoulder area is neglected (unlike the shoulder force)
% only additional pressure generates force, hence the P_red-Pout term

F_red = (P_red-P_out)*(pi*D_s^2)/4;

if F_red<F_init
    F_red = F_init;
end

dx=zeros(2,1);

dx(1)=x(2);
dx(2)=(F_red-F_init)/m_s - k*x(1)/m_s;
end

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

