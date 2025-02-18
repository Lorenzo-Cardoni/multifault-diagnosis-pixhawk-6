%% Dataset completo 2
% Aggiungi altre timetable
% save('allFlights_senzaLabel.mat', 'diagnosticTimetable(:,1:end-1)', 'diagnosticTimetable2_1(10000:end,1:end-1)' ...
%     , 'diagnosticTimetable2_2(10000:end,1:end-1)', 'diagnosticTimetable2_3(10000:end,1:end-1)', ...
%     'diagnosticTimetable3_1(10000:end,1:end-1)', 'diagnosticTimetable3_2(10000:end,1:end-1)', ...
%     'diagnosticTimetable3_3(10000:end,1:end-1)', 'diagnosticTimetable4_1(10000:end,1:end-1)' ...
%     , 'diagnosticTimetable4_2(10000:end,1:end-1)', 'diagnosticTimetable4_3(10000:end,1:end-1)', ...
%     'diagnosticTimetable_F2(10000:end,1:end-1)' );

% FaultCode per ciascuna timetable
faultCodes = [0; 1; 1; 1; 0; 2; 2; 3; 3; 3; 4; 4; 4; 
              0; 1; 1; 1; 0; 2; 2; 3; 3; 3; 4; 4; 4; 
              0; 1; 1; 1; 0; 2; 2; 3; 3; 3; 4; 4; 4;
              0; 0; 0; 0; 0; 0]; % Sostituisci con i tuoi codici di errore

% Crea una cell array per contenere le timetable
timetableArray = {diagnosticTimetable; diagnosticTimetable2_1; diagnosticTimetable2_2;
    diagnosticTimetable2_3; diagnosticTimetable3_1; diagnosticTimetable3_2_F1_new; diagnosticTimetable3_3_F1_new;
    diagnosticTimetable4_1; diagnosticTimetable4_2; diagnosticTimetable4_3; diagnosticTimetable5_1;
    diagnosticTimetable5_2; diagnosticTimetable5_3; 
    diagnosticTimetable_F2; diagnosticTimetable2_1_F2; diagnosticTimetable2_2_F2;
    diagnosticTimetable2_3_F2; diagnosticTimetable3_1_F2; diagnosticTimetable3_2_F2_new; diagnosticTimetable3_3_F2_new;
    diagnosticTimetable4_1_F2; diagnosticTimetable4_2_F2; diagnosticTimetable4_3_F2; diagnosticTimetable5_1_F2;
    diagnosticTimetable5_2_F2; diagnosticTimetable5_3_F2;
    diagnosticTimetable_F3; diagnosticTimetable2_1_F3; diagnosticTimetable2_2_F3;
    diagnosticTimetable2_3_F3_new; diagnosticTimetable3_1_F3; diagnosticTimetable3_2_F3_new; diagnosticTimetable3_3_F3_new;
    diagnosticTimetable4_1_F3; diagnosticTimetable4_2_F3; diagnosticTimetable4_3_F3; diagnosticTimetable5_1_F3;
    diagnosticTimetable5_2_F3; diagnosticTimetable5_3_F3; diagnosticTimetableF4_new; diagnosticTimetableF5_new; 
    diagnosticTimetableF6_new; diagnosticTimetableF7_new; diagnosticTimetableF8_new; diagnosticTimetableF9_new}; % Aggiungi qui tutte le tue timetable

% Associa timetable e faultCode in una tabella
resultTable5 = table(timetableArray, faultCodes, 'VariableNames', {'Timetable', 'FaultCode'});

save("allFlights5.mat", "resultTable5");
disp('Tabella salvata!');