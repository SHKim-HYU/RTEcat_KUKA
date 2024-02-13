/*! 
 *  @file PropertyDefinition.h
 *  @brief header for property definition
 *  @author Sunhong Kim (tjsghd101@naver.com)
 *  @data Oct. 26. 2023
 *  @Comm
 */


#pragma once

#include <Eigen/Dense>

#define CONTROL_FREQ 1000
#define ROBOT_DOF 1
#define JOINTNUM 1
#define ROBOTNUM 2

#define ZERO_POS_1 -1625

#define MAX_CURRENT_1 2.55

#define MAX_TORQUE_1 431.97

#define invL2sqr_1 1000

// [General Parameters]
// 1. Motor
#define TORQUE_CONST_500 0.0884 		
#define TORQUE_CONST_200 0.087		
#define TORQUE_CONST_100 0.058		

#define TORQUE_ADC_500 48 // Torque ADC for Core 500 [NRMK]
#define TORQUE_ADC_200 96 // Torque ADC for Core 200 [NRMK]
#define TORQUE_ADC_100 96 // Torque ADC for Core 100 [NRMK]


// 2. Electrical
#define ENC_2048 2048
#define ENC_1024 1024
#define ENC_1000 1000
#define ENC_512 512
#define ABS_ENC_19 524288

#define ENC_CORE_500 65536
#define ENC_CORE_200 65536
#define ENC_CORE_100 65536
#define ENC_CORE 65536

// 3. Mechanical
#define HARMONIC_120 120
#define HARMONIC_100 100
#define HARMONIC_50 50

#define GEAR_RATIO_121 121
#define GEAR_RATIO_101 101
#define GEAR_RATIO_50 50

#define EFFICIENCY 75.0 // Gear efficiency

// 4. Type Definition
typedef Eigen::Matrix<float, JOINTNUM, 1> JVec;
typedef Eigen::Matrix<float, JOINTNUM, JOINTNUM> JMat;
typedef Eigen::Matrix<float, 4, 4> SE3;
typedef Eigen::Matrix<float, 3, 3> SO3;
typedef Eigen::Matrix<float, 4, 4> se3;
typedef Eigen::Matrix<float, 3, 3> so3;
typedef Eigen::Matrix<float, 6, JOINTNUM> ScrewList;
typedef Eigen::Matrix<float, 6, JOINTNUM> Jacobian;
typedef Eigen::Matrix<float, JOINTNUM,6 > pinvJacobian;
typedef Eigen::Matrix<float, 6*JOINTNUM, JOINTNUM> DerivativeJacobianVec;
typedef Eigen::Matrix<float, 6*JOINTNUM, 1> vecJVec;
typedef Eigen::Matrix<int, 6, 1> Vector6i;   
typedef Eigen::Matrix<double, 6, 1> Vector6d;   
typedef Eigen::Matrix<float, 6, 1> Vector6f;  
typedef Eigen::Matrix<float, 3, 1> Vector3f;   
typedef Eigen::Matrix<float, 4, 1> Vector4f;  
typedef Eigen::Matrix<float, 6, 6> Matrix6f;  
typedef Eigen::Matrix<float, JOINTNUM, JOINTNUM> Matrixnf;  
typedef Eigen::Matrix<float, 3, 3> Matrix3f;  
typedef Eigen::Matrix<float, 6, JOINTNUM> Matrix6xn;
typedef Eigen::Matrix<float, 6, JOINTNUM+1> Matrix6xn_1;
typedef Eigen::Matrix<float, JOINTNUM, JOINTNUM> MassMat;