%% Plot delle accelerazioni delle dynamics e del Flight Controller
figure;
plot(label.Time, label1.Data, 'r', 'DisplayName', 'Fault');
hold on;
%xline(100,'DisplayName','Fault Time');
%plot(out.pwm_WOF.Time(14800:15500), out.pwm_WOF.Data(14800:15500,1), 'b', 'DisplayName', 'pwm WOF');
xlabel('Time (s)');
ylabel('Faul code');
legend();
grid on;
title('Fault Diagnosis');

%% Plot delle accelerazioni delle dynamics e del Flight Controller
figure;
plot(label.Time, label.Data, 'r', 'DisplayName', 'Fault');
hold on;
%xline(100,'DisplayName','Fault Time');
%plot(out.pwm_WOF.Time(14800:15500), out.pwm_WOF.Data(14800:15500,1), 'b', 'DisplayName', 'pwm WOF');
xlabel('Time (s)');
ylabel('Faul code');
legend();
grid on;
title('Fault Diagnosis');

%% Plot delle accelerazioni delle dynamics e del Flight Controller
figure;
plot(out.label2.Time, out.label.Data, 'r', 'DisplayName', 'Fault');
hold on;
xline(100,'DisplayName','Fault Time');
%plot(out.pwm_WOF.Time(14800:15500), out.pwm_WOF.Data(14800:15500,1), 'b', 'DisplayName', 'pwm WOF');
xlabel('Time (s)');
ylabel('Faul code');
legend();
grid on;
title('Fault Diagnosis');
%% Plot delle accelerazioni delle dynamics e del Flight Controller
figure;
plot(out.label2.Time, out.label2.Data, 'r', 'DisplayName', 'Fault');
hold on;
xline(100,'DisplayName','Fault Time');
%plot(out.pwm_WOF.Time(14800:15500), out.pwm_WOF.Data(14800:15500,1), 'b', 'DisplayName', 'pwm WOF');
xlabel('Time (s)');
ylabel('Faul code');
legend();
grid on;
title('Fault Diagnosis');


