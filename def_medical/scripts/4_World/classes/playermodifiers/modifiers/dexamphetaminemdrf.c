class DexamphetamineMdfr: ModifierBase
{
    private float m_RegenTime;
    private ref OverdoseManager m_OverdoseManager;
    private bool m_FromReconnect = false;

    override void Init()
    {
        m_OverdoseManager = new OverdoseManager();
        m_TrackActivatedTime = true;
        m_IsPersistent = true;
        m_ID = eCustomModifiers.MDF_DEXAMPHETAMINE;
        m_TickIntervalInactive = DEFAULT_TICK_TIME_INACTIVE;
        m_TickIntervalActive = DEFAULT_TICK_TIME_ACTIVE;
        m_RegenTime = DEFMedicineConstants.DEXAMPHETAMINE_EFFECT_DURATION;
        DisableActivateCheck();
    }

    override bool ActivateCondition(PlayerBase player)
    {
        return false;
    }

    override bool DeactivateCondition(PlayerBase player)
    {
        float attached_time = GetAttachedTime();
        return attached_time > m_RegenTime;
    }

    override void OnReconnect(PlayerBase player)
    {
        m_FromReconnect = true;
        OnActivate(player);
    }

    override void OnActivate(PlayerBase player)
    {

        player.IncreaseHealingsCount();
        
        if (!m_FromReconnect) //* happens only once on the initial injection, when player has not reconnected (to not kill him with overdose and not apply positive complementary effects twice)
        {
            ApplyComplementaryModifiers(player);
            player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);

            if(player.GetCurrentPoisoningLevel() != 0)
            {
               m_OverdoseManager.ApplyOverdoseEffects(player, player.GetPoisoningSeverityLevel());
            }
        }
        
        player.InduceDexamphetaminePoisoning(DEFMedicineConstants.DEXAMPHETAMINE_POISONING_DOSAGE);
        
        m_FromReconnect = false;
    }

    override void OnDeactivate(PlayerBase player)
    {
        player.DecreaseHealingsCount();
    }

    override void OnTick(PlayerBase player, float deltaT)
    {
        if (player.IsAlive())
        {
            if (DeactivateCondition(player))
            {
                ModifiersManager modifiersManager = player.GetModifiersManager();
                if (modifiersManager)
                {
                    modifiersManager.DeactivateModifier(m_ID);
                }
                return;
            }
        }
        
        if (player.GetHealth("", "Health") < player.GetMaxHealth("", "Health"))
        {
            ForceDisplayAscendingHealthTendency(player, 2);
        }

        float health_buff = DEFMedicineConstants.HEALTH_REGEN_MULTIPLIER * PlayerConstants.HEALTH_REGEN_MAX * deltaT;
        player.AddHealth("", "Health", health_buff);
    }

    void ForceDisplayAscendingHealthTendency(PlayerBase player, int tendency)
    {
        DisplayElementTendency dis_elm = DisplayElementTendency.Cast(player.GetVirtualHud().GetElement(eDisplayElements.DELM_TDCY_HEALTH));
        if (dis_elm)
        {
            dis_elm.SetTendency(tendency);
        }
    }

    void ApplyComplementaryModifiers(PlayerBase player)
    {
         ModifiersManager modifiersManager = player.GetModifiersManager();
        
        if (modifiersManager)
        {
            modifiersManager.ActivateModifier(eModifiers.MDF_MORPHINE);
            modifiersManager.ActivateModifier(eModifiers.MDF_EPINEPHRINE);
        }
    }
};