modded class DayZPlayerImplementAiming //TODO Deplete
{
	override bool ProcessAimFilters(float pDt, SDayZPlayerAimingModel pModel, int stance_index)
	{
		float breathing_offset_x;
		float breathing_offset_y;
		
		float noise_offset_x;
		float noise_offset_y;		
		
		float shake_offset_x;
		float shake_offset_y;
		
		float recoil_offset_mouse_x;
		float recoil_offset_mouse_y;
		
		float recoil_offset_hands_x;
		float recoil_offset_hands_y;
		
		float kuru_offset_x;
		float kuru_offset_y;
		
		float player_stamina = m_PlayerPb.GetStaminaHandler().GetSyncedStaminaNormalized();
		
		#ifdef DEVELOPER
		DbgPrintAimingImplement("Player: " + m_PlayerPb + " | ProcessAimFilters | timestamp: " + m_PlayerPb.GetSimulationTimeStamp());
		#endif
		
		//negates stamina effect during hold breath
		if (m_PlayerPb.IsHoldingBreath())
		{
			player_stamina = 1;
		}
		float speed = CalculateSpeedMultiplier(player_stamina);
		m_TotalTime += pDt * speed;
		
		if (m_PlayerPb.IsHoldingBreath() && !m_HoldingBreathSet)
		{
			m_ReferenceTime = m_TotalTime;
		}
		else if (!m_PlayerPb.IsHoldingBreath() && m_HoldingBreathSet)
		{
			m_ReferenceTime = m_TotalTime;
		}
		
		float adjusted_sway_multiplier = CalculateSwayMultiplier();
		m_LastSwayMultiplier = adjusted_sway_multiplier;
		
		m_SwayWeight = CalculateWeight(	stance_index, player_stamina, 0.5/*m_PlayerPb.m_CameraSwayModifier*/, m_PlayerPb.IsHoldingBreath()) * adjusted_sway_multiplier;

		//! get sway
		ApplyBreathingPattern(breathing_offset_x, breathing_offset_y, 3.0, m_TotalTime, m_SwayWeight);
		ApplyHorizontalNoise(noise_offset_x, noise_offset_y, 0.2, 0.5, 3.0 * m_SwayModifier[0], speed, 3 * m_SwayModifier[1], m_SwayWeight, pDt);
		
		int shake_level = m_PlayerPb.GetShakeLevel();
		if (shake_level != 0)
		{
			ApplyShakes(shake_offset_x, shake_offset_y, shake_level);
		}

		//! get recoil
		if (m_CurrentRecoil)
		{
			m_CurrentRecoil.Update(pModel, recoil_offset_mouse_x, recoil_offset_mouse_y, recoil_offset_hands_x, recoil_offset_hands_y, pDt);
		}
		
		if (m_KuruShake)
		{
			m_KuruShake.Update(pDt, kuru_offset_x, kuru_offset_y);
		}
		
		//! hands offset
		pModel.m_fAimXHandsOffset = breathing_offset_x + noise_offset_x + recoil_offset_hands_x + shake_offset_x + kuru_offset_x;
		pModel.m_fAimYHandsOffset = breathing_offset_y + noise_offset_y + recoil_offset_hands_y + shake_offset_y + kuru_offset_y;
		
		#ifdef DEVELOPER
		DbgPrintAimingImplement("breathing_offset_y: " + breathing_offset_y);
		DbgPrintAimingImplement("noise_offset_y: " + noise_offset_y);
		DbgPrintAimingImplement("recoil_offset_hands_y: " + recoil_offset_hands_y);
		DbgPrintAimingImplement("shake_offset_y: " + shake_offset_y);
		DbgPrintAimingImplement("kuru_offset_y: " + kuru_offset_y);
		DbgPrintAimingImplement("pModel.m_fAimYHandsOffset: " + pModel.m_fAimYHandsOffset);
		#endif
		//! cam offset
		pModel.m_fAimXCamOffset = -shake_offset_x - recoil_offset_hands_x - kuru_offset_x + m_CamShakeX;
		pModel.m_fAimYCamOffset	= -shake_offset_y - recoil_offset_hands_y - kuru_offset_y + m_CamShakeY;
		
		
		#ifdef DEVELOPER
		DbgPrintAimingImplement("m_CamShakeY: " + m_CamShakeY);
		DbgPrintAimingImplement("pModel.m_fAimYCamOffset: " + pModel.m_fAimYCamOffset);
		#endif
		
		//! clamp aim ranges 
		if (stance_index == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
		{
			float newVal = DayZPlayerUtils.LinearRangeClamp(pModel.m_fCurrentAimX, pModel.m_fCurrentAimY, m_AimXClampRanges);
			pModel.m_fAimYHandsOffset += newVal - pModel.m_fCurrentAimY;
		}
		float absAimY = Math.AbsFloat(pModel.m_fCurrentAimY);
		pModel.m_fAimYHandsOffset = Math.Clamp(pModel.m_fAimYHandsOffset,absAimY - 89.9,89.9 - absAimY); //'90' leads to rounding errors down the line
		
		if (m_PlayerDpi.IsInOptics() && m_KuruShake)
		{
			//TODO - do not offset mouse
		}
		//! mouse offset
		pModel.m_fAimXMouseShift = recoil_offset_mouse_x -kuru_offset_x / 10;
		pModel.m_fAimYMouseShift = recoil_offset_mouse_y + kuru_offset_y / 10;

		#ifdef DEVELOPER
		DbgPrintAimingImplement("recoil_offset_mouse_y: " + recoil_offset_mouse_y);
		DbgPrintAimingImplement("pModel.m_fAimYMouseShift: " + pModel.m_fAimYMouseShift);
		#endif
		
		if (m_PlayerPb.IsHoldingBreath() && !m_HoldingBreathSet)
		{
			m_HoldingBreathSet = true;
			m_HorizontalNoiseXAxisOffset = noise_offset_x;
			m_BreathingXAxisOffset = breathing_offset_x;
			m_BreathingYAxisOffset = breathing_offset_y;
		}
		else if (!m_PlayerPb.IsHoldingBreath() && m_HoldingBreathSet)
		{
			m_HoldingBreathSet = false;
		}
		
		if (!m_PlayerPb.IsHoldingBreath() && m_LastSwayMultiplier == PlayerSwayConstants.SWAY_MULTIPLIER_DEFAULT && m_HorizontalNoiseXAxisOffset != 0)
		{
			m_HorizontalNoiseXAxisOffset = 0;
			m_BreathingXAxisOffset = 0;
			m_BreathingYAxisOffset = 0;
		}
		
		if (m_PlayerPb.IsHoldingBreath())
		{
			ModifiersManager modifiersManager = m_PlayerPb.GetModifiersManager();
        	bool isConsumededAdderallActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_CONSUMPTION_ADDERALL);
        	bool isInjectedAdderallActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_INJECTION_ADDERALL);

        	if(!isConsumededAdderallActive && !isInjectedAdderallActive) //* if Adderall is not applied and active, we will normally deplete stamina.
       			{
					m_PlayerPb.DepleteStamina(EStaminaModifiers.HOLD_BREATH,pDt*speed);
       			}
		}
		#ifdef DEVELOPER
		DbgPrintAimingImplement("----------------------------");
		#endif
		return true;
	}
};