function [x_new, chi] = oneRound(x, Z)

  H=zeros(3,3);
  b=zeros(3,1);
  nmeas=size(Z,2);
  chi=0;
  
  for (i = 1:nmeas)
    
    if all(Z(1:2,i) == [0 0])
      continue
    end
    [e,J]=errorAndJacobian(x,Z(:,i));
    H+=J'*J;
    b+=J'*e;
    chi+=e'*e;
    
  endfor
  dx=-H\b;
  x_new = x+dx;
end
