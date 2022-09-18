%% Signal declaration 
Signals = {
	'p_RailPressure_Error', 'fixdt(1,32,18)', 0, [[0] [4500]], 'bar', '{{GROUP=HPP_PID}} error of PID-control';
	'p_RailPressure', 'fixdt(0,32,18)', 0, [[0] [4500]], 'bar', '{{GROUP=HPP_PID}} measured rail pressure';
	'P_RailPressure_set', 'fixdt(0,32,18)', 0, [[0] [4500]], 'bar', '{{GROUP=HPP_PID}} desired rail pressure';
	'P_I_Coeff', 'fixdt(1,32,22)', 0, [[-500] [500]], '-', '{{GROUP=HPP_PID}} I-part coefficient';
    'P_P_Coeff', 'fixdt(1,32,22)', 0, [[-500] [500]], '-', '{{GROUP=HPP_PID}} P-part coefficient';
	'p_I_Part', 'int32', 0, [[-10] [10]], '-', '{{GROUP=HPP_PID}} I-part coefficient';
	'p_P_Part', 'int32', 0, [[-10] [10]], '-', '{{GROUP=HPP_PID}} I-part coefficient';
	'p_PID_Out', 'int32', 0, [[-10] [10]], '-', '{{GROUP=HPP_PID}} I-part coefficient';
	'P_PIDMode_Set', 'boolean', 0, [[0] [1]], '-', '{{GROUP=HPP_PID}} mode of PID-control: 1 - PID on 2 - PID off';
	'P_PIDMode', 'boolean', 0, [[0] [1]], 'bar', '{{GROUP=HPP_PID}} P_PIDMode_Set copy';
	'p_PIDError_Status', 'boolean', 0, [[0] [1]], 'bar', '{{GROUP=HPP_PID}} Error status: 0 - there is no error	1 - overpressure';
	'p_PWM_out', 'int32', 0, [[0] [100]], '-', '{{GROUP=HPP_PID}} HPP MEU PWM:	0 - max rate 1 - HPP disabled';
	
	'P_In_RailPressure_set', 'int32', 0, [[0] [4500]], 'bar', '{{GROUP=HPP_PID}} desired rail pressure';
	'P_In_I_Coeff', 'single', 0, [[-10] [10]], '-', '{{GROUP=HPP_PID}} I-part coefficient';
	'P_In_P_Coeff', 'single', 0, [[-10] [10]], '-', '{{GROUP=HPP_PID}} P-part coefficient';	
	'p_RailPressureSensor_bit', 'fixdt(0,32,18)', 0, [[0] [10000]], '-', '{{GROUP=HPP_PID}} bit of rail pressure sensor ADC';
	'p_RailPressureSensor_U', 'fixdt(0,32,18)', 0, [[0] [5000]], 'mv', '{{GROUP=HPP_PID}} bit of rail pressure sensor ADC';
};
CreateSignals(Signals);
clear Signals;

