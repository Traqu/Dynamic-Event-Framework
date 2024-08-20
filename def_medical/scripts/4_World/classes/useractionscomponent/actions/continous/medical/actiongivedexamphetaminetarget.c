class ActionGiveDexamphetamineTarget : ActionGiveSalineTarget
{
    private ref OverdoseManager m_OverdoseManager;
  
    void ActionGiveDexamphetamineTarget()
    {
        m_OverdoseManager = new OverdoseManager();
        m_CallbackClass = ActionGiveSalineTargetCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAGTARGET;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "#STR_give_dexamphetamine_person";
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        PlayerBase ntarget = PlayerBase.Cast(action_data.m_Target.GetObject());
        Param1<float> nacdata = Param1<float>.Cast(action_data.m_ActionComponent.GetACData());
        float delta = nacdata.param1;
        

        ModifiersManager modifiersManager = ntarget.GetModifiersManager();
        bool isModifierActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_DEXAMPHETAMINE);

        if(isModifierActive)
        {
            PlayerBase player = ntarget;
            m_OverdoseManager.ApplyOverdoseEffects(player, player.GetPoisoningSeverityLevel());
        }
        else
        {
        modifiersManager.ActivateModifier(eCustomModifiers.MDF_DEXAMPHETAMINE);
        }
        
        action_data.m_MainItem.Delete();
    }
};