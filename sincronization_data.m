%% Sincronizzazione tra dati ricevuti dal FC e il Plant

fcData = FC_states.Data;
fcTime = FC_states.Time;

dynamicsData = transpose(squeeze(out.dynamics_states.Data(:,:,:)));
dynamicsTime = out.tout;

validStartIndex = find(fcData ~= 0, 1, 'first');

disp(validStartIndex);

fcTime = fcTime(validStartIndex:end);
fcData = fcData(validStartIndex:end, :);

%fault_time = out.fault_time.Data(:,1);

% Tronca anche dynamicsTS se necessario, per allineare le dimensioni
% commonLength = min(length(fcTime), length(dynamicsTime));
% fcTime = fcTime(1:commonLength);
% fcData = fcData(1:commonLength, :);
% dynamicsTime = dynamicsTime(1:commonLength);
% dynamicsData = dynamicsData(1:commonLength, :);
% fault_time = fault_time(1:commonLength);

% Ricrea le tabelle aggiornate
flightControllerTS.Time = fcTime;
flightControllerTS.Data = fcData;
dynamicsTS.Time = dynamicsTime;
dynamicsTS.Data = dynamicsData;

% Verifica che le due tabelle siano allineate
disp(size(flightControllerTS.Data));
disp(size(dynamicsTS.Data));

%% Salvataggio dei dati

x_stim = flightControllerTS.Data(:,1);
y_stim = flightControllerTS.Data(:,2);
z_stim = flightControllerTS.Data(:,3);

vx = flightControllerTS.Data(:,4);
vy = flightControllerTS.Data(:,5);
vz = flightControllerTS.Data(:,6);

x_des = flightControllerTS.Data(:,7);
y_des = flightControllerTS.Data(:,8);
z_des = flightControllerTS.Data(:,9);

yaw = flightControllerTS.Data(:,10);
pitch = flightControllerTS.Data(:,11);
roll = flightControllerTS.Data(:,12);

yawspeed = flightControllerTS.Data(:,13);
pitchspeed = flightControllerTS.Data(:,14);
rollspeed = flightControllerTS.Data(:,15);

yaw_des = flightControllerTS.Data(:,16);
pitch_des = flightControllerTS.Data(:,17);
roll_des = flightControllerTS.Data(:,18);

dataArray = out.dynamics_states.Data;

ax = dynamicsTS.Data(:,15);
ay = dynamicsTS.Data(:,16);
az = dynamicsTS.Data(:,17);

gyx = dynamicsTS.Data(:,12);
gyy = dynamicsTS.Data(:,13);
gyz = dynamicsTS.Data(:,14);

mx = dynamicsTS.Data(:,9);
my = dynamicsTS.Data(:,10);
mz = dynamicsTS.Data(:,11);

long = dynamicsTS.Data(:,6);
lat = dynamicsTS.Data(:,7);
alt = dynamicsTS.Data(:,8);

vx_gps = dynamicsTS.Data(:,3);
vy_gps = dynamicsTS.Data(:,4);
vz_gps = dynamicsTS.Data(:,5);

gnd_speed = dynamicsTS.Data(:,2);

course = dynamicsTS.Data(:,1);

%disp(out.dynamics_states.signals.values(:,17,:));

prova_log = 'prova_volo.mat';
save(prova_log, "out" ,'FC_states', "flightControllerTS", "dynamicsTS" , ...
    'x_stim','y_stim','z_stim', 'vx','vy','vz', ...
    'x_des',"y_des",'z_des', "yaw", 'pitch', "roll", "yawspeed", ...
    "pitchspeed", "rollspeed", "yaw_des", "pitch_des", "roll_des", ...
     "ax", "ay", "az", "gyx", "gyy", "gyz", "mx", "my", "mz", "long", ...
    "lat", "alt","vx_gps", "vy_gps", "vz_gps","gnd_speed", "course");
%% 


