class PrimobolanMdfr : ModifierBase
{
    private bool m_FromReconnect = false;

	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= eCustomModifiers.MDF_PRIMOBOLAN;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		DisableActivateCheck();
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override void OnReconnect(PlayerBase player)
	{
        m_FromReconnect = true;
		OnActivate(player);
	}
	
	override string GetDebugText()
	{
		return (DEFMedicineConstants.PRIMOBOLAN_INJECTION_EFFECT_DURATION - GetAttachedTime()).ToString();
	}
	
	override void OnActivate(PlayerBase player)
    {

        player.IncreaseHealingsCount();
        
        if (!m_FromReconnect) //* happens only once on the initial injection, when player has not reconnected (to not apply positive complementary effects twice)
        {
			player.AddHealth("", "Blood", 600); //* mimics the effect of anemia curing that takes place irl.
        }
        
        m_FromReconnect = false;
    }
	
	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseHealingsCount();
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if( attached_time >= DEFMedicineConstants.PRIMOBOLAN_INJECTION_EFFECT_DURATION )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
				//player.GetStaminaHandler().SetStamina(100);
	}
};