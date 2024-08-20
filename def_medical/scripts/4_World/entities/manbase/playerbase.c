modded class PlayerBase : ManBase
{
    private float m_DexamphetaminePoisoningLevel = 0.0;

    override void OnTick()
    {
        super.OnTick();

        DecreaseDexamphetaminePoisoningLevel(DEFMedicineConstants.DEXAMPHETAMINE_POISONING_HEAL_RATE);
    }

    void DecreaseDexamphetaminePoisoningLevel(float detoxificationRate)
    {
        m_DexamphetaminePoisoningLevel -= detoxificationRate;

        if (m_DexamphetaminePoisoningLevel < 0)
        {
            m_DexamphetaminePoisoningLevel = 0;
        }
    }

    void InduceDexamphetaminePoisoning(float poisoningDose)
    {
        m_DexamphetaminePoisoningLevel += poisoningDose;
    }

    eDexamphetaminePoisoningSeverityLevel GetPoisoningSeverityLevel()
    {
        if (m_DexamphetaminePoisoningLevel >= DEFMedicineConstants.DEXAMPHETAMINE_OVERDOSE_TRESHOLD_HIGH)
        {
            Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_HIGH + "rd DPSL at: " + m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_HIGH;
        }
        else if (m_DexamphetaminePoisoningLevel >= DEFMedicineConstants.DEXAMPHETAMINE_OVERDOSE_TRESHOLD_MEDIUM)
        {
            Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_MEDIUM + "nd DPSL at: " + m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_MEDIUM;
        }
        else
        {
            Print("[DEF - MEDICINE] Player " + GetCachedName() + " reached " + eDexamphetaminePoisoningSeverityLevel.DPSL_LOW + "st DPSL at: "+ m_DexamphetaminePoisoningLevel);
            return eDexamphetaminePoisoningSeverityLevel.DPSL_LOW;
        }
    }

    float GetCurrentPoisoningLevel()
    {
        return m_DexamphetaminePoisoningLevel;
    }
};