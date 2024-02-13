#include "RTEcat_KUKA_Client.h"

ROBOT_INFO kuka_info[ROBOTNUM];

RT_TASK motor_task;
RT_TASK print_task;
RT_TASK xddp_writer;

kuka_state kuka_data[ROBOTNUM];

using namespace std;

bool isSlaveInit()
{
    for(int i=0; i<ROBOTNUM; i++)
    {
        if(!ecat_el6695[i].isSystemReady())
            return false;
    }
    return true;
}

void readData()
{
    ecat_master.RxUpdate();
    for(int i=0; i<ROBOTNUM;i++)
    {
        // Read raw data
        kuka_data[i].actual_x[0].RxData_uint32 = ecat_el6695[i].sx_data;
        kuka_data[i].actual_x[1].RxData_uint32 = ecat_el6695[i].sy_data;
        kuka_data[i].actual_x[2].RxData_uint32 = ecat_el6695[i].sz_data;
        kuka_data[i].actual_x[3].RxData_uint32 = ecat_el6695[i].sa_data;
        kuka_data[i].actual_x[4].RxData_uint32 = ecat_el6695[i].sb_data;
        kuka_data[i].actual_x[5].RxData_uint32 = ecat_el6695[i].sc_data;
        kuka_data[i].actual_x[6].RxData_uint32 = ecat_el6695[i].se_data;
        kuka_data[i].actual_q[0].RxData_uint32 = ecat_el6695[i].sq1_data;
        kuka_data[i].actual_q[1].RxData_uint32 = ecat_el6695[i].sq2_data;
        kuka_data[i].actual_q[2].RxData_uint32 = ecat_el6695[i].sq3_data;
        kuka_data[i].actual_q[3].RxData_uint32 = ecat_el6695[i].sq4_data;
        kuka_data[i].actual_q[4].RxData_uint32 = ecat_el6695[i].sq5_data;
        kuka_data[i].actual_q[5].RxData_uint32 = ecat_el6695[i].sq6_data;
        kuka_data[i].actual_tau[0].RxData_uint32 = ecat_el6695[i].sT1_data;
        kuka_data[i].actual_tau[1].RxData_uint32 = ecat_el6695[i].sT2_data;
        kuka_data[i].actual_tau[2].RxData_uint32 = ecat_el6695[i].sT3_data;
        kuka_data[i].actual_tau[3].RxData_uint32 = ecat_el6695[i].sT4_data;
        kuka_data[i].actual_tau[4].RxData_uint32 = ecat_el6695[i].sT5_data;
        kuka_data[i].actual_tau[5].RxData_uint32 = ecat_el6695[i].sT6_data;
        // Data conversion
        kuka_info[i].act.x[0] = kuka_data[i].actual_x[0].RxData_float;
        kuka_info[i].act.x[1] = kuka_data[i].actual_x[1].RxData_float;
        kuka_info[i].act.x[2] = kuka_data[i].actual_x[2].RxData_float;
        kuka_info[i].act.x[3] = kuka_data[i].actual_x[3].RxData_float;
        kuka_info[i].act.x[4] = kuka_data[i].actual_x[4].RxData_float;
        kuka_info[i].act.x[5] = kuka_data[i].actual_x[5].RxData_float;
        kuka_info[i].act.x[6] = kuka_data[i].actual_x[6].RxData_float;
        kuka_info[i].act.q[0] = kuka_data[i].actual_q[0].RxData_float;
        kuka_info[i].act.q[1] = kuka_data[i].actual_q[1].RxData_float;
        kuka_info[i].act.q[2] = kuka_data[i].actual_q[2].RxData_float;
        kuka_info[i].act.q[3] = kuka_data[i].actual_q[3].RxData_float;
        kuka_info[i].act.q[4] = kuka_data[i].actual_q[4].RxData_float;
        kuka_info[i].act.q[5] = kuka_data[i].actual_q[5].RxData_float;
        kuka_info[i].act.tau[0] = kuka_data[i].actual_tau[0].RxData_float;
        kuka_info[i].act.tau[1] = kuka_data[i].actual_tau[1].RxData_float;
        kuka_info[i].act.tau[2] = kuka_data[i].actual_tau[2].RxData_float;
        kuka_info[i].act.tau[3] = kuka_data[i].actual_tau[3].RxData_float;
        kuka_info[i].act.tau[4] = kuka_data[i].actual_tau[4].RxData_float;
        kuka_info[i].act.tau[5] = kuka_data[i].actual_tau[5].RxData_float;
    
        // if(ecat_el6695[i].checkKRC() == ecat_el6695[i].STOPMESS_ON)
        // {

        // }
    }
}

