/**
 * @file RateControlFuzzy.hpp
 *
 * Fuzzy logic controller for rate changes
 */




#pragma once

#include <matrix/matrix/math.hpp>

//Fuzzy logic library
#include <lib/eFLL/Fuzzy.h>
#include <lib/mixer/MultirotorMixer/MultirotorMixer.hpp>
#include <uORB/topics/rate_ctrl_status.h>

class FuzzyControl
{
public:
	FuzzyControl() = default;
	
	Fuzzy *fuzzy = new Fuzzy();
	Fuzzy *fuzzy_z = new Fuzzy();
	
	~FuzzyControl(){ delete fuzzy;
	delete fuzzy_z;};
	
	
/**
* Fuzzy inputs parameters
**/
	float left_border = -81.0;
	float right_border = 81.0;

	float leftfar_rate = -80.0;
	float left_rate_fast = -60.0;
	float left_rate = -65.0;
	float mid_rate = 0.0;
	float right_rate_fast = 60.0;
	float right_rate = 65.0;
	float rightfar_rate = 80.0;
	

	float left_rate_border = -9.1;
	float right_rate_border = 9.1;

	float leftfar_fast = -9.0;
	float left_fast = -2.5;
	float left_fast_far = -2.0;
	float slow = 0.0;
	float right_fast_far = 2.0;
	float right_fast = 2.5;
	float rightfar_fast = 9.0;
	
	
	float left_acc_border = -1.1;
	float right_acc_border = 1.1;

	float left_acc = -1.0;
	float slow_acc = 0.0;
	float right_acc = 1.0;
	
/**
* Fuzzy outputs parameters
**/		

	float left_motor_border = -0.98;
	float right_motor_border = 0.98;


	float far_left = -0.96;
	float far_left_far = -0.3;
	float _left = -0.5;
	float _zero = 0.0;
	float _right = 0.5;
	float far_right_far = -0.3;
	float far_right = 0.96;
	
	
	/**
	 * Run initiating function for creating all fuzzy rules
	 **/
	
	 void initiate();
	 
	 /*
	    FuzzySet *left = new FuzzySet(-100.0, -100.0, leftfar_rate, mid_rate);

	    //FuzzySet *left = new FuzzySet(leftfar_rate, left_rate, left_rate, mid_rate);

	    FuzzySet *mid = new FuzzySet(leftfar_rate, mid_rate, mid_rate, rightfar_rate);

	    //FuzzySet *right = new FuzzySet(mid_rate, right_rate, right_rate, rightfar_rate);

	   FuzzySet *right = new FuzzySet(mid_rate, rightfar_rate, 100.0, 100.0);


	   //FuzzySet *motor_farleft = new FuzzySet(far_left, far_left, far_left, _left);
	   FuzzySet *motor_left = new FuzzySet(far_left, _zero, _zero, _zero);

	    //FuzzySet *motor_left = new FuzzySet(far_left, _left, _left, _zero);

	    FuzzySet *motor_zero = new FuzzySet(far_left, _zero, _zero, far_right);

	    //FuzzySet *motor_right = new FuzzySet(_zero,  _right,  _right, far_right);

	   FuzzySet *motor_right = new FuzzySet(_zero,  _zero, _zero, far_right);
*/

/*
	//############################# RULES 3x3 CASE ###########################################

	    //FuzzySet *leftfar = new FuzzySet(leftfar_rate, leftfar_rate, leftfar_rate, left_rate);
	    FuzzySet *left = new FuzzySet(left_border, left_border,  leftfar_rate, mid_rate);
	    FuzzySet *mid = new FuzzySet( leftfar_rate, mid_rate, mid_rate, rightfar_rate);
	    FuzzySet *right = new FuzzySet(mid_rate, rightfar_rate, right_border, right_border);
	   //FuzzySet *rightfar = new FuzzySet(right_rate, rightfar_rate, rightfar_rate, rightfar_rate);
	    
	    
	    FuzzySet *left_speed = new FuzzySet(left_rate_border, left_rate_border, left_fast, slow);
	    FuzzySet *slow_speed = new FuzzySet(left_fast, slow, slow, right_fast);
	    FuzzySet *right_speed = new FuzzySet(slow, right_fast, right_rate_border, right_rate_border);
	    

	   //FuzzySet *motor_farleft = new FuzzySet(far_left, far_left, far_left, _left);
	    FuzzySet *motor_left = new FuzzySet(left_motor_border, left_motor_border, _left, _zero);
	    FuzzySet *motor_zero = new FuzzySet(_left, _zero, _zero, _right);
	    FuzzySet *motor_right = new FuzzySet(_zero,  _right,  right_motor_border, right_motor_border);
	   //FuzzySet *motor_farright = new FuzzySet(_right,  far_right, far_right, far_right);
*/

/*
	 	//############################# RULES 5x3 CASE ###########################################

	 	    FuzzySet *leftfar = new FuzzySet(left_border, left_border, leftfar_rate, left_rate);
	 	    FuzzySet *left = new FuzzySet(leftfar_rate, left_rate,   left_rate, mid_rate);
	 	    FuzzySet *mid = new FuzzySet(left_rate, mid_rate, mid_rate, right_rate);
	 	    FuzzySet *right = new FuzzySet(mid_rate, right_rate, right_rate, rightfar_rate);
	 	    FuzzySet *rightfar = new FuzzySet(right_rate, rightfar_rate, right_border, right_border);


	 	    FuzzySet *left_speed = new FuzzySet(left_rate_border, left_rate_border, left_fast, slow);
	 	    FuzzySet *slow_speed = new FuzzySet(left_fast, slow, slow, right_fast);
	 	    FuzzySet *right_speed = new FuzzySet(slow, right_fast, right_rate_border, right_rate_border);


	 	    FuzzySet *motor_farleft = new FuzzySet(left_motor_border, left_motor_border, far_left, _left);
	 	    FuzzySet *motor_left = new FuzzySet(far_left, _left, _left, _zero);
	 	    FuzzySet *motor_zero = new FuzzySet(_left, _zero, _zero, _right);
	 	    FuzzySet *motor_right = new FuzzySet(_zero,  _right,  _right, far_right);
	 	    FuzzySet *motor_farright = new FuzzySet(_right,  far_right, right_motor_border, right_motor_border);

*/

