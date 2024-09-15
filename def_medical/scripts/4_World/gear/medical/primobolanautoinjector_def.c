class PrimobolanAutoInjector_DEF: Inventory_Base
{
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionInjectPrimobolanTarget);
        AddAction(ActionInjectPrimobolanSelf);
    }

    override void OnApply(PlayerBase player)
	{
		if (!player)
			return;
		if( player.GetModifiersManager().IsModifierActive( eCustomModifiers.MDF_PRIMOBOLAN ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( eCustomModifiers.MDF_PRIMOBOLAN );
		}
		player.GetModifiersManager().ActivateModifier( eCustomModifiers.MDF_PRIMOBOLAN );
	}
};