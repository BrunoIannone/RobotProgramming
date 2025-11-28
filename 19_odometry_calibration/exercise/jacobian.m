#derivative of the error function for the ith measurement in Z
#does not depend on the state
#i:	the measuement number
#Z:	the measurement matrix
#A:	the jacobian of the ith measurement
function A=jacobian(i,Z)
	u=Z(i,4:6);
	A=zeros(3,9);
	A(1,1:3)= -u;
	A(2,4:6)= -u;
	A(3,7:9)= -u;
end
