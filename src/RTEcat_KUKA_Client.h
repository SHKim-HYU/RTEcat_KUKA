#ifndef RTECAT_MOTOR_CLIENT_H_
#define RTECAT_MOTOR_CLIENT_H_

#include <stdio.h>
#include "iostream"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>

#include <sched.h>
#include <alchemy/task.h>
#include <alchemy/timer.h>
#include <rtdm/ipc.h> 

#undef debug


#include "Ecat_Master.h"
#include "ServoAxis_Motor.h"
#include <PropertyDefinition.h>

#define XDDP_PORT 0	/* [0..CONFIG-XENO_OPT_PIPE_NRDEV - 1] */

#define NSEC_PER_SEC 			1000000000
unsigned int cycle_ns = 1000000; // 2 ms
double period=((double) cycle_ns)/((double) NSEC_PER_SEC);	//period in second unit

// For RT thread management
static int run = 1;

unsigned long periodCycle = 0, worstCycle = 0;
unsigned int overruns = 0;

// FT Sensor parameter
unsigned char data_field[16];
short raw_data[6] = { 0 };
unsigned short temp;
float DF=50.0, DT=1000.0;
float ft_array[6];

// Interface to physical axes
NRMKHelper::ServoAxis Axis[JOINTNUM];
const int 	 zeroPos[JOINTNUM] = {0};
const INT32 	 gearRatio[JOINTNUM] = {18};

// EtherCAT System interface object
Master ecat_master;
Ecat_EL6695 ecat_el6695[ROBOTNUM];

// When all slaves or drives reach OP mode,
// system_ready becomes 1.
bool system_ready = false;
bool system_update = false;

// Global time (beginning from zero)
double gt=0;

// Trajectory parameers
double traj_time=0;
int motion=-1;


// Packet data converting: int <-> float
union converting{
	UINT32 RxData_uint32;
	float RxData_float;
};

typedef struct KUKA_STATE{
	converting actual_q[6];
	converting actual_tau[6];
	converting target_x[7];
	converting actual_x[7];
}kuka_state;

typedef struct STATE{
	Vector6f q;
	Vector6f tau;

	Vector6f x;                           //Task space
	Vector6f x_dot;
	Vector6f F;
    Vector6f F_ext;
    
    double s_time;
}state;

typedef struct ROBOT_INFO{
	int statusword[JOINTNUM];
    int modeofop[JOINTNUM];

	JVec traj_time;
	unsigned int idx;

	STATE act;
	STATE des;

}ROBOT_INFO;

#endif  // /* RTECAT_MOTOR_CLIENT_H */