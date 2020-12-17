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
D_w = param_set(6);
F_init = param_set(7);
k = param_set(8);
b = param_set(9);
m_s = param_set(10);

% calculate current value of P_in as a function of time
%P_in = 0.1e6;                      % constant, ambient
%P_in = 0.15e6;                     % constant, 1.5*ambient
P_in = 0.9e5*t + 1e5;               % ramp input 0.1 MPa .. 1 MPa in 10 s
% calculate current values of the valve parameters

% calculate effective valve area
alpha = 2*asin(a/D_s);              % angular extent of the window
l = (D_s/2)*alpha;                  % circumferential length of the window
A_o1 = l*(a-x(1));                    % current area of the valve

if A_o1<0, A_o1 = 0;
end                                 % valve closes if x(1)>a, so A_o1 is non-negative

beta_o1 = sqrt(4*A_o1/pi)/D_w;      % equivalent valve to equivalent window diameter ratio 

gamma_1 = A_o1^2*(1-beta_o2^4);
gamma_2 = A_o2^2*(1-beta_o1^4);
% calculate current reduced pressure
P_red = (gamma_1*P_in + gamma_2*P_out)/(gamma_1 + gamma_2);
% and reduced pressure force on the spool, assuming it acts on the whole
% surface, i.e. shoulder area is neglected (unlike the shoulder force)

F_red = P_red*(pi*D_s^2)/4;

if F_red<F_init
    F_red = F_init;
end

dx=zeros(2,1);

dx(1)=x(2);
dx(2)=(F_red-F_init)/m_s - k*x(1)/m_s - b*(x(2))/m_s;
end