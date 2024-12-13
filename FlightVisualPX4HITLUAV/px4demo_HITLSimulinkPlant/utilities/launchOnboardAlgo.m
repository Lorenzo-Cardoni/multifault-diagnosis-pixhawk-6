function launchOnboardAlgo
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'onboard_algorithm','Onboard_Autopilot_Communication.slx'));
end
