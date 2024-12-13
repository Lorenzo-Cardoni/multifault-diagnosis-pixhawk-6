%% Scenario Simulation and Flight Visualization with PX4 Hardware-in-the-Loop (HITL) and UAV Dynamics in Simulink
% This example demonstrates 3D scenario Simulation and
% Flight visualization with PX4 Hardware-in-the-Loop (HITL) and UAV
% Dynamics contained in Simulink.  Unreal Engine(R) simulation environment is
% used for the 3D scenario Simulation and visualization. For more
% information, see <https://www.mathworks.com/help/uav/ug/3d-simulation-for-unmanned-aerial-vehicles.html Unreal Engine Simulation for Unmanned Aerial Vehicles>.
%
%
% *Limitation:* The Unreal Engine simulation environment is supported only on Microsoft(R) Windows(R) system.

% Copyright 2022 The MathWorks, Inc.

%% Prerequisites
%
% * If you are new to Simulink, watch the   
% <https://www.mathworks.com/videos/simulink-quick-start-78774.html Simulink Quick Start> video.
%
% * Go through the <docid:px4_ug#mw_ce8a26a6-40e5-4eb8-9e81-267f2b4ebd19
% PX4 Hardware-in-the-Loop System Architecture> document to understand the
% physical connections required to setup the Pixhawk and Simulink for HITL Simulation.
%
% * Configure and set up Pixhawk in HITL mode. For more information, see
% <docid:px4_ug#mw_49996cc7-11da-4f9c-b092-b03070e074b4 Setting up PX4 Autopilot in Hardware-in-the-Loop (HITL) Mode from QGroundControl>.
%
% * Setup the PX4 Firmware as mentioned in <docid:px4_ug#mw_d9e6ae3b-da4d-4f10-a899-0bda8d385b60 Set Up PX4 Firmware for Hardware-in-the-Loop Simulation>.
% In the *Select a PX4 Autopilot and Build Target* screen, select any
% Pixhawk Series board as the PX4 Autopilot board from the drop-down list.
% This example uses Pixhawk 4.
%
% * Familiarize with the co-simulation framework for UAVs, see
% <https://www.mathworks.com/help/uav/ug/3d-simulation-for-unmanned-aerial-vehicles.html
% Unreal Engine Simulation for Unmanned Aerial Vehicles>
% 
% *Required Third-Party Software*
%
% This example requires this third-party software:
% 
% * <https://docs.qgroundcontrol.com/master/en/index.html QGroundControl (QGC)>
%
% *Required Hardware*
%
% To run this example, you will need the following hardware:
%
% * Host PC Configured with
% <https://mathworks.com/help/parallel-computing/gpu-computing-requirements.html MATLAB supported GPU>. It is recommend to use GPU with <https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#compute-capabilities compute capability> of more than 5.
%
% * Pixhawk Series flight controller
%
% * Micro USB type-B cable
%
% * Micro-SD card
%
% * Pixhawk serial port connectors.
%
%% Workflow to Run Unreal Engine Flight Visualization Model along with Pixhawk in HITL Mode
%
% This example uses three different Simulink models.
%
% * Simulink model for Flight Controller to be deployed on PX4 Autopilot.
%
% * Simulink model for UAV Dynamics and sensor simulation.
%
% * Simulink model for flight visualization with Unreal Engine Simulation for Unmanned Aerial Vehicles.
%
% To avoid performance degradation in MATLAB due to three different Simulink models running at the same time, launch two separate sessions of same MATLAB.
%
% In first session of MATLAB, the Flight Controller will be deployed on the Autopilot and the UAV Dynamics model will be running on host computer communicating with Autopilot. 
%
% In second session of MATLAB, the Simulink model for flight visualization with Unreal Engine Simulation will be running.
%
%% Step 1: Make Hardware Connections and Setup the Pixhawk in HITL Mode
%
% The below diagram illustrates the HITL setup and the physical communication between various modules.
%
% <<../px4_flvis_setup.png>>
%
% 1. Connect your Pixhawk board to the host computer using the USB cable.  
% 
% 2. Ensure that you have configured the Pixhawk board in HITL mode as
% documented in <docid:px4_ug#mw_49996cc7-11da-4f9c-b092-b03070e074b4
% Setting up PX4 Autopilot in Hardware-in-the-Loop (HITL) Mode from
% QGroundControl>.
%
% 3. Ensure that you have setup the PX4 Firmware as mentioned in
% <docid:px4_ug#mw_d9e6ae3b-da4d-4f10-a899-0bda8d385b60 Set Up PX4 Firmware for Hardware-in-the-Loop Simulation>.
%
%% Step 2: Launch First Session of MATLAB and the MATLAB Project
%
% 1. Open MATLAB.
% 
% 2. Open the <matlab:openExample('px4/SimulationFlightVisualizationPX4HITLUAVDynamicsExample') px4demo_HardwareInLoopWithSimulinkPlant> MATLAB project. 
%
% 3. Once the Simulink project is open, click the *Project Shortcuts* tab
% on the MATLAB window and click *Open Autopilot Controller* to launch PX4
% Controller named _Quadcopter_ControllerWithNavigation_.
% 
% <<../project_shortcut1.png>>
%
% 4. In the *Project Shortcuts* tab, click *Open UAV Dynamics* to launch the
% Simulink UAV Dynamics model named _UAV_Dynamics_Autopilot_Communication_.
%
% 5. Open the Simulink Plant model _UAV_Dynamics_Autopilot_Communication_ and a connection for the flight visualization in the MAVLink Bridge Source block. Double-click the *MAVLink Bridge Source* block to open the block Parameters dialog box.
%
% <<../px4_mavlink_block.png>>
%
%% Step 3: Configure Simulink Controller Model for HITL Mode
%
% 1. Follow the instructions mentioned in <docid:px4_ug#mw_73c3ab3d-e4de-4b39-a52d-7829cad83f55
% Configure Simulink Model for Deployment in Hardware-in-the-Loop (HITL)
% Simulation>.
%
% *Note:* These steps are not required in the pre-configured model. Perform
% these steps if you have changed the hardware or not using the
% pre-configured model.
%
% 2. Click *Build, Deploy & Start* from *Deploy* section of *Hardware* tab in the Simulink
% Toolstrip for the Controller model _Quadcopter_ControllerWithNavigation_.
% 
% <<../px4_deploy1.png>>
%
% The code will be generated for the Controller model and the same will be
% automatically deployed to the Pixhawk board (Pixhawk 4 in this example).
%
% After the deployment is complete, QGroundControl will be automatically launched.
%
%% Step 4: Launch Second Session of MATLAB and Open the Flight Visualization Model
%
% 1. Launch second session of MATLAB.
%
% 2. Open the
% <matlab:openExample('px4/SimulationFlightVisualizationPX4HITLUAVDynamicsExample') px4demo_HardwareInLoopWithSimulinkPlant> MATLAB project.
%
% 3. Once the Simulink project is open, click the *Project Shortcuts* tab
% on the MATLAB window and click *Open 3D Visualization with Unreal Engine* to launch the onboard model named _Unreal_3DVisualization_.
%
% <<../px4_open_unrealmodel.png>>
%
%
% <<../px4_unreal_updated.png>>
%
% In this model, The MAVLink data from the PX4 Autopilot is received over
% UDP (port : 25000) and is used to decode the position and attitude data
% of the UAV. After coordinate conversion, it is then passed to the
% <https://www.mathworks.com/help/uav/ref/simulation3duavvehicle.html Simulation 3D UAV Vehicle> block for flight visualization.
%
% 4. On the *Simulation* tab, click *Run* to simulate the model. Once the
% model start running, you will see the Unreal simulation environment
% getting launched. A sample screen is shown below.
%
% <<../px4_unreal.png>>
%
%
%% Step 5: Run the UAV Dynamics Model, Upload Mission from QGroundControl and Fly the UAV
%
% 1. In the Simulink toolstrip of the Plant model (_UAV_Dynamics_Autopilot_Communication_), on the *Simulation* tab, click *Run* to simulate the model.
% 
% <<../px4_run_model1.png>>
%
% 2. In the QGC, navigate to the _<https://docs.qgroundcontrol.com/master/en/qgc-user-guide/plan_view/pattern_survey.html Plan View>_.
%
% <<../px4_pln_view.png>>
%  
%
% 3. Create a mission. For information on creating a mission, see <https://docs.qgroundcontrol.com/master/en/qgc-user-guide/plan_view/pattern_survey.html Plan View>. 
%
% After you create a mission, it is visible in QGC.
% 
% 4. Click Upload button in the QGC interface to upload the mission from QGroundControl.
%
% 5. Navigate to _<https://docs.qgroundcontrol.com/master/en/qgc-user-guide/fly_view/fly_view.html Fly View>_ to view the uploaded mission. 
%
% 6. Start the Mission in QGC. The UAV should follow the mission path and the flight will be simulated in the Unreal environment.
%
% <<../px4_unreal_sim.png>>
%
%% Troubleshooting
%
% * While Simulating the visualization model in Step 4, you might get any eSTD exceptionc errors such as, "some module could not be found". Change the compiler to Microsoft Visual C++ 2019 using |mex --setup C++| command to fix the issue.
%
% * If the Unreal environment simulation is very slow, ensure that your
% Host PC is Configured with MATLAB supported GPU (GPU with <https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#compute-capabilities compute capability> of more than 5).
