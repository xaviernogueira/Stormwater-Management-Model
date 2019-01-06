#include <boost/test/included/unit_test.hpp>
 
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>

#include "swmm5.h"
#include "toolkitAPI.h"
#include "../src/error.h"

// NOTE: Test LID Input File
#define DATA_PATH_INP_LID_BC "lid/w_wo_BC_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_BC "lid/w_wo_BC_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_BC "lid/w_wo_BC_2Subcatchments.out"

#define DATA_PATH_INP_LID_BC_REVISED "lid/revised/w_wo_BC_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_BC_REVISED "lid/revised/w_wo_BC_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_BC_REVISED "lid/revised/w_wo_BC_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_GR "lid/w_wo_GR_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_GR "lid/w_wo_GR_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_GR "lid/w_wo_GR_2Subcatchments.out"

#define DATA_PATH_INP_LID_GR_REVISED "lid/revised/w_wo_GR_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_GR_REVISED "lid/revised/w_wo_GR_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_GR_REVISED "lid/revised/w_wo_GR_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_IT "lid/w_wo_IT_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_IT "lid/w_wo_IT_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_IT "lid/w_wo_IT_2Subcatchments.out"

#define DATA_PATH_INP_LID_IT_REVISED "lid/revised/w_wo_IT_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_IT_REVISED "lid/revised/w_wo_IT_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_IT_REVISED "lid/revised/w_wo_IT_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_PP "lid/w_wo_PP_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_PP "lid/w_wo_PP_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_PP "lid/w_wo_PP_2Subcatchments.out"

#define DATA_PATH_INP_LID_PP_REVISED "lid/revised/w_wo_PP_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_PP_REVISED "lid/revised/w_wo_PP_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_PP_REVISED "lid/revised/w_wo_PP_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_RB "lid/w_wo_RB_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_RB "lid/w_wo_RB_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_RB "lid/w_wo_RB_2Subcatchments.out"

#define DATA_PATH_INP_LID_RB_REVISED "lid/revised/w_wo_RB_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_RB_REVISED "lid/revised/w_wo_RB_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_RB_REVISED "lid/revised/w_wo_RB_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_RG "lid/w_wo_RG_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_RG "lid/w_wo_RG_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_RG "lid/w_wo_RG_2Subcatchments.out"

#define DATA_PATH_INP_LID_RG_REVISED "lid/revised/w_wo_RG_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_RG_REVISED "lid/revised/w_wo_RG_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_RG_REVISED "lid/revised/w_wo_RG_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_SWALE "lid/w_wo_SWALE_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_SWALE "lid/w_wo_SWALE_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_SWALE "lid/w_wo_SWALE_2Subcatchments.out"

#define DATA_PATH_INP_LID_SWALE_REVISED "lid/revised/w_wo_SWALE_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_SWALE_REVISED "lid/revised/w_wo_SWALE_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_SWALE_REVISED "lid/revised/w_wo_SWALE_2Subcatchments_revised.out"

#define DATA_PATH_INP_LID_RD "lid/w_wo_RD_2Subcatchments.inp"
#define DATA_PATH_RPT_LID_RD "lid/w_wo_RD_2Subcatchments.rpt"
#define DATA_PATH_OUT_LID_RD "lid/w_wo_RD_2Subcatchments.out"

#define DATA_PATH_INP_LID_RD_REVISED "lid/revised/w_wo_RD_2Subcatchments_revised.inp"
#define DATA_PATH_RPT_LID_RD_REVISED "lid/revised/w_wo_RD_2Subcatchments_revised.rpt"
#define DATA_PATH_OUT_LID_RD_REVISED "lid/revised/w_wo_RD_2Subcatchments_revised.out"

using namespace std;

