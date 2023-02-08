
#include "RateControlFuzzy.hpp"
#include <iostream>
#include <mathlib/math/Limits.hpp>
#include <mathlib/math/Functions.hpp>



void FuzzyControl::initiate(){

		std::cout << "I am initiating Fuzzy rules...." << std::endl;

		/*#####################################
	    ### Instantiating a Fuzzy INPUT object for rate ###
	    ######################################*/
	    FuzzyInput *rate = new FuzzyInput(1);
	    
	    rate->addFuzzySet(leftfar);
	    rate->addFuzzySet(left);
	    rate->addFuzzySet(mid);
	    rate->addFuzzySet(right);
	    rate->addFuzzySet(rightfar);

	    // Including the FuzzyInput into Fuzzy Control Engine
	    fuzzy->addFuzzyInput(rate);
	    fuzzy_z->addFuzzyInput(rate);


		/*#####################################
	    ### Instantiating a Fuzzy INPUT object for speed ###
	    ######################################*/


	    FuzzyInput *speed = new FuzzyInput(2);

		speed->addFuzzySet(leftfar_speed);
		speed->addFuzzySet(left_speed);
		speed->addFuzzySet(slow_speed);
		speed->addFuzzySet(right_speed);
		speed->addFuzzySet(rightfar_speed);

		// Including the FuzzyInput into Fuzzy Control Engine
		fuzzy->addFuzzyInput(speed);
		fuzzy_z->addFuzzyInput(speed);
		/*#####################################
	    ### Instantiating a Fuzzy INPUT object for acceleration ###
	    ######################################*/


	    FuzzyInput *acceleration = new FuzzyInput(3);

		acceleration->addFuzzySet(left_accel);
		acceleration->addFuzzySet(slow_accel);
		acceleration->addFuzzySet(right_accel);

		// Including the FuzzyInput into Fuzzy Control Engine
		fuzzy->addFuzzyInput(acceleration);
		fuzzy_z->addFuzzyInput(speed);

		/*#####################################
	    ### Instantiating a Fuzzy OUTPUT object for motor ###
	    ######################################*/
	    FuzzyOutput *motors = new FuzzyOutput(1);


	    motors -> addFuzzySet(motor_farleft);
	    motors -> addFuzzySet(motor_left);
	    motors -> addFuzzySet(motor_zero);
	    motors -> addFuzzySet(motor_right);
	    motors -> addFuzzySet(motor_farright);

	    // Including the FuzzyOutput into Fuzzy Control Engine
	    fuzzy->addFuzzyOutput(motors);
	    fuzzy_z->addFuzzyOutput(motors);

	    //  FuzzyRule IF error = far left AND speed = left THEN motor = far_right
	    //  FuzzyRule IF error = far left AND speed = slow or right THEN motor = right
	    //  FuzzyRule IF error = left AND speed = right THEN motor = zero
	    //  FuzzyRule IF error = zero AND speed = left or slow or right THEN motor = zero
	    //  FuzzyRule IF error = right AND speed = left or slow THEN motor = left
	    //  FuzzyRule IF error = right AND speed = left THEN motor = zero
	    //  FuzzyRule IF error = far right AND speed = left THEN motor = far_left
	    //  FuzzyRule IF error = far right AND speed = slow or right THEN motor = far_left



	    //  Building FuzzyRule "IF error =  left AND speed = left THEN motor = far_right


	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft1 = new FuzzyRuleAntecedent();
	    	    	    errorleftandspeedfarleft1 -> joinWithAND(leftfar, left_speed);

	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    FuzzyRuleConsequent *thenmotorfarright1 = new FuzzyRuleConsequent();
	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    thenmotorfarright1->addOutput(motor_farright);

	    	    	    // Instantiating a FuzzyRule objects
	    	    	    FuzzyRule *fuzzyRule1 = new FuzzyRule(1, errorleftandspeedfarleft1, thenmotorfarright1);
	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    fuzzy->addFuzzyRule(fuzzyRule1);

	 //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft2 = new FuzzyRuleAntecedent();
	    	    	    errorleftandspeedfarleft2 -> joinWithAND(leftfar, slow_speed);

	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    FuzzyRuleConsequent *thenmotorfarright2 = new FuzzyRuleConsequent();
	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    thenmotorfarright2->addOutput(motor_right);

	    	    	    // Instantiating a FuzzyRule objects
	    	    	    FuzzyRule *fuzzyRule2 = new FuzzyRule(2, errorleftandspeedfarleft2, thenmotorfarright2);
	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    fuzzy->addFuzzyRule(fuzzyRule2);


	    	//  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft3 = new FuzzyRuleAntecedent();
	    	    	    errorleftandspeedfarleft3 -> joinWithAND(leftfar, right_speed);

	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    FuzzyRuleConsequent *thenmotorfarright3 = new FuzzyRuleConsequent();
	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    thenmotorfarright3->addOutput(motor_right);

	    	    	    // Instantiating a FuzzyRule objects
	    	    	    FuzzyRule *fuzzyRule3 = new FuzzyRule(3, errorleftandspeedfarleft3, thenmotorfarright3);
	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    fuzzy->addFuzzyRule(fuzzyRule3);


	    //  Building FuzzyRule "IF error =  left AND speed = left THEN motor = far_right


	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft = new FuzzyRuleAntecedent();
	    	    	    errorleftandspeedfarleft -> joinWithAND(left, left_speed);

	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    FuzzyRuleConsequent *thenmotorfarright = new FuzzyRuleConsequent();
	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    thenmotorfarright->addOutput(motor_right);

	    	    	    // Instantiating a FuzzyRule objects
	    	    	    FuzzyRule *fuzzyRule04 = new FuzzyRule(4, errorleftandspeedfarleft, thenmotorfarright);
	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    fuzzy->addFuzzyRule(fuzzyRule04);


	    	     // Building FuzzyRule "IF error = left AND speed = slow THEN motor = right

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorleftandspeedslow = new FuzzyRuleAntecedent();
	    	    		errorleftandspeedslow -> joinWithAND(left, slow_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorright = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorright->addOutput(motor_right);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule05 = new FuzzyRule(5, errorleftandspeedslow, thenmotorright);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule05);


	    	     //Building FuzzyRule "IF error = left AND speed = right THEN motor = right

	    	    	// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorleftandspeedright = new FuzzyRuleAntecedent();
	    	    		errorleftandspeedright -> joinWithAND(left, right_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorright1 = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorright1->addOutput(motor_right);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule06 = new FuzzyRule(6, errorleftandspeedright, thenmotorright1);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule06);


	    	     //Building FuzzyRule "IF error = zero AND speed = left THEN motor = right

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorzeroandspeedleft = new FuzzyRuleAntecedent();
	    	    		errorzeroandspeedleft -> joinWithAND(mid, left_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorright2 = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorright2->addOutput(motor_right);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule07 = new FuzzyRule(7, errorzeroandspeedleft, thenmotorright2);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule07);


	    	     // Building FuzzyRule "IF error = zero AND speed = slow THEN motor = zero

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorzeroandspeedslow = new FuzzyRuleAntecedent();
	    	    		errorzeroandspeedslow -> joinWithAND(mid, slow_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorzero = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorzero->addOutput(motor_zero);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule08 = new FuzzyRule(8, errorzeroandspeedslow, thenmotorzero);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule08);


	    	     //  Building FuzzyRule "IF error = zero AND speed = right THEN motor = left

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorzeroandspeedright = new FuzzyRuleAntecedent();
	    	    		errorzeroandspeedright -> joinWithAND(mid, right_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorleft = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorleft->addOutput(motor_left);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule09 = new FuzzyRule(9, errorzeroandspeedright, thenmotorleft);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule09);


	    	     // Building FuzzyRule "IF error = right AND speed = left THEN motor = left

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorrightandspeedleft = new FuzzyRuleAntecedent();
	    	    		errorrightandspeedleft -> joinWithAND(right, left_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorleft1 = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorleft1->addOutput(motor_left);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule12 = new FuzzyRule(12, errorrightandspeedleft, thenmotorleft1);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule12);


	    	     //  Building FuzzyRule "IF error = right AND speed = slow THEN motor = left

	    	    	// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorrightandspeedslow = new FuzzyRuleAntecedent();
	    	    		errorrightandspeedslow -> joinWithAND(right, slow_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorleft2 = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorleft2->addOutput(motor_left);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule11 = new FuzzyRule(11, errorrightandspeedslow, thenmotorleft2);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule11);



	    	    // Building FuzzyRule "IF error = right AND speed = right THEN motor = far_left

	    	    		// Instantiating a FuzzyRuleAntecedent objects
	    	    		FuzzyRuleAntecedent *errorrightandspeedright = new FuzzyRuleAntecedent();
	    	    		errorrightandspeedright -> joinWithAND(right, right_speed);

	    	    		// Instantiating a FuzzyRuleConsequent objects
	    	    		FuzzyRuleConsequent *thenmotorfarleft = new FuzzyRuleConsequent();
	    	    		// Including a FuzzySet to this FuzzyRuleConsequent
	    	    		thenmotorfarleft->addOutput(motor_left);

	    	    		// Instantiating a FuzzyRule objects
	    	    		FuzzyRule *fuzzyRule10 = new FuzzyRule(10, errorrightandspeedright, thenmotorfarleft);
	    	    		// Including the FuzzyRule into Fuzzy
	    	    		fuzzy->addFuzzyRule(fuzzyRule10);






	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft4 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft4 -> joinWithAND(rightfar, left_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright4 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright4->addOutput(motor_left);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule13 = new FuzzyRule(13, errorleftandspeedfarleft4, thenmotorfarright4);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule13);


	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft5 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft5 -> joinWithAND(rightfar, slow_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright5 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright5->addOutput(motor_left);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule14 = new FuzzyRule(14, errorleftandspeedfarleft5, thenmotorfarright5);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule14);

	    	    	    	 //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft6 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft6 -> joinWithAND(rightfar, right_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright6 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright6->addOutput(motor_farleft);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule15 = new FuzzyRule(15, errorleftandspeedfarleft6, thenmotorfarright6);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule15);
	    	    	    	    	    
	    	    	    	  //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft7 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft7 -> joinWithAND(rightfar, rightfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright7 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright7->addOutput(motor_farleft);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule24 = new FuzzyRule(24, errorleftandspeedfarleft7, thenmotorfarright7);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule24);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	  //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft8 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft8 -> joinWithAND(right, rightfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright8 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright8->addOutput(motor_farleft);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule23 = new FuzzyRule(23, errorleftandspeedfarleft8, thenmotorfarright8);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule23);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	    	    	 //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft9 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft9 -> joinWithAND(mid, rightfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright9 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright9->addOutput(motor_left);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule21 = new FuzzyRule(21, errorleftandspeedfarleft9, thenmotorfarright9);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule21);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	    //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft10 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft10 -> joinWithAND(left, rightfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright10= new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright10->addOutput(motor_zero);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule19 = new FuzzyRule(19, errorleftandspeedfarleft10, thenmotorfarright10);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule19);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	   //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft11 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft11 -> joinWithAND(leftfar, rightfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright11= new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright11->addOutput(motor_right);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule17 = new FuzzyRule(17, errorleftandspeedfarleft11, thenmotorfarright11);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule17);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	  //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft12 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft12 -> joinWithAND(rightfar, leftfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright12 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright12->addOutput(motor_left);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule25 = new FuzzyRule(25, errorleftandspeedfarleft12, thenmotorfarright12);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule25);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	  //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft13 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft13 -> joinWithAND(right, leftfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright13 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright13->addOutput(motor_zero);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule22 = new FuzzyRule(22, errorleftandspeedfarleft13, thenmotorfarright13);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule22);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	    	    	 //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft14 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft14 -> joinWithAND(mid, leftfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright14 = new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright14->addOutput(motor_right);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule20 = new FuzzyRule(20, errorleftandspeedfarleft14, thenmotorfarright14);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule20);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	    //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft15 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft15 -> joinWithAND(left, leftfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright15= new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright15->addOutput(motor_farright);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule18 = new FuzzyRule(18, errorleftandspeedfarleft15, thenmotorfarright15);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule18);
	    	    	    	    	    
	    	    	    	    	    
	    	    	    	    	    	    	    	    	   //  Building FuzzyRule "IF error =  far left AND speed = zero THEN motor = right
	    	    	    	    	    // Instantiating a FuzzyRuleAntecedent objects
	    	    	    	    	    FuzzyRuleAntecedent *errorleftandspeedfarleft16 = new FuzzyRuleAntecedent();
	    	    	    	    	    errorleftandspeedfarleft16 -> joinWithAND(leftfar, leftfar_speed);


	    	    	    	    	    // Instantiating a FuzzyRuleConsequent objects
	    	    	    	    	    FuzzyRuleConsequent *thenmotorfarright16= new FuzzyRuleConsequent();
	    	    	    	    	    // Including a FuzzySet to this FuzzyRuleConsequent
	    	    	    	    	    thenmotorfarright16->addOutput(motor_farright);

	    	    	    	    	    // Instantiating a FuzzyRule objects
	    	    	    	    	    FuzzyRule *fuzzyRule16 = new FuzzyRule(16, errorleftandspeedfarleft16, thenmotorfarright16);
	    	    	    	    	    // Including the FuzzyRule into Fuzzy
	    	    	    	    	    fuzzy->addFuzzyRule(fuzzyRule16);





}

