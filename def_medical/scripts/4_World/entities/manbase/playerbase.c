modded class PlayerBase : ManBase
{
    private float m_DexamphetaminePoisoningLevel = 0.0;

    override void OnTick()
    {
        super.OnTick();

        DecreaseDexamphetaminePoisoningLevel(DEFMedicineConstants.DEXAMPHETAMINE_POISONING_HEAL_RATE);
    };

    void DecreaseDexamphetaminePoisoningLevel(float detoxificationRate)
    {
        m_DexamphetaminePoisoningLevel -= detoxificationRate;

        if (m_DexamphetaminePoisoningLevel < 0)
        {
            m_DexamphetaminePoisoningLevel = 0;
        };
    };

    void InduceDexamphetaminePoisoning(float poisoningDose)
    {
        m_DexamphetaminePoisoningLevel += poisoningDose;
    };

    eDexamphetaminePoisoningSeverityLevel GetPoisoningSeverityLevel()
    {
        if (m_DexamphetaminePoisoningLevel >= DEFMedicineConstants.DEXAMPHETAMINE_OVERDOSE_TRESHOLD_HIGH)
        {
          //  Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_HIGH + "rd DPSL at: " + m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_HIGH;
        }
        else if (m_DexamphetaminePoisoningLevel >= DEFMedicineConstants.DEXAMPHETAMINE_OVERDOSE_TRESHOLD_MEDIUM)
        {
         //  Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_MEDIUM + "nd DPSL at: " + m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_MEDIUM;
        }
        else
        {
          //  Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_LOW + "st DPSL at: "+ m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_LOW;
        };
    };

    float GetCurrentPoisoningLevel()
    {
        return m_DexamphetaminePoisoningLevel;
    };

    override bool IsHoldingBreath()     //* For adderall mechanic
    {
        ModifiersManager modifiersManager = GetModifiersManager();
        // Usual behaviour, if null
        if (!modifiersManager)
        {
            return super.IsHoldingBreath();
        };

        bool isConsumedAdderallActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_CONSUMPTION_ADDERALL);
        bool isInjectedAdderallActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_INJECTION_ADDERALL);
        // Usual behaviour, if non of the modifiers is active → we will proceed to stamina depletion on aiming
        if (!isConsumedAdderallActive && !isInjectedAdderallActive)
        {
            return super.IsHoldingBreath();
        };
        // If Adderall is active, we will not proceed to stamina depletion
        return false;
    };
};