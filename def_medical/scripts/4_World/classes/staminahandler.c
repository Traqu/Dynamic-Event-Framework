modded class StaminaHandler
{
	protected bool m_DEF_HasPrimobolanOverride;
	protected bool m_DEF_PrimobolanOverrideState;

	override void RecalculateStaminaCap()
	{
		if (m_PlayerLoad >= CfgGameplayHandler.GetStaminaWeightLimitThreshold())
		{
			float minCap = CfgGameplayHandler.GetStaminaMinCap();
			if (IsPrimobolanActive())
			{
				minCap = Math.Max(minCap, GetMedicineConfig().PrimobolanEffectStrength);
			}

			m_StaminaCap = CalculateNewStaminaCap(minCap);
		}
		else
		{
			m_StaminaCap = CfgGameplayHandler.GetStaminaMax();
		}

		m_StaminaCapSynced = m_StaminaCap;
	}

	void DEF_ForceRecalculateStaminaCap()
	{
		if (!m_Player || !m_Player.IsAuthority())
			return;

		m_PlayerLoad = m_Player.GetWeightEx();
		RecalculateStaminaCap();
	}

	void DEF_SetPrimobolanState(bool isActive)
	{
		m_DEF_HasPrimobolanOverride = true;
		m_DEF_PrimobolanOverrideState = isActive;
		DEF_ForceRecalculateStaminaCap();
	}

	protected bool IsPrimobolanActive()
	{
		if (m_DEF_HasPrimobolanOverride)
		{
			return m_DEF_PrimobolanOverrideState;
		}

		if (!m_Player)
			return false;

		ModifiersManager modifiersManager = m_Player.GetModifiersManager();
		if (!modifiersManager)
			return false;

		return modifiersManager.IsModifierActive(eCustomModifiers.MDF_PRIMOBOLAN);
	}

	protected float CalculateNewStaminaCap(float minCap)
	{
		float calculatedCap = CfgGameplayHandler.GetStaminaMax() - (((m_PlayerLoad - CfgGameplayHandler.GetStaminaWeightLimitThreshold()) / GameConstants.STAMINA_KG_TO_GRAMS) * CfgGameplayHandler.GetStaminaKgToStaminaPercentPenalty());
		return Math.Max(calculatedCap, minCap);
	}
};
