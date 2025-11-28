#this function computes the error of the i^th measurement in Z
#given the calibration parameters
#i:	the number of the measurement
#X:	the actual calibration parameters
#Z:	the measurement matrix
#e:	the error of the ith measurement
function e=error_function(i,X,Z)
	ustar=Z(i,1:3)';
	u=Z(i,4:6)';
	e= ustar-X*u;%TODO;
end
