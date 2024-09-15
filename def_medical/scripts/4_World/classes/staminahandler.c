modded class StaminaHandler
{
    override void Update(float deltaT, int pCurrentCommandID)
	{
		#ifdef DIAG_DEVELOPER
		if (m_StaminaDisabled)
			return;
		#endif
		if (m_Player)
		{
			// Calculates actual max stamina based on player's load
			if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			{
				//! gets the actual players load
				m_PlayerLoad = m_Player.GetWeightEx();

				//! StaminaCap calculation starts when PlayerLoad exceeds STAMINA_WEIGHT_LIMIT_THRESHOLD
				if (m_PlayerLoad >= CfgGameplayHandler.GetStaminaWeightLimitThreshold())
                {
                    if (IsPrimobolanActive())   // * we change the StaminaMinCap while PrimobolanMdfr is active
                    {
                       if(!IsMinStaminaCapGreaterThanPrimobolanCap()) //* it is important to check whether current server's cfgGampeplay setting is higher than what we want to apply, otherwise we could possibly nerf instead of buff the effect!
                       {
                            SetPrimobolanStaminaCap();
                       }
                       else
                       {
                        KeepCfgGameplayStaminaCap();
                       }
                    }
                    else    // * otherwise vanilla code will be run
                    {
                        KeepCfgGameplayStaminaCap();
                    }
                }

				else
				{
					m_StaminaCap = CfgGameplayHandler.GetStaminaMax();
				}
			}
			
			// Calculates stamina gain/loss based on movement and load
			m_Player.GetMovementState(m_State);

			switch (m_State.m_CommandTypeId)
			{
				case DayZPlayerConstants.COMMANDID_MOVE:
					StaminaProcessor_Move(m_State);
					break;
				case DayZPlayerConstants.COMMANDID_LADDER:
					StaminaProcessor_Ladder(m_State);
					break;
				case DayZPlayerConstants.COMMANDID_SWIM:
					StaminaProcessor_Swimming(m_State);
					break;
				case DayZPlayerConstants.COMMANDID_FALL:	//! processed on event
				case DayZPlayerConstants.COMMANDID_MELEE2:  //! processed on event
				case DayZPlayerConstants.COMMANDID_CLIMB:	//! processed on event
					break;
				default:
					if (!m_IsInCooldown)
					{
						m_StaminaDelta = GameConstants.STAMINA_GAIN_IDLE_PER_SEC;
					}
					break;
			}
			
			//Sets current stamina & stores + syncs data with client
			float temp = m_StaminaDelta * deltaT;
			if (temp < 0)
			{
				temp *= m_StaminaDepletionMultiplier;
			}
			else
			{
				temp *= m_StaminaRecoveryMultiplier;
			}
			
			m_Stamina = Math.Max(0, Math.Min((m_Stamina + temp), m_StaminaCap));
			m_Stamina = m_Stamina - m_StaminaDepletion;

			if (GetGame().IsServer() || !GetGame().IsMultiplayer())
			{
				m_Player.GetStatStamina().Set(m_Stamina);
				m_Time += deltaT;
				
				if (m_Time >= GameConstants.STAMINA_SYNC_RATE)
				{
					m_Time = 0;
					SetStamina(m_Stamina);
				}
			}

			#ifndef SERVER
			m_Player.SetStamina(m_StaminaSynced, m_StaminaCap);
			#endif

			ApplyExhaustion();
			CheckStaminaState();

			m_StaminaDelta = 0;
			m_StaminaDepletion = 0; // resets depletion modifier
			
		}
	}

    bool IsPrimobolanActive()
    {
        ModifiersManager modifiersManager = m_Player.GetModifiersManager();
        return modifiersManager.IsModifierActive(eCustomModifiers.MDF_PRIMOBOLAN);
    }

    float CalculateNewStaminaCap(float minCap)
    {
        return Math.Max(
            CfgGameplayHandler.GetStaminaMax() - (((m_PlayerLoad - CfgGameplayHandler.GetStaminaWeightLimitThreshold()) / GameConstants.STAMINA_KG_TO_GRAMS) * CfgGameplayHandler.GetStaminaKgToStaminaPercentPenalty()), minCap);
    }

    void SetPrimobolanStaminaCap()
    {
        m_StaminaCap = CalculateNewStaminaCap(DEFMedicineConstants.PRIMOBOLAN_EFFECT_STRENGTH);
    }

    void KeepCfgGameplayStaminaCap()
    {
        m_StaminaCap = CalculateNewStaminaCap(CfgGameplayHandler.GetStaminaMinCap());
    }

    bool IsMinStaminaCapGreaterThanPrimobolanCap()
    {
        return CfgGameplayHandler.GetStaminaMinCap() > DEFMedicineConstants.PRIMOBOLAN_EFFECT_STRENGTH;
    }
}