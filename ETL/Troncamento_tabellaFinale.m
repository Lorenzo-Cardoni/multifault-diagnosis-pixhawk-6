% Carico i dati
data =  dataTable6;% Carica la tua tabella qui

% Trovo la lunghezza minima tra tutte le timetable
minLength = min(cellfun(@(x) height(x), data{:,1}));

% Trunco tutte le timetable alla lunghezza minima
for i = 1:height(data)
     data{i,1}{:} = data{i,1}{:}(1:minLength, :);
end

disp('Troncamento eseguito!');