%% Downsampling
T = resultTable5;
% Nuova frequenza di campionamento
newFs = 65; % Hz
oldFs = 100; % Hz

% Calcolo del passo di downsampling
step = round(oldFs / newFs); % Calcola il passo corretto per selezionare i dati

% Pre-allocazione per i dati downsampled
downsampledData = cell(height(T), 1);

% Itera attraverso le righe della tabella
for i = 1:height(T)
    tt = T.Timetable{i}; % Estrai la timetable originale
    
    % Applica il downsampling selezionando una riga ogni 'step' righe
    ttDownsampled = tt(1:step:end, :); % Selezione delle righe
    
    % Salva il risultato
    downsampledData{i} = ttDownsampled;
end

% Crea una nuova tabella con le timetable downsampled
resultTable6 = table(downsampledData, T.FaultCode, 'VariableNames', {'Timetable', 'FaultCode'});

% Visualizza un esempio
disp('downsampling avvenuto');