matrix::Vector3f FuzzyControl::calculate(const matrix::Vector3f &rate, const matrix::Vector3f &rate_sp, const matrix::Vector3f &rate_actual, const matrix::Vector3f &rate_setpoint, const matrix::Vector3f accel, const float dt, const bool landed)
{

		//out matrix for output values
		matrix::Vector3f out;
		

		// Calculating actual error
		matrix::Vector3f error = rate_sp - rate;

		matrix::Vector3f speed_rate = rate_setpoint - rate_actual;
	    //############## Calculate first axis #######################
	    
	    fuzzy->setInput(1, error(0));
	    fuzzy->setInput(2, (float)speed_rate(0));
	    fuzzy->setInput(3, (float)accel(0));
	    
	    // Running the Fuzzification
	    fuzzy->fuzzify();
/*
	    for(int i=0;i<25;i++){
	    	x_fired[i] = fuzzy->isFiredRule(i);
	    	if(x_fired[i] == 1){
	    		std::cout << i << ", ";
	    	}
	    };
	     std::cout << "" << std::endl;

*/
	    // Running the Defuzzification
	    float output_x = fuzzy->defuzzify(1);


	    //############## Calculate Second axis #######################
	    
	    fuzzy->setInput(1, (float)error(1));
	    fuzzy->setInput(2, (float)speed_rate(1));
	    fuzzy->setInput(3, (float)accel(1));

	    // Running the Fuzzification
	    fuzzy->fuzzify();

	    for(int i=0;i<25;i++){
	    	y_fired[i] = fuzzy->isFiredRule(i);
	    };
	    // Running the Defuzzification
	    float output_y = (fuzzy->defuzzify(1));
	    


	    //############## Calculate Third axis #######################
	    
	    fuzzy->setInput(1, (float)error(2));
	    fuzzy->setInput(2, (float)speed_rate(2));
	    fuzzy->setInput(3, (float)accel(2));
	    
	    // Running the Fuzzification
	    fuzzy->fuzzify();

	    // Running the Defuzzification
	    float output_z = fuzzy->defuzzify(1);

  	// Pass value as 3d vector to output
	    out = matrix::Vector3f(output_x, output_y, output_z);

	return out;

}

float FuzzyControl::calculate1(float e)
{

	    //############## Calculate first axis #######################

	    fuzzy->setInput(1, e);

	    // Set the random value as an input
	    //fuzzy->setInput(2, (float)angular_accel(0));

	    // Running the Fuzzification
	    fuzzy->fuzzify();

	    // Running the Defuzzification
	    float output_x = fuzzy->defuzzify(1);


	return output_x;

}