void open_swmm_lid(int lid_type, bool revised=false)
{
    if (revised)
    {
        switch(lid_type) 
        {
            case 0:
                swmm_open((char *)DATA_PATH_INP_LID_BC_REVISED, (char *)DATA_PATH_RPT_LID_BC_REVISED, (char *)DATA_PATH_OUT_LID_BC_REVISED);
                break;
            case 1:
                swmm_open((char *)DATA_PATH_INP_LID_GR_REVISED, (char *)DATA_PATH_RPT_LID_GR_REVISED, (char *)DATA_PATH_OUT_LID_GR_REVISED);
                break;
            case 2:
                swmm_open((char *)DATA_PATH_INP_LID_IT_REVISED, (char *)DATA_PATH_RPT_LID_IT_REVISED, (char *)DATA_PATH_OUT_LID_IT_REVISED);
                break;
            case 3:
                swmm_open((char *)DATA_PATH_INP_LID_PP_REVISED, (char *)DATA_PATH_RPT_LID_PP_REVISED, (char *)DATA_PATH_OUT_LID_PP_REVISED);
                break;
            case 4:
                swmm_open((char *)DATA_PATH_INP_LID_RB_REVISED, (char *)DATA_PATH_RPT_LID_RB_REVISED, (char *)DATA_PATH_OUT_LID_RB_REVISED);
                break;
            case 5:
                swmm_open((char *)DATA_PATH_INP_LID_RG_REVISED, (char *)DATA_PATH_RPT_LID_RG_REVISED, (char *)DATA_PATH_OUT_LID_RG_REVISED);
                break;
            case 6:
                swmm_open((char *)DATA_PATH_INP_LID_SWALE_REVISED, (char *)DATA_PATH_RPT_LID_SWALE_REVISED, (char *)DATA_PATH_OUT_LID_SWALE_REVISED);
                break;
            case 7:
                swmm_open((char *)DATA_PATH_INP_LID_RD_REVISED, (char *)DATA_PATH_RPT_LID_RD_REVISED, (char *)DATA_PATH_OUT_LID_RD_REVISED);
                break;
            default:
                break;
        }
    }
    else 
    {
        switch(lid_type) 
        {
            case 0:
                swmm_open((char *)DATA_PATH_INP_LID_BC, (char *)DATA_PATH_RPT_LID_BC, (char *)DATA_PATH_OUT_LID_BC);
                break;
            case 1:
                swmm_open((char *)DATA_PATH_INP_LID_GR, (char *)DATA_PATH_RPT_LID_GR, (char *)DATA_PATH_OUT_LID_GR);
                break;
            case 2:
                swmm_open((char *)DATA_PATH_INP_LID_IT, (char *)DATA_PATH_RPT_LID_IT, (char *)DATA_PATH_OUT_LID_IT);
                break;
            case 3:
                swmm_open((char *)DATA_PATH_INP_LID_PP, (char *)DATA_PATH_RPT_LID_PP, (char *)DATA_PATH_OUT_LID_PP);
                break;
            case 4:
                swmm_open((char *)DATA_PATH_INP_LID_RB, (char *)DATA_PATH_RPT_LID_RB, (char *)DATA_PATH_OUT_LID_RB);
                break;
            case 5:
                swmm_open((char *)DATA_PATH_INP_LID_RG, (char *)DATA_PATH_RPT_LID_RG, (char *)DATA_PATH_OUT_LID_RG);
                break;
            case 6:
                swmm_open((char *)DATA_PATH_INP_LID_SWALE, (char *)DATA_PATH_RPT_LID_SWALE, (char *)DATA_PATH_OUT_LID_SWALE);
                break;
            case 7:
                swmm_open((char *)DATA_PATH_INP_LID_RD, (char *)DATA_PATH_RPT_LID_RD, (char *)DATA_PATH_OUT_LID_RD);
                break;
            default:
                break;
        }
    }
} 

/* Fixture Open Close
 1. Opens Model
 *. testing interactions
 2. Closes Model 
*/
struct FixtureOpenClose_LID 
{
    FixtureOpenClose_LID() { }
    
    void open_swmm_model(int lid_type)
    {
        open_swmm_lid(lid_type);
    }
    
    ~FixtureOpenClose_LID() 
    {
        swmm_close();
    }
};

