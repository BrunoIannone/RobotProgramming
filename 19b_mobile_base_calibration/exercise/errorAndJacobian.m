function [e, J] = errorAndJacobian(x,z)
  ticks = z(1:2);
  ticks
  meas  = z(3:5);
  meas
  pause(5)
  pred  = h_odom(x,ticks);
  e     = pred-meas;
  J     = zeros(3,3);
  epsilon = 1e-3;
  inv_eps2= 0.5/epsilon;
  for (i=1:3)
    e_vec = zeros(3);
    e_vec(i)=epsilon;
    J(:,i) = inv_eps2 * (h_odom(x+e_vec, ticks) -h_odom(x-e_vec, ticks));
  endfor;
endfunction