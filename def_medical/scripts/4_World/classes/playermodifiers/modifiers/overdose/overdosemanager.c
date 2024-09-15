class OverdoseManager
{
    private PlayerBase m_Player;

    void ApplyOverdoseEffects(PlayerBase player, eDexamphetaminePoisoningSeverityLevel poisoningLevel)
    {
        m_Player = player;
        switch (poisoningLevel)
        {
            case eDexamphetaminePoisoningSeverityLevel.DPSL_LOW:
                ApplyOverdoseEffectsLOW(player);
                break;

            case eDexamphetaminePoisoningSeverityLevel.DPSL_MEDIUM:
                ApplyOverdoseEffectsMEDIUM(player);
                break;

            case eDexamphetaminePoisoningSeverityLevel.DPSL_HIGH:
                ApplyOverdoseEffectsHIGH(player);
                break;

            default:
                Print("[DEF] Unknown Dexamphetamine poisoning level: " + poisoningLevel);
                break;
        }
    }

    void ApplyOverdoseEffectsLOW(PlayerBase player)
    {
        player.AddHealth("", "Shock", -70);
        player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
        player.GetStatWater().Add(-1000);
        player.GetStatEnergy().Add(-800);
    }

    void ApplyOverdoseEffectsMEDIUM(PlayerBase player)
    {
        ApplyOverdoseEffectsLOW(player);
        player.AddHealth("", "Blood", -1000);
        player.AddHealth("", "Health", -40);
    }

    void ApplyOverdoseEffectsHIGH(PlayerBase player)
    {
        player.SetHealth("", "Health", 11);
        ApplyOverdoseEffectsLOW(player);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DelayedKill, 5555, false);
    }

    void DelayedKill()
    {
        if (m_Player)
        {
            m_Player.SetHealth("", "Health", 0);
        }
    }
};