/* Fixture Before Start
 1. Opens Model
 *. can choose to start simulation 
 2. Starts Simulation
 3. Runs Simlation
 4. Ends simulation
 5. Closes Model 
*/
struct FixtureBeforeStart_LID {
    FixtureBeforeStart_LID() { }

    void open_swmm_model(int lid_type)
    {
        open_swmm_lid(lid_type);
    }
    
    ~FixtureBeforeStart_LID() {
        swmm_start(0);
        int error;
        double elapsedTime = 0.0;
        do
        {
            error = swmm_step(&elapsedTime);
        }while (elapsedTime != 0 && !error);
        if (!error) swmm_end();
        if (!error) swmm_report();

        swmm_close();
    }
};

/* Fixture Before Step Default
 1. Opens Model
 2. Starts Simulation
 *. can choose iterate over simulation if simulation started, 
    must call swmm_end() 
 3. Closes Model 
*/
struct FixtureBeforeStep_LID {
    FixtureBeforeStep_LID(){ }
    
    void open_swmm_model(int lid_type)
    {
        open_swmm_lid(lid_type);
        swmm_start(0);
    }
    
    ~FixtureBeforeStep_LID() {
        swmm_close();
    }
};

/* Fixture for comparing results using LID API
1. Opens model 
2. Starts simulation
3. Save data results 
4. Closes model
5. Open revised model
6. Starts simulation
*. update parameters to match original model
7. Closes model
*/
struct Fixture_LID_Results 
{
    Fixture_LID_Results()
    {
    }
    
    void open_swmm_model(int lid_type)
    {
        int error, sub_index;
        double elapsed_time = 0.0;
        double db_value = 0.0;
        
        string subcatch = string("wBC");
        
        open_swmm_lid(lid_type);
        swmm_start(0);
        sub_index = swmm_getObjectIndex(SM_SUBCATCH, (char *)subcatch.c_str(), &error);
        BOOST_REQUIRE(error == ERR_NONE);
        
        do
        {
            error = swmm_step(&elapsed_time);
            BOOST_REQUIRE(error == ERR_NONE);
            error = swmm_getSubcatchResult(sub_index, SM_SUBCRUNOFF, &db_value);
            BOOST_REQUIRE(error == ERR_NONE);

            subcatchment_runoff.push_back(db_value);
        }while (elapsed_time != 0 && !error);
        BOOST_CHECK_EQUAL(0, error);
        swmm_end();
        swmm_close();
        
        open_swmm_lid(lid_type, true);
        swmm_start(0);
    }
    ~Fixture_LID_Results() {
        swmm_close();
    }
    
    vector<double> subcatchment_runoff;
};

/* Fixture Before End
 1. Opens Model
 2. Starts Simulation
 3. Runs Simlation
 * can choose to interact after simulation end
 4. Ends simulation
 5. Closes Model 
*/
struct FixtureBeforeEnd_LID
{
    FixtureBeforeEnd_LID() { }

    void open_swmm_model(int lid_type)
    {
        open_swmm_lid(lid_type);
        swmm_start(0);

        int error;
        double elapsedTime = 0.0;
        do
        {
            error = swmm_step(&elapsedTime);
        }while (elapsedTime != 0 && !error);
        BOOST_CHECK_EQUAL(0, error);
    }
    
    ~FixtureBeforeEnd_LID() {
        swmm_end();
        swmm_close();
    }
};

/* Fixture Before Close
 1. Opens Model
 2. Starts Simulation
 3. Runs Simlation
 4. Ends simulation
 * can choose to interact after simulation end
 5. Closes Model 
*/
struct FixtureBeforeClose_LID
{
    FixtureBeforeClose_LID() {}

    void open_swmm_model(int lid_type)
    {
        open_swmm_lid(lid_type);
        swmm_start(0);

        int error;
        double elapsedTime = 0.0;
        do
        {
            error = swmm_step(&elapsedTime);
        }while (elapsedTime != 0 && !error);
        BOOST_CHECK_EQUAL(0, error);
        swmm_end();
    }
    
    ~FixtureBeforeClose_LID() {
        swmm_close();
    }
};