/* Copyright (c) 2020, Dyssol Development Team. All rights reserved. This file is part of Dyssol. See LICENSE file for license information. */

#pragma once

// ========== Initial values

// Simulator
#define DEFAULT_MAX_ITERATIONS_NUMBER		500
#define DEFAULT_SIMULATION_TIME				60
#define DEFAULT_INIT_TIME_WINDOW			1
#define DEFAULT_MIN_TIME_WINDOW				1e-9
#define DEFAULT_MAX_TIME_WINDOW				1000000
#define DEFAULT_ITERS_UPPER_LIMIT			7
#define DEFAULT_ITERS_LOWER_LIMIT			3
#define DEFAULT_ITERS_1ST_UPPER_LIMIT		20
#define DEFAULT_WINDOW_MAGNIFICATION_RATIO	1.2
#define	DEFAULT_WEGSTEIN_ACCEL_PARAM		-0.5
#define DEFAULT_RELAXATION_PARAM			1

// Cache
#define DEFAULT_CACHE_FLAG_STREAMS		true
#define DEFAULT_CACHE_FLAG_HOLDUPS		false
#define DEFAULT_CACHE_FLAG_INTERNAL		false
#define DEFAULT_CACHE_WINDOW			100

// Initial tolerances
#define DEFAULT_A_TOL	1e-6
#define DEFAULT_R_TOL	1e-3

// Initial minimal fraction
#define DEFAULT_MIN_FRACTION	1e-9

//////////////////////////////////////////////////////////////////////////
/// Aggregation states

// Identifiers of phase types
enum EPhaseTypes : unsigned
{
	SOA_SOLID,
	SOA_LIQUID,
	SOA_VAPOR,
	SOA_LIQUID2,
	SOA_UNDEFINED
};

// ========== Convergence methods
enum EConvMethod
{
	CM_DIRECT_SUBSTITUTION	= 0,
	CM_WEGSTEIN				= 1,
	CM_STEFFENSEN			= 2
};

// ========== Extrapolation methods
enum class EExtrapMethod : unsigned
{
	EM_LINEAR	= 0,
	EM_SPLINE	= 1,
	EM_NEAREST	= 2
};

//======== SOLID DISTRIBUTIONS DATABASE [0; 50] ===============
#define DISTRIBUTIONS_NUMBER 15

enum EDistrTypes : unsigned
{
	DISTR_COMPOUNDS		  = 0,
	DISTR_SIZE			  = 1,
	DISTR_PART_POROSITY	  = 2,
	DISTR_FORM_FACTOR	  = 3,
	DISTR_COLOR			  = 4,
	DISTR_USER_DEFINED_01 = 20,
	DISTR_USER_DEFINED_02 = 21,
	DISTR_USER_DEFINED_03 = 22,
	DISTR_USER_DEFINED_04 = 23,
	DISTR_USER_DEFINED_05 = 24,
	DISTR_USER_DEFINED_06 = 25,
	DISTR_USER_DEFINED_07 = 26,
	DISTR_USER_DEFINED_08 = 27,
	DISTR_USER_DEFINED_09 = 28,
	DISTR_USER_DEFINED_10 = 29,
	DISTR_UNDEFINED		  = 31
};

#define DISTR_NAMES { "Compounds", "Size", "Particle porosity", "Form factor", "Color", "Distribution 1", "Distribution 2", "Distribution 3", "Distribution 4", "Distribution 5", "Distribution 6", "Distribution 7", "Distribution 8", "Distribution 9", "Distribution 10" }
#define DISTR_TYPES { DISTR_COMPOUNDS,  DISTR_SIZE, DISTR_PART_POROSITY, DISTR_FORM_FACTOR, DISTR_COLOR, DISTR_USER_DEFINED_01, DISTR_USER_DEFINED_02, DISTR_USER_DEFINED_03, DISTR_USER_DEFINED_04, DISTR_USER_DEFINED_05, DISTR_USER_DEFINED_06, DISTR_USER_DEFINED_07, DISTR_USER_DEFINED_08, DISTR_USER_DEFINED_09, DISTR_USER_DEFINED_10}
inline int GetDistributionTypeIndex(EDistrTypes _nType)
{
	EDistrTypes vTypes[] = DISTR_TYPES;
	for (unsigned i = 0; i < DISTRIBUTIONS_NUMBER; ++i)
		if (_nType == vTypes[i])
			return i;
	return -1;
}


