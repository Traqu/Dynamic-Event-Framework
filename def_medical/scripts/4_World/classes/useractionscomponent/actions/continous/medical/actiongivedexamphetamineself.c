class ActionGiveDexamphetamineSelf : ActionGiveSalineSelf
{
    private ref OverdoseManager m_OverdoseManager;
 
    void ActionGiveDexamphetamineSelf()
    {
        m_OverdoseManager = new OverdoseManager();
        m_CallbackClass = ActionGiveSalineSelfCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SALINEBLOODBAG;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "#STR_give_dexamphetamine_self";
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        action_data.m_MainItem.TransferModifiers(action_data.m_Player);
        Param1<float> nacdata = Param1<float>.Cast(action_data.m_ActionComponent.GetACData());		
        float delta = nacdata.param1;

        ModifiersManager modifiersManager = action_data.m_Player.GetModifiersManager();
        bool isModifierActive = modifiersManager.IsModifierActive(eCustomModifiers.MDF_DEXAMPHETAMINE);

        if(isModifierActive)
        {
            PlayerBase player = action_data.m_Player;
            m_OverdoseManager.ApplyOverdoseEffects(player, player.GetPoisoningSeverityLevel());
        }
        else
        {
        modifiersManager.ActivateModifier(eCustomModifiers.MDF_DEXAMPHETAMINE);
        }

        action_data.m_MainItem.Delete();
    }
};