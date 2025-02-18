% Caricare i dati salvati
%load('AllFlight5_E_new.mat', 'dataTable5');

% Inizializzare i vettori per latitudine e longitudine normalizzate
lat_normalized = [];
lon_normalized = [];
ax = [];
gy = [];
mz = [];
x_error = [];
y_error = [];
z_error = [];
% Estrarre le latitudini e longitudini normalizzate
for i = 1:height(data)
    currentTimetable = data{i, 1}{1};

    if ismember('Lat', currentTimetable.Properties.VariableNames) && ...
       ismember('Lon', currentTimetable.Properties.VariableNames)
        lat_normalized = [lat_normalized; currentTimetable.Lat];
        lon_normalized = [lon_normalized; currentTimetable.Lon];
    end
    
    if ismember('ax', currentTimetable.Properties.VariableNames)
        ax = [ax; currentTimetable.ax];
    end

    if ismember('gyy', currentTimetable.Properties.VariableNames)
        gy = [gy; currentTimetable.gyy];
    end

    if ismember('mz', currentTimetable.Properties.VariableNames)
        mz = [mz; currentTimetable.mz];
    end
    
    if ismember('x_error', currentTimetable.Properties.VariableNames)
        x_error = [x_error; currentTimetable.x_error];
    end

    if ismember('y_error', currentTimetable.Properties.VariableNames)
        y_error = [y_error; currentTimetable.y_error];
    end

    if ismember('z_error', currentTimetable.Properties.VariableNames)
        z_error = [z_error; currentTimetable.z_error];
    end
end

% Tracciare i dati normalizzati
figure;

% Tracciato della latitudine normalizzata
subplot(2, 1, 1);
plot(lat_normalized);
title('Latitudine Normalizzata');
xlabel('Campioni');
ylabel('Latitudine Normalizzata');

% Tracciato della longitudine normalizzata
subplot(2, 1, 2);
plot(lon_normalized);
title('Longitudine Normalizzata');
xlabel('Campioni');
ylabel('Longitudine Normalizzata');

figure;

subplot(3, 1, 1);
plot(ax);
title('Accelerazione X');
xlabel('Campioni');
ylabel('m/s^2');

subplot(3, 1, 2);
plot(gy);
title('Giroscopio y');
xlabel('Campioni');
ylabel('rad/s');

subplot(3, 1, 3);
plot(mz);
title('Magnetometro z');
xlabel('Campioni');
ylabel('');

figure;

subplot(3, 1, 1);
plot(x_error);
title('X error');
xlabel('Campioni');
ylabel('');

subplot(3, 1, 2);
plot(y_error);
title('Y error');
xlabel('Campioni');
ylabel('');

subplot(3, 1, 3);
plot(z_error);
title('Z error');
xlabel('Campioni');
ylabel('');

disp('Script per il tracciamento completato.');