/****************************************************************************/
void trajectory_generation(){
	/////////////Trajectory for Joint Space//////////////
    if(!Axis[0].trajInitialized())
    {
	    switch(motion)
	    {
	    case 1:
	    	// kuka_info[i].q_target(0)=1000; //kuka_info[i].q_target(1)=-1.5709;
	    	traj_time = 3;
	    	motion++;
	        break;
	    case 2:
	    	// kuka_info[i].q_target(0)=0.0; //kuka_info[i].q_target(1)=0.0;
	    	traj_time = 3;
	    	motion++;
	    	// motion=1;
	        break;
	    case 3:
	    	// kuka_info[i].q_target(0)=-1000; //kuka_info[i].q_target(1)=1.5709;
	    	traj_time = 3;
	    	motion++;
	        break;
	    case 4:
	    	// kuka_info[i].q_target(0)=0.0; //kuka_info[i].q_target(1)=0.0;
	    	traj_time = 3;
	    	motion=1;
	    	break;
	    default:
	    	// kuka_info[i].q_target(0)=kuka_info[i].act.q(0);
            // kuka_info[i].q_target(1)=kuka_info[i].act.q(1);

	    	motion=1;
	    	break;
	    }
	}

	// for(int i=0;i<ROBOTNUM;i++)
	// {
	// 	if(!Axis[i].trajInitialized())
	// 	{
	// 		Axis[i].setTrajInitialQuintic();
	// 		Axis[i].setTarPosInRad(kuka_info[i].q_target(i));
	// 		Axis[i].setTarVelInRad(0);
	// 		Axis[i].setTrajTargetQuintic(traj_time);
	// 	}

	// 	Axis[i].TrajQuintic();

	// 	kuka_info[i].des.q(i)=Axis[i].getDesPosInRad();
	// 	kuka_info[i].des.q_dot(i)=Axis[i].getDesVelInRad();
	// 	kuka_info[i].des.q_ddot(i)=Axis[i].getDesAccInRad();
	// }
}

void compute()
{

}

void control()
{
    for(int i=0;i<ROBOTNUM;i++){
        kuka_data[i].target_x[0].RxData_float = 0.3*sin(2*3.141592*0.3*gt);
        // kuka_data[i].target_x[1].RxData_float = 0.004*cos(2*3.141592*0.3*gt);
        // kuka_data[i].target_x[2].RxData_float = 0.004*sin(2*3.141592*0.3*gt);
        // kuka_data[i].target_x[3].RxData_float = 0.003*sin(2*3.141592*0.3*gt);
	}
    
}

void writeData()
{
    
    for(int i=0;i<ROBOTNUM;i++){
        ecat_el6695[i].writeXdata(kuka_data[i].target_x[0].RxData_uint32);      
        ecat_el6695[i].writeYdata(kuka_data[i].target_x[1].RxData_uint32);      
        ecat_el6695[i].writeZdata(kuka_data[i].target_x[2].RxData_uint32);    
        ecat_el6695[i].writeEdata(kuka_data[i].target_x[3].RxData_uint32);  
	}
    ecat_master.TxUpdate();
    ecat_master.SyncEcatMaster(rt_timer_read());
}

void motor_run(void *arg)
{
    RTIME beginCycle, endCycle;
   
    memset(&kuka_info, 0, sizeof(ROBOT_INFO));

    // ecat_master.activate_all(DEVICE2, config, JOINTNUM);

    for(int j=0; j<ROBOTNUM; ++j)
	{
		ecat_master.addSlaveEL6695(0, j, &ecat_el6695[j]);
	}
        
    // ecat_master.activateWithDC(0, cycle_ns);
    ecat_master.activate();

    for (int i=0; i<ROBOTNUM; i++)
        ecat_el6695[i].setServoOn();
    

    rt_task_set_periodic(NULL, TM_NOW, cycle_ns);
    while (1) {
        beginCycle = rt_timer_read();
        
        // Read Joints Data
        readData();

        if(system_ready)
        {
            // Trajectory Generation
            trajectory_generation();
            
            // Compute KDL
            // compute();	

            
            // Controller
            control();
                
        }
        // Write Joint Data
        writeData();

        endCycle = rt_timer_read();
		periodCycle = (unsigned long) endCycle - beginCycle;

        if(isSlaveInit())
            system_ready=true;
            
        gt+= period;
        if (periodCycle > cycle_ns) overruns++;
        rt_task_wait_period(NULL); //wait for next cycle
    }
}

