function Z=generateMeasurements(n, x)
  # zi = tl, tr, dx, dy dth
  Z=zeros(5,n);
  Z(1:2,:) = rand(2, n);
  for (i = 1:n)
    ticks = Z(1:2,i);
    Z(3:5,i) = h_odom(x, ticks);
  endfor
endfunction