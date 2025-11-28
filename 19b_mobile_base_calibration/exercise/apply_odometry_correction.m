#computes a calibrated vector of odometry measurements
#by applying the bias term to each line of the measurements
#X: 	3x3 matrix obtained by the calibration process
#U: 	Nx3 matrix containing the odometry measurements
#C:	Nx3 matrix containing the corrected odometry measurements	

function C=apply_odometry_correction(X, U)
	C=zeros(size(U,1),3);
	for i=1:size(U,1),
	
		u=U(i,1:3)';
		uc = X*u;%TODO
		C(i,:)=uc;
	end
end