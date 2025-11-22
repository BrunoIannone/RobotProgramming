function delta = h_odom(x,ticks)
  global S;
  global C;
  kl  = x(1);
  kr  = x(2);
  b   = x(3);
  tl  = ticks(1);
  tr  = ticks(2);
  dl  = tl*kl;
  dr  = tr*kr;
  dth = (dr-dl)/b;
  d_plus2 = 0.5 * (dr+dl);
  dx = d_plus2 * sin(dth)/dth;
  dy = d_plus2 * (1-cos(dth))/dth;
  delta = [dx, dy, dth]';
endfunction