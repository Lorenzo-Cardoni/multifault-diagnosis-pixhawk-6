%close all;

x_stim = FC_states.Data(:,1);
y_stim = FC_states.Data(:,2);
z_stim = FC_states.Data(:,3);

% vx = FC_states.Data(:,4);
% vy = FC_states.Data(:,5);
% vz = FC_states.Data(:,6);

x_des = FC_states.Data(:,7);
y_des = FC_states.Data(:,8);
z_des = FC_states.Data(:,9);

% yaw = FC_states.Data(:,10);
% pitch = FC_states.Data(:,11);
% roll = FC_states.Data(:,12);
% 
% yawspeed = FC_states.Data(:,13);
% pitchspeed = FC_states.Data(:,14);
% rollspeed = FC_states.Data(:,15);
% 
% yaw_des = FC_states.Data(:,16);
% pitch_des = FC_states.Data(:,17);
% roll_des = FC_states.Data(:,18);
% 
% dt = FC_states.Time(1:end-1);
% % Accellerazioni lineari
% 
% dataArray = out.dynamics_states.Data;
% 
% ax = squeeze(dataArray(:,15,:));
% ay = squeeze(dataArray(:,16,:));
% az = squeeze(dataArray(:,17,:));
% 
% gyx = squeeze(dataArray(:,12,:));
% gyy = squeeze(dataArray(:,13,:));
% gyz = squeeze(dataArray(:,14,:));
% 
% mx = squeeze(dataArray(:,9,:));
% my = squeeze(dataArray(:,10,:));
% mz = squeeze(dataArray(:,11,:));
% 
% long = squeeze(dataArray(:,6,:));
% lat = squeeze(dataArray(:,7,:));
% alt = squeeze(dataArray(:,8,:));
% 
% vx_gps = squeeze(dataArray(:,3,:));
% vy_gps = squeeze(dataArray(:,4,:));
% vz_gps = squeeze(dataArray(:,5,:));
% 
% gnd_speed = squeeze(dataArray(:,2,:));
% 
% course = squeeze(dataArray(:,1,:));

%disp(out.dynamics_states.signals.values(:,17,:));

prova_log = 'prova_volo9.mat';
save(prova_log, "out" ,'FC_states');
% save(prova_log, "out" ,'FC_states','x_stim','y_stim','z_stim', 'vx','vy','vz', ...
%     'x_des',"y_des",'z_des', "yaw", 'pitch', "roll", "yawspeed", ...
%     "pitchspeed", "rollspeed", "yaw_des", "pitch_des", "roll_des", ...
%     "ax", "ay", "az", "gyx", "gyy", "gyz", "mx", "my", "mz", "long", ...
%     "lat", "alt","vx_gps", "vy_gps", "vz_gps","gnd_speed", "course");

% plot(FC_states.Time, yaw);hold on;
% plot(FC_states.Time, yaw_des);
% xlabel('Tempo');
% ylabel('Valore');
% title('Yaw');
% legend('yaw','yaw des','show');

% Creare una figura
figure;

% Plot 3D col guasto inserito
plot3(x_des,-y_des,z_des,x_stim,-y_stim,-z_stim, 'LineWidth', 2);

% Aggiungere etichette, titolo e legenda
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Plot 3D');
legend('stim', 'des', 'show');

% Aggiungere la griglia se necessario
grid on;