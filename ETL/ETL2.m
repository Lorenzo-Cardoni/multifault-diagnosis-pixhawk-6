%% Sincronizzazione dati tra dynamics e Flight Controller
fcData = FC_states.Data;
fcTime = FC_states.Time;

dynamicsData = transpose(squeeze(out.dynamics_states.Data(:,:,:)));
dynamicsTime = out.tout;

LLAData = transpose(squeeze(out.LLA.Data(:,:,:)));

LLA_noFault_Data = transpose(squeeze(out.LLA_noFault.Data(:,:,:)));

%Indice del primo valore diverso da zero
validStartIndex = find(acc.Data(:,1) ~= 0, 1, 'first')-19;


disp('Indice di partenza FC: ');
disp(validStartIndex);

fcTime = fcTime(validStartIndex:end);
fcData = fcData(validStartIndex:end, :);

% Verifica che le due tabelle siano allineate
disp('Campioni FC: ');
disp(size(fcData));
disp('Campioni dynamics: ');
disp(size(dynamicsData));

%% Calcolo del tempo medio di campionamento

% Calcola il tempo medio di campionamento
mean_sampling_interval = mean(diff(fcTime));

% Visualizza il risultato
disp(['Tempo medio di campionamento: ', num2str(mean_sampling_interval), ' secondi']);
disp(['Frequenza media di campionamento: ', num2str(1/mean_sampling_interval), ' Hz']);

%% Riempimento in avanti

% Definisci l'intervallo atteso
deltaExpected = 0.01;

% Calcola le differenze tra campioni consecutivi
timeDiffs = diff(fcTime);

% Verifica che tutte le differenze siano uguali all'intervallo atteso
isRegular = all(abs(timeDiffs - deltaExpected) < 1e-6); % Tollera piccoli errori numerici

if isRegular
    fprintf('Tutti i campioni sono regolarmente distanziati di %.3f secondi.\n', deltaExpected);
else
    fprintf('I campioni NON sono regolarmente distanziati di %.3f secondi.\n', deltaExpected);

    % Trova gli indici dei campioni con intervalli non regolari
    irregularIndices = find(abs(timeDiffs - deltaExpected) >= 1e-6);
    % fprintf('Intervalli irregolari trovati ai seguenti indici: \n');
    % disp(irregularIndices);

    % Riempimento in avanti per i campioni mancanti
    correctedTimeVector = fcTime(1); % Inizializza con il primo campione
    correctedData = fcData(1, :); % Inizializza con il primo dato (adatta se necessario)

    for i = 2:length(fcTime)
        expectedTime = correctedTimeVector(end) + deltaExpected;
        if abs(fcTime(i) - expectedTime) >= 1e-6 % Se manca un campione
            % Aggiungi il campione mancante
            correctedTimeVector(end+1) = expectedTime;
            correctedData(end+1, :) = correctedData(end, :); % Forward fill
        end
        % Aggiungi il campione attuale
        correctedTimeVector(end+1) = fcTime(i);
        correctedData(end+1, :) = fcData(i, :);
    end

    fprintf('Campioni mancanti riempiti in avanti.\n');
end

disp(size(correctedData));
%% Troncamento dei dati del FC

if size(dynamicsData, 1) < size(correctedData, 1)
    correctedData = correctedData(1:size(dynamicsData, 1), :);
end
disp('I dati di dynamics e FC troncati sono rispettivamente: ')
disp(size(dynamicsData));
disp(size(correctedData));


% %% Etichette Guasti
% 
% num_samples = length(dynamicsTime); % Numero di campioni temporali
% 
% % Inizializza il vettore delle etichette
% faultCode = zeros(1, num_samples);
% 
% % Parametri del guasto
% fault_start = 0; % Tempo di inizio guasto (secondi)
% % fault_end = 0.07;   % Tempo di fine guasto (secondi)
% fault_type = 0;     % Tipo di guasto (esempio)
% 
% % Trova gli indici corrispondenti all'intervallo del guasto
% start_idx = find(dynamicsTime >= fault_start, 1, 'first');
% 
% 
% % Assegna il valore del tipo di guasto nel vettore delle etichette
% faultCode(start_idx:end) = fault_type;
% 
% faultCode = categorical(transpose(faultCode));


%% Unione dati
pwm = out.pwm.Data;

finaltable.Data = [dynamicsData, correctedData, pwm, LLAData];
finaltable.Time = dynamicsTime;