// ========== m_StreamMTP indexes
#define MTP_MASS		0
#define MTP_TEMPERATURE	1
#define MTP_PRESSURE	2

// ========== TYPES OF GRIDS ENTRIES
enum class EGridEntry : unsigned
{
	GRID_NUMERIC	= 0,
	GRID_SYMBOLIC	= 2,
	GRID_UNDEFINED	= 15
};

// ========== TYPES OF GRID FUNCTIONAL DISTRIBUTIONS
enum class EGridFunction : unsigned
{
	GRID_FUN_MANUAL	         = 0,
	GRID_FUN_EQUIDISTANT	 = 1,
	GRID_FUN_GEOMETRIC_S2L	 = 2,
	GRID_FUN_LOGARITHMIC_S2L = 3,
	GRID_FUN_GEOMETRIC_L2S	 = 4,
	GRID_FUN_LOGARITHMIC_L2S = 5,
	GRID_FUN_UNDEFINED		 = 15
};

// ========== PSD TYPES
enum EPSDTypes
{
	PSD_q3       = 0,
	PSD_Q3       = 1,
	PSD_q0       = 2,
	PSD_Q0       = 3,
	PSD_MassFrac = 4,
	PSD_Number   = 5,
	PSD_q2       = 6,
	PSD_Q2       = 7
};

// ========== For stream addition

enum ETimePointsComposition
{
	BOTH_TP	= 0,
	DST_TP	= 1,
	SRC_TP	= 2
};

// ========== For lookup table creation
enum class EDependencyTypes
{
	DEPENDENCE_UNKNOWN = 0,
	DEPENDENCE_TEMP = 1,
	DEPENDENCE_PRES = 2
};

// ========== Non-constant single-phase mixture properties and overall properties [300..399]

//#define ENTHALPY				308 // overall
#define FLOW					320	// overall (stream)
#define MASS					320	// overall (holdup)
#define FRACTION				321
#define PHASE_FRACTION			327
#define PRESSURE				338	// overall
#define TEMPERATURE				340	// overall
#define TOTAL_FLOW				342	// overall (stream)
#define TOTAL_MASS				342	// overall (holdup)

// ========== Universal constants

#define AVOGADRO_CONSTANT					6.022141994747e+23
#define BOLTZMANN_CONSTANT					1.38065032424e-23
#define IDEAL_GAS_STATE_REFERENCE_PRESSURE	101325
#define MOLAR_GAS_CONSTANT					8.314459848
#define SPEED_OF_LIGHT_IN_VACUUM			2.9979245811e+8
#define STANDARD_ACCELERATION_OF_GRAVITY	9.80665
#define STANDARD_CONDITION_T				298.15	// standard condition temperature in K
#define STANDARD_CONDITION_P				101325	// standard condition pressure in Pa
#define MATH_PI								3.14159265358979323846

// ========== Value basis

enum eValueBasises
{
	BASIS_MASS, BASIS_MOLL
};


//////////////////////////////////////////////////////////////////////////
/// Common enumerators
//////////////////////////////////////////////////////////////////////////
enum class EDistrFunction : unsigned
{
	Manual = 0,
	Normal = 1,
	RRSB = 2,
	GGS = 3,
	LogNormal = 4
};

enum class EPSDGridType : unsigned
{
	DIAMETER = 0,
	VOLUME = 1
};
