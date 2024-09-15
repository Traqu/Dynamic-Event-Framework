class AdderallAutoInjector_DEF: Inventory_Base
{
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionInjectAdderallTarget);
        AddAction(ActionInjectAdderallSelf);
    }

    override void OnApply(PlayerBase player)
	{
		if (!player)
			return;
		if( player.GetModifiersManager().IsModifierActive( eCustomModifiers.MDF_INJECTION_ADDERALL ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( eCustomModifiers.MDF_INJECTION_ADDERALL );
		}
		player.GetModifiersManager().ActivateModifier( eCustomModifiers.MDF_INJECTION_ADDERALL );
	}
};