disp('Dati uniti correttamente!');


%% Creazione della Timetable per il Diagnostic Feature Designer

% Creazione del vettore temporale
timeVector = seconds(dynamicsTime); % Converti in formato durate per la timetable

% Assegna nomi significativi ai dati
dataNames = {
    'course', 'ground_speed', 'vx_gps', 'vy_gps', 'vz_gps', ... % Dynamics
    'mx', 'my', 'mz', 'gyx', 'gyy', 'gyz', ...
    'ax', 'ay', 'az', ...
    'x_stim', 'y_stim', 'z_stim', ... % Flight Controller
    'vx', 'vy', 'vz', ...
    'x_des', 'y_des', 'z_des', ...
    'yaw', 'pitch', 'roll', ...
    'yawspeed', 'pitchspeed', 'rollspeed', ...
    'yaw_des', 'pitch_des', 'roll_des', ...
    'PWM1', 'PWM2', 'PWM3', 'PWM4', 'Lat', 'Lon', 'Alt' ... % PWM (aggiungi se ci sono più canali PWM)
};

% Unione dei dati e aggiunta delle etichette dei guasti
dataMatrix = [finaltable.Data];

%dataMatrix = array2timetable(dataMatrix, 'RowTimes', timeVector, 'VariableNames', dataNames);

% Creazione della timetable
diagnosticTimetable2_3 = array2timetable(dataMatrix, 'RowTimes', timeVector, 'VariableNames', dataNames);

diagnosticTimetable2_3 = diagnosticTimetable2_3(10000:end-1000,:);

% Salvataggio della timetable
save('diagnosticTimetable2_3.mat', 'diagnosticTimetable2_3');

disp('Timetable creata e salvata con successo per il Diagnostic Feature Designer!');
%% Salvataggio dei dati
% x_stim = finaltable.Data(:, 15);
% y_stim = finaltable.Data(:, 16);
% z_stim = finaltable.Data(:, 17);
% 
% vx = finaltable.Data(:, 18);
% vy = finaltable.Data(:, 19);
% vz = finaltable.Data(:, 20);
% 
% x_des = finaltable.Data(:, 21);
% y_des = finaltable.Data(:, 22);
% z_des = finaltable.Data(:, 23);
% 
% yaw = finaltable.Data(:, 24);
% pitch = finaltable.Data(:, 25);
% roll = finaltable.Data(:, 26);
% 
% yawspeed = finaltable.Data(:, 27);
% pitchspeed = finaltable.Data(:, 28);
% rollspeed = finaltable.Data(:, 29);
% 
% yaw_des = finaltable.Data(:, 30);
% pitch_des = finaltable.Data(:, 31);
% roll_des = finaltable.Data(:, 32);
% 
% ax_FC = finaltable.Data(:, 33);
% ay_FC = finaltable.Data(:, 34);
% az_FC = finaltable.Data(:, 35);
% 
% ax = finaltable.Data(:,12);
% ay = finaltable.Data(:,13);
% az = finaltable.Data(:,14);
% 
% gyx = finaltable.Data(:,9);
% gyy = finaltable.Data(:,10);
% gyz = finaltable.Data(:,11);
% 
% mx = finaltable.Data(:,6);
% my = finaltable.Data(:,7);
% mz = finaltable.Data(:,8);
% 
% vx_gps = finaltable.Data(:,3);
% vy_gps = finaltable.Data(:,4);
% vz_gps = finaltable.Data(:,5);
% 
% gnd_speed = finaltable.Data(:,2);
% 
% course = finaltable.Data(:,1);
% 
% realStates = out.real_states;
% 
% file_name = 'E_state_WOF.mat';
% save(file_name, 'x_stim','y_stim','z_stim', 'vx','vy','vz', ...
%     'x_des',"y_des",'z_des', "yaw", 'pitch', "roll", "yawspeed", ...
%     "pitchspeed", "rollspeed", "yaw_des", "pitch_des", "roll_des", ...
%      "ax", "ay", "az", "ax_FC", "ay_FC", "az_FC","gyx", "gyy", "gyz", "mx", "my", "mz", ...
%      "vx_gps", "vy_gps", "vz_gps","gnd_speed", "course", "realStates", ...
%      "LLAData", "LLA_noFault_Data", "faultCode", ...
%      "pwm", "dynamicsTime", "finaltable");