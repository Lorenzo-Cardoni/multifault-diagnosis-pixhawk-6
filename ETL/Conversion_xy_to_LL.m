% Constants
    CONSTANTS_RADIUS_OF_EARTH = 6371000; % Raggio medio della Terra in metri

    % Convert input reference latitude and longitude to radians
    ref_lat_rad = deg2rad(47.397742);
    ref_lon_rad = deg2rad(8.545594);

    % Calculate x_rad and y_rad
    x_rad = x_real.Data / CONSTANTS_RADIUS_OF_EARTH;
    y_rad = y_real.Data / CONSTANTS_RADIUS_OF_EARTH;
    c = sqrt(x_rad.^2 + y_rad.^2);
    
    % Pre-allocate outputs
    latT = zeros(size(x_real.Data));
    lonT = zeros(size(x_real.Data));

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

%% Calcolo errori
error_lat = abs(lonT - lat);
error_lon = abs(latT - long);

% Mostra errori
disp('Errori:');
fprintf('Errore medio assoluto in lat: %.6f deg', mean(error_lat));
fprintf('Errore medio assoluto in long: %.6f deg', mean(error_lon));
%% Conversione Da LL a xy

% Constants
    CONSTANTS_RADIUS_OF_EARTH = 6371000; % Raggio medio della Terra in metri

    % Convert input latitude and longitude to radians
    lat_rad = deg2rad(long);    % Può essere vettoriale
    lon_rad = deg2rad(lat);    % Può essere vettoriale
    ref_lat_rad = deg2rad(47.397742);
    ref_lon_rad = deg2rad(8.545594);

    % Precompute reference terms
    ref_sin_lat = sin(ref_lat_rad);
    ref_cos_lat = cos(ref_lat_rad);

    % Compute trigonometric terms
    sin_lat = sin(lat_rad);
    cos_lat = cos(lat_rad);
    cos_d_lon = cos(lon_rad - ref_lon_rad);

    % Compute c using constrained argument
    arg = min(max(ref_sin_lat .* sin_lat + ref_cos_lat .* cos_lat .* cos_d_lon, -1.0), 1.0);
    c = acos(arg);

    % Compute k
    k = ones(size(c));
    idx = abs(c) > 0; % Logical index for non-zero c
    k(idx) = c(idx) ./ sin(c(idx));

    % Compute x and y
    x = k .* (ref_cos_lat .* sin_lat - ref_sin_lat .* cos_lat .* cos_d_lon) * CONSTANTS_RADIUS_OF_EARTH;
    y = k .* cos_lat .* sin(lon_rad - ref_lon_rad) * CONSTANTS_RADIUS_OF_EARTH;

%% Compute errors
    error_x = abs(x - x_real.Data); % Errore assoluto in x
    error_y = abs(y - y_real.Data); % Errore assoluto in y
    error_relative_x = error_x ./ abs(x_real.Data); % Errore relativo in x
    error_relative_y = error_y ./ abs(y_real.Data); % Errore relativo in y

   % Display summary of errors
    disp('Riassunto degli errori:');
    fprintf('Errore medio assoluto in X: %.6f m\n', mean(error_x));
    fprintf('Errore medio assoluto in Y: %.6f m\n', mean(error_y));
    fprintf('Errore medio relativo in X: %.6f %%\n', mean(error_relative_x) * 100);
    fprintf('Errore medio relativo in Y: %.6f %%\n', mean(error_relative_y) * 100);

    %% Conversione da z ad Altitude e viceversa
% Calcolo di z dalla relazione diretta
altitude_ref = 488;
    z_calculated = altitude_ref - alt;

    % Calcolo dell'altitudine dalla relazione inversa
    altitude_calculated = altitude_ref - z_real.Data;

    % Confronto tra i valori calcolati e quelli reali
    error_z = abs(z_calculated - z_real.Data); % Errore assoluto su z
    error_altitude = abs(altitude_calculated - alt); % Errore assoluto su altitudine

    % Riassunto degli errori
    disp('Riassunto degli errori:');
    fprintf('Errore medio assoluto in Z: %.6f m\n', mean(error_z));
    fprintf('Errore medio assoluto in Altitudine: %.6f m\n', mean(error_altitude));

    %% Plot 3D delle cordinate XYZ

    figure;

% Plot 3D col guasto inserito
plot3(x_real.Data,-y_real.Data,-z_real.Data,x,-y,-z_calculated, 'LineWidth', 2);


% Aggiungere etichette, titolo e legenda
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Plot 3D');
legend('real', 'calculated', 'show');

% Aggiungere la griglia se necessario
grid on;
