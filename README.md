# Master Thesis PX4
 Contains files for Master Thesis
 
 
 eFLL Library (Fuzzy Logic Library for Embedded Systems)
 - Fuzzy Logic Library is placed in path /src/lib/eFLL/.
 - This library is connected in PX4 and used in mc_rate_control module.
 
 Fuzzy logic Controller:
 - FLC was designed with the usage of eFLL library.
 - It was designed in Rate Control module (/src/modules/mc_rate_control/RateControl_Fuzzy)
   Designed controller is placed in files "RateControlFuzzy.hpp" and "RateControlFuzzy.cpp".
 - It is used in main files of rate controller called "MulticopterRateControl.cpp" and "MulticopterRateControl.hpp".
   Also in this file PID is working. Both of these controller was used in testing.
   
   
 Testing Part:
   QGroundControl Test:
   - These tests were performed with creating path manually in QGroundControl and was not saved anywhere.
   
   FLC Test:
   - These tests were performed with the usage of Attitude Control module (/src/modules/mc_att_control)
     Main file which serves as a script which is calculating set point for drone was modified in a way it allows to
     examine unit response. Script file is called "mc_att_control_main.cpp" (added code - lines 340-385).
 
 
