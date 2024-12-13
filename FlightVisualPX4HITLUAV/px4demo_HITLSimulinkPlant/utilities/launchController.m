function launchController
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'controller','Quadcopter_ControllerWithNavigation.slx'));
end
