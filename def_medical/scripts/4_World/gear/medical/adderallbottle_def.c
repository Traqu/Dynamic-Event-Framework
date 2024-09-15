class AdderallBottle_DEF: Edible_Base
{
    //Specify this item can only be combined but not split
	override void InitItemVariables()
	{
		super.InitItemVariables();

		can_this_be_combined = true;
	}
	
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if (consumer.GetModifiersManager().IsModifierActive(eCustomModifiers.MDF_CONSUMPTION_ADDERALL)) //effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier(eCustomModifiers.MDF_CONSUMPTION_ADDERALL);
		}

		consumer.GetModifiersManager().ActivateModifier(eCustomModifiers.MDF_CONSUMPTION_ADDERALL);
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionEatPillFromBottle);
	}
}