% Assumiamo che la tabella si chiami 'dataTable'
dataTable6 = resultTable6;
% Numero totale di righe nella tabella
numRows = height(dataTable6);

bufferSize = 130;

for i = 1:numRows
    % Estrarre la timetable dalla prima colonna
    currentTimetable = dataTable6{i, 1}{1};
    disp(i);

    % Uniformare la variabile: rinominare 'Long' in 'Lon' se esiste
    if ismember('Long', currentTimetable.Properties.VariableNames)
        currentTimetable.Properties.VariableNames{'Long'} = 'Lon';
    end

    % Calcolare gli errori tra dati stimati e desiderati
    x_error = currentTimetable.x_stim - currentTimetable.x_des;
    y_error = currentTimetable.y_stim - currentTimetable.y_des;
    z_error = currentTimetable.z_stim - currentTimetable.z_des;
    
    yaw_error = currentTimetable.yaw - currentTimetable.yaw_des;
    pitch_error = currentTimetable.pitch - currentTimetable.pitch_des;
    roll_error = currentTimetable.roll - currentTimetable.roll_des;

    % Aggiungere gli errori alla timetable
    currentTimetable.x_error = x_error;
    currentTimetable.y_error = y_error;
    currentTimetable.z_error = z_error;
    currentTimetable.yaw_error = yaw_error;
    currentTimetable.pitch_error = pitch_error;
    currentTimetable.roll_error = roll_error;

    % Sostituire i valori NaN con 0 nelle colonne Lan, Lon e Alt
    currentTimetable.Lat(isnan(currentTimetable.Lat)) = 0;
    currentTimetable.Lon(isnan(currentTimetable.Lon)) = 0;

    % Normalizzare Lan e Lon in buffer di 128 campioni
    if ismember('Lat', currentTimetable.Properties.VariableNames) && ...
       ismember('Lon', currentTimetable.Properties.VariableNames)

        numBuffers = ceil(height(currentTimetable) / bufferSize);

        for b = 1:numBuffers
            startIdx = (b-1) * bufferSize + 1;
            endIdx = min(b * bufferSize, height(currentTimetable));

            latBuffer = currentTimetable.Lat(startIdx:endIdx);
            lonBuffer = currentTimetable.Lon(startIdx:endIdx);

            lat_mean = mean(latBuffer, 'omitnan');
            lat_std = std(latBuffer, 'omitnan');
            lon_mean = mean(lonBuffer, 'omitnan');
            lon_std = std(lonBuffer, 'omitnan');

            currentTimetable.Lat(startIdx:endIdx) = (latBuffer - lat_mean) ./ lat_std;
            currentTimetable.Lon(startIdx:endIdx) = (lonBuffer - lon_mean) ./ lon_std;
        end
    else
        warning('Le variabili Lat o Lon non sono presenti nella timetable della riga %d.', i);
    end

    % Rimuovere le colonne di dati stimati e desiderati
    currentTimetable(:, {'x_stim', 'y_stim', 'z_stim', 'x_des', 'y_des', 'z_des', ...
                         'yaw', 'pitch', 'roll', 'yaw_des', 'pitch_des', 'roll_des', ...
                         'Alt', 'course', 'ground_speed', 'vx_gps', ...
                         'vy_gps', 'vz_gps'}) = [];

    % Aggiornare la timetable nella tabella principale
    dataTable6{i, 1}{1} = currentTimetable;
end

% Salvataggio dei risultati
disp('Script completato e dati elaborati con successo.');

% Salvataggio della tabella aggiornata in un file .mat
save('AllFlight7_E_new.mat', 'dataTable6');
disp('Tabella aggiornata salvata nel file AllFlight7_E.mat');

