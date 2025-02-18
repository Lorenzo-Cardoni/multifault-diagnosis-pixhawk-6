%% Confronto valori GPS tra dynamics e FC

% Constants
    CONSTANTS_RADIUS_OF_EARTH = 6371000; % Raggio medio della Terra in metri

    % Convert input reference latitude and longitude to radians
    ref_lat_rad = deg2rad(47.397742);
    ref_lon_rad = deg2rad(8.545594);

    % Calculate x_rad and y_rad
    x_rad = x_stim / CONSTANTS_RADIUS_OF_EARTH;
    y_rad = y_stim / CONSTANTS_RADIUS_OF_EARTH;
    c = sqrt(x_rad.^2 + y_rad.^2);
    
    % Pre-allocate outputs
    latT = zeros(size(x_stim));
    lonT = zeros(size(x_stim));

    % Calculate latitude and longitude for c > 0
    idx = c > 0; % Logical index for valid c values

    % Spherical trigonometry (only where c > 0)
    sin_c = sin(c(idx));
    cos_c = cos(c(idx));

    % Reference latitude and longitude in spherical terms
    ref_sin_lat = sin(ref_lat_rad);
    ref_cos_lat = cos(ref_lat_rad);

    % Compute latitude and longitude in radians
    lat_rad = asin(cos_c .* ref_sin_lat + (x_rad(idx) .* sin_c .* ref_cos_lat) ./ c(idx));
    lon_rad = ref_lon_rad + atan2(y_rad(idx) .* sin_c, c(idx) .* ref_cos_lat .* cos_c - x_rad(idx) .* ref_sin_lat .* sin_c);

    % Assign computed values to output
    latT(idx) = rad2deg(lat_rad);
    lonT(idx) = rad2deg(lon_rad);

    % Handle cases where c == 0 (no displacement)
    latT(~idx) = 47.397742;
    lonT(~idx) = 8.545594;

%% Plot della Latitudine delle dynamics e del Flight Controller
figure;
plot(finaltable.dynamicsTime, latT, 'r', 'DisplayName', 'latFC');
hold on;
plot(finaltable.dynamicsTime, LLAData(:, 1), 'b', 'DisplayName', 'lat dynamics');
xlabel('Time (s)');
ylabel('Acceleration');
legend();
grid on;
title('Verifica Sincronizzazione Dynamics e FC');

%% Calcolo errori
error_lat = abs(lonT - LLAData(:, 2));
error_lon = abs(latT - LLAData(:, 1));

% Mostra errori
disp('Errori:');
fprintf('Errore medio assoluto in lat: %.6f deg', mean(error_lat));
fprintf('Errore medio assoluto in long: %.6f deg', mean(error_lon));