	 	//############################# RULES 5x5 CASE ###########################################

	 	    FuzzySet *leftfar = new FuzzySet(left_border, left_border, leftfar_rate, left_rate_fast);
	 	    FuzzySet *left = new FuzzySet(leftfar_rate, left_rate,   left_rate, mid_rate);
	 	    FuzzySet *mid = new FuzzySet(left_rate, mid_rate, mid_rate, right_rate);
	 	    FuzzySet *right = new FuzzySet(mid_rate, right_rate, right_rate, rightfar_rate);
	 	    FuzzySet *rightfar = new FuzzySet(right_rate_fast, rightfar_rate, right_border, right_border);


	 	    FuzzySet *leftfar_speed = new FuzzySet(left_rate_border, left_rate_border, leftfar_fast, left_fast_far);
	 	    FuzzySet *left_speed = new FuzzySet(leftfar_fast, left_fast, left_fast, slow);
	 	    FuzzySet *slow_speed = new FuzzySet(left_fast, slow, slow, right_fast);
	 	    FuzzySet *right_speed = new FuzzySet(slow, right_fast, right_fast, rightfar_fast);
	 	    FuzzySet *rightfar_speed = new FuzzySet(right_fast_far, rightfar_fast, right_rate_border, right_rate_border);
	 	    
	 	    
	 	    FuzzySet *left_accel = new FuzzySet(left_acc_border, left_acc_border, left_acc, slow_acc);
	 	    FuzzySet *slow_accel = new FuzzySet(left_acc, slow_acc, slow_acc, right_acc);
	 	    FuzzySet *right_accel = new FuzzySet(slow_acc, right_acc, right_acc_border, right_acc_border);


	 	    FuzzySet *motor_farleft = new FuzzySet(left_motor_border, left_motor_border, far_left, far_left_far);
	 	    FuzzySet *motor_left = new FuzzySet(far_left, _left, _left, _zero);
	 	    FuzzySet *motor_zero = new FuzzySet(_left, _zero, _zero, _right);
	 	    FuzzySet *motor_right = new FuzzySet(_zero,  _right,  _right, far_right);
	 	    FuzzySet *motor_farright = new FuzzySet(far_right_far,  far_right, right_motor_border, right_motor_border);

	/**
	 * Run one control loop cycle calculation
	 * @param rate estimation of the current vehicle angular rate
	 * @param rate_sp desired vehicle angular rate setpoint
	 * @param dt desired vehicle angular rate setpoint
	 * @return [-1,1] normalized torque vector to apply to the vehicle
	 */
	
	 matrix::Vector3f calculate(const matrix::Vector3f &rate, const matrix::Vector3f &rate_sp, const matrix::Vector3f &rate1,
			 const matrix::Vector3f &rate_sp2, const matrix::Vector3f accel, const float dt, const bool landed);
	int x_fired[25];
	int y_fired[25];

	 float calculate1(float);

	/**
	 * Get status message of controller for logging/debugging
	 * @param rate_ctrl_status status message to fill with internal states
	 */
	void getRateControlStatus(rate_ctrl_status_s &rate_ctrl_status);


private:


	// States ??????????????????
	matrix::Vector3f _rate_int; ///< integral term of the rate controller

};
	