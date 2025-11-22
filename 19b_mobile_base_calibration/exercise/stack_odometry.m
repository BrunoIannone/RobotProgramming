function odom = stack_odometry(x, ticks)
    odom = zeros(size(ticks, 1), 3);

    for i = 1:size(ticks, 1)
        if all(ticks(i, :) == [0 0])

            if i == 1  
                odom(i, :) = [0, 0, 0];
            else
                odom(i, :) = odom(i-1, :);
            end

            continue;   
        end

        odom(i, :) = compute_odometry_trajectory(h_odom(x, ticks(i, :))');
    end
end