void print_run(void *arg)
{
	RTIME now, previous=0;
	int i;
	unsigned long itime=0, step;
	long stick=0;
	int count=0;
		
	/* Arguments: &task (NULL=self),
	 *            start time,
	 *            period (here: 100ms = 0.1s)
	 */
	rt_task_set_periodic(NULL, TM_NOW, cycle_ns*100);
	
	while (1)
	{
		rt_task_wait_period(NULL); //wait for next cycle
		if (++count==10)
		{
			++stick;
			count=0;
		}
		
		if (system_ready)
		{
			now = rt_timer_read();
			step=(unsigned long)(now - previous) / 1000000;
			itime+=step;
			previous=now;

			rt_printf("Time=%0.3lfs, cycle_dt=%lius,  overrun=%d\n", gt, periodCycle/1000, overruns);
			for(int i=0; i<ROBOTNUM; i++)
            {
                rt_printf("Robot: %d\n", i);
                rt_printf("\tsx: %lf, sy: %lf, sz: %lf, se: %lf\n", kuka_info[i].act.x[0], kuka_info[i].act.x[1], kuka_info[i].act.x[2], kuka_info[i].act.x[6]);
                rt_printf("\tsa: %lf, sb: %lf, sc: %lf\n", kuka_info[i].act.x[3], kuka_info[i].act.x[4], kuka_info[i].act.x[5]);
                rt_printf("\tq1: %lf, q2: %lf, q3: %lf, q4: %lf, q5: %lf, q6: %lf\n", kuka_info[i].act.q[0], kuka_info[i].act.q[1], kuka_info[i].act.q[2], kuka_info[i].act.q[3], kuka_info[i].act.q[4], kuka_info[i].act.q[5]);
                rt_printf("\ttau1: %lf, tau2: %lf, tau3: %lf, tau4: %lf, tau5: %lf, tau6: %lf\n", kuka_info[i].act.tau[0], kuka_info[i].act.tau[1], kuka_info[i].act.tau[2], kuka_info[i].act.tau[3], kuka_info[i].act.tau[4], kuka_info[i].act.tau[5]);
            }
			rt_printf("\n");

		}
		else
		{
			if (count==0){
				rt_printf("%i", stick);
				for(i=0; i<stick; ++i)
					rt_printf(".");
				rt_printf("\n");
			}
		}
	}
}


void signal_handler(int signum)
{
    rt_task_delete(&motor_task);
    rt_task_delete(&print_task);
    rt_task_delete(&xddp_writer);

    

    printf("\n\n");
	if(signum==SIGINT)
		printf("╔════════════════[SIGNAL INPUT SIGINT]═══════════════╗\n");
	else if(signum==SIGTERM)
		printf("╔═══════════════[SIGNAL INPUT SIGTERM]═══════════════╗\n");	
	else if(signum==SIGTSTP)
		printf("╔═══════════════[SIGNAL INPUT SIGTSTP]══════════════╗\n");
    printf("║                Servo drives Stopped!               ║\n");
	printf("╚════════════════════════════════════════════════════╝\n");	

    ecat_master.deactivate();

    exit(1);
}

int main(int argc, char *argv[])
{
    // Perform auto-init of rt_print buffers if the task doesn't do so
    rt_print_init(0, NULL);

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
	signal(SIGTSTP, signal_handler);

    /* Avoids memory swapping for this program */
    mlockall(MCL_CURRENT|MCL_FUTURE);

    cpu_set_t cpuset_qt, cpuset_rt1, cpuset_rt2;
    CPU_ZERO(&cpuset_qt);
    CPU_ZERO(&cpuset_rt1);  
    CPU_ZERO(&cpuset_rt2);  

    CPU_SET(2, &cpuset_qt);  
    CPU_SET(3, &cpuset_rt1);  
    CPU_SET(2, &cpuset_rt2);  

    // // For CST (cyclic synchronous torque) control
	// if (ecat_master.init(OP_MODE_CYCLIC_SYNC_TORQUE, cycle_ns) == -1)
	// {
	// 	printf("System Initialization Failed\n");
	//     return 0;
	// }
	// for (int i = 0; i < JOINTNUM; ++i)
	// 	ModeOfOperation[i] = OP_MODE_CYCLIC_SYNC_TORQUE;
    
    rt_task_create(&motor_task, "motor_task", 0, 99, 0);
    rt_task_set_affinity(&motor_task, &cpuset_rt2);
    rt_task_start(&motor_task, &motor_run, NULL);

    rt_task_create(&print_task, "print_task", 0, 70, 0);
    rt_task_set_affinity(&print_task, &cpuset_rt2);
    rt_task_start(&print_task, &print_run, NULL);

    // Must pause here
    pause();

    // Finalize
    signal_handler(0);

    return 0;
}

