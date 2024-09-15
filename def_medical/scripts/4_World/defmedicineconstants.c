/**
 * The class `DEFMedicineConstants` defines constants related to dexamphetamine and adderall effects
 * and thresholds.
 */
class DEFMedicineConstants
{
    //* With current settings of healing rate (0.0001) and poisoning dosage (1000.0) it takes ~25 minutes to fully remove the subsctance from the bloodstream,
    //* given that we are recovering on each tick in `PlayerBase` → ~200/250 units removed per `DexamphetamineMdfr` duration time (5 min / 300 seconds)...
    //TODO make more predictable way of removing the substance from the bloodstream ↑
    //----------------------------------------------------------
	//				DEXAMPHETAMINE
	//----------------------------------------------------------
    static const float DEXAMPHETAMINE_POISONING_DOSAGE = 1000.0;
    static const float DEXAMPHETAMINE_EFFECT_DURATION = 300.0; //? 5 min.
    static const float DEXAMPHETAMINE_POISONING_HEAL_RATE = 0.0001;
    //----------------------------------------------------------
	//				DEXAMPHETAMINE → OVERDOSE TRESHOLDS
	//----------------------------------------------------------
    static const float DEXAMPHETAMINE_OVERDOSE_TRESHOLD_HIGH = 750.0;   //! kill player
    static const float DEXAMPHETAMINE_OVERDOSE_TRESHOLD_MEDIUM = 500.0; //! LOW & subtract some health and blood
    static const float DEXAMPHETAMINE_OVERDOSE_TRESHOLD_LOW = 250.0;    //! cause vomit and apply shock damage
    //----------------------------------------------------------
	//				DEXAMPHETAMINE → HEALTH REGEN
	//----------------------------------------------------------
    static const float HEALTH_REGEN_MULTIPLIER = 3.0;
    //----------------------------------------------------------
	//				ADDERALL
	//----------------------------------------------------------
    //?--------------------------------------------------------←
    static const int ADDERALL_INJECTION_EFFECT_DURATION = 300; //? 5 min.
    static const int ADDERALL_CONSUMPTION_EFFECT_DURATION = 60; //? 1 min.
    //----------------------------------------------------------
	//				PRIMOBOLAN
	//----------------------------------------------------------
    static const int PRIMOBOLAN_INJECTION_EFFECT_DURATION = 300; //? 5 min.
    static const int PRIMOBOLAN_EFFECT_STRENGTH = 50 //* new temporary STAMINA_MIN_CAP value
};