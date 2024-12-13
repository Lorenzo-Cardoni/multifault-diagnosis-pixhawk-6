%% Verifica tempo di campionamento

% Supponiamo che il vettore temporale sia 'timeVector'
timeVector = fcTime; % Sostituisci con il tuo vettore del tempo

% Definisci l'intervallo atteso
deltaExpected = 0.01;

% Calcola le differenze tra campioni consecutivi
timeDiffs = diff(timeVector);

% Verifica che tutte le differenze siano uguali all'intervallo atteso
isRegular = all(abs(timeDiffs - deltaExpected) < 1e-6); % Tollera piccoli errori numerici

if isRegular
    fprintf('Tutti i campioni sono regolarmente distanziati di %.3f secondi.\n', deltaExpected);
else
    fprintf('I campioni NON sono regolarmente distanziati di %.3f secondi.\n', deltaExpected);

    % Trova gli indici dei campioni con intervalli non regolari
    irregularIndices = find(abs(timeDiffs - deltaExpected) >= 1e-6);
    fprintf('Intervalli irregolari trovati ai seguenti indici: \n');
    % disp(irregularIndices);

    % Riempimento in avanti per i campioni mancanti
    correctedTimeVector = timeVector(1); % Inizializza con il primo campione
    correctedData = fcData(1, :); % Inizializza con il primo dato (adatta se necessario)

    for i = 2:length(timeVector)
        expectedTime = correctedTimeVector(end) + deltaExpected;
        if abs(timeVector(i) - expectedTime) >= 1e-6 % Se manca un campione
            % Aggiungi il campione mancante
            correctedTimeVector(end+1) = expectedTime;
            correctedData(end+1, :) = correctedData(end, :); % Forward fill
        end
        % Aggiungi il campione attuale
        correctedTimeVector(end+1) = timeVector(i);
        correctedData(end+1, :) = fcData(i, :);
    end

    % Aggiorna il timeseries con i dati corretti
    FC_new.Time = correctedTimeVector;
    FC_new.Data = correctedData;

    fprintf('Campioni mancanti riempiti in avanti.\n');
end

disp(size(FC_new.Data));