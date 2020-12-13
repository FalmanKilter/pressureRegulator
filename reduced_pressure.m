function P_red = reduced_pressure(t, y, param_set)
% calculate evolution of the value of reduced pressure
%%
% inlet pressure
P_in = 0.9e5*t + 1e5;                   % ramp input 0.1 MPa .. 1 MPa in 10 s 

P_red = zeros(1,size(y,1));

% get intermediate parameters from param_set
A_o2 = param_set(1);
beta_o2 = param_set(2);
P_out = param_set(3);
a = param_set(5);
D_w = param_set(6);

% calculate reduced pressure at each time step using spool position y(:,1)
% and inlet pressure P_in
for i = 1:length(y)
    
    A_o1 = a*(a-y(i,1));                % current area of the valve
    
    if A_o1<0, A_o1 = 0;
    end
    
    beta_o1 = sqrt(4*A_o1/pi)/D_w;      % valve to pipe diameter ratio
    
    gamma_1 = A_o1*(1-beta_o2^4);
    gamma_2 = A_o2*(1-beta_o1^4);
    
    P_red(i) = (gamma_1*P_in(i) + gamma_2*P_out)/(gamma_1 + gamma_2);
    
end